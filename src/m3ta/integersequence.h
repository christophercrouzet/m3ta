#ifndef M3TA_INTEGERSEQUENCE_H
#define M3TA_INTEGERSEQUENCE_H

#include <cstddef>
#include <type_traits>


namespace m3ta
{

//- Traits.

template<typename T, T ... T_values>
struct IntegerSequence
{
    static_assert(std::is_integral<T>::value, "Not an integral type.");
    
    using value_type = T;
    
    static constexpr std::size_t
    size() noexcept
    {
        return sizeof ... (T_values);
    };
};


//- Aliases.

template<std::size_t ... T_values>
using IndexSequence = IntegerSequence<std::size_t, T_values ...>;

} // namespace m3ta.

#endif // M3TA_INTEGERSEQUENCE_H
