.. _reference_arithmeticoperationresult:

Arithmetic Operation Result
===========================

.. code-block:: cpp
   
   #include <m3ta/arithmeticoperationresult>


Deduces the resulting type of an arithmetic operation between the given type
elements.

The deduction follows a left-to-right associativity, meaning that ``a + b + c``
is evaluated as ``(a + b) + c``.


Enumerators
-----------

.. _enumerator_arithmeticoperator:

.. describe:: m3ta::ArithmeticOperator
   
   .. code-block:: cpp
      
      enum class ArithmeticOperator {
          addition,
          subtraction,
          multiplication,
          division
      };
   
   
   .. describe:: addition
      
      Addition operator ``+``.
   
   .. describe:: subtraction
      
      Subtraction operator ``-``.
   
   .. describe:: multiplication
      
      Multiplication operator ``*``.
   
   .. describe:: division
      
      Division operator ``/``.


Traits
------

.. _trait_arithmeticoperationresult:
   
.. describe:: m3ta::ArithmeticOperationResult
   
   .. code-block:: cpp
      
      template<ArithmeticOperator T_operator, typename ... T_Values>
      struct ArithmeticOperationResult
  
  
   :Template Parameters:
      - **T_operator** – Operator to use for the check.
      - **T_Values** – Variable number of types to check.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The resulting type of the arithmetic operation between the given type
      elements.


Aliases
-------

.. _alias_arithmeticoperationresultt:

.. describe:: m3ta::ArithmeticOperationResultT
   
   .. code-block:: cpp
      
      template<ArithmeticOperator T_operator, typename ... T_Values>
      using ArithmeticOperationResultT =
          typename ArithmeticOperationResult<T_operator, T_Values ...>::type;


.. _alias_additionresult:

.. describe:: m3ta::AdditionResult
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using AdditionResult =
          ArithmeticOperationResult<ArithmeticOperator::addition, T_Values ...>;


.. _alias_additionresultt:

.. describe:: m3ta::AdditionResultT
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using AdditionResultT =
          typename AdditionResult<T_Values ...>::type;


.. _alias_subtractionresult:

.. describe:: m3ta::SubtractionResult
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using SubtractionResult =
          ArithmeticOperationResult<ArithmeticOperator::subtraction, T_Values ...>;


.. _alias_subtractionresultt:

.. describe:: m3ta::SubtractionResultT
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using SubtractionResultT =
          typename SubtractionResult<T_Values ...>::type;


.. _alias_multiplicationresult:

.. describe:: m3ta::MultiplicationResult
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using MultiplicationResult =
          ArithmeticOperationResult<ArithmeticOperator::multiplication, T_Values ...>;


.. _alias_multiplicationresultt:

.. describe:: m3ta::MultiplicationResultT
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using MultiplicationResultT =
          typename MultiplicationResult<T_Values ...>::type;


.. _alias_divisionresult:

.. describe:: m3ta::DivisionResult
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using DivisionResult =
          ArithmeticOperationResult<ArithmeticOperator::division, T_Values ...>;


.. _alias_divisionresultt:

.. describe:: m3ta::DivisionResultT
   
   .. code-block:: cpp
      
      template<typename ... T_Values>
      using DivisionResultT =
          typename DivisionResult<T_Values ...>::type;


Usage Examples
--------------

.. _usageexamples_arithmeticoperationresult:

.. code-block:: cpp
   
   using Type1 = m3ta::AdditionResultT<char, short>; // int
   using Type2 = m3ta::SubtractionResultT<int, float>; // float
   using Type3 = m3ta::ArithmeticOperationResultT<
       m3ta::ArithmeticOperator::multiplication,
       float,
       std::complex<float>
   >; // std::complex<float>
