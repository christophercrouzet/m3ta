#ifndef TESTS_TYPENAME_H
#define TESTS_TYPENAME_H

#include <complex>
#include <string>


namespace tests
{

template<typename T>
struct TypeName
{
    static std::string value()
    { return "unknown"; }
};

template<>
struct TypeName<bool>
{
    static std::string value()
    { return "bool"; }
};

template<>
struct TypeName<char>
{
    static std::string value()
    { return "char"; }
};

template<>
struct TypeName<short>
{
    static std::string value()
    { return "short"; }
};

template<>
struct TypeName<int>
{
    static std::string value()
    { return "int"; }
};

template<>
struct TypeName<long>
{
    static std::string value()
    { return "long"; }
};

template<>
struct TypeName<long long>
{
    static std::string value()
    { return "long long"; }
};

template<>
struct TypeName<unsigned char>
{
    static std::string value()
    { return "unsigned char"; }
};

template<>
struct TypeName<unsigned short>
{
    static std::string value()
    { return "unsigned short"; }
};

template<>
struct TypeName<unsigned int>
{
    static std::string value()
    { return "unsigned int"; }
};

template<>
struct TypeName<unsigned long>
{
    static std::string value()
    { return "unsigned long"; }
};

template<>
struct TypeName<unsigned long long>
{
    static std::string value()
    { return "unsigned long long"; }
};

template<>
struct TypeName<float>
{
    static std::string value()
    { return "float"; }
};

template<>
struct TypeName<double>
{
    static std::string value()
    { return "double"; }
};

template<>
struct TypeName<long double>
{
    static std::string value()
    { return "long double"; }
};

template<>
struct TypeName<std::complex<float>>
{
    static std::string value()
    { return "std::complex<float>"; }
};

template<>
struct TypeName<std::complex<double>>
{
    static std::string value()
    { return "std::complex<double>"; }
};

template<>
struct TypeName<std::complex<long double>>
{
    static std::string value()
    { return "std::complex<long double>"; }
};

} // namespace tests.

#endif // TESTS_TYPENAME_H
