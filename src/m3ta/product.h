#ifndef M3TA_PRODUCT_H
#define M3TA_PRODUCT_H

#include <cstddef>
#include <type_traits>

#include "arithmeticoperationresult.h"


namespace m3ta
{

//- Functions.

template<typename T_Unique>
constexpr T_Unique
product(T_Unique unique) noexcept
{
    return unique;
}

template<typename T_First, typename T_Second, typename ... T_Others>
constexpr m3ta::MultiplicationResultT<T_First, T_Second, T_Others ...>
product(T_First first, T_Second second, T_Others ... others) noexcept
{
    return product(first * second, others ...);
}


//- Traits.

template<typename T, T T_first, T ... T_others>
struct Product
    : public std::integral_constant<T, product(T_first, T_others ...)>
{};


//- Aliases.

// The template parameters `T_first` and `T_others` need to be grouped into a
// single parameter to avoid the following compilation error:
// "pack expansion used as argument for non-pack parameter of alias template".

template<typename T, T ... T_values>
using ProductT = typename Product<T, T_values ...>::type;

template<std::size_t ... T_values>
using IndexProduct = Product<std::size_t, T_values ...>;

template<std::size_t ... T_values>
using IndexProductT = typename IndexProduct<T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_PRODUCT_H
