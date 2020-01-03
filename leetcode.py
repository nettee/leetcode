from pathlib import Path

import fire as fire

from coder.generator import render_readme, dump_submissions_to


def difficulty_to_badge(difficulty):
    return difficulty.name


class LeetCode:

    def dump(self, start=0):
        solutions_dir = Path('solutions')
        solutions_dir.mkdir(exist_ok=True)
        dump_submissions_to(solutions_dir, start)

    def render(self):
        render_readme()


if __name__ == '__main__':
    fire.Fire(LeetCode)
