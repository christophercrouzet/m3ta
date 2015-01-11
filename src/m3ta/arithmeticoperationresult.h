#ifndef M3TA_ARITHMETICOPERATIONRESULT_H
#define M3TA_ARITHMETICOPERATIONRESULT_H

#include <utility>


namespace m3ta
{

//- Enumerators.

enum class ArithmeticOperator {
    addition,
    subtraction,
    multiplication,
    division
};


namespace _arithmeticoperationresult
{

template<ArithmeticOperator T_operator, typename T1, typename T2>
struct BinaryResult;

template<typename T1, typename T2>
struct BinaryResult<ArithmeticOperator::addition, T1, T2>
{ using type = decltype(std::declval<T1>() + std::declval<T2>()); };

template<typename T1, typename T2>
struct BinaryResult<ArithmeticOperator::subtraction, T1, T2>
{ using type = decltype(std::declval<T1>() - std::declval<T2>()); };

template<typename T1, typename T2>
struct BinaryResult<ArithmeticOperator::multiplication, T1, T2>
{ using type = decltype(std::declval<T1>() * std::declval<T2>()); };

template<typename T1, typename T2>
struct BinaryResult<ArithmeticOperator::division, T1, T2>
{ using type = decltype(std::declval<T1>() / std::declval<T2>()); };

} // namespace _arithmeticoperationresult.


//- Traits.

template<
    ArithmeticOperator T_operator,
    typename T_First,
    typename ... T_Others
>
struct ArithmeticOperationResult;

template<
    ArithmeticOperator T_operator,
    typename T_First,
    typename T_Second,
    typename ... T_Others
>
struct ArithmeticOperationResult<
    T_operator,
    T_First,
    T_Second,
    T_Others ...
>
{
    using type = typename ArithmeticOperationResult<
        T_operator,
        typename _arithmeticoperationresult::BinaryResult<
            T_operator,
            T_First,
            T_Second
        >::type,
        T_Others ...
    >::type;
};

template<
    ArithmeticOperator T_operator,
    typename T_Last
>
struct ArithmeticOperationResult<T_operator, T_Last>
{
    using type = T_Last;
};


//- Aliases.

template<ArithmeticOperator T_operator, typename ... T_Values>
using ArithmeticOperationResultT =
    typename ArithmeticOperationResult<T_operator, T_Values ...>::type;

template<typename ... T_Values>
using AdditionResult =
    ArithmeticOperationResult<ArithmeticOperator::addition, T_Values ...>;

template<typename ... T_Values>
using AdditionResultT =
    typename AdditionResult<T_Values ...>::type;

template<typename ... T_Values>
using SubtractionResult =
    ArithmeticOperationResult<ArithmeticOperator::subtraction, T_Values ...>;

template<typename ... T_Values>
using SubtractionResultT =
    typename SubtractionResult<T_Values ...>::type;

template<typename ... T_Values>
using MultiplicationResult =
    ArithmeticOperationResult<ArithmeticOperator::multiplication, T_Values ...>;

template<typename ... T_Values>
using MultiplicationResultT =
    typename MultiplicationResult<T_Values ...>::type;

template<typename ... T_Values>
using DivisionResult =
    ArithmeticOperationResult<ArithmeticOperator::division, T_Values ...>;

template<typename ... T_Values>
using DivisionResultT =
    typename DivisionResult<T_Values ...>::type;

} // namespace m3ta.

#endif // M3TA_ARITHMETICOPERATIONRESULT_H
