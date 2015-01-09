#ifndef M3TA_ALL_H
#define M3TA_ALL_H

#include <type_traits>


namespace m3ta
{

//- Functions.

constexpr bool
all() noexcept
{
    return true;
}

template<typename T, typename ... T_Others>
constexpr bool
all(T first, T_Others ... others) noexcept
{
    return !first ? false : all(others ...);
}


//- Traits.

template<typename T, T ... T_values>
struct All
    : public std::integral_constant<bool, all(T_values ...)>
{};


//- Aliases.

template<typename T, T ... T_values>
using AllT = typename All<T, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_ALL_H
