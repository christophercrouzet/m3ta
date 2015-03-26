.. _reference_none:

None
====

.. code-block:: cpp
    
   #include <m3ta/none>


Checks if none of the values evaluate to `true`.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`reference_all` and :ref:`reference_any`.


Functions
---------

.. _function_none:

.. describe:: m3ta::none
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      constexpr bool
      none(T_Values ... values) noexcept
   
   
   :Template Parameters:
      - **T_Values** (automatically deduced) — Types of the values to check.
   
   :Function Parameters:
      - **values** – Variable number of values to check.
        Those can be of heterogeneous types.
   
   
   .. rubric:: Returns
   
   Whether none of the values evaluate to `true`.


Traits
------

.. _trait_none:

.. describe:: m3ta::None
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      struct None
   
   
   :Template Parameters:
      - **T** – Type of the values to check.
      - **T_values** – Variable number of values to check.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<bool, value>`` where `value` is
      the result of the function :ref:`m3ta::none() <function_none>`.
   
   .. describe:: value_type
      
      The type ``bool``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr bool value
      
      Whether none of the values evaluate to `true`.


Aliases
-------

.. _alias_nonet:

.. describe:: m3ta::NoneT
   
   .. code-block:: cpp
      
      template<typename T, T ... T_values>
      using NoneT = typename None<T, T_values ...>::type;


Usage Examples
--------------

.. _usageexamples_none:

.. code-block:: cpp
   
   bool value1 = m3ta::none(true, true); // false
   bool value2 = m3ta::none(false, false); // true
   bool value3 = m3ta::none(true, false); // false
   bool value4 = m3ta::none(true, 1, 2L, 4.0f, 9.0, 85.0L); // false
   
   using Type1 = m3ta::NoneT<bool, true, true>; // std::integral_constant<bool, false>
   using Type2 = m3ta::NoneT<bool, false, false>; // std::integral_constant<bool, true>
   using Type3 = m3ta::NoneT<bool, true, false>; // std::integral_constant<bool, false>
   using Type4 = m3ta::NoneT<bool, 1, 2, 4, 9, 85>; // std::integral_constant<bool, false>
