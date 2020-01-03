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


class Status(Enum):
    CE = 'Compile Error'
    RE = 'Runtime Error'
    TLE = 'Time Limit Exceeded'
    MLE = 'Memory Limit Exceeded'
    WA = 'Wrong Answer'
    AC = 'Accepted'


class Language(Enum):
    CPP = 'cpp'
    Java = 'java'
    Python = 'python'
    MySQL = 'mysql'

    def __le__(self, other):
        if not isinstance(other, Language):
            return False
        return self.value.__le__(other.value)

    @staticmethod
    def from_extension(extension):
        return {
            'cpp': Language.CPP,
            'java': Language.Java,
            'py': Language.Python,
            'sql': Language.MySQL,
        }[extension]

    def extension(self):
        return {
            Language.CPP: 'cpp',
            Language.Java: 'java',
            Language.Python: 'py',
            Language.MySQL: 'sql',
        }[self]

    def display(self):
        return {
            Language.CPP: 'C++',
        }.get(self, self.name)


@dataclass
class Problem:
    id: int
    title: str
    title_slug: str
    difficulty: Difficulty
    paid_only: bool

    def dir_name(self):
        return f'{self.id:04}.{self.title_slug}'


@dataclass
class Submission:
    id: int
    status: Status
    language: Language
    timestamp: int
    url: str
    code: str = ''


@dataclass
class ProblemSubmission:
    problem: Problem
    submission: Submission

    def file_name(self):
        problem = self.problem
        submission = self.submission
        return f'{problem.id:04}.{problem.title_slug}.{submission.timestamp}.{submission.language.extension()}'


@dataclass
class SubmissionFileName:
    id: int
    title_slug: str
    timestamp: int
    language: Language

    @staticmethod
    def from_str(file_name: str):
        id, title_slug, timestamp, extension = file_name.split('.')
        language = Language.from_extension(extension)
        return SubmissionFileName(id=id, title_slug=title_slug, timestamp=timestamp, language=language)

    def to_str(self):
        return f'{self.id:0>4}.{self.title_slug}.{self.timestamp}.{self.language.extension()}'
