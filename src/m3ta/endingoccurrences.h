#ifndef M3TA_ENDINGOCCURRENCES_H
#define M3TA_ENDINGOCCURRENCES_H

#include <cstddef>
#include <type_traits>

#include "all.h"
#include "isoperatorcallable.h"


namespace m3ta
{
namespace _endingoccurrences
{

template<typename T_Search>
constexpr std::size_t
impl(std::size_t count, T_Search search)
{
    return count;
}

template<typename T_Search, typename T_Unique>
constexpr std::size_t
impl(std::size_t count, T_Search search, T_Unique unique)
{
    return unique == search ? count + 1 : 0;
}

template<typename T_Search, typename T_First, typename ... T_Others>
constexpr std::size_t
impl(std::size_t count, T_Search search, T_First first, T_Others ... others)
{
    return first == search ?
        impl(count + 1, search, others ...) :
        impl(0, search, others ...);
}

} // namespace _endingoccurrences.


//- Functions.

template<typename T_Search, typename ... T_Values>
constexpr std::size_t
endingOccurrences(T_Search search, T_Values ... values) noexcept
{
    static_assert(
        all(isOperatorCallable<
                BinaryOperator::equalTo,
                T_Values,
                T_Search
            >() ...),
        "Not all the values are comparable for equality with "
        "the search argument."
    );
    
    return _endingoccurrences::impl(0, search, values ...);
}


//- Traits.

template<typename T, T T_search, T ... T_values>
struct EndingOccurrences
    : public std::integral_constant<
          std::size_t,
          endingOccurrences(T_search, T_values ...)
      >
{};


//- Aliases.

template<typename T, T T_search, T ... T_values>
using EndingOccurrencesT =
    typename EndingOccurrences<T, T_search, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_ENDINGOCCURRENCES_H
