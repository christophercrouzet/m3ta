.. _reference_any:

Any
===

.. code-block:: cpp
    
   #include <m3ta/any>


Checks if any of the values evaluate to `true`.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`reference_all` and :ref:`reference_none`.


Functions
---------

.. _function_any:

.. describe:: m3ta::any
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      constexpr bool
      any(T_Values ... values) noexcept
   
   
   :Template Parameters:
      - **T_Values** (automatically deduced) — Types of the values to check.
   
   :Function Parameters:
      - **values** – Variable number of values to check.
        Those can be of heterogeneous types.
   
   
   .. rubric:: Returns
   
   Whether any of the values evaluate to `true`.


Traits
------

.. _trait_any:

.. describe:: m3ta::Any
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      struct Any
   
   
   :Template Parameters:
      - **T** – Type of the values to check.
      - **T_values** – Variable number of values to check.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<bool, value>`` where `value` is
      the result of the function :ref:`m3ta::any() <function_any>`.
   
   .. describe:: value_type
      
      The type ``bool``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr bool value
      
      Whether any of the values evaluate to `true`.


Aliases
-------

.. _alias_anyt:

.. describe:: m3ta::AnyT
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using AnyT = typename Any<T, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_any:

.. code-block:: cpp
   
   bool value1 = m3ta::any(true, true); // true
   bool value2 = m3ta::any(false, false); // false
   bool value3 = m3ta::any(true, false); // true
   bool value4 = m3ta::any(true, 1, 2L, 4.0f, 9.0, 85.0L); // true
   
   using Type1 = m3ta::AnyT<bool, true, true>; // std::integral_constant<bool, true>
   using Type2 = m3ta::AnyT<bool, false, false>; // std::integral_constant<bool, false>
   using Type3 = m3ta::AnyT<bool, true, false>; // std::integral_constant<bool, true>
   using Type4 = m3ta::AnyT<bool, 1, 2, 4, 9, 85>; // std::integral_constant<bool, true>
