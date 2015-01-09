#include <type_traits>

#include <m3ta/popintegersequence>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void typeIntegral()
{
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T>, 0>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0>, 0>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 1>, 0>, m3ta::IntegerSequence<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 1>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 1>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 1>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 1>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 1>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 2>, 0>, m3ta::IntegerSequence<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 2>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 2>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 2>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 2>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 2>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 4>, 0>, m3ta::IntegerSequence<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 4>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 4>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 4>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 4>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 4>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 9>, 0>, m3ta::IntegerSequence<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 9>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 9>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 9>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 9>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 9>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 85>, 0>, m3ta::IntegerSequence<T, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 85>, 1>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 85>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 85>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 85>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 85>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1>, 0>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1>, 1>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1>, 2>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2>, 0>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2>, 1>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2>, 2>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4>, 0>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4>, 1>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4>, 2>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4>, 4>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>, 0>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>, 1>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>, 2>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>, 4>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>, 0>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>, 1>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>, 2>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>, 4>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>, 9>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>, 85>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
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
