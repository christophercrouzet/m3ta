#include <type_traits>

#include <m3ta/all>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

void functionBool()
{
    TEST_ASSERT(m3ta::all(true) == true);
    TEST_ASSERT(m3ta::all(true, true) == true);
    TEST_ASSERT(m3ta::all(true, true, true) == true);
    TEST_ASSERT(m3ta::all(false) == false);
    TEST_ASSERT(m3ta::all(false, false) == false);
    TEST_ASSERT(m3ta::all(false, false, false) == false);
    TEST_ASSERT(m3ta::all(true, false) == false);
    TEST_ASSERT(m3ta::all(false, true) == false);
    TEST_ASSERT(m3ta::all(true, true, false) == false);
    TEST_ASSERT(m3ta::all(false, true, true) == false);
}

template<typename T>
void functionNumeric()
{
    TEST_ASSERT(m3ta::all() == true, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::all(static_cast<T>(0)) == false, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(0), static_cast<T>(1)) == false, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2)) == false, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2), static_cast<T>(4)) == false, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2), static_cast<T>(4), static_cast<T>(9)) == false, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(0), static_cast<T>(1), static_cast<T>(2), static_cast<T>(4), static_cast<T>(9), static_cast<T>(85)) == false, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::all(static_cast<T>(85)) == true, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(85), static_cast<T>(9)) == true, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(85), static_cast<T>(9), static_cast<T>(4)) == true, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(85), static_cast<T>(9), static_cast<T>(4), static_cast<T>(2)) == true, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(85), static_cast<T>(9), static_cast<T>(4), static_cast<T>(2), static_cast<T>(1)) == true, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::all(static_cast<T>(85), static_cast<T>(9), static_cast<T>(4), static_cast<T>(2), static_cast<T>(1), static_cast<T>(0)) == false, tests::errorMessageForType<T>());
}

void functionMixed()
{
    TEST_ASSERT(m3ta::all(true, 1, 2L, 4.0f, 9.0, 85.0L) == true);
    TEST_ASSERT(m3ta::all(false, 1, 2L, 4.0f, 9.0, 85.0L) == false);
    TEST_ASSERT(m3ta::all(true, 0, 2L, 4.0f, 9.0, 85.0L) == false);
    TEST_ASSERT(m3ta::all(true, 1, 0L, 4.0f, 9.0, 85.0L) == false);
    TEST_ASSERT(m3ta::all(true, 1, 2L, 0.0f, 9.0, 85.0L) == false);
    TEST_ASSERT(m3ta::all(true, 1, 2L, 4.0f, 0.0, 85.0L) == false);
    TEST_ASSERT(m3ta::all(true, 1, 2L, 4.0f, 9.0, 0.0L) == false);
}

void typeBool()
{
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, true>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, true, true>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, true, true, true>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, false>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, false, false>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, false, false, false>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, true, false>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, false, true>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, true, true, false>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::AllT<bool, false, true, true>, std::integral_constant<bool, false>>::value));
}

template<typename T>
void typeIntegral()
{
    TEST_ASSERT((std::is_same<m3ta::AllT<T>, std::integral_constant<bool, true>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 0>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 0, 1>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 0, 1, 2>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 0, 1, 2, 4>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 0, 1, 2, 4, 9>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 0, 1, 2, 4, 9, 85>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 85>, std::integral_constant<bool, true>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 85, 9>, std::integral_constant<bool, true>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 85, 9, 4>, std::integral_constant<bool, true>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 85, 9, 4, 2>, std::integral_constant<bool, true>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 85, 9, 4, 2, 1>, std::integral_constant<bool, true>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::AllT<T, 85, 9, 4, 2, 1, 0>, std::integral_constant<bool, false>>::value), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    functionBool();
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
    functionMixed();
    
    typeBool();
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
