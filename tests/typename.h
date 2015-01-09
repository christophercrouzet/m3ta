#ifndef TESTS_TYPENAME_H
#define TESTS_TYPENAME_H

#include <complex>


namespace tests
{

template<typename T>
struct TypeName
{ static constexpr const char *value = "unknown"; };

template<>
struct TypeName<bool>
{ static constexpr const char *value = "bool"; };

template<>
struct TypeName<char>
{ static constexpr const char *value = "char"; };

template<>
struct TypeName<short>
{ static constexpr const char *value = "short"; };

template<>
struct TypeName<int>
{ static constexpr const char *value = "int"; };

template<>
struct TypeName<long>
{ static constexpr const char *value = "long"; };

template<>
struct TypeName<long long>
{ static constexpr const char *value = "long long"; };

template<>
struct TypeName<unsigned char>
{ static constexpr const char *value = "unsigned char"; };

template<>
struct TypeName<unsigned short>
{ static constexpr const char *value = "unsigned short"; };

template<>
struct TypeName<unsigned int>
{ static constexpr const char *value = "unsigned int"; };

template<>
struct TypeName<unsigned long>
{ static constexpr const char *value = "unsigned long"; };

template<>
struct TypeName<unsigned long long>
{ static constexpr const char *value = "unsigned long long"; };

template<>
struct TypeName<float>
{ static constexpr const char *value = "float"; };

template<>
struct TypeName<double>
{ static constexpr const char *value = "double"; };

template<>
struct TypeName<long double>
{ static constexpr const char *value = "long double"; };

template<>
struct TypeName<std::complex<float>>
{ static constexpr const char *value = "std::complex<float>"; };

template<>
struct TypeName<std::complex<double>>
{ static constexpr const char *value = "std::complex<double>"; };

template<>
struct TypeName<std::complex<long double>>
{ static constexpr const char *value = "std::complex<long double>"; };

} // namespace tests.

#endif // TESTS_TYPENAME_H
