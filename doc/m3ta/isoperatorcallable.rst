.. _reference_isoperatorcallable:

Is Operator Callable?
=====================

.. code-block:: cpp
    
   #include <m3ta/isoperatorcallable>


Checks if an operator can be called on given types.


Enumerators
-----------

.. _enumerator_unaryoperator:

.. describe:: m3ta::UnaryOperator
   
   .. code-block:: cpp
      
      enum class UnaryOperator {
          plus,
          minus,
          postfixIncrement,
          postfixDecrement,
          prefixIncrement,
          prefixDecrement,
          logicalNot,
          bitwiseNot
      };
   
   
   .. describe:: plus
      
      Plus operator ``+a``.
   
   .. describe:: minus
      
      Minus operator ``-a``.
   
   .. describe:: posfixIncrement
      
      Postfix increment operator ``a++``.
   
   .. describe:: postfixDecrement
      
      Postfix decrement operator ``a--``.
   
   .. describe:: prefixIncrement
      
      Prefix increment operator ``++a``.
   
   .. describe:: prefixDecrement
      
      Prefix decrement operator ``--a``.
   
   .. describe:: logicalNot
      
      Logical NOT operator ``!a``.
   
   .. describe:: bitwiseNot
      
      Bitwise NOT operator ``~a``.


.. _enumerator_binaryoperator:

.. describe:: m3ta::BinaryOperator
   
   .. code-block:: cpp
      
      enum class BinaryOperator {
          assignment,
          addition,
          subtraction,
          multiplication,
          division,
          modulo,
          equalTo,
          notEqualTo,
          greaterThan,
          lessThan,
          greaterThanOrEqualTo,
          lessThanOrEqualTo,
          logicalAnd,
          logicalOr,
          bitwiseAnd,
          bitwiseOr,
          bitwiseXor,
          bitwiseLeftShift,
          bitwiseRightShift,
          additionAssignment,
          subtractionAssignment,
          multiplicationAssignment,
          divisionAssignment,
          moduloAssignment,
          bitwiseAndAssignment,
          bitwiseOrAssignment,
          bitwiseXorAssignment,
          bitwiseLeftShiftAssignment,
          bitwiseRightShiftAssignment
      };
   
   
   .. describe:: assignment
      
      Assignment operator ``a = b``.
   
   .. describe:: addition
      
      Addition operator ``a + b``.
   
   .. describe:: subtraction
      
      Subtraction operator ``a - b``.
   
   .. describe:: multiplication
      
      Multiplication operator ``a * b``.
   
   .. describe:: division
      
      Division operator ``a / b``.
   
   .. describe:: modulo
      
      Modulo operator ``a % b``.
   
   .. describe:: equalTo
      
      Equal to operator ``a == b``.
   
   .. describe:: notEqualTo
      
      Not equal to operator ``a != b``.
   
   .. describe:: greaterThan
      
      Greater than operator ``a > b``.
   
   .. describe:: lessThan
      
      Less than operator ``a < b``.
   
   .. describe:: greaterThanOrEqualTo
      
      Greater than or equal to operator ``a >= b``.
   
   .. describe:: lessThanOrEqualTo
      
      Less than or equal to operator ``a <= b``.
   
   .. describe:: logicalAnd
      
      Logical AND operator ``a && b``.
   
   .. describe:: logicalOr
      
      Logical OR operator ``a || b``.
   
   .. describe:: bitwiseAnd
      
      Bitwise AND operator ``a & b``.
   
   .. describe:: bitwiseOr
      
      Bitwise OR operator ``a | b``.
   
   .. describe:: bitwiseXOr
      
      Bitwise XOR operator ``a ^ b``.
   
   .. describe:: bitwiseLeftShift
      
      Bitwise left shift operator ``a << b``.
   
   .. describe:: bitwiseRightShift
      
      Bitwise right shift operator ``a >> b``.
   
   .. describe:: additionAssignment
      
      Addition assignment operator ``a += b``.
   
   .. describe:: subtractionAssignment
      
      Subtraction assignment operator ``a -= b``.
   
   .. describe:: multiplicationAssignment
      
      Multiplication assignment operator ``a *= b``.
   
   .. describe:: divisionAssignment
      
      Division assignment operator ``a /= b``.
   
   .. describe:: moduloAssignment
      
      Modulo assignment operator ``a %= b``.
   
   .. describe:: bitwiseAndAssignment
      
      Bitwise AND assignment operator ``a &= b``.
   
   .. describe:: bitwiseOrAssignment
      
      Bitwise OR assignment operator ``a |= b``.
   
   .. describe:: bitwiseXOrAssignment
      
      Bitwise XOR assignment operator ``a ^= b``.
   
   .. describe:: bitwiseLeftShiftAssignment
      
      Bitwise left shift assignment operator ``a <<= b``.
   
   .. describe:: bitwiseRightShiftAssignment
      
      Bitwise right shift assignment operator ``a >>= b``.


Functions
---------

.. _function_isoperatorcallable:

.. describe:: m3ta::isOperatorCallable
   
   .. code-block:: cpp
      
      template<UnaryOperator T_operator, typename T>
      constexpr bool
      isOperatorCallable() noexcept
      
      template<BinaryOperator T_operator, typename T, typename T_Other>
      constexpr bool
      isOperatorCallable() noexcept
   
   
   :Template Parameters:
      - **T_operator** — Operator to check for.
      - **T** — Type of the first operand.
      - **T_Other** — Type of the second operand. For binary operators only.
   
   
   .. rubric:: Returns
   
   Whether the operator can be called on the operand(s).


Traits
------

.. _trait_isoperatorcallable:

.. describe:: m3ta::IsOperatorCallable
   
   .. code-block:: cpp
      
      template<typename T_Operator, T_Operator T_operator, typename ... T>
      struct IsOperatorCallable;
   
   
   :Template Parameters:
      - **T_Operator** – Type of the operator to check for.
      - **T_operator** – Operator to check for.
      - **T** - Type of the operand(s). Only one operand is expected when
        checking against unary operators, and two for the binary operators.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``std::integral_constant<bool, value>`` where `value` is
      the result of the function
      :ref:`m3ta::isOperatorCallable() <function_isoperatorcallable>`.
   
   .. describe:: value_type
      
      The type ``bool``.
   
   
   .. rubric:: Member Constants
   
   .. describe:: static constexpr bool value
      
      Whether the operator can be called on the operand(s).


Aliases
-------

.. _alias_isoperatorcallablet:

.. describe:: m3ta::IsOperatorCallableT
   
   .. code-block:: cpp
      
      template<typename T_Operator, T_Operator T_operator, typename ... T>
      using IsOperatorCallableT =
          typename IsOperatorCallable<T_Operator, T_operator, T ...>::type;


Usage Examples
--------------

.. _usageexamples_isoperatorcallable:

.. code-block:: cpp
   
   bool value1 = m3ta::isOperatorCallable<
       m3ta::UnaryOperator::logicalNot,
       int
   >(); // true
   bool value2 = m3ta::isOperatorCallable<
       m3ta::BinaryOperator::addition,
       int,
       float
   >(); // true
   bool value3 = m3ta::isOperatorCallable<
       m3ta::BinaryOperator::multiplication,
       int,
       std::complex<float>
   >(); // false
   
   using Type1 = m3ta::IsOperatorCallableT<
       m3ta::UnaryOperator::logicalNot,
       int
   >; // std::integral_constant<bool, true>
   using Type2 = m3ta::IsOperatorCallableT<
       m3ta::BinaryOperator::addition,
       int,
       float
   >; // std::integral_constant<bool, true>
   using Type3 = m3ta::IsOperatorCallableT<
       m3ta::BinaryOperator::multiplication,
       int,
       std::complex<float>
   >; // std::integral_constant<bool, false>
