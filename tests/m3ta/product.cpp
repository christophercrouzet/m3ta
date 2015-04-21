#include <complex>
#include <limits>
#include <type_traits>
#include <utility>

#include <m3ta/product>

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



//      Helpers to test the associativity.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

struct X { int value; };
struct Y { int value; };
struct Z { int value; };

Z operator*(const X &a, const Y &b) { return Z{a.value + b.value}; }
Y operator*(const Y &a, const Z &b) { return Y{a.value - b.value}; }
X operator*(const Z &a, const Z &b) { return X{a.value * b.value}; }



//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void functionNumeric()
{
    TEST_ASSERT(m3ta::product(static_cast<T>(0)) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::product(static_cast<T>(0), static_cast<T>(1)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2), static_cast<T>(4)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2), static_cast<T>(4), static_cast<T>(9)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2), static_cast<T>(4), static_cast<T>(9), static_cast<T>(85)) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::product(static_cast<T>(1)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(1), static_cast<T>(2)) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(1), static_cast<T>(2), static_cast<T>(4)) == 8, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(1), static_cast<T>(2), static_cast<T>(4), static_cast<T>(9)) == 72, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(1), static_cast<T>(2), static_cast<T>(4), static_cast<T>(9), static_cast<T>(85)) == 6120, tests::errorMessageForType<T>());
    
    // Make sure the result has the correct type.
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(0))), T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(0), static_cast<T>(85))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(1), static_cast<T>(9))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(2), static_cast<T>(4))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(4), static_cast<T>(2))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(9), static_cast<T>(1))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<decltype(m3ta::product(static_cast<T>(85), static_cast<T>(0))), decltype(std::declval<T>() * std::declval<T>())>::value), tests::errorMessageForType<T>());
}

template<typename T>
void functionComplex()
{
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0), std::complex<T>(1, 1)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0), std::complex<T>(1, 1), std::complex<T>(2, 2)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0), std::complex<T>(1, 1), std::complex<T>(2, 2), std::complex<T>(4, 4)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0), std::complex<T>(1, 1), std::complex<T>(2, 2), std::complex<T>(4, 4), std::complex<T>(9, 9)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0), std::complex<T>(1, 1), std::complex<T>(2, 2), std::complex<T>(4, 4), std::complex<T>(9, 9), std::complex<T>(85, 85)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::product(std::complex<T>(1, 1)) == std::complex<T>(1, 1), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(1, 1), std::complex<T>(2, 2)) == std::complex<T>(0, 4), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(1, 1), std::complex<T>(2, 2), std::complex<T>(4, 4)) == std::complex<T>(-16, 16), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(1, 1), std::complex<T>(2, 2), std::complex<T>(4, 4), std::complex<T>(9, 9)) == std::complex<T>(-288, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(1, 1), std::complex<T>(2, 2), std::complex<T>(4, 4), std::complex<T>(9, 9), std::complex<T>(85, 85)) == std::complex<T>(-24480, -24480), tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::product(static_cast<T>(85), std::complex<T>(0, 0)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(9), std::complex<T>(1, 1)) == std::complex<T>(9, 9), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(4), std::complex<T>(2, 2)) == std::complex<T>(8, 8), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(2), std::complex<T>(4, 4)) == std::complex<T>(8, 8), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(1), std::complex<T>(9, 9)) == std::complex<T>(9, 9), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(static_cast<T>(0), std::complex<T>(85, 85)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::product(std::complex<T>(0, 0), static_cast<T>(85)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(1, 1), static_cast<T>(9)) == std::complex<T>(9, 9), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(2, 2), static_cast<T>(4)) == std::complex<T>(8, 8), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(4, 4), static_cast<T>(2)) == std::complex<T>(8, 8), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(9, 9), static_cast<T>(1)) == std::complex<T>(9, 9), tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::product(std::complex<T>(85, 85), static_cast<T>(0)) == std::complex<T>(0, 0), tests::errorMessageForType<T>());
}

template<typename T>
void functionVector3()
{
    TEST_ASSERT((m3ta::product(Vector3<T>(0), Vector3<T>(1), Vector3<T>(2), Vector3<T>(4), Vector3<T>(9), Vector3<T>(85)) == Vector3<T>(0)), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::product(Vector3<T>(1), Vector3<T>(2), Vector3<T>(4), Vector3<T>(9), Vector3<T>(85)) == Vector3<T>(6120)), tests::errorMessageForType<T>());
}

template<typename T>
void type()
{
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 0>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 0, 1>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 0, 1, 2>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 0, 1, 2, 4>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 0, 1, 2, 4, 9>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 0, 1, 2, 4, 9, 85>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 1>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 1, 2>, std::integral_constant<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 1, 2, 4>, std::integral_constant<T, 8>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ProductT<T, 1, 2, 4, 9>, std::integral_constant<T, 72>>::value), tests::errorMessageForType<T>());
}

void associativity()
{
    X x{2};
    Y y{4};
    Z z{6};
    
    TEST_ASSERT(m3ta::product(x, y, z).value == 36);  // Would be 0 with a right-to-left associativity.
}

void overflow()
{
    TEST_ASSERT(m3ta::product(static_cast<char>(2), std::numeric_limits<char>::max()) == 2 * std::numeric_limits<char>::max());
    TEST_ASSERT(m3ta::product(static_cast<double>(1), static_cast<int>(2), std::numeric_limits<int>::max()) == 2.0 * std::numeric_limits<int>::max());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    functionNumeric<char>();
    functionNumeric<unsigned char>();
    functionNumeric<short>();
    functionNumeric<unsigned short>();
    functionNumeric<int>();
    functionNumeric<unsigned int>();
    functionNumeric<long>();
    functionNumeric<unsigned long>();
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
    
    associativity();
    overflow();
    
    return 0;
}
