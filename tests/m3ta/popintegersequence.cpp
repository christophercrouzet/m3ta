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
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<0, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<1, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<2, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<4, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<9, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopIntegerSequenceT<85, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
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
