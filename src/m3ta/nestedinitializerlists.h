#ifndef M3TA_NESTEDINITIALIZERLISTS_H
#define M3TA_NESTEDINITIALIZERLISTS_H

#include <cstddef>
#include <initializer_list>


namespace m3ta
{

//- Traits.

template<typename T, std::size_t T_levels>
struct NestedInitializerLists
{
    using type = std::initializer_list<
        typename NestedInitializerLists<T, T_levels - 1>::type
    >;
};

template<typename T>
struct NestedInitializerLists<T, 0>
{
    using type = T;
};


//- Aliases.

template<typename T, std::size_t T_levels>
using NestedInitializerListsT =
    typename NestedInitializerLists<T, T_levels>::type;

} // namespace m3ta.

#endif // M3TA_NESTEDINITIALIZERLISTS_H
