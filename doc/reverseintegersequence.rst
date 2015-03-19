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


Usage Examples
--------------

.. _usageexamples_reverseintegersequence:

.. code-block:: cpp
   
   using Type = m3ta::ReverseIntegerSequenceT<
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<int, 4, 2, 1, 0>
