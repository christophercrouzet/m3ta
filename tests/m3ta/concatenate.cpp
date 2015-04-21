#include <type_traits>

#include <m3ta/concatenate>
#include <m3ta/integersequence>
#include <m3ta/parameterpack>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void typeForIntegerSequence()
{
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 0>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 1>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 2>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 4>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 9>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 85>, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T>, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T, 85>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 0>, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 0, 2>, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T, 0, 2, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 0, 2>, m3ta::IntegerSequence<T, 1, 4>>, m3ta::IntegerSequence<T, 0, 2, 1, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 0, 2, 9>, m3ta::IntegerSequence<T, 1, 4>>, m3ta::IntegerSequence<T, 0, 2, 9, 1, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::IntegerSequence<T, 0, 2, 9>, m3ta::IntegerSequence<T, 1, 4, 85>>, m3ta::IntegerSequence<T, 0, 2, 9, 1, 4, 85>>::value), tests::errorMessageForType<T>());
}

void typeForParameterPack()
{
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<>, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<bool>, m3ta::ParameterPack<>>, m3ta::ParameterPack<bool>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<>, m3ta::ParameterPack<bool>>, m3ta::ParameterPack<bool>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<char>, m3ta::ParameterPack<short>>, m3ta::ParameterPack<char, short>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<char, int>, m3ta::ParameterPack<short>>, m3ta::ParameterPack<char, int, short>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<char, int>, m3ta::ParameterPack<short, long>>, m3ta::ParameterPack<char, int, short, long>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<char, int, float>, m3ta::ParameterPack<short, long>>, m3ta::ParameterPack<char, int, float, short, long>>::value));
    TEST_ASSERT((std::is_same<m3ta::ConcatenateT<m3ta::ParameterPack<char, int, float>, m3ta::ParameterPack<short, long, double>>, m3ta::ParameterPack<char, int, float, short, long, double>>::value));
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
