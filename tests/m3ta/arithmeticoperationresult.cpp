#include <type_traits>
#include <utility>

#include <m3ta/arithmeticoperationresult>

#include "../assert.h"
#include "../messages.h"


//      Helpers to test the associativity.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

struct X {};
struct Y {};
struct Z {};

X operator+(const X &, const Y &);
Y operator+(const Y &, const Z &);
Z operator+(const X &, const Z &);

Y operator-(const X &, const Y &);
Z operator-(const Y &, const Z &);
X operator-(const X &, const Z &);

Z operator*(const X &, const Y &);
Y operator*(const Y &, const Z &);
X operator*(const Z &, const Z &);

Y operator/(const X &, const Y &);
X operator/(const Y &, const Z &);
Z operator/(const X &, const Z &);



//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void typeNumeric()
{
    //- Addition.
    
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, T>, decltype(std::declval<T>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, T, T>, decltype(std::declval<T>() + std::declval<T>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, T, T, T>, decltype(std::declval<T>() + std::declval<T>() + std::declval<T>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, char>, decltype(std::declval<T>() + std::declval<char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, unsigned char>, decltype(std::declval<T>() + std::declval<unsigned char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, short>, decltype(std::declval<T>() + std::declval<short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, unsigned short>, decltype(std::declval<T>() + std::declval<unsigned short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, int>, decltype(std::declval<T>() + std::declval<int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, unsigned int>, decltype(std::declval<T>() + std::declval<unsigned int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, long>, decltype(std::declval<T>() + std::declval<long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, unsigned long>, decltype(std::declval<T>() + std::declval<unsigned long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, float>, decltype(std::declval<T>() + std::declval<float>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, double>, decltype(std::declval<T>() + std::declval<double>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, long double>, decltype(std::declval<T>() + std::declval<long double>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<char, T>, decltype(std::declval<char>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<unsigned char, T>, decltype(std::declval<unsigned char>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<short, T>, decltype(std::declval<short>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<unsigned short, T>, decltype(std::declval<unsigned short>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<int, T>, decltype(std::declval<int>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<unsigned int, T>, decltype(std::declval<unsigned int>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<long, T>, decltype(std::declval<long>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<unsigned long, T>, decltype(std::declval<unsigned long>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<float, T>, decltype(std::declval<float>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<double, T>, decltype(std::declval<double>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<long double, T>, decltype(std::declval<long double>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    
    //- Subtraction.
    
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, T>, decltype(std::declval<T>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, T, T>, decltype(std::declval<T>() - std::declval<T>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, T, T, T>, decltype(std::declval<T>() - std::declval<T>() - std::declval<T>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, char>, decltype(std::declval<T>() - std::declval<char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, unsigned char>, decltype(std::declval<T>() - std::declval<unsigned char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, short>, decltype(std::declval<T>() - std::declval<short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, unsigned short>, decltype(std::declval<T>() - std::declval<unsigned short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, int>, decltype(std::declval<T>() - std::declval<int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, unsigned int>, decltype(std::declval<T>() - std::declval<unsigned int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, long>, decltype(std::declval<T>() - std::declval<long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, unsigned long>, decltype(std::declval<T>() - std::declval<unsigned long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, float>, decltype(std::declval<T>() - std::declval<float>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, double>, decltype(std::declval<T>() - std::declval<double>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, long double>, decltype(std::declval<T>() - std::declval<long double>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<char, T>, decltype(std::declval<char>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<unsigned char, T>, decltype(std::declval<unsigned char>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<short, T>, decltype(std::declval<short>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<unsigned short, T>, decltype(std::declval<unsigned short>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<int, T>, decltype(std::declval<int>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<unsigned int, T>, decltype(std::declval<unsigned int>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<long, T>, decltype(std::declval<long>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<unsigned long, T>, decltype(std::declval<unsigned long>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<float, T>, decltype(std::declval<float>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<double, T>, decltype(std::declval<double>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<long double, T>, decltype(std::declval<long double>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    
    //- Multiplication.
    
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, T>, decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, T, T>, decltype(std::declval<T>() * std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, T, T, T>, decltype(std::declval<T>() * std::declval<T>() * std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, char>, decltype(std::declval<T>() * std::declval<char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, unsigned char>, decltype(std::declval<T>() * std::declval<unsigned char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, short>, decltype(std::declval<T>() * std::declval<short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, unsigned short>, decltype(std::declval<T>() * std::declval<unsigned short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, int>, decltype(std::declval<T>() * std::declval<int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, unsigned int>, decltype(std::declval<T>() * std::declval<unsigned int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, long>, decltype(std::declval<T>() * std::declval<long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, unsigned long>, decltype(std::declval<T>() * std::declval<unsigned long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, float>, decltype(std::declval<T>() * std::declval<float>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, double>, decltype(std::declval<T>() * std::declval<double>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, long double>, decltype(std::declval<T>() * std::declval<long double>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<char, T>, decltype(std::declval<char>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<unsigned char, T>, decltype(std::declval<unsigned char>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<short, T>, decltype(std::declval<short>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<unsigned short, T>, decltype(std::declval<unsigned short>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<int, T>, decltype(std::declval<int>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<unsigned int, T>, decltype(std::declval<unsigned int>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<long, T>, decltype(std::declval<long>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<unsigned long, T>, decltype(std::declval<unsigned long>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<float, T>, decltype(std::declval<float>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<double, T>, decltype(std::declval<double>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<long double, T>, decltype(std::declval<long double>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    
    //- Division.
    
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, T>, decltype(std::declval<T>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, T, T>, decltype(std::declval<T>() / std::declval<T>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, T, T, T>, decltype(std::declval<T>() / std::declval<T>() / std::declval<T>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, char>, decltype(std::declval<T>() / std::declval<char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, unsigned char>, decltype(std::declval<T>() / std::declval<unsigned char>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, short>, decltype(std::declval<T>() / std::declval<short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, unsigned short>, decltype(std::declval<T>() / std::declval<unsigned short>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, int>, decltype(std::declval<T>() / std::declval<int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, unsigned int>, decltype(std::declval<T>() / std::declval<unsigned int>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, long>, decltype(std::declval<T>() / std::declval<long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, unsigned long>, decltype(std::declval<T>() / std::declval<unsigned long>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, float>, decltype(std::declval<T>() / std::declval<float>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, double>, decltype(std::declval<T>() / std::declval<double>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, long double>, decltype(std::declval<T>() / std::declval<long double>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<char, T>, decltype(std::declval<char>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<unsigned char, T>, decltype(std::declval<unsigned char>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<short, T>, decltype(std::declval<short>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<unsigned short, T>, decltype(std::declval<unsigned short>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<int, T>, decltype(std::declval<int>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<unsigned int, T>, decltype(std::declval<unsigned int>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<long, T>, decltype(std::declval<long>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<unsigned long, T>, decltype(std::declval<unsigned long>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<float, T>, decltype(std::declval<float>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<double, T>, decltype(std::declval<double>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<long double, T>, decltype(std::declval<long double>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
}

template<typename T>
void typeComplex()
{
    //- Addition.
    
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<std::complex<T>>, std::complex<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() + std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() + std::declval<std::complex<T>>() + std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<std::complex<T>, std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() + std::declval<std::complex<T>>() + std::declval<std::complex<T>>() + std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<std::complex<T>, T>, decltype(std::declval<std::complex<T>>() + std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<T, std::complex<T>>, decltype(std::declval<T>() + std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    
    //- Subtraction.
    
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<std::complex<T>>, std::complex<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() - std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() - std::declval<std::complex<T>>() - std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<std::complex<T>, std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() - std::declval<std::complex<T>>() - std::declval<std::complex<T>>() - std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<std::complex<T>, T>, decltype(std::declval<std::complex<T>>() - std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<T, std::complex<T>>, decltype(std::declval<T>() - std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    
    //- Multiplication.
    
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<std::complex<T>>, std::complex<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() * std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() * std::declval<std::complex<T>>() * std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<std::complex<T>, std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() * std::declval<std::complex<T>>() * std::declval<std::complex<T>>() * std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<std::complex<T>, T>, decltype(std::declval<std::complex<T>>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<T, std::complex<T>>, decltype(std::declval<T>() * std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    
    //- Division.
    
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<std::complex<T>>, std::complex<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() / std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() / std::declval<std::complex<T>>() / std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<std::complex<T>, std::complex<T>, std::complex<T>, std::complex<T>>, decltype(std::declval<std::complex<T>>() / std::declval<std::complex<T>>() / std::declval<std::complex<T>>() / std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<std::complex<T>, T>, decltype(std::declval<std::complex<T>>() / std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<T, std::complex<T>>, decltype(std::declval<T>() / std::declval<std::complex<T>>())>::value), tests::errorMessageForType<T>());
}

void associativity()
{
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<X, Y, Z>, decltype(std::declval<X>() + std::declval<Y>() + std::declval<Z>())>::value));
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<X, Y, Z>, decltype(std::declval<X>() - std::declval<Y>() - std::declval<Z>())>::value));
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<X, Y, Z>, decltype(std::declval<X>() * std::declval<Y>() * std::declval<Z>())>::value));
    TEST_ASSERT((std::is_same<m3ta::DivisionResultT<X, Y, Z>, decltype(std::declval<X>() / std::declval<Y>() / std::declval<Z>())>::value));
    
    // Double-check.
    TEST_ASSERT((std::is_same<m3ta::AdditionResultT<X, Y, Z>, Z>::value)); // Would be `X` with a right-to-left associativity.
    TEST_ASSERT((std::is_same<m3ta::SubtractionResultT<X, Y, Z>, Z>::value)); // Would be `X` with a right-to-left associativity.
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<X, Y, Z>, X>::value)); // Would be `Z` with a right-to-left associativity.
    TEST_ASSERT((std::is_same<m3ta::MultiplicationResultT<X, Y, Z>, X>::value)); // Would be `Z` with a right-to-left associativity.
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    typeNumeric<char>();
    typeNumeric<unsigned char>();
    typeNumeric<short>();
    typeNumeric<unsigned short>();
    typeNumeric<int>();
    typeNumeric<unsigned int>();
    typeNumeric<long>();
    typeNumeric<unsigned long>();
    typeNumeric<float>();
    typeNumeric<double>();
    typeNumeric<long double>();
    
    typeComplex<float>();
    typeComplex<double>();
    typeComplex<long double>();
    
    associativity();
    
    return 0;
}
