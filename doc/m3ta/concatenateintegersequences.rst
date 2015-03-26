.. _reference_concatenateintegersequences:

Concatenate Integer Sequences
=============================

.. code-block:: cpp
   
   #include <m3ta/concatenateintegersequences>


Concatenates two integer sequences into one.


Traits
------

.. _trait_concatenateintegersequences:

.. describe:: m3ta::ConcatenateIntegerSequences
   
   .. code-block:: cpp
      
      template<typename T_Sequence1, typename T_Sequence2>
      struct ConcatenateIntegerSequences
   
   
   :Template Parameters:
      - **T_Sequence1** – The first integer sequence.
      - **T_Sequence2** – The second integer sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type :ref:`m3ta::IntegerSequence <trait_integersequence>`
      resulting of the concatenation.


Aliases
-------

.. _alias_concatenateintegersequencest:

.. describe:: m3ta::ConcatenateIntegerSequencesT
   
   .. code-block:: cpp
      
      template<typename T_Sequence1, typename T_Sequence2>
      using ConcatenateIntegerSequencesT =
          typename ConcatenateIntegerSequences<T_Sequence1, T_Sequence2>::type;


Usage Examples
--------------

.. _usageexamples_concatenateintegersequences:

.. code-block:: cpp
   
   using Type = m3ta::ConcatenateIntegerSequencesT<
       m3ta::IntegerSequence<int, 1, 2>,
       m3ta::IntegerSequence<int, 3, 4>
   >; // m3ta::IntegerSequence<int, 1, 2, 3, 4>
