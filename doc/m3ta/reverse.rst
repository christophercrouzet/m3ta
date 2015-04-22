.. _reference_reverse:

Reverse
=======

.. code-block:: cpp
   
   #include <m3ta/reverse>


Reverses a sequence. Works for both
:ref:`m3ta::IntegerSequence <trait_integersequence>` and
:ref:`m3ta::ParameterPack <trait_parameterpack>`.


Traits
------

.. _trait_reverse:

.. describe:: m3ta::Reverse
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      struct Reverse;
   
   
   :Template Parameters:
      - **T_Sequence** – Sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      Either the type :ref:`m3ta::IntegerSequence <trait_integersequence>` or
      :ref:`m3ta::ParameterPack <trait_parameterpack>` resulting of the
      reversal.


Aliases
-------

.. _alias_reverset:

.. describe:: m3ta::ReverseT
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      using ReverseT = typename Reverse<T_Sequence>::type;
      
      
.. _alias_reverseintegerpack:

.. describe:: m3ta::ReverseIntegerPack
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using ReverseIntegerPack =
          Reverse<IntegerSequence<T, T_values...>>;
      
      
.. _alias_reverseintegerpackt:

.. describe:: m3ta::ReverseIntegerPackT
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using ReverseIntegerPackT =
          typename ReverseIntegerPack<T, T_values...>::type;
      
      
.. _alias_reverseindexpack:

.. describe:: m3ta::ReverseIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using ReverseIndexPack = Reverse<IndexSequence<T_values...>>;
      
      
.. _alias_reverseindexpackt:

.. describe:: m3ta::ReverseIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using ReverseIndexPackT = typename ReverseIndexPack<T_values...>::type;


Usage Examples
--------------

.. _usageexamples_reverse:

.. code-block:: cpp
   
   using Type1 = m3ta::ReverseIndexPackT<
      0, 1, 2, 4
    >; // m3ta::IntegerSequence<std::size_t, 4, 2, 1, 0>
   using Type2 = m3ta::ReverseT<
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<int, 4, 2, 1, 0>
   using Type3 = m3ta::ReverseT<
       m3ta::ParameterPack<int, float, double>
   >; // m3ta::ParameterPack<double, float, int>
