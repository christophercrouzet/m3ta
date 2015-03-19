#include <array>

#include <m3ta/extractintegersequence>
#include <m3ta/integersequence>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void asArrayIntegral()
{
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T>>::asArray() == std::array<T, 0>{}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 0>>::asArray() == std::array<T, 1>{0}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 1>>::asArray() == std::array<T, 1>{1}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 2>>::asArray() == std::array<T, 1>{2}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 4>>::asArray() == std::array<T, 1>{4}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 9>>::asArray() == std::array<T, 1>{9}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 85>>::asArray() == std::array<T, 1>{85}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 0, 1>>::asArray() == std::array<T, 2>{0, 1}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 0, 1, 2>>::asArray() == std::array<T, 3>{0, 1, 2}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 0, 1, 2, 4>>::asArray() == std::array<T, 4>{0, 1, 2, 4}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::asArray() == std::array<T, 5>{0, 1, 2, 4, 9}), tests::errorMessageForType<T>());
    TEST_ASSERT((m3ta::ExtractIntegerSequence<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>::asArray() == std::array<T, 6>{0, 1, 2, 4, 9, 85}), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    asArrayIntegral<char>();
    asArrayIntegral<unsigned char>();
    asArrayIntegral<short>();
    asArrayIntegral<unsigned short>();
    asArrayIntegral<int>();
    asArrayIntegral<unsigned int>();
    asArrayIntegral<long>();
    asArrayIntegral<unsigned long>();
    
    return 0;
}
