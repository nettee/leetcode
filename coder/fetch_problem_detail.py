from coder.graphql import execute_graphql


api_url = 'https://leetcode-cn.com/graphql'
problem_url = 'https://leetcode-cn.com/problems/two-sum/description/'


def get_problem_detail(title_slug):
    query = '''query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionId
        titleSlug
        title
        translatedTitle
        content
        difficulty
        topicTags {
          name
          slug
        }
      }
    }
    '''

    payload = {
        "operationName": "questionData",
        "variables": {
            "titleSlug": title_slug,
        },
        "query": query,
    }

    headers = {
        'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36',
        # 'cookie': "csrftoken=sNWfBP2BOPGfz6GqX7gkZ9ZkGWWnMROLmoXq0irB2wYliVbrPNaBqQs7xwwrNbQH; __asc=09210b5216f55ff90fa38e8c0b6; __auc=09210b5216f55ff90fa38e8c0b6; Hm_lvt_fa218a3ff7179639febdb15e372f411c=1577695810; Hm_lpvt_fa218a3ff7179639febdb15e372f411c=1577695810; gr_user_id=4e9195d6-8f57-444c-b6c5-13f3e4034220; a2873925c34ecbd2_gr_session_id=f08c96bd-3dda-4a40-96dd-6aa2dde911ad; _ga=GA1.2.396238290.1577695811; _gid=GA1.2.159095560.1577695811; _gat_gtag_UA_131851415_1=1; grwng_uid=e7b70cd3-0f1e-4d59-84a3-670f73550282; a2873925c34ecbd2_gr_session_id_f08c96bd-3dda-4a40-96dd-6aa2dde911ad=true",
        # 'x-csrftoken': 'sNWfBP2BOPGfz6GqX7gkZ9ZkGWWnMROLmoXq0irB2wYliVbrPNaBqQs7xwwrNbQH',
        'referer': problem_url,
        'content-type': "application/json",
    }

    return execute_graphql(api_url, payload=payload, headers=headers)


if __name__ == '__main__':
    # get_cookies(problem_url)
    data = get_problem_detail('two-sum')
    print(data['question']['topicTags'])

