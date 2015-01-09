#ifndef M3TA_MINIMUM_H
#define M3TA_MINIMUM_H

#include <type_traits>


namespace m3ta
{

//- Functions.

template<typename T>
constexpr T
minimum(T value1, T value2) noexcept
{
    return value1 < value2 ? value1 : value2;
}


//- Traits.

template<typename T, T T_value1, T T_value2>
struct Minimum
    : public std::integral_constant<T, minimum(T_value1, T_value2)>
{};


//- Aliases.

template<typename T, T T_value1, T T_value2>
using MinimumT = typename Minimum<T, T_value1, T_value2>::type;

} // namespace m3ta.

#endif // M3TA_MINIMUM_H
