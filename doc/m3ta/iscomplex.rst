.. _reference_iscomplex:

Is Complex?
===========

.. code-block:: cpp
    
   #include <m3ta/iscomplex>


Checks if a type is the same as ``std::complex``.

.. note::
   
   Following the behavior of the type traits from the C++ standard library,
   the check will return `false` is a ``std::complex`` type is passed as a
   reference.


Functions
---------

.. _function_iscomplex:

.. describe:: m3ta::isComplex
   
   .. code-block:: cpp
      
      template<typename T>
      constexpr bool
      isComplex() noexcept
   
   
   :Template Parameters:
      - **T** — Type to check.
   
   
   .. rubric:: Returns
   
   Whether the type is the same as ``std::complex``.


Traits
------

.. _trait_iscomplex:

.. describe:: m3ta::IsComplex
   
   .. code-block:: cpp
      
      template<typename T>
      struct IsComplex
   
   
   :Template Parameters:
      - **T** – Type to check.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<bool, value>`` where `value` is
      the result of the function :ref:`m3ta::isComplex() <function_iscomplex>`.
   
   .. describe:: value_type
      
      The type ``bool``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr bool value
      
      Whether the type is the same as ``std::complex``.


Aliases
-------

.. _alias_iscomplext:

.. describe:: m3ta::IsComplexT
   
   .. code-block:: cpp
      
      template<typename T>
      using IsComplexT = typename IsComplex<T>::type;


Usage Examples
--------------

.. _usageexamples_iscomplex:

.. code-block:: cpp
   
   bool value1 = m3ta::isComplex<float>() // false
   bool value2 = m3ta::isComplex<std::complex<float>>() // true
   bool value3 = m3ta::isComplex<std::complex<float> &>() // false
   
   using Type1 = m3ta::IsComplexT<float>; // std::integral_constant<bool, false>
   using Type2 = m3ta::IsComplexT<std::complex<float>>; // std::integral_constant<bool, true>
   using Type3 = m3ta::IsComplexT<std::complex<float> &>; // std::integral_constant<bool, false>
