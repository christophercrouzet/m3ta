#ifndef M3TA_POPINTEGERSEQUENCE_H
#define M3TA_POPINTEGERSEQUENCE_H

#include <cstddef>

#include "concatenate.h"
#include "integersequence.h"
#include "minimum.h"


namespace m3ta
{
namespace _popintegersequence
{

template<std::size_t T_position, typename T_Sequence>
struct Base;

template<std::size_t T_position, typename T, T T_first, T ... T_others>
struct Base<T_position, IntegerSequence<T, T_first, T_others ...>>
{
    using type = ConcatenateT<
        IntegerSequence<T, T_first>,
        typename Base<
            T_position - 1,
            IntegerSequence<T, T_others ...>
        >::type
    >;
};

template<typename T, T T_first, T ... T_others>
struct Base<0, IntegerSequence<T, T_first, T_others ...>>
{
    using type = IntegerSequence<T>;
};

} // namespace _popintegersequence.


//- Traits.

template<std::size_t T_count, typename T_Sequence>
struct PopIntegerSequence;

template<std::size_t T_count, typename T, T ... T_values>
struct PopIntegerSequence<T_count, IntegerSequence<T, T_values ...>>
    : public _popintegersequence::Base<
          sizeof ... (T_values) - minimum(T_count, sizeof ... (T_values)),
          IntegerSequence<T, T_values ...>
      >
{};

template<typename T, T T_first, T ... T_others>
struct PopIntegerSequence<0, IntegerSequence<T, T_first, T_others ...>>
{
    using type = IntegerSequence<T, T_first, T_others ...>;
};

template<std::size_t T_count, typename T>
struct PopIntegerSequence<T_count, IntegerSequence<T>>
{
    using type = IntegerSequence<T>;
};


//- Aliases.

template<std::size_t T_count, typename T_Sequence>
using PopIntegerSequenceT =
    typename PopIntegerSequence<T_count, T_Sequence>::type;

template<std::size_t T_count, typename T, T ... T_values>
using PopIntegerPack =
    PopIntegerSequence<
        T_count,
        IntegerSequence<T, T_values...>
    >;

template<std::size_t T_count, typename T, T ... T_values>
using PopIntegerPackT =
    typename PopIntegerPack<T_count, T, T_values ...>::type;

template<std::size_t T_count, std::size_t ... T_values>
using PopIndexPack =
    PopIntegerSequence<
        T_count,
        IndexSequence<T_values...>
    >;

template<std::size_t T_count, std::size_t ... T_values>
using PopIndexPackT =
    typename PopIndexPack<T_count, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_POPINTEGERSEQUENCE_H
