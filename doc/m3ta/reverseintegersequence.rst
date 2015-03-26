.. _reference_reverseintegersequence:

Reverse Integer Sequence
========================

.. code-block:: cpp
   
   #include <m3ta/reverseintegersequence>


Reverses an integer sequence.


Traits
------

.. _trait_reverseintegersequence:

.. describe:: m3ta::ReverseIntegerSequence
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      struct ReverseIntegerSequence;
   
   
   :Template Parameters:
      - **T_Sequence** – Integer sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type :ref:`m3ta::IntegerSequence <trait_integersequence>`
      resulting of the reversal.


Aliases
-------

.. _alias_reverseintegersequencet:

.. describe:: m3ta::ReverseIntegerSequenceT
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      using ReverseIntegerSequenceT =
          typename ReverseIntegerSequence<T_Sequence>::type;
      
      template<typename T, T ... T_values>
      using ReverseIntegerPack =
          ReverseIntegerSequence<IntegerSequence<T, T_values...>>;
      
      template<typename T, T ... T_values>
      using ReverseIntegerPackT =
          typename ReverseIntegerPack<T, T_values...>::type;
      
      template<std::size_t ... T_values>
      using ReverseIndexPack =
          ReverseIntegerSequence<IndexSequence<T_values...>>;
      
      template<std::size_t ... T_values>
      using ReverseIndexPackT =
          typename ReverseIndexPack<T_values...>::type;


Usage Examples
--------------

.. _usageexamples_reverseintegersequence:

.. code-block:: cpp
   
   using Type1 = m3ta::ReverseIndexPackT<
      0, 1, 2, 4
    >; // m3ta::IntegerSequence<std::size_t, 4, 2, 1, 0>
   using Type2 = m3ta::ReverseIntegerSequenceT<
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<int, 4, 2, 1, 0>
