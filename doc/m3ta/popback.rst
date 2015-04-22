.. _reference_popback:

Pop Back
========

.. code-block:: cpp
   
   #include <m3ta/popback>


Removes a given number of elements from the end of a sequence. Works for
:ref:`m3ta::IntegerSequence <trait_integersequence>`,
:ref:`m3ta::ParameterPack <trait_parameterpack>`, and integer packs.


Traits
------

.. _trait_popback:

.. describe:: m3ta::PopBack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T_Sequence>
      struct PopBack;
   
   
   :Template Parameters:
      - **T_count** – Number of elements to remove from the end.
      - **T_Sequence** – The sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      Either the type :ref:`m3ta::IntegerSequence <trait_integersequence>` or
      :ref:`m3ta::ParameterPack <trait_parameterpack>` resulting of the
      elements removal.


Aliases
-------

.. _alias_popbackt:

.. describe:: m3ta::PopBackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T_Sequence>
      using PopBackT = typename PopBack<T_count, T_Sequence>::type;


.. _alias_popbackintegerpack:

.. describe:: m3ta::PopBackIntegerPack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T, T ... T_values>
      using PopBackIntegerPack =
        PopBack<T_count, IntegerSequence<T, T_values...>>;


.. _alias_popbackintegerpackt:

.. describe:: m3ta::PopBackIntegerPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T, T ... T_values>
      using PopBackIntegerPackT =
          typename PopBackIntegerPack<T_count, T, T_values ...>::type;


.. _alias_popbackindexpack:

.. describe:: m3ta::PopBackIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, std::size_t ... T_values>
      using PopBackIndexPack = PopBack<T_count, IndexSequence<T_values...>>;


.. _alias_popbackindexpackt:

.. describe:: m3ta::PopBackIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, std::size_t ... T_values>
      using PopBackIndexPackT =
        typename PopBackIndexPack<T_count, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_popback:

.. code-block:: cpp
   
   using Type1 = m3ta::PopBackIndexPackT<
       1,
       0, 1, 2, 4
   >; // m3ta::IntegerSequence<std::size_t, 0, 1, 2>
   using Type2 = m3ta::PopBackT<
       2,
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<int, 0, 1>
   using Type3 = m3ta::PopBackT<
       3,
       m3ta::ParameterPack<char, short, int, long, double>
   >; // m3ta::ParameterPack<char, short>
