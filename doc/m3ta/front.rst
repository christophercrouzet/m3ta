.. _reference_front:

Front
=====

.. code-block:: cpp
   
   #include <m3ta/front>


Retrieves the first element from a sequence. Works for
:ref:`m3ta::IntegerSequence <trait_integersequence>`,
:ref:`m3ta::ParameterPack <trait_parameterpack>`, and integer packs.


Traits
------

.. _trait_front:

.. describe:: m3ta::Front
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      struct Front;
   
   
   :Template Parameters:
      - **T_Sequence** – The sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type of the element retrieved. In the case of an
      :ref:`m3ta::IntegerSequence <trait_integersequence>`, the type is
      ``std::integral_constant``.


Aliases
-------

.. _alias_frontt:

.. describe:: m3ta::FrontT
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      using FrontT = typename Front<T_Sequence>::type;


.. _alias_frontintegerpack:

.. describe:: m3ta::FrontIntegerPack
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using FrontIntegerPack = Front<IntegerSequence<T, T_values...>>;


.. _alias_frontintegerpackt:

.. describe:: m3ta::FrontIntegerPackT
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using FrontIntegerPackT =
          typename FrontIntegerPack<T, T_values ...>::type;


.. _alias_frontindexpack:

.. describe:: m3ta::FrontIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using FrontIndexPack = Front<IndexSequence<T_values...>>;


.. _alias_frontindexpackt:

.. describe:: m3ta::FrontIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t ... T_values>
      using FrontIndexPackT = typename FrontIndexPack<T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_front:

.. code-block:: cpp
   
   using Type1 = m3ta::FrontIndexPackT<
       4, 9, 85, 19
   >; // std::integral_constant<std::size_t, 4>
   using Type2 = m3ta::FrontT<
       m3ta::IntegerSequence<int, 4, 9, 85, 19>
   >; // std::integral_constant<int, 4>
   using Type3 = m3ta::FrontT<
       m3ta::ParameterPack<char, short, int, long, double>
   >; // char
