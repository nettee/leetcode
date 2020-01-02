import requests


class GraphQLError(RuntimeError):

    pass


def execute_graphql(url, payload, headers):
    r = requests.post(url, json=payload, headers=headers)
    json = r.json()
    if 'errors' in json:
        errors = json['errors']
        messages = [error['message'] for error in errors]
        raise GraphQLError(messages)
    return json['data']
