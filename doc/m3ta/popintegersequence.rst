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
      
      template<std::size_t T_count, typename T_Sequence>
      struct PopIntegerSequence;
   
   
   :Template Parameters:
      - **T_count** – Number of elements to remove from the end.
      - **T_Sequence** – The integer sequence.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type :ref:`m3ta::IntegerSequence <trait_integersequence>`
      resulting of the elements removal.


Aliases
-------

.. _alias_popintegersequencet:

.. describe:: m3ta::PopIntegerSequenceT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T_Sequence>
      using PopIntegerSequenceT =
          typename PopIntegerSequence<T_count, T_Sequence>::type;
      

.. _alias_popintegerpack:

.. describe:: m3ta::PopIntegerPack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T, T ... T_values>
      using PopIntegerPack = PopIntegerSequence<
          T_count,
          IntegerSequence<T, T_values...>
      >;
      
      
.. _alias_popintegerpackt:

.. describe:: m3ta::PopIntegerPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, typename T, T ... T_values>
      using PopIntegerPackT =
          typename PopIntegerPack<T_count, T, T_values ...>::type;
      
      
.. _alias_popindexpack:

.. describe:: m3ta::PopIndexPack
   
   .. code-block:: cpp
      
      template<std::size_t T_count, std::size_t ... T_values>
      using PopIndexPack =
          PopIntegerSequence<
              T_count,
              IndexSequence<T_values...>
          >;
      
.. _alias_popindexpackt:

.. describe:: m3ta::PopIndexPackT
   
   .. code-block:: cpp
      
      template<std::size_t T_count, std::size_t ... T_values>
      using PopIndexPackT =
          typename PopIndexPack<T_count, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_popintegersequence:

.. code-block:: cpp
   
   using Type1 = m3ta::PopIndexPackT<
       1,
       0, 1, 2, 4
   >; // m3ta::IntegerSequence<std::size_t, 0, 1, 2>
   using Type2 = m3ta::PopIntegerSequenceT<
       2,
       m3ta::IntegerSequence<int, 0, 1, 2, 4>
   >; // m3ta::IntegerSequence<int, 0, 1>
