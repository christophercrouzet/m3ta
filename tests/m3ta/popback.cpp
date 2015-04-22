#include <type_traits>

#include <m3ta/integersequence>
#include <m3ta/parameterpack>
#include <m3ta/popback>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void typeForIntegerSequence()
{
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 0>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 0, 1>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 0, 1, 2>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 0, 1, 2, 4>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0, 1, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1, 2, 4>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T, 0, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::IntegerSequence<T, 0, 1, 2, 4, 9, 85>>, m3ta::IntegerSequence<T>>::value), tests::errorMessageForType<T>());
}

void typeForParameterPack()
{
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<char>>, m3ta::ParameterPack<char>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<char>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<char>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<char>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<char>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<char>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<char, short>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<char>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<char, short>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<char, short, int>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<char, short>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<char>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<char, short, int>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<char, short, int, long>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<char, short, int>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<char, short>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<char, short, int, long>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<char, short, int, long, float>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<char, short, int, long>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<char, short, int>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<char>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<char, short, int, long, float>>, m3ta::ParameterPack<>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::PopBackT<0, m3ta::ParameterPack<char, short, int, long, float, double>>, m3ta::ParameterPack<char, short, int, long, float, double>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<1, m3ta::ParameterPack<char, short, int, long, float, double>>, m3ta::ParameterPack<char, short, int, long, float>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<2, m3ta::ParameterPack<char, short, int, long, float, double>>, m3ta::ParameterPack<char, short, int, long>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<4, m3ta::ParameterPack<char, short, int, long, float, double>>, m3ta::ParameterPack<char, short>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<9, m3ta::ParameterPack<char, short, int, long, float, double>>, m3ta::ParameterPack<>>::value));
    TEST_ASSERT((std::is_same<m3ta::PopBackT<85, m3ta::ParameterPack<char, short, int, long, float, double>>, m3ta::ParameterPack<>>::value));
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
