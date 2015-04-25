#include <type_traits>

#include <m3ta/front>
#include <m3ta/integersequence>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void typeForIntegerSequence()
{
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, std::integral_constant<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::IntegerSequence<T, 1, 2, 4, 9, 85>>, std::integral_constant<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::IntegerSequence<T, 2, 4, 9, 85>>, std::integral_constant<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::IntegerSequence<T, 4, 9, 85>>, std::integral_constant<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::IntegerSequence<T, 9, 85>>, std::integral_constant<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::IntegerSequence<T, 85>>, std::integral_constant<T, 85>>::value), tests::errorMessageForType<T>());
}

void typeForParameterPack()
{
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::ParameterPack<char, short, int, long, float, double>>, char>::value));
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::ParameterPack<short, int, long, float, double>>, short>::value));
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::ParameterPack<int, long, float, double>>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::ParameterPack<long, float, double>>, long>::value));
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::ParameterPack<float, double>>, float>::value));
    TEST_ASSERT((std::is_same<m3ta::FrontT<m3ta::ParameterPack<double>>, double>::value));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    typeForIntegerSequence<char>();
    typeForIntegerSequence<unsigned char>();
    typeForIntegerSequence<short>();
    typeForIntegerSequence<unsigned short>();
    typeForIntegerSequence<int>();
    typeForIntegerSequence<unsigned int>();
    typeForIntegerSequence<long>();
    typeForIntegerSequence<unsigned long>();
    
    typeForParameterPack();
    
    return 0;
}
