#ifndef TESTS_OPERATORS_H
#define TESTS_OPERATORS_H

#include <m3ta/isoperatorcallable>


namespace tests
{

//- Unary operators.

template<m3ta::UnaryOperator T_operator>
struct UnaryOperator
{
    static constexpr const char *value =
        "unknown";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::plus>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::plus";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::minus>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::minus";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::postfixIncrement>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::postfixIncrement";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::postfixDecrement>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::postfixDecrement";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::prefixIncrement>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::prefixIncrement";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::prefixDecrement>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::prefixDecrement";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::logicalNot>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::logicalNot";
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::bitwiseNot>
{
    static constexpr const char *value =
        "m3ta::UnaryOperator::bitwiseNot";
};


//- Binary operators.

template<m3ta::BinaryOperator T_operator>
struct BinaryOperator
{
    static constexpr const char *value =
        "unknown";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::assignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::assignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::addition>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::addition";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::subtraction>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::subtraction";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::multiplication>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::multiplication";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::division>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::division";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::modulo>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::modulo";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::equalTo>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::equalTo";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::notEqualTo>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::notEqualTo";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::greaterThan>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::greaterThan";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::lessThan>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::lessThan";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::greaterThanOrEqualTo>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::greaterThanOrEqualTo";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::lessThanOrEqualTo>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::lessThanOrEqualTo";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::logicalAnd>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::logicalAnd";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::logicalOr>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::logicalOr";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseAnd>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseAnd";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseOr>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseOr";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseXor>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseXor";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseLeftShift>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseLeftShift";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseRightShift>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseRightShift";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::additionAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::additionAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::subtractionAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::subtractionAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::multiplicationAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::multiplicationAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::divisionAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::divisionAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::moduloAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::moduloAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseAndAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseAndAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseOrAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseOrAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseXorAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseXorAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseLeftShiftAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseLeftShiftAssignment";
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseRightShiftAssignment>
{
    static constexpr const char *value =
        "m3ta::BinaryOperator::bitwiseRightShiftAssignment";
};

} // namespace tests.

#endif // TESTS_OPERATORS_H
