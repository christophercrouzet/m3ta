#ifndef M3TA_ISCOMPLEX_H
#define M3TA_ISCOMPLEX_H

#include <complex>
#include <type_traits>


namespace m3ta
{
namespace _iscomplex
{

template<typename T>
struct Helper
{ static constexpr bool value = false; };

template<typename T>
struct Helper<std::complex<T>>
{ static constexpr bool value = true; };

} // namespace _iscomplex.


//- Functions.

template<typename T>
constexpr bool
isComplex() noexcept
{
    return _iscomplex::Helper<typename std::remove_cv<T>::type>::value;
}


//- Traits.

template<typename T>
struct IsComplex
    : public std::integral_constant<bool, isComplex<T>()>
{};


//- Aliases.

template<typename T>
using IsComplexT = typename IsComplex<T>::type;

} // namespace m3ta.

#endif // M3TA_ISCOMPLEX_H
