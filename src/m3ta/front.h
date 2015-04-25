#ifndef M3TA_FRONT_H
#define M3TA_FRONT_H

#include <cstddef>

#include "at.h"
#include "integersequence.h"


namespace m3ta
{

//- Traits.

template<typename T_Sequence>
struct Front
{
    using type = AtT<0, T_Sequence>;
};


//- Aliases.

template<typename T_Sequence>
using FrontT = typename Front<T_Sequence>::type;

template<typename T, T ... T_values>
using FrontIntegerPack = Front<IntegerSequence<T, T_values...>>;

template<typename T, T ... T_values>
using FrontIntegerPackT = typename FrontIntegerPack<T, T_values ...>::type;

template<std::size_t ... T_values>
using FrontIndexPack = Front<IndexSequence<T_values...>>;

template<std::size_t ... T_values>
using FrontIndexPackT = typename FrontIndexPack<T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_FRONT_H
