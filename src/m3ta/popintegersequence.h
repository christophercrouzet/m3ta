#ifndef M3TA_POPINTEGERSEQUENCE_H
#define M3TA_POPINTEGERSEQUENCE_H

#include <cstddef>

#include "concatenateintegersequences.h"
#include "integersequence.h"
#include "minimum.h"


namespace m3ta
{
namespace _popintegersequence
{

template<
    std::size_t T_position,
    typename T_DestinationIntegerSequence,
    typename T_SourceIntegerSequence
>
struct Base;

template<
    std::size_t T_position,
    typename T,
    T ... T_destination,
    T T_firstSource,
    T ... T_otherSources
>
struct Base<
    T_position,
    IntegerSequence<T, T_destination ...>,
    IntegerSequence<T, T_firstSource, T_otherSources ...>
>
{
    using type = ConcatenateIntegerSequencesT<
        IntegerSequence<T, T_destination ..., T_firstSource>,
        typename Base<
            T_position - 1,
            IntegerSequence<T, T_destination ...>,
            IntegerSequence<T, T_otherSources ...>
        >::type
    >;
};

template<
    typename T,
    T ... T_destination,
    T T_firstSource,
    T ... T_otherSources
>
struct Base<
    0,
    IntegerSequence<T, T_destination ...>,
    IntegerSequence<T, T_firstSource, T_otherSources ...>
>
{
    using type = IntegerSequence<T, T_destination ...>;
};

} // namespace _popintegersequence.


//- Traits.

template<std::size_t T_count, typename T_Sequence>
struct PopIntegerSequence;

template<std::size_t T_count, typename T, T ... T_values>
struct PopIntegerSequence<T_count, IntegerSequence<T, T_values ...>>
    : public _popintegersequence::Base<
          sizeof ... (T_values) - minimum(T_count, sizeof ... (T_values)),
          IntegerSequence<T>,
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

} // namespace m3ta.

#endif // M3TA_POPINTEGERSEQUENCE_H
