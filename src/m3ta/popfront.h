#ifndef M3TA_POPFRONT_H
#define M3TA_POPFRONT_H

#include <cstddef>

#include "concatenate.h"
#include "integersequence.h"
#include "minimum.h"


namespace m3ta
{

//- Traits.

template<std::size_t T_count, typename T_Sequence>
struct PopFront;

template<std::size_t T_count, typename T, T T_first, T ... T_others>
struct PopFront<T_count, IntegerSequence<T, T_first, T_others ...>>
{
    using type =
        typename PopFront<T_count - 1, IntegerSequence<T, T_others ...>>::type;
};

template<typename T, T T_first, T ... T_others>
struct PopFront<0, IntegerSequence<T, T_first, T_others ...>>
{
    using type = IntegerSequence<T, T_first, T_others ...>;
};

template<std::size_t T_count, typename T>
struct PopFront<T_count, IntegerSequence<T>>
{
    using type = IntegerSequence<T>;
};

template<std::size_t T_count, typename T_First, typename ... T_Others>
struct PopFront<T_count, ParameterPack<T_First, T_Others ...>>
{
    using type =
        typename PopFront<T_count - 1, ParameterPack<T_Others ...>>::type;
};

template<typename T_First, typename ... T_Others>
struct PopFront<0, ParameterPack<T_First, T_Others ...>>
{
    using type = ParameterPack<T_First, T_Others ...>;
};

template<std::size_t T_count>
struct PopFront<T_count, ParameterPack<>>
{
    using type = ParameterPack<>;
};


//- Aliases.

template<std::size_t T_count, typename T_Sequence>
using PopFrontT = typename PopFront<T_count, T_Sequence>::type;

template<std::size_t T_count, typename T, T ... T_values>
using PopFrontIntegerPack = PopFront<T_count, IntegerSequence<T, T_values...>>;

template<std::size_t T_count, typename T, T ... T_values>
using PopFrontIntegerPackT = 
  typename PopFrontIntegerPack<T_count, T, T_values ...>::type;

template<std::size_t T_count, std::size_t ... T_values>
using PopFrontIndexPack = PopFront<T_count, IndexSequence<T_values...>>;

template<std::size_t T_count, std::size_t ... T_values>
using PopFrontIndexPackT =
    typename PopFrontIndexPack<T_count, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_POPFRONT_H
