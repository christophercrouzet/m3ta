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
    typename T_DestinationIntegerSequence,
    typename T_SourceIntegerSequence,
    std::size_t T_position
>
struct Base;

template<
    typename T,
    T ... T_destination,
    T T_firstSource,
    T ... T_otherSources,
    std::size_t T_position
>
struct Base<
    IntegerSequence<T, T_destination ...>,
    IntegerSequence<T, T_firstSource, T_otherSources ...>,
    T_position
>
{
    using type = ConcatenateIntegerSequencesT<
        IntegerSequence<T, T_destination ..., T_firstSource>,
        typename Base<
            IntegerSequence<T, T_destination ...>,
            IntegerSequence<T, T_otherSources ...>,
            T_position - 1
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
    IntegerSequence<T, T_destination ...>,
    IntegerSequence<T, T_firstSource, T_otherSources ...>,
    0
>
{
    using type = IntegerSequence<T, T_destination ...>;
};

} // namespace _popintegersequence.


//- Traits.

template<typename T_Sequence, std::size_t T_count = 1>
struct PopIntegerSequence;

template<typename T, T ... T_values, std::size_t T_count>
struct PopIntegerSequence<IntegerSequence<T, T_values ...>, T_count>
    : public _popintegersequence::Base<
          IntegerSequence<T>,
          IntegerSequence<T, T_values ...>,
          sizeof ... (T_values) - minimum(T_count, sizeof ... (T_values))
      >
{};

template<typename T, T T_first, T ... T_others>
struct PopIntegerSequence<IntegerSequence<T, T_first, T_others ...>, 0>
{
    using type = IntegerSequence<T, T_first, T_others ...>;
};

template<typename T, std::size_t T_count>
struct PopIntegerSequence<IntegerSequence<T>, T_count>
{
    using type = IntegerSequence<T>;
};


//- Aliases.

template<typename T_Sequence, std::size_t T_count = 1>
using PopIntegerSequenceT =
    typename PopIntegerSequence<T_Sequence, T_count>::type;

} // namespace m3ta.

#endif // M3TA_POPINTEGERSEQUENCE_H
