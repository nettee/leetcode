from jinja2 import Environment, PackageLoader


def render(problems):

    env = Environment(loader=PackageLoader('coder', 'templates'))

    template = env.get_template('README.md')
    rendered = template.render(problems=problems)
    print(rendered)

