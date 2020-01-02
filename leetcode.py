from coder.fetcher import fetch_problem_list
from coder.generator import render

if __name__ == '__main__':

    problems = fetch_problem_list()
    render(problems)