.. _reference_at:

At
==

.. code-block:: cpp
   
   #include <m3ta/at>


Retrieves an element at a given position from a sequence. Works for
:ref:`m3ta::IntegerSequence <trait_integersequence>`,
:ref:`m3ta::ParameterPack <trait_parameterpack>`, and integer packs.


Traits
------

.. _trait_at:

.. describe:: m3ta::At
   
   .. code-block:: cpp
      
      template<std::size_t T_position, typename T_Sequence>
      struct At;
   
   
   :Template Parameters:
      - **T_position** – Element position.
      - **T_Sequence** – The sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type of the element retrieved. In the case of an
      :ref:`m3ta::IntegerSequence <trait_integersequence>`, the type is
      ``std::integral_constant``.


Aliases
-------

.. _alias_att:

.. describe:: m3ta::AtT
   
   .. code-block:: cpp
      
      template<std::size_t T_position, typename T_Sequence>
      using AtT = typename At<T_position, T_Sequence>::type;


.. _alias_atintegerpack:

.. describe:: m3ta::AtIntegerPack
   
   .. code-block:: cpp
      
      template<std::size_t T_position, typename T, T ... T_values>
      using AtIntegerPack = At<T_position, IntegerSequence<T, T_values...>>;


.. _alias_atintegerpackt:

.. describe:: m3ta::AtIntegerPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_position, typename T, T ... T_values>
      using AtIntegerPackT =
          typename AtIntegerPack<T_position, T, T_values ...>::type;


.. _alias_atindexpack:

.. describe:: m3ta::AtIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t T_position, std::size_t ... T_values>
      using AtIndexPack = At<T_position, IndexSequence<T_values...>>;


.. _alias_atindexpackt:

.. describe:: m3ta::AtIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_position, std::size_t ... T_values>
      using AtIndexPackT = typename AtIndexPack<T_position, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_at:

.. code-block:: cpp
   
   using Type1 = m3ta::AtIndexPackT<
       1,
       4, 9, 85, 19
   >; // std::integral_constant<std::size_t, 9>
   using Type2 = m3ta::AtT<
       2,
       m3ta::IntegerSequence<int, 4, 9, 85, 19>
   >; // std::integral_constant<int, 85>
   using Type3 = m3ta::AtT<
       3,
       m3ta::ParameterPack<char, short, int, long, double>
   >; // long
