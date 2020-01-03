import re
from urllib.parse import urljoin

import requests
from pipetools import pipe, where, X, foreach

from coder.graphql import execute_graphql
from coder.model import Problem, Difficulty, Submission, Status, Language

base_url = 'https://leetcode-cn.com/'
api_url = 'https://leetcode-cn.com/graphql'
problem_url = 'https://leetcode-cn.com/problems/two-sum/description/'

# Manually copied
user_agent = 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36'
cookie = '__auc=09210b5216f55ff90fa38e8c0b6; gr_user_id=4e9195d6-8f57-444c-b6c5-13f3e4034220; _ga=GA1.2.396238290.1577695811; grwng_uid=e7b70cd3-0f1e-4d59-84a3-670f73550282; a2873925c34ecbd2_gr_last_sent_cs1=nettee; __atuvc=1%7C1; _gid=GA1.2.129572262.1577945236; _uab_collina=157794856592973486997455; csrftoken=reURCcM7pqxeXKquqhxL4nuc0LEqg1jPRcCdJCNIIPyvipdtNmSslYlS65J3uH3B; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiNjM2MjkyIiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiZGphbmdvLmNvbnRyaWIuYXV0aC5iYWNrZW5kcy5Nb2RlbEJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJlODBlMjYxOTU4MGFlMjc4ODg2NmRkOGNiYzcwMWUxZmQxYTY0NDgxIiwiaWQiOjYzNjI5MiwiZW1haWwiOiJhbmNob3JpQDE2My5jb20iLCJ1c2VybmFtZSI6Im5ldHRlZSIsInVzZXJfc2x1ZyI6Im5ldHRlZSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLWNuLmNvbS9hbGl5dW4tbGMtdXBsb2FkL3VzZXJzL25ldHRlZS9hdmF0YXJfMTU3NjczNjg2MS5wbmciLCJwaG9uZV92ZXJpZmllZCI6dHJ1ZSwidGltZXN0YW1wIjoiMjAyMC0wMS0wMiAwNzoxMTo0Ni4xMjgyNTErMDA6MDAiLCJSRU1PVEVfQUREUiI6IjE3Mi4yMS41LjE5NSIsIklERU5USVRZIjoiYTljZmMzOGM4YzI3ZDhhYWRlN2IxOTcwMTA5N2JlZGEiLCJfc2Vzc2lvbl9leHBpcnkiOjEyMDk2MDB9.SnmRHT-K_YTpnHDONNphCJa_ZpwhNqWhH-So__d82lE; Hm_lvt_fa218a3ff7179639febdb15e372f411c=1577695810,1577945411,1577977918; _gat_gtag_UA_131851415_1=1; a2873925c34ecbd2_gr_session_id=32fabe7f-68cc-4c81-9d17-312fbf3a2a7d; a2873925c34ecbd2_gr_last_sent_sid_with_cs1=32fabe7f-68cc-4c81-9d17-312fbf3a2a7d; a2873925c34ecbd2_gr_session_id_32fabe7f-68cc-4c81-9d17-312fbf3a2a7d=true; Hm_lpvt_fa218a3ff7179639febdb15e372f411c=1577977927; __asc=66d0138316f66d054741bc3f95e; a2873925c34ecbd2_gr_cs1=nettee'


def fetch_problem_list():
    url = 'https://leetcode-cn.com/api/problems/all/'

    r = requests.get(url)
    r.raise_for_status()

    data = r.json()

    def item_to_problem(item):
        id = item['stat']['question_id']
        title = item['stat']['question__title']
        title_slug = item['stat']['question__title_slug']
        difficulty = item['difficulty']['level']
        paid_only = item['paid_only']
        problem = Problem(id=id,
                          title=title,
                          title_slug=title_slug,
                          difficulty=Difficulty(difficulty),
                          paid_only=paid_only)
        return problem

    problems = list(
        data['stat_status_pairs'] > pipe
        | foreach(item_to_problem)
        | where(X.id < 10000)
    )
    return problems


def fetch_submission_code(submission_url):
    headers = {
        'user-agent': user_agent,
        'cookie': cookie,
        'referer': submission_url,
        'content-type': "application/json",
    }
    r = requests.get(submission_url, headers=headers)

    pattern = re.compile(r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl', re.S)
    m = pattern.search(r.text)
    code = m.groupdict()['code'] if m else None
    return eval('"' + code + '"')


def fetch_problem_submissions(title_slug, offset, limit):
    query = '''query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {
      submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
        lastKey
        hasNext
        submissions {
          id
          statusDisplay
          lang
          timestamp
          url
        }
      }
    }
    '''
    payload = {
        "operationName": "Submissions",
        "variables": {
            'offset': offset,
            'limit': limit,
            "questionSlug": title_slug,
        },
        "query": query,
    }

    headers = {
        'user-agent': user_agent,
        'cookie': cookie,
        'referer': problem_url,
        'content-type': "application/json",
    }

    data = execute_graphql(api_url, payload=payload, headers=headers)

    def item_to_submission(item):
        id = item['id']
        status = Status(item['statusDisplay'])
        language = Language(item['lang'])
        timestamp = item['timestamp']
        url = urljoin(base_url, item['url'])
        return Submission(id=id, status=status, language=language, timestamp=timestamp, url=url)

    def fill_submission_code(submission):
        submission.code = fetch_submission_code(submission.url)
        return submission

    submissions = list(
        data['submissionList']['submissions'] > pipe
        | foreach(item_to_submission)
        | where(X.status == Status.AC)
        | foreach(fill_submission_code)
    )
    return submissions


if __name__ == '__main__':
    submissiojns = fetch_problem_submissions('two-sum', 0, 50)
    for e in submissiojns:
        print(e)
