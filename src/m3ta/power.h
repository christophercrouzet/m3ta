#ifndef M3TA_POWER_H
#define M3TA_POWER_H

#include <type_traits>

#include "arithmeticoperationresult.h"


namespace m3ta
{

//- Functions.

template<typename T_Base, typename T_Exponent>
constexpr MultiplicationResultT<T_Base, T_Base>
power(T_Base base, T_Exponent exponent) noexcept
{
    static_assert(
        std::is_integral<T_Exponent>::value,
        "Not an integral type."
    );
    
    return exponent == 0 ? 1 :
        exponent > 0 ? (base * power(base, exponent - 1)) :
            (static_cast<T_Base>(1) / (base * power(base, -exponent - 1)));
}


//- Traits.

template<typename T, T T_base, T T_exponent>
struct Power
    : public std::integral_constant<T, power(T_base, T_exponent)>
{};


//- Aliases.

template<typename T, T T_base, T T_exponent>
using PowerT = typename Power<T, T_base, T_exponent>::type;

} // namespace m3ta.

#endif // M3TA_POWER_H
