import time

from jinja2 import Environment, PackageLoader
from pipetools import pipe, where, X, sort_by

from coder.fetcher import fetch_problem_list, fetch_problem_submissions, fetch_submission_code


def render_readme(problems):

    env = Environment(loader=PackageLoader('coder', 'templates'), trim_blocks=True)

    template = env.get_template('README.md')
    rendered = template.render(problems=problems)

    with open('README.md', 'w') as f:
        print(rendered, file=f)


def dump_submissions_to(dir, start=0):
    for problem in (
            fetch_problem_list() > pipe
            | where(X.paid_only == False)
            | where(X.id >= start)
            | sort_by(X.id)
    ):
        submissions = fetch_problem_submissions(problem.title_slug)

        if len(submissions) == 0:
            continue

        problem_dir = dir / f'{problem.id:04}.{problem.title_slug}'
        problem_dir.mkdir(exist_ok=True)
        print(f'{len(submissions)} submissions for problem {problem.id}. {problem.title}')

        for submission in submissions:
            code = fetch_submission_code(submission.url)
            problem_file = problem_dir / f'{problem.id:04}.{problem.title_slug}.{submission.timestamp}.{submission.language.extension()}'
            with problem_file.open('w') as f:
                print(code, file=f)

        time.sleep(0.3)
