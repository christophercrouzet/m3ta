#ifndef M3TA_REVERSEINTEGERSEQUENCE_H
#define M3TA_REVERSEINTEGERSEQUENCE_H

#include "concatenateintegersequences.h"
#include "integersequence.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence>
struct ReverseIntegerSequence;

template<typename T, T T_first, T ... T_others>
struct ReverseIntegerSequence<IntegerSequence<T, T_first, T_others ...>>
{
    using type = ConcatenateIntegerSequencesT<
        typename ReverseIntegerSequence<IntegerSequence<T, T_others ...>>::type,
        IntegerSequence<T, T_first>
    >;
};

template<typename T>
struct ReverseIntegerSequence<IntegerSequence<T>>
{
    using type = IntegerSequence<T>;
};


//- Aliases.

template<typename T_Sequence>
using ReverseIntegerSequenceT =
    typename ReverseIntegerSequence<T_Sequence>::type;

template<typename T, T ... T_values>
using ReverseIntegerPack =
    ReverseIntegerSequence<IntegerSequence<T, T_values...>>;

template<typename T, T ... T_values>
using ReverseIntegerPackT =
    typename ReverseIntegerPack<T, T_values...>::type;

template<std::size_t ... T_values>
using ReverseIndexPack =
    ReverseIntegerSequence<IndexSequence<T_values...>>;

template<std::size_t ... T_values>
using ReverseIndexPackT =
    typename ReverseIndexPack<T_values...>::type;

} // namespace m3ta.

#endif // M3TA_REVERSEINTEGERSEQUENCE_H
