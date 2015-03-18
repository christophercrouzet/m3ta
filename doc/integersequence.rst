.. _reference_integersequence:

Integer Sequence
================

.. code-block:: cpp
    
   #include <m3ta/integersequence>


Sequence of integers.

This is the equivalent of C++14’s ``std::integer_sequence``.


Traits
------

.. _trait_integersequence:

.. describe:: m3ta::IntegerSequence
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      struct IntegerSequence
   
   
   :Template Parameters:
      - **T** – Type of the integer values.
      - **T_values** – Integral values.
   
   
   .. rubric:: Member Types
      
   .. describe:: value_type
      
      The type ``T``.
   
   
   .. rubric:: Member Functions
   
   .. describe:: std::size_t size() noexcept
      
      Number of values.
   
   .. describe:: std::array<T, size()> asArray()
      
      The integer sequence as a ``std::array``.


Aliases
-------

.. _alias_indexsequence:

.. describe:: m3ta::IndexSequence
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using IndexSequence = IntegerSequence<std::size_t, T_values ...>;
