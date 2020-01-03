import time
from dataclasses import dataclass
from pathlib import Path
from typing import List

from jinja2 import Environment, PackageLoader
from pipetools import pipe, where, X, sort_by, foreach, group_by

from coder.fetcher import fetch_problem_list, fetch_problem_submissions, fetch_submission_code
from coder.model import Problem, ProblemSubmission, Language, SubmissionFileName


@dataclass
class ProblemForRender:
    id: int
    link: str
    difficulty_badge: str
    solution_links: List[str]

    @staticmethod
    def from_problem(problem: Problem):
        problem_url = f'https://leetcode.com/problems/{problem.title_slug}/'
        problem_link = f'[{problem.title}]({problem_url})'

        difficulty_badge_url = f'https://img.shields.io/badge/{problem.difficulty.name}-{problem.difficulty.color()}'
        difficulty_badge = f'![]({difficulty_badge_url})'

        solution_links = ProblemForRender.link_to_solutions(problem)

        return ProblemForRender(id=problem.id,
                                link=problem_link,
                                difficulty_badge=difficulty_badge,
                                solution_links=solution_links)

    @staticmethod
    def link_to_solutions(problem: Problem):
        solution_dir = Path('solutions')
        problem_dir = solution_dir / problem.dir_name()
        if not problem_dir.exists():
            return []
        links = (
            problem_dir.iterdir() > pipe
            | foreach(X.name)
            | foreach(SubmissionFileName.from_str)
            # Select one newest submission from each language
            | group_by(X.language)
            | foreach(X[1])
            | foreach(lambda submissions: max(submissions, key=lambda s: s.timestamp))
            # Sort
            | sort_by(X.language.order())
            # Format to links
            | foreach(lambda file: f'[{file.language.display()}]({problem_dir / file.to_str()})')
        )
        links = list(links)
        return links


def render_readme():
    problems = fetch_problem_list()

    problems_for_render = (problems > pipe
           | sort_by(X.id)
           | foreach(ProblemForRender.from_problem)
           | list
   )

    env = Environment(loader=PackageLoader('coder', 'templates'), trim_blocks=True)

    template = env.get_template('README.md')
    rendered = template.render(problems=problems_for_render)

    with open('README.md', 'w') as f:
        print(rendered, file=f)


def dump_submissions_to(solution_dir, start=0):
    for problem in (
            fetch_problem_list() > pipe
            | where(X.paid_only == False)
            | where(X.id >= start)
            | sort_by(X.id)
    ):
        submissions = fetch_problem_submissions(problem.title_slug)

        if len(submissions) == 0:
            continue

        problem_dir = solution_dir / problem.dir_name()
        problem_dir.mkdir(exist_ok=True)
        print(f'{len(submissions)} submissions for problem {problem.id}. {problem.title}')

        for submission in submissions:
            code = fetch_submission_code(submission.url)
            problem_submission = ProblemSubmission(problem=problem, submission=submission)
            problem_file = problem_dir / problem_submission.file_name()
            with problem_file.open('w') as f:
                print(code, file=f)

        time.sleep(0.3)
