.. _reference:

Reference
=========

.. code-block:: cpp
   
   #include <m3ta/m3ta>


Constants
---------

Regroups the utilities that are outputting constant values.

They are defined both as ``constexpr`` functions and as conventional traits
inheriting from ``std::integral_constant``.

.. toctree::
   :maxdepth: 1
   
   m3ta/all
   m3ta/any
   m3ta/endingoccurrences
   m3ta/iscomplex
   m3ta/isoperatorcallable
   m3ta/maximum
   m3ta/minimum
   m3ta/none
   m3ta/power
   m3ta/product


Types
-----

Traits defining a ``type`` member holding the resulting type of an operation.

An alias ending with the prefix `T` that refers to the ``type`` member is also
available as a convenience.

.. toctree::
   :maxdepth: 1
   
   m3ta/arithmeticoperationresult
   m3ta/concatenate
   m3ta/extractintegersequence
   m3ta/nestedinitializerlists
   m3ta/pass
   m3ta/popintegersequence
   m3ta/readonlyparameter
   m3ta/removequalifiers
   m3ta/reverse


Specials
--------

For the uncategorizable ones.

.. toctree::
   :maxdepth: 1
   
   m3ta/dependentbool
   m3ta/integersequence
   m3ta/parameterpack
