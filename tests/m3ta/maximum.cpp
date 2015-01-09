#include <type_traits>

#include <m3ta/maximum>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void functionNumeric()
{
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(0)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(1), static_cast<T>(1)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(2), static_cast<T>(2)) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(4), static_cast<T>(4)) == 4, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(9), static_cast<T>(9)) == 9, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(85), static_cast<T>(85)) == 85, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(1)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(2)) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(4)) == 4, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(9)) == 9, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(85)) == 85, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::maximum(static_cast<T>(0), static_cast<T>(85)) == 85, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(1), static_cast<T>(9)) == 9, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(2), static_cast<T>(4)) == 4, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(4), static_cast<T>(2)) == 4, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(9), static_cast<T>(1)) == 9, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::maximum(static_cast<T>(85), static_cast<T>(0)) == 85, tests::errorMessageForType<T>());
}

template<typename T>
void typeIntegral()
{
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 0>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 1, 1>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 2, 2>, std::integral_constant<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 4, 4>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 9, 9>, std::integral_constant<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 85, 85>, std::integral_constant<T, 85>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 1>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 2>, std::integral_constant<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 4>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 9>, std::integral_constant<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 85>, std::integral_constant<T, 85>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 0, 85>, std::integral_constant<T, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 1, 9>, std::integral_constant<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 2, 4>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 4, 2>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 9, 1>, std::integral_constant<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::MaximumT<T, 85, 0>, std::integral_constant<T, 85>>::value), tests::errorMessageForType<T>());
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
    
    typeIntegral<char>();
    typeIntegral<unsigned char>();
    typeIntegral<short>();
    typeIntegral<unsigned short>();
    typeIntegral<int>();
    typeIntegral<unsigned int>();
    typeIntegral<long>();
    typeIntegral<unsigned long>();
    
    return 0;
}
