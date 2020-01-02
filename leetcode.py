from pipetools import pipe, X, sort_by, foreach

from coder.fetcher import fetch_problem_list
from coder.generator import render_readme
from coder.model import ProblemForRender


def difficulty_to_badge(difficulty):
    return difficulty.name


if __name__ == '__main__':

    problems = fetch_problem_list()

    problems_for_render = (problems > pipe
            | sort_by(X.id)
            | foreach(ProblemForRender.from_problem)
            | list
    )

    render_readme(problems_for_render)