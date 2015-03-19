#ifndef M3TA_EXTRACTINTEGERSEQUENCE_H
#define M3TA_EXTRACTINTEGERSEQUENCE_H

#include <array>

#include "integersequence.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence>
struct ExtractIntegerSequence;

template<typename T, T ... T_values>
struct ExtractIntegerSequence<IntegerSequence<T, T_values ...>>
{
    static constexpr std::array<T, sizeof ... (T_values)>
    asArray()
    {
        return {T_values ...};
    }
};

} // namespace m3ta.

#endif // M3TA_EXTRACTINTEGERSEQUENCE_H
