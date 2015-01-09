# -*- coding: utf-8 -*-

import sys
import os


# -- General configuration ------------------------------------------------

project = u'm3ta'
copyright = u'2015, Christopher Crouzet'
language = None

extensions = []
primary_domain = 'cpp'
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
exclude_patterns = ['_build']
pygments_style = 'sphinx'


# -- Options for HTML output ----------------------------------------------

html_theme = 'default'
if os.environ.get('READTHEDOCS', None) != 'True':
    try:
        import sphinx_rtd_theme
        html_theme = 'sphinx_rtd_theme'
        html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]
    except ImportError:
        pass

html_static_path = ['_static']
htmlhelp_basename = 'm3tadoc'


# -- Options for LaTeX output ---------------------------------------------

latex_elements = {}
latex_documents = [
  ('index', 'm3ta.tex', u'm3ta Documentation',
   u'Christopher Crouzet', 'manual'),
]


# -- Options for manual page output ---------------------------------------

man_pages = [
    ('index', 'm3ta', u'm3ta Documentation',
     [u'Christopher Crouzet'], 1)
]


# -- Options for Texinfo output -------------------------------------------

texinfo_documents = [
  ('index', 'm3ta', u'm3ta Documentation',
   u'Christopher Crouzet', 'm3ta', 'One line description of project.',
   'Miscellaneous'),
]


# -- Options for Epub output ----------------------------------------------

epub_title = u'm3ta'
epub_author = u'Christopher Crouzet'
epub_publisher = u'Christopher Crouzet'
epub_copyright = u'2015, Christopher Crouzet'
epub_exclude_files = ['search.html']
