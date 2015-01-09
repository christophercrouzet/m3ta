.. _reference_popintegersequence:

Pop Integer Sequence
====================

.. code-block:: cpp
   
   #include <m3ta/popintegersequence>


Removes a given number of elements from the end of an integer sequence.


Traits
------

.. _trait_popintegersequence:

.. describe:: m3ta::PopIntegerSequence
   
   .. code-block:: cpp
      
      template<typename T_Sequence, std::size_t T_count = 1>
      struct PopIntegerSequence;
   
   
   :Template Parameters:
      - **T_Sequence** – Type of the sequence.
      - **T_count** (optional) – Number of elements to remove from the end.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type :ref:`m3ta::IntegerSequence <trait_integersequence>`
      resulting of the elements removal.


Aliases
-------

.. _alias_popintegersequencest:

.. describe:: m3ta::ConcatenateIntegerSequencesT
   
   .. code-block:: cpp
      
      template<typename T_Sequence, std::size_t T_count = 1>
      using PopIntegerSequenceT =
          typename PopIntegerSequence<T_Sequence, T_count>::type;


Usage Examples
--------------

.. _usageexamples_popintegersequences:

.. code-block:: cpp
   
   using Type1 = m3ta::PopIntegerSequenceT<
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<T, 0, 1, 2>
   using Type2 = m3ta::PopIntegerSequenceT<
       m3ta::IntegerSequence<int, 0, 1, 2, 4>,
       2
   >; // m3ta::IntegerSequence<T, 0, 1>
