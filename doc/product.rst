.. _reference_product:

Product
=======

.. code-block:: cpp
    
   #include <m3ta/product>


Computes the product of a sequence of elements.

The computation follows a left-to-right associativity, meaning that
``a * b * c`` is evaluated as ``(a * b) * c``.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`thenestedinitializerstrickformultidimensionalarrays`.


Functions
---------

.. _function_product:

.. describe:: m3ta::product
   
   .. code-block:: cpp
      
      template<typename T_First, typename ... T_Others>
      constexpr m3ta::MultiplicationResultT<T_First, T_Others ...>
      product(T_First first, T_Others ... others) noexcept
    
    
    The arguments passed do not have to be of numeric type—custom types such as
    matrices and vectors can be passed as soon as they define arithmetic
    multiplications with the values preceding and/or following them.
   
   
   :Template Parameters:
      - **T_First** (automatically deduced) — Type of the first value
        to multiply.
      - **T_Others** (automatically deduced) — Types of the other values
        to mutiply.
   
   :Function Parameters:
      - **first** – First value to multiply.
      - **others** – Other values to multiply.
   
   
   .. rubric:: Returns
   
   The product of the values.


Traits
------

.. _trait_product:

.. describe:: m3ta::Product
   
   .. code-block:: cpp
      
      template<typename T, T T_first, T ... T_others>
      struct Product
   
   
   :Template Parameters:
      - **T** – Type of the values.
      - **T_first** – First value to multiply.
      - **T_others** – Other values to multiply.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<T, value>`` where `value` is
      the result of the function :ref:`m3ta::product() <function_product>`.
   
   .. describe:: value_type
      
      The type ``T``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr T value
      
      The product of the values.


Aliases
-------

.. _alias_productt:

.. describe:: m3ta::ProductT
   
   .. code-block:: cpp
      
      template<typename T, T T_first, T ... T_others>
      using ProductT = typename Product<T, T_first, T_others ...>::type;


.. _alias_indexproduct:

.. describe:: m3ta::IndexProduct
   
   .. code-block:: cpp
      
      template<std::size_t T_first, std::size_t ... T_others>
      using IndexProduct = Product<std::size_t, T_first, T_others ...>;


.. _alias_indexproductt:

.. describe:: m3ta::IndexProductT
   
   .. code-block:: cpp
      
      template<std::size_t T_first, std::size_t ... T_others>
      using IndexProductT = typename IndexProduct<T_first, T_others ...>::type;


Usage Examples
--------------

.. _usageexamples_product:

.. code-block:: cpp
   
   auto value1 = m3ta::product(1, 2, 4); // 8
   auto value2 = m3ta::product(4.9, 85); // 416.5
   auto value3 = m3ta::product(std::complex<float>(2, 2), 4); // std::complex<float>(8, 8)
   
   using Type = m3ta::ProductT<int, 1, 2, 4>; // std::integral_constant<int, 8>
