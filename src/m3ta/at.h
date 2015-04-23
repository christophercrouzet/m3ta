#ifndef M3TA_AT_H
#define M3TA_AT_H

#include <cstddef>
#include <type_traits>

#include "dependentbool.h"
#include "integersequence.h"
#include "parameterpack.h"


namespace m3ta
{

//- Traits.

template<std::size_t T_position, typename T_Sequence>
struct At;

template<std::size_t T_position, typename T, T T_first, T ... T_others>
struct At<T_position, IntegerSequence<T, T_first, T_others ...>>
{
    static_assert(T_position <= (sizeof ... (T_others)),
                  "The position is out of range.");
    
    using type =
        typename At<T_position - 1, IntegerSequence<T, T_others ...>>::type;
};

template<typename T, T T_first, T ... T_others>
struct At<0, IntegerSequence<T, T_first, T_others ...>>
{
    using type = std::integral_constant<T, T_first>;
};

template<std::size_t T_position, typename T>
struct At<T_position, IntegerSequence<T>>
{
    static_assert(dependentBool<T>(false), "The integer sequence is empty.");
};

template<std::size_t T_position, typename T_First, typename ... T_Others>
struct At<T_position, ParameterPack<T_First, T_Others ...>>
{
    static_assert(T_position <= (sizeof ... (T_Others)),
                  "The position is out of range.");
    
    using type = typename At<T_position - 1, ParameterPack<T_Others ...>>::type;
};

template<typename T_First, typename ... T_Others>
struct At<0, ParameterPack<T_First, T_Others ...>>
{
    using type = T_First;
};

template<std::size_t T_position>
struct At<T_position, ParameterPack<>>
{
    static_assert(
        dependentBool<std::integral_constant<std::size_t, T_position>>(false),
        "The parameter pack is empty."
    );
};


//- Aliases.

template<std::size_t T_position, typename T_Sequence>
using AtT = typename At<T_position, T_Sequence>::type;

template<std::size_t T_position, typename T, T ... T_values>
using AtIntegerPack = At<T_position, IntegerSequence<T, T_values...>>;

template<std::size_t T_position, typename T, T ... T_values>
using AtIntegerPackT =
    typename AtIntegerPack<T_position, T, T_values ...>::type;

template<std::size_t T_position, std::size_t ... T_values>
using AtIndexPack = At<T_position, IndexSequence<T_values...>>;

template<std::size_t T_position, std::size_t ... T_values>
using AtIndexPackT = typename AtIndexPack<T_position, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_AT_H
