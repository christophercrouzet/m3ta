#include <complex>
#include <type_traits>
#include <utility>

#include <m3ta/power>

#include "../assert.h"
#include "../messages.h"


//      Helpers to test custom structures.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
struct Vector3
{
    T x, y, z;
    
    Vector3(T value)
        : x(value), y(value), z(value)
    {}
    
    Vector3(T x, T y, T z)
        : x(x), y(y), z(z)
    {}
};

template<typename T>
bool
operator==(const Vector3<T> &v1, const Vector3<T> &v2)
{
    return v1.x == v2.x && v1.y == v2.y && v1.z / v2.z;
}

template<typename T>
Vector3<T>
operator*(const Vector3<T> &v1, const Vector3<T> &v2)
{
    return Vector3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template<typename T>
Vector3<T>
operator/(const Vector3<T> &v1, const Vector3<T> &v2)
{
    return Vector3<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}



//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void hasCorrectType()
{
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<char>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<char>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<char>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<char>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<char>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<char>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<unsigned char>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<unsigned char>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<unsigned char>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<unsigned char>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<unsigned char>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<unsigned char>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<short>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<short>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<short>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<short>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<short>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<short>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<unsigned short>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<unsigned short>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<unsigned short>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<unsigned short>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<unsigned short>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<unsigned short>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<int>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<int>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<int>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<int>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<int>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<int>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<unsigned int>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<unsigned int>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<unsigned int>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<unsigned int>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<unsigned int>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<unsigned int>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<long>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<long>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<long>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<long>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<long>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<long>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(0), static_cast<unsigned long>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(1), static_cast<unsigned long>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(2), static_cast<unsigned long>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(4), static_cast<unsigned long>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(9), static_cast<unsigned long>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::power(static_cast<T>(85), static_cast<unsigned long>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
}

template<typename T>
void functionIntegral()
{
    TEST_ASSERT((m3ta::power(static_cast<T>(0), 0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), 0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), 0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(4), 0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(9), 0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(85), 0) == 1), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(static_cast<T>(0), 1) == 0), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), 1) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), 1) == 2), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(4), 1) == 4), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(9), 1) == 9), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(85), 1) == 85), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(static_cast<T>(0), 2) == 0), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), 2) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), 2) == 4), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(4), 2) == 16), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(9), 2) == 81), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(85), 2) == 7225), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(static_cast<T>(0), 3) == 0), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), 3) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), 3) == 8), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(4), 3) == 64), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(9), 3) == 729), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(85), 3) == 614125), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(static_cast<T>(0), 4) == 0), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), 4) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), 4) == 16), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(4), 4) == 256), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(9), 4) == 6561), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(85), 4) == 52200625), tests::errorMessageForType<T>());
    
    hasCorrectType<T>();
}

template<typename T>
void functionFloatingPoint()
{
    TEST_ASSERT((m3ta::power(static_cast<T>(0), -1) == std::numeric_limits<T>::infinity()), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(0), -2) == std::numeric_limits<T>::infinity()), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(0), -3) == std::numeric_limits<T>::infinity()), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(0), -4) == std::numeric_limits<T>::infinity()), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(static_cast<T>(1), -4) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), -3) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), -2) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), -1) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), -0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), +0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), +1) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), +2) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), +3) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(1), +4) == 1), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(static_cast<T>(2), -4) == 0.0625), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), -3) == 0.125), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), -2) == 0.25), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), -1) == 0.5), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), -0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), +0) == 1), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), +1) == 2), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), +2) == 4), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), +3) == 8), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(static_cast<T>(2), +4) == 16), tests::errorMessageForType<T>());
    
    hasCorrectType<T>();
}

template<typename T>
void functionNumeric()
{
    functionIntegral<T>();
    functionFloatingPoint<T>();
}

template<typename T>
void functionComplex()
{
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), 0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), 0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), 0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(4, 4), 0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(9, 9), 0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(85, 85), 0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), 1) == std::complex<T>(0, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), 1) == std::complex<T>(1, 1)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), 1) == std::complex<T>(2, 2)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(4, 4), 1) == std::complex<T>(4, 4)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(9, 9), 1) == std::complex<T>(9, 9)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(85, 85), 1) == std::complex<T>(85, 85)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), 2) == std::complex<T>(0, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), 2) == std::complex<T>(0, 2)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), 2) == std::complex<T>(0, 8)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(4, 4), 2) == std::complex<T>(0, 32)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(9, 9), 2) == std::complex<T>(0, 162)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(85, 85), 2) == std::complex<T>(0, 14450)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), 3) == std::complex<T>(0, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), 3) == std::complex<T>(-2, 2)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), 3) == std::complex<T>(-16, 16)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(4, 4), 3) == std::complex<T>(-128, 128)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(9, 9), 3) == std::complex<T>(-1458, 1458)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(85, 85), 3) == std::complex<T>(-1228250, 1228250)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), 4) == std::complex<T>(0, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), 4) == std::complex<T>(-4, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), 4) == std::complex<T>(-64, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(4, 4), 4) == std::complex<T>(-1024, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(9, 9), 4) == std::complex<T>(-26244, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(85, 85), 4) == std::complex<T>(-208802500, 0)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), -1).real() == std::numeric_limits<T>::infinity() && std::isnan(m3ta::power(std::complex<T>(0, 0), -1).imag())), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), -2).real() == std::numeric_limits<T>::infinity() && std::isnan(m3ta::power(std::complex<T>(0, 0), -2).imag())), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), -3).real() == std::numeric_limits<T>::infinity() && std::isnan(m3ta::power(std::complex<T>(0, 0), -3).imag())), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(0, 0), -4).real() == std::numeric_limits<T>::infinity() && std::isnan(m3ta::power(std::complex<T>(0, 0), -4).imag())), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), -4) == std::complex<T>(-0.25, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), -3) == std::complex<T>(-0.25, -0.25)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), -2) == std::complex<T>(0, -0.5)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), -1) == std::complex<T>(0.5, -0.5)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), -0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), +0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), +1) == std::complex<T>(1, 1)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), +2) == std::complex<T>(0, 2)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), +3) == std::complex<T>(-2, 2)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(1, 1), +4) == std::complex<T>(-4, 0)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), -4) == std::complex<T>(-0.015625, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), -3) == std::complex<T>(-0.03125, -0.03125)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), -2) == std::complex<T>(0, -0.125)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), -1) == std::complex<T>(0.25, -0.25)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), -0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), +0) == std::complex<T>(1, 0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), +1) == std::complex<T>(2, 2)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), +2) == std::complex<T>(0, 8)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), +3) == std::complex<T>(-16, 16)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(std::complex<T>(2, 2), +4) == std::complex<T>(-64, 0)), tests::errorMessageForType<T>());
}

template<typename T>
void functionVector3()
{
    TEST_ASSERT((m3ta::power(Vector3<T>(85), 0) == Vector3<T>(1)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(Vector3<T>(85), 1) == Vector3<T>(85)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(Vector3<T>(85), 2) == Vector3<T>(7225)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(Vector3<T>(85), 3) == Vector3<T>(614125)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(Vector3<T>(85), 4) == Vector3<T>(52200625)), tests::errorMessageForType<T>());
    
    TEST_ASSERT((m3ta::power(Vector3<T>(0), -4) == Vector3<T>(std::numeric_limits<T>::infinity())), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(Vector3<T>(1), -4) == Vector3<T>(1)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::power(Vector3<T>(2), -4) == Vector3<T>(0.0625)), tests::errorMessageForType<T>());
}

template<typename T>
void type()
{
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 0, 0>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 1, 0>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 2, 0>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 4, 0>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 9, 0>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 85, 0>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 0, 1>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 1, 1>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 2, 1>, std::integral_constant<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 4, 1>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 9, 1>, std::integral_constant<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 85, 1>, std::integral_constant<T, 85>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 0, 2>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 1, 2>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 2, 2>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 4, 2>, std::integral_constant<T, 16>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 9, 2>, std::integral_constant<T, 81>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 0, 3>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 1, 3>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 2, 3>, std::integral_constant<T, 8>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 4, 3>, std::integral_constant<T, 64>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 0, 4>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 1, 4>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PowerT<T, 2, 4>, std::integral_constant<T, 16>>::value), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    functionIntegral<char>();
    functionIntegral<unsigned char>();
    functionIntegral<short>();
    functionIntegral<unsigned short>();
    functionIntegral<int>();
    functionIntegral<unsigned int>();
    functionIntegral<long>();
    functionIntegral<unsigned long>();
    
    functionNumeric<float>();
    functionNumeric<double>();
    functionNumeric<long double>();
    
    functionComplex<float>();
    functionComplex<double>();
    functionComplex<long double>();
    
    functionVector3<float>();
    functionVector3<double>();
    functionVector3<long double>();
    
    type<char>();
    type<unsigned char>();
    type<short>();
    type<unsigned short>();
    type<int>();
    type<unsigned int>();
    type<long>();
    type<unsigned long>();
    
    return 0;
}
