#ifndef M3TA_BACK_H
#define M3TA_BACK_H

#include <cstddef>

#include "at.h"
#include "integersequence.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence>
struct Back
{
    using type = AtT<T_Sequence::size() - 1, T_Sequence>;
};


//- Aliases.

template<typename T_Sequence>
using BackT = typename Back<T_Sequence>::type;

template<typename T, T ... T_values>
using BackIntegerPack = Back<IntegerSequence<T, T_values...>>;

template<typename T, T ... T_values>
using BackIntegerPackT = typename BackIntegerPack<T, T_values ...>::type;

template<std::size_t ... T_values>
using BackIndexPack = Back<IndexSequence<T_values...>>;

template<std::size_t ... T_values>
using BackIndexPackT = typename BackIndexPack<T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_BACK_H
