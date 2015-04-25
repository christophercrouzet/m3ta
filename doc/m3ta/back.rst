.. _reference_back:

Back
=====

.. code-block:: cpp
   
   #include <m3ta/back>


Retrieves the last element from a sequence. Works for
:ref:`m3ta::IntegerSequence <trait_integersequence>`,
:ref:`m3ta::ParameterPack <trait_parameterpack>`, and integer packs.


Traits
------

.. _trait_back:

.. describe:: m3ta::Back
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      struct Back;
   
   
   :Template Parameters:
      - **T_Sequence** – The sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type of the element retrieved. In the case of an
      :ref:`m3ta::IntegerSequence <trait_integersequence>`, the type is
      ``std::integral_constant``.


Aliases
-------

.. _alias_backt:

.. describe:: m3ta::BackT
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      using BackT = typename Back<T_Sequence>::type;


.. _alias_backintegerpack:

.. describe:: m3ta::BackIntegerPack
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using BackIntegerPack = Back<IntegerSequence<T, T_values...>>;


.. _alias_backintegerpackt:

.. describe:: m3ta::BackIntegerPackT
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using BackIntegerPackT =
          typename BackIntegerPack<T, T_values ...>::type;


.. _alias_backindexpack:

.. describe:: m3ta::BackIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using BackIndexPack = Back<IndexSequence<T_values...>>;


.. _alias_backindexpackt:

.. describe:: m3ta::BackIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using BackIndexPackT = typename BackIndexPack<T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_back:

.. code-block:: cpp
   
   using Type1 = m3ta::BackIndexPackT<
       4, 9, 85, 19
   >; // std::integral_constant<std::size_t, 19>
   using Type2 = m3ta::BackT<
       m3ta::IntegerSequence<int, 4, 9, 85, 19>
   >; // std::integral_constant<int, 19>
   using Type3 = m3ta::BackT<
       m3ta::ParameterPack<char, short, int, long, double>
   >; // double
