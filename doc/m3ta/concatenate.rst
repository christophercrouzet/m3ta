.. _reference_concatenate:

Concatenate
===========

.. code-block:: cpp
   
   #include <m3ta/concatenate>


Concatenates two sequences into one. Works for both
:ref:`m3ta::IntegerSequence <trait_integersequence>` and
:ref:`m3ta::ParameterPack <trait_parameterpack>`.


Traits
------

.. _trait_concatenate:

.. describe:: m3ta::Concatenate
   
   .. code-block:: cpp
      
      template<typename T_Sequence1, typename T_Sequence2>
      struct Concatenate
   
   
   :Template Parameters:
      - **T_Sequence1** – The first sequence.
      - **T_Sequence2** – The second sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      Either the type :ref:`m3ta::IntegerSequence <trait_integersequence>` or
      :ref:`m3ta::ParameterPack <trait_parameterpack>` resulting of the
      concatenation.


Aliases
-------

.. _alias_concatenatet:

.. describe:: m3ta::ConcatenateT
   
   .. code-block:: cpp
      
      template<typename T_Sequence1, typename T_Sequence2>
      using ConcatenateT = typename Concatenate<T_Sequence1, T_Sequence2>::type;


Usage Examples
--------------

.. _usageexamples_concatenate:

.. code-block:: cpp
   
   using Type1 = m3ta::Concatenate<
       m3ta::IntegerSequence<int, 1, 2>,
       m3ta::IntegerSequence<int, 3, 4>
   >; // m3ta::IntegerSequence<int, 1, 2, 3, 4>
   using Type2 = m3ta::Concatenate<
       m3ta::ParameterPack<float>,
       m3ta::ParameterPack<double>
   >; // m3ta::ParameterPack<float, double>
