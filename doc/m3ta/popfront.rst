.. _reference_popfront:

Pop Front
=========

.. code-block:: cpp
   
   #include <m3ta/popfront>


Removes a given number of elements from the begin of a sequence. Works for
:ref:`m3ta::IntegerSequence <trait_integersequence>`,
:ref:`m3ta::ParameterPack <trait_parameterpack>`, and integer packs.


Traits
------

.. _trait_popfront:

.. describe:: m3ta::PopFront
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T_Sequence>
      struct PopFront;
   
   
   :Template Parameters:
      - **T_count** – Number of elements to remove from the begin.
      - **T_Sequence** – The sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      Either the type :ref:`m3ta::IntegerSequence <trait_integersequence>` or
      :ref:`m3ta::ParameterPack <trait_parameterpack>` resulting of the
      elements removal.


Aliases
-------

.. _alias_popfrontt:

.. describe:: m3ta::PopFrontT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T_Sequence>
      using PopFrontT = typename PopFront<T_count, T_Sequence>::type;


.. _alias_popfrontintegerpack:

.. describe:: m3ta::PopFrontIntegerPack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T, T ... T_values>
      using PopFrontIntegerPack =
        PopFront<T_count, IntegerSequence<T, T_values...>>;


.. _alias_popfrontintegerpackt:

.. describe:: m3ta::PopFrontIntegerPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T, T ... T_values>
      using PopFrontIntegerPackT =
          typename PopFrontIntegerPack<T_count, T, T_values ...>::type;


.. _alias_popfrontindexpack:

.. describe:: m3ta::PopFrontIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, std::size_t ... T_values>
      using PopFrontIndexPack = PopFront<T_count, IndexSequence<T_values...>>;


.. _alias_popfrontindexpackt:

.. describe:: m3ta::PopFrontIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, std::size_t ... T_values>
      using PopFrontIndexPackT =
        typename PopFrontIndexPack<T_count, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_popfront:

.. code-block:: cpp
   
   using Type1 = m3ta::PopFrontIndexPackT<
       1,
       0, 1, 2, 4
   >; // m3ta::IntegerSequence<std::size_t, 1, 2, 4>
   using Type2 = m3ta::PopFrontT<
       2,
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<int, 2, 4>
   using Type3 = m3ta::PopFrontT<
       3,
       m3ta::ParameterPack<char, short, int, long, double>
   >; // m3ta::ParameterPack<long, double>
