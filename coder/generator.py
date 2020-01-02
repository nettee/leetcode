from jinja2 import Environment, PackageLoader


def render_readme(problems):

    env = Environment(loader=PackageLoader('coder', 'templates'), trim_blocks=True)

    template = env.get_template('README.md')
    rendered = template.render(problems=problems)

    with open('README.md', 'w') as f:
        print(rendered, file=f)


