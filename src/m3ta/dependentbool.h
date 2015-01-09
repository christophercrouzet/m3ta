#ifndef M3TA_DEPENDENTBOOL_H
#define M3TA_DEPENDENTBOOL_H


namespace m3ta
{

//- Functions.

template<typename ...>
constexpr bool
dependentBool(bool value) noexcept
{
    return value;
}

} // namespace m3ta.

#endif // M3TA_DEPENDENTBOOL_H
