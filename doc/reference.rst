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
   
   all
   any
   endingoccurrences
   iscomplex
   isoperatorcallable
   maximum
   minimum
   none
   power
   product


Types
-----

Traits defining a ``type`` member holding the resulting type of an operation.

An alias ending with the prefix `T` that refers to the ``type`` member is also
available as a convenience.

.. toctree::
   :maxdepth: 1
   
   arithmeticoperationresult
   concatenateintegersequences
   nestedinitializerlists
   pass
   popintegersequence
   readonlyparameter
   removequalifiers
   reverseintegersequence


Specials
--------

For the uncategorizable ones.

.. toctree::
   :maxdepth: 1
   
   dependentbool
   integersequence
   parameterpack
