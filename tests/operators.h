#ifndef TESTS_OPERATORS_H
#define TESTS_OPERATORS_H

#include <string>

#include <m3ta/isoperatorcallable>


namespace tests
{

//- Unary operators.

template<m3ta::UnaryOperator T_operator>
struct UnaryOperator
{
    static std::string value()
    { return "unknown"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::plus>
{
    static std::string value()
    { return "m3ta::UnaryOperator::plus"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::minus>
{
    static std::string value()
    { return "m3ta::UnaryOperator::minus"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::postfixIncrement>
{
    static std::string value()
    { return "m3ta::UnaryOperator::postfixIncrement"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::postfixDecrement>
{
    static std::string value()
    { return "m3ta::UnaryOperator::postfixDecrement"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::prefixIncrement>
{
    static std::string value()
    { return "m3ta::UnaryOperator::prefixIncrement"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::prefixDecrement>
{
    static std::string value()
    { return "m3ta::UnaryOperator::prefixDecrement"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::logicalNot>
{
    static std::string value()
    { return "m3ta::UnaryOperator::logicalNot"; }
};

template<>
struct UnaryOperator<m3ta::UnaryOperator::bitwiseNot>
{
    static std::string value()
    { return "m3ta::UnaryOperator::bitwiseNot"; }
};


//- Binary operators.

template<m3ta::BinaryOperator T_operator>
struct BinaryOperator
{
    static std::string value()
    { return "unknown"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::assignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::assignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::addition>
{
    static std::string value()
    { return "m3ta::BinaryOperator::addition"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::subtraction>
{
    static std::string value()
    { return "m3ta::BinaryOperator::subtraction"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::multiplication>
{
    static std::string value()
    { return "m3ta::BinaryOperator::multiplication"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::division>
{
    static std::string value()
    { return "m3ta::BinaryOperator::division"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::modulo>
{
    static std::string value()
    { return "m3ta::BinaryOperator::modulo"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::equalTo>
{
    static std::string value()
    { return "m3ta::BinaryOperator::equalTo"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::notEqualTo>
{
    static std::string value()
    { return "m3ta::BinaryOperator::notEqualTo"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::greaterThan>
{
    static std::string value()
    { return "m3ta::BinaryOperator::greaterThan"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::lessThan>
{
    static std::string value()
    { return "m3ta::BinaryOperator::lessThan"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::greaterThanOrEqualTo>
{
    static std::string value()
    { return "m3ta::BinaryOperator::greaterThanOrEqualTo"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::lessThanOrEqualTo>
{
    static std::string value()
    { return "m3ta::BinaryOperator::lessThanOrEqualTo"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::logicalAnd>
{
    static std::string value()
    { return "m3ta::BinaryOperator::logicalAnd"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::logicalOr>
{
    static std::string value()
    { return "m3ta::BinaryOperator::logicalOr"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseAnd>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseAnd"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseOr>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseOr"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseXor>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseXor"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseLeftShift>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseLeftShift"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseRightShift>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseRightShift"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::additionAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::additionAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::subtractionAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::subtractionAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::multiplicationAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::multiplicationAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::divisionAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::divisionAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::moduloAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::moduloAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseAndAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseAndAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseOrAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseOrAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseXorAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseXorAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseLeftShiftAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseLeftShiftAssignment"; }
};

template<>
struct BinaryOperator<m3ta::BinaryOperator::bitwiseRightShiftAssignment>
{
    static std::string value()
    { return "m3ta::BinaryOperator::bitwiseRightShiftAssignment"; }
};

} // namespace tests.

#endif // TESTS_OPERATORS_H
