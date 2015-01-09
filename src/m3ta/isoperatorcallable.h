#ifndef M3TA_ISOPERATORCALLABLE_H
#define M3TA_ISOPERATORCALLABLE_H

#include <type_traits>

#include "pass.h"


#define M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(OPERATOR, EXPRESSION) \
template<typename T> \
struct UnaryHelper< \
    OPERATOR, \
    T, \
    typename std::enable_if< \
        true, \
        PassT<void, decltype(EXPRESSION)> \
    >::type \
> \
{ static constexpr bool value = true; };

#define M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(OPERATOR, EXPRESSION) \
template<typename T, typename T_Other> \
struct BinaryHelper< \
    OPERATOR, \
    T, \
    T_Other, \
    typename std::enable_if< \
        true, \
        PassT<void, decltype(EXPRESSION)> \
    >::type \
> \
{ static constexpr bool value = true; };


namespace m3ta
{

//- Enumerators.
    
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


namespace _isoperatorcallable
{

//- Custom declval to match both lvalue and rvalue parameters.

template<typename T>
struct DeclvalArgument
{
    using type = typename std::conditional<
        std::is_rvalue_reference<T>::value,
        T,
        T &
    >::type;
};

template<typename T>
using DeclvalArgumentT = typename DeclvalArgument<T>::type;

template<typename T>
typename std::add_rvalue_reference<DeclvalArgumentT<T>>::type
declval() noexcept;


//- Helpers for unary operators.

template<
    UnaryOperator T_operator,
    typename T,
    typename = void
>
struct UnaryHelper
{ static constexpr bool value = false; };

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::plus,
    +declval<T>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::minus,
    -declval<T>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::postfixIncrement,
    declval<T>()++
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::postfixDecrement,
    declval<T>()--
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::prefixIncrement,
    ++declval<T>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::prefixDecrement,
    --declval<T>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::logicalNot,
    !declval<T>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER(
    UnaryOperator::bitwiseNot,
    ~declval<T>()
);


//- Helpers for binary operators.

template<
    BinaryOperator T_operator,
    typename T,
    typename T_Other,
    typename = void
>
struct BinaryHelper
{ static constexpr bool value = false; };

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::assignment,
    declval<T>() = declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::addition,
    declval<T>() + declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::subtraction,
    declval<T>() - declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::multiplication,
    declval<T>() * declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::division,
    declval<T>() / declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::modulo,
    declval<T>() % declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::equalTo,
    declval<T>() == declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::notEqualTo,
    declval<T>() != declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::greaterThan,
    declval<T>() > declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::lessThan,
    declval<T>() < declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::greaterThanOrEqualTo,
    declval<T>() >= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::lessThanOrEqualTo,
    declval<T>() <= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::logicalAnd,
    declval<T>() && declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::logicalOr,
    declval<T>() || declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseAnd,
    declval<T>() & declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseOr,
    declval<T>() | declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseXor,
    declval<T>() ^ declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseLeftShift,
    declval<T>() << declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseRightShift,
    declval<T>() >> declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::additionAssignment,
    declval<T>() += declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::subtractionAssignment,
    declval<T>() -= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::multiplicationAssignment,
    declval<T>() *= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::divisionAssignment,
    declval<T>() /= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::moduloAssignment,
    declval<T>() %= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseAndAssignment,
    declval<T>() &= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseOrAssignment,
    declval<T>() |= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseXorAssignment,
    declval<T>() ^= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseLeftShiftAssignment,
    declval<T>() <<= declval<T_Other>()
);

M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER(
    BinaryOperator::bitwiseRightShiftAssignment,
    declval<T>() >>= declval<T_Other>()
);

} // namespace _isoperatorcallable.


//- Functions.

template<UnaryOperator T_operator, typename T>
constexpr bool
isOperatorCallable() noexcept
{
    return _isoperatorcallable::UnaryHelper<
        T_operator,
        T
    >::value;
}

template<BinaryOperator T_operator, typename T, typename T_Other>
constexpr bool
isOperatorCallable() noexcept
{
    return _isoperatorcallable::BinaryHelper<
        T_operator,
        T,
        T_Other
    >::value;
}


//- Traits.

template<typename T_Operator, T_Operator T_operator, typename ... T>
struct IsOperatorCallable;

template<UnaryOperator T_operator, typename T>
struct IsOperatorCallable<UnaryOperator, T_operator, T>
    : public std::integral_constant<
          bool,
          isOperatorCallable<T_operator, T>()
      >
{};

template<BinaryOperator T_operator, typename T, typename T_Other>
struct IsOperatorCallable<BinaryOperator, T_operator, T, T_Other>
    : public std::integral_constant<
          bool,
          isOperatorCallable<T_operator, T, T_Other>()
      >
{};


//- Aliases.

template<typename T_Operator, T_Operator T_operator, typename ... T>
using IsOperatorCallableT =
    typename IsOperatorCallable<T_Operator, T_operator, T ...>::type;

} // namespace m3ta.


#undef M3TA_ISOPERATORCALLABLE_DEFINE_UNARY_HELPER
#undef M3TA_ISOPERATORCALLABLE_DEFINE_BINARY_HELPER

#endif // M3TA_ISOPERATORCALLABLE_H
