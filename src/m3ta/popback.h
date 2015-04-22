#ifndef M3TA_POPBACK_H
#define M3TA_POPBACK_H

#include <cstddef>

#include "concatenate.h"
#include "integersequence.h"
#include "minimum.h"


namespace m3ta
{
namespace _popback
{

//- Helper to retrieve the starting position.

template<std::size_t T_count, std::size_t T_size>
constexpr std::size_t
position()
{
    return T_size - minimum(T_count, T_size);
}


//- Base class for integer sequences.

template<std::size_t T_position, typename T_Sequence>
struct IntegerSequenceBase;

template<std::size_t T_position, typename T, T T_first, T ... T_others>
struct IntegerSequenceBase<T_position, IntegerSequence<T, T_first, T_others ...>>
{
    using type = ConcatenateT<
        IntegerSequence<T, T_first>,
        typename IntegerSequenceBase<
            T_position - 1,
            IntegerSequence<T, T_others ...>
        >::type
    >;
};

template<typename T, T T_first, T ... T_others>
struct IntegerSequenceBase<0, IntegerSequence<T, T_first, T_others ...>>
{
    using type = IntegerSequence<T>;
};


//- Base class for parameter packs.

template<std::size_t T_position, typename T_Sequence>
struct ParameterPackBase;

template<std::size_t T_position, typename T_First, typename ... T_Others>
struct ParameterPackBase<T_position, ParameterPack<T_First, T_Others ...>>
{
    using type = ConcatenateT<
        ParameterPack<T_First>,
        typename ParameterPackBase<
            T_position - 1,
            ParameterPack<T_Others ...>
        >::type
    >;
};

template<typename T_First, typename ... T_Others>
struct ParameterPackBase<0, ParameterPack<T_First, T_Others ...>>
{
    using type = ParameterPack<>;
};

} // namespace _popback.


//- Traits.

template<std::size_t T_count, typename T_Sequence>
struct PopBack;

template<std::size_t T_count, typename T, T ... T_values>
struct PopBack<T_count, IntegerSequence<T, T_values ...>>
    : public _popback::IntegerSequenceBase<
          _popback::position<T_count, sizeof ... (T_values)>(),
          IntegerSequence<T, T_values ...>
      >
{};

template<typename T, T T_first, T ... T_others>
struct PopBack<0, IntegerSequence<T, T_first, T_others ...>>
{
    using type = IntegerSequence<T, T_first, T_others ...>;
};

template<std::size_t T_count, typename T>
struct PopBack<T_count, IntegerSequence<T>>
{
    using type = IntegerSequence<T>;
};

template<std::size_t T_count, typename ... T>
struct PopBack<T_count, ParameterPack<T ...>>
    : public _popback::ParameterPackBase<
          _popback::position<T_count, sizeof ... (T)>(),
          ParameterPack<T ...>
      >
{};

template<typename T_First, typename ... T_Others>
struct PopBack<0, ParameterPack<T_First, T_Others ...>>
{
    using type = ParameterPack<T_First, T_Others ...>;
};

template<std::size_t T_count>
struct PopBack<T_count, ParameterPack<>>
{
    using type = ParameterPack<>;
};


//- Aliases.

template<std::size_t T_count, typename T_Sequence>
using PopBackT = typename PopBack<T_count, T_Sequence>::type;

template<std::size_t T_count, typename T, T ... T_values>
using PopBackIntegerPack = PopBack<T_count, IntegerSequence<T, T_values...>>;

template<std::size_t T_count, typename T, T ... T_values>
using PopBackIntegerPackT = 
  typename PopBackIntegerPack<T_count, T, T_values ...>::type;

template<std::size_t T_count, std::size_t ... T_values>
using PopBackIndexPack = PopBack<T_count, IndexSequence<T_values...>>;

template<std::size_t T_count, std::size_t ... T_values>
using PopBackIndexPackT = typename PopBackIndexPack<T_count, T_values ...>::type;

} // namespace m3ta.

#endif // M3TA_POPBACK_H
