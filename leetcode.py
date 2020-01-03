from pathlib import Path

import fire as fire
from pipetools import pipe, X, sort_by, foreach

from coder.fetcher import fetch_problem_list
from coder.generator import render_readme, dump_submissions_to
from coder.model import ProblemForRender


def difficulty_to_badge(difficulty):
    return difficulty.name


class LeetCode:

    def dump(self, start=0):
        solutions_dir = Path('solutions')
        solutions_dir.mkdir(exist_ok=True)
        dump_submissions_to(solutions_dir, start)

    def render(self):
        problems = fetch_problem_list()

        problems_for_render = (problems > pipe
                               | sort_by(X.id)
                               | foreach(ProblemForRender.from_problem)
                               | list
                               )

        render_readme(problems_for_render)


if __name__ == '__main__':
    fire.Fire(LeetCode)
