#ifndef M3TA_CONCATENATE_H
#define M3TA_CONCATENATE_H

#include <type_traits>

#include "integersequence.h"
#include "parameterpack.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence1, typename T_Sequence2>
struct Concatenate;

template<typename T, T ... T_values1, T ... T_values2>
struct Concatenate<
    IntegerSequence<T, T_values1 ...>,
    IntegerSequence<T, T_values2 ...>
>
{
    static_assert(std::is_integral<T>::value, "Not an integral type.");
    
    using type = IntegerSequence<T, T_values1 ..., T_values2 ...>;
};

template<typename ... T_Types1, typename ... T_Types2>
struct Concatenate<ParameterPack<T_Types1 ...>, ParameterPack<T_Types2 ...>>
{
    using type = ParameterPack<T_Types1 ..., T_Types2 ...>;
};


//- Aliases.

template<typename T_Sequence1, typename T_Sequence2>
using ConcatenateT = typename Concatenate<T_Sequence1, T_Sequence2>::type;

} // namespace m3ta.

#endif // M3TA_CONCATENATE_H
