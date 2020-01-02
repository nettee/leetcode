from collections import namedtuple
from enum import Enum

Problem = namedtuple('Problem', ['id', 'title', 'title_slug', 'difficulty', 'paid_only'])


class Difficulty(Enum):
    Easy = 1
    Medium = 2
    Hard = 3