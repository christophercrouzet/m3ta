.. _reference_minimum:

Minimum
=======

.. code-block:: cpp
    
   #include <m3ta/minimum>


Returns the greater of two values.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`reference_maximum`.


Functions
---------

.. _function_minimum:

.. describe:: m3ta::minimum
   
   .. code-block:: cpp
      
      template<typename T>
      constexpr T
      minimum(T value1, T value2) noexcept
   
   
   :Template Parameters:
      - **T** (automatically deduced) — Type of the values to compare.
   
   :Function Parameters:
      - **value1** – First value to compare.
      - **value2** – Second value to compare.
   
   
   .. rubric:: Returns
   
   The greater of the two values.


Traits
------

.. _trait_minimum:

.. describe:: m3ta::Minimum
   
   .. code-block:: cpp
      
      template<typename T, T T_value1, T T_value2>
      struct Minimum
   
   
   :Template Parameters:
      - **T** – Type of the values to check.
      - **T_value1** – First value to compare.
      - **T_value2** – Second value to compare.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<T, value>`` where `value` is
      the result of the function :ref:`m3ta::minimum() <function_minimum>`.
   
   .. describe:: value_type
      
      The type ``T``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr T value
      
      The greater of the two values.


Aliases
-------

.. _alias_minimumt:

.. describe:: m3ta::MinimumT
   
   .. code-block:: cpp
      
      template<typename T, T T_value1, T T_value2>
      using MinimumT = typename Minimum<T, T_value1, T_value2>::type;


Usage Examples
--------------

.. _usageexamples_minimum:

.. code-block:: cpp
   
   auto value = m3ta::minimum(1, 2); // 1
   
   using Type = m3ta::MinimumT<int, 1, 2>; // std::integral_constant<int, 1>
