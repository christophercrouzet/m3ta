.. _reference_maximum:

Maximum
=======

.. code-block:: cpp
    
   #include <m3ta/maximum>


Returns the greater of two values.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`reference_minimum`.


Functions
---------

.. _function_maximum:

.. describe:: m3ta::maximum
   
   .. code-block:: cpp
      
      template<typename T>
      constexpr T
      maximum(T value1, T value2) noexcept
   
   
   :Template Parameters:
      - **T** (automatically deduced) — Type of the values to compare.
   
   :Function Parameters:
      - **value1** – First value to compare.
      - **value2** – Second value to compare.
   
   
   .. rubric:: Returns
   
   The greater of the two values.


Traits
------

.. _trait_maximum:

.. describe:: m3ta::Maximum
   
   .. code-block:: cpp
      
      template<typename T, T T_value1, T T_value2>
      struct Maximum
   
   
   :Template Parameters:
      - **T** – Type of the values to check.
      - **T_value1** – First value to compare.
      - **T_value2** – Second value to compare.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<T, value>`` where `value` is
      the result of the function :ref:`m3ta::maximum() <function_maximum>`.
   
   .. describe:: value_type
      
      The type ``T``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr T value
      
      The greater of the two values.


Aliases
-------

.. _alias_maximumt:

.. describe:: m3ta::MaximumT
   
   .. code-block:: cpp
      
      template<typename T, T T_value1, T T_value2>
      using MaximumT = typename Maximum<T, T_value1, T_value2>::type;


Usage Examples
--------------

.. _usageexamples_maximum:

.. code-block:: cpp
   
   auto value = m3ta::maximum(1, 2); // 2
   
   using Type = m3ta::MaximumT<int, 1, 2>; // std::integral_constant<int, 2>
