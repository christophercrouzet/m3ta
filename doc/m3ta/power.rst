.. _reference_power:

Power
=====

.. code-block:: cpp
    
   #include <m3ta/power>


Functions
---------

.. _function_power:

.. describe:: m3ta::power
   
   .. code-block:: cpp
      
      template<typename T_Base, typename T_Exponent>
      constexpr MultiplicationResultT<T_Base, T_Base>
      power(T_Base base, T_Exponent exponent) noexcept
   
   
   :Template Parameters:
      - **T_Base** (automatically deduced) — Type of the base value.
      - **T_Exponent** (automatically deduced) — Type of the exponent value.
   
   :Function Parameters:
      - **base** – Base value.
      - **exponent** – Exponent value.
   
   
   .. rubric:: Returns
   
   The number `base` raised to the power `exponent`.


Traits
------

.. _trait_power:

.. describe:: m3ta::Power
   
   .. code-block:: cpp
      
      template<typename T, T T_base, T T_exponent>
      struct Power
   
   
   :Template Parameters:
      - **T** – Type of the values.
      - **T_base** – Base value.
      - **T_exponent** – Exponent value.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<T, value>`` where `value` is
      the result of the function :ref:`m3ta::power() <function_power>`.
   
   .. describe:: value_type
      
      The type ``T``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr T value
      
      The number `T_base` raised to the power `T_exponent`.


Aliases
-------

.. _alias_powert:

.. describe:: m3ta::PowerT
   
   .. code-block:: cpp
      
      template<typename T, T T_base, T T_exponent>
      using PowerT = typename Power<T, T_base, T_exponent>::type;


Usage Examples
--------------

.. _usageexamples_power:

.. code-block:: cpp
   
   auto value1 = m3ta::power(4, 3); // 64
   auto value2 = m3ta::power(1.0f, -1); // 0.5
   auto value3 = m3ta::power(std::complex<float>(1, 1), 2); // std::complex<float>(0, 2)
   
   using Type = m3ta::PowerT<int, 4, 3>; // std::integral_constant<int, 64>
