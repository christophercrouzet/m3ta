#ifndef M3TA_MAXIMUM_H
#define M3TA_MAXIMUM_H

#include <type_traits>


namespace m3ta
{

//- Functions.

template<typename T>
constexpr T
maximum(T value1, T value2) noexcept
{
    return value1 < value2 ? value2 : value1;
}


//- Traits.

template<typename T, T T_value1, T T_value2>
struct Maximum
    : public std::integral_constant<T, maximum(T_value1, T_value2)>
{};


//- Aliases.

template<typename T, T T_value1, T T_value2>
using MaximumT = typename Maximum<T, T_value1, T_value2>::type;

} // namespace m3ta.

#endif // M3TA_MAXIMUM_H
