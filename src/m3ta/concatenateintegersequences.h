#ifndef M3TA_CONCATENATEINTEGERSEQUENCES_H
#define M3TA_CONCATENATEINTEGERSEQUENCES_H

#include <type_traits>

#include "integersequence.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence1, typename T_Sequence2>
struct ConcatenateIntegerSequences;

template<typename T, T ... T_values1, T ... T_values2>
struct ConcatenateIntegerSequences<
    IntegerSequence<T, T_values1 ...>,
    IntegerSequence<T, T_values2 ...>
>
{
    static_assert(std::is_integral<T>::value, "Not an integral type.");
    
    using type = IntegerSequence<T, T_values1 ..., T_values2 ...>;
};


//- Aliases.

template<typename T_Sequence1, typename T_Sequence2>
using ConcatenateIntegerSequencesT =
    typename ConcatenateIntegerSequences<T_Sequence1, T_Sequence2>::type;

} // namespace m3ta.

#endif // M3TA_CONCATENATEINTEGERSEQUENCES_H
