.. _reference_endingoccurrences:

Ending Occurrences
==================

.. code-block:: cpp
    
   #include <m3ta/endingoccurrences>


Counts the number of occurrences of a value at the end of a sequence of elements.


Functions
---------

.. _function_endingoccurrences:

.. describe:: m3ta::endingOccurrences
   
   .. code-block:: cpp
      
      template<typename T_Search, typename ... T_Values>
      constexpr std::size_t
      endingOccurrences(T_Search search, T_Values ... values) noexcept
   
   
   :Template Parameters:
      - **T_Search** (automatically deduced) — Type of the value to search for.
      - **T_Values** (automatically deduced) — Types of the values to search in.
   
   :Function Parameters:
      - **search** – Value to search for.
      - **values** – Variable number of values to search in.
        Those can be of heterogeneous types.
   
   
   .. note::
      
      Values of heterogeneous types can be passed to the `values` parameter
      only if they all can be compared for equality (``==``) against the value
      to be searched for.
   
   
   .. rubric:: Returns
   
   The number of occurrences of the `search` value at the end of the `values`
   elements.


Traits
------

.. _trait_endingoccurrences:

.. describe:: m3ta::EndingOccurrences
   
   .. code-block:: cpp
      
      template<typename T, T T_search, T ... T_values>
      struct EndingOccurrences
   
   
   :Template Parameters:
      - **T** – Type of the values to check.
      - **T_Search** – Value to search for.
      - **T_Values** – Variable number of values to search in.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<std::size_t, value>`` where `value` is
      the result of the function
      :ref:`m3ta::endingOccurrences() <function_endingoccurrences>`.
   
   .. describe:: value_type
      
      The type ``std::size_t``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr std::size_t value
      
      The number of occurrences of the `search` value at the end of the
      `T_values` elements.


Aliases
-------

.. _alias_endingoccurrencest:

.. describe:: m3ta::EndingOccurrencesT
   
   .. code-block:: cpp
      
      template<typename T, T T_search, T ... T_values>
      using EndingOccurrencesT =
          typename EndingOccurrences<T, T_search, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_endingoccurrences:

.. code-block:: cpp
   
   std::size_t value1 = m3ta::endingOccurrences(4, 1, 2, 4, 4, 4); // 3
   std::size_t value2 = m3ta::endingOccurrences(4, 1, 4, 2, 4, 4); // 2
   std::size_t value3 = m3ta::endingOccurrences(4.0f, std::complex<float>(4, 0)); // 1
   
   using Type1 = m3ta::EndingOccurrencesT<int, 4, 1, 2, 4, 4, 4>; // std::integral_constant<std::size_t, 1>
   using Type2 = m3ta::EndingOccurrencesT<int, 4, 1, 4, 2, 4, 4>; // std::integral_constant<std::size_t, 2>
