#ifndef M3TA_PARAMETERPACK_H
#define M3TA_PARAMETERPACK_H

#include <cstddef>


namespace m3ta
{

//- Traits.

template<typename ... T>
struct ParameterPack
{
    static constexpr std::size_t
    size() noexcept
    {
        return sizeof ... (T);
    }
};

} // namespace m3ta.

#endif // M3TA_PARAMETERPACK_H
