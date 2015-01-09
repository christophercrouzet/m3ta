m3ta
====

m3ta is an header-only library regrouping utilities for template metaprogramming.

See the ``overview`` and ``examples`` sections of the documentation for more
details.


Documentation
-------------

Read the documentation online at <http://m3ta.readthedocs.org> or check
their source from the ``doc`` folder.

The documentation can be built in different formats using Sphinx.


Running the Tests
-----------------

A suite of unit tests is available from the ``tests`` directory. You can run it
with the help of CMake.

.. code-block:: bash
    
    $ cd m3ta
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ ctest


To run specific tests, it is possible to pass names to match in the command
line.

.. code-block:: bash
    
    $ ctest -R test_my_code


This command will run all the tests containing ``test_my_code`` in their name.


Get the Source
--------------

The source code is available from the `GitHub project page`_.


Contributing
------------

Found a bug or got a feature request? Don’t keep it for yourself, log a new
issue on `GitHub <https://github.com/christophercrouzet/m3ta/issues>`_.


Author
------

Christopher Crouzet
<`christophercrouzet.com <http://christophercrouzet.com>`_>


Credits
-------

- Andy Prowl for his
  answers `here <http://stackoverflow.com/a/16399732/1640404>`_ and
  `there <http://stackoverflow.com/a/16268296/1640404>`_ on StackOverflow,
  respectively leading the way to the `Is Operator Callable` and the `Pop
  Integer Sequence` utilities.
- R. Martinho Fernandes for his
  `dependent boolean trick <http://flamingdangerzone.com/cxx11/2012/05/29/type-traits-galore.html>`_.
- Xeo for his
  `type sequence concatenation <http://stackoverflow.com/a/17426611/1640404>`_.


.. _GitHub project page: https://github.com/christophercrouzet/m3ta
