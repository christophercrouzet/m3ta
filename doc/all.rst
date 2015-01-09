.. _reference_all:

All
===

.. code-block:: cpp
    
   #include <m3ta/all>


Checks if all the values evaluate to `true`.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`reference_any` and :ref:`reference_none`.


Functions
---------

.. _function_all:

.. describe:: m3ta::all
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      constexpr bool
      all(T_Values ... values) noexcept
   
   
   :Template Parameters:
      - **T_Values** (automatically deduced) — Types of the values to check.
   
   :Function Parameters:
      - **values** – Variable number of values to check.
        Those can be of heterogeneous types.
   
   
   .. rubric:: Returns
   
   Whether all the values evaluate to `true`.


Traits
------

.. _trait_all:

.. describe:: m3ta::All
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      struct All
   
   
   :Template Parameters:
      - **T** – Type of the values to check.
      - **T_values** – Variable number of values to check.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<bool, value>`` where `value` is
      the result of the function :ref:`m3ta::all() <function_all>`.
   
   .. describe:: value_type
      
      The type ``bool``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr bool value
      
      Whether all the values evaluate to `true`.


Aliases
-------

.. _alias_allt:

.. describe:: m3ta::AllT
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using AllT = typename All<T, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_all:

.. code-block:: cpp
   
   bool value1 = m3ta::all(true, true); // true
   bool value2 = m3ta::all(false, false); // false
   bool value3 = m3ta::all(true, false); // false
   bool value4 = m3ta::all(true, 1, 2L, 4.0f, 9.0, 85.0L); // true
   
   using Type1 = m3ta::AllT<bool, true, true>; // std::integral_constant<bool, true>
   using Type2 = m3ta::AllT<bool, false, false>; // std::integral_constant<bool, false>
   using Type3 = m3ta::AllT<bool, true, false>; // std::integral_constant<bool, false>
   using Type4 = m3ta::AllT<bool, 1, 2, 4, 9, 85>; // std::integral_constant<bool, true>
