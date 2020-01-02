from dataclasses import dataclass
from enum import Enum


class Difficulty(Enum):
    Easy = 1
    Medium = 2
    Hard = 3

    def color(self):
        return {
            Difficulty.Easy: 'brightgreen',
            Difficulty.Medium: 'orange',
            Difficulty.Hard: 'red',
        }[self]



@dataclass
class Problem:
    id: int
    title: str
    title_slug: str
    difficulty: Difficulty
    paid_only: bool


@dataclass
class ProblemForRender:
    id: int
    link: str
    difficulty_badge: str

    @staticmethod
    def from_problem(problem: Problem):
        problem_url = f'https://leetcode.com/problems/{problem.title_slug}/'
        problem_link = f'[{problem.title}]({problem_url})'

        difficulty_badge_url = f'https://img.shields.io/badge/{problem.difficulty.name}-{problem.difficulty.color()}'
        difficulty_badge = f'![]({difficulty_badge_url})'

        return ProblemForRender(id=problem.id,
                                link=problem_link,
                                difficulty_badge=difficulty_badge)