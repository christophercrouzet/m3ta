#ifndef M3TA_ANY_H
#define M3TA_ANY_H

#include <type_traits>


namespace m3ta
{

//- Functions.

constexpr bool
any() noexcept
{
    return false;
}

template<typename T, typename ... T_Others>
constexpr bool
any(T first, T_Others ... others) noexcept
{
    return first ? true : any(others ...);
}


//- Traits.

template<typename T, T ... T_values>
struct Any
    : public std::integral_constant<bool, any(T_values ...)>
{};


//- Aliases.

template<typename T, T ... T_values>
using AnyT = typename Any<T, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_ANY_H
