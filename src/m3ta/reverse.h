#ifndef M3TA_REVERSE_H
#define M3TA_REVERSE_H

#include "concatenate.h"
#include "integersequence.h"
#include "parameterpack.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence>
struct Reverse;

template<typename T, T T_first, T ... T_others>
struct Reverse<IntegerSequence<T, T_first, T_others ...>>
{
    using type = ConcatenateT<
        typename Reverse<IntegerSequence<T, T_others ...>>::type,
        IntegerSequence<T, T_first>
    >;
};

template<typename T>
struct Reverse<IntegerSequence<T>>
{
    using type = IntegerSequence<T>;
};

template<typename T_First, typename ... T_Others>
struct Reverse<ParameterPack<T_First, T_Others ...>>
{
    using type = ConcatenateT<
        typename Reverse<ParameterPack<T_Others ...>>::type,
        ParameterPack<T_First>
    >;
};

template<>
struct Reverse<ParameterPack<>>
{
    using type = ParameterPack<>;
};


//- Aliases.

template<typename T_Sequence>
using ReverseT = typename Reverse<T_Sequence>::type;

template<typename T, T ... T_values>
using ReverseIntegerPack = Reverse<IntegerSequence<T, T_values...>>;

template<typename T, T ... T_values>
using ReverseIntegerPackT = typename ReverseIntegerPack<T, T_values...>::type;

template<std::size_t ... T_values>
using ReverseIndexPack = Reverse<IndexSequence<T_values...>>;

template<std::size_t ... T_values>
using ReverseIndexPackT = typename ReverseIndexPack<T_values...>::type;

} // namespace m3ta.

#endif // M3TA_REVERSE_H
