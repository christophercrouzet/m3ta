#ifndef M3TA_NONE_H
#define M3TA_NONE_H

#include <type_traits>


namespace m3ta
{

//- Functions.

constexpr bool
none() noexcept
{
    return true;
}

template<typename T, typename ... T_Others>
constexpr bool
none(T first, T_Others ... others) noexcept
{
    return first ? false : none(others ...);
}


//- Traits.

template<typename T, T ... T_values>
struct None
    : public std::integral_constant<bool, none(T_values ...)>
{};


//- Aliases.

template<typename T, T ... T_values>
using NoneT = typename None<T, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_NONE_H
