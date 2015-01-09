#include <cstddef>

#include <m3ta/parameterpack>

#include "../assert.h"


//      Helper.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T_ParameterPack>
struct Helper;

template<typename ... T_Values>
struct Helper<m3ta::ParameterPack<T_Values ...>>
{
    static constexpr std::size_t size = sizeof ... (T_Values);
};



//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

void basics()
{
    TEST_ASSERT((Helper<m3ta::ParameterPack<>>::size == 0));
    TEST_ASSERT((Helper<m3ta::ParameterPack<char>>::size == 1));
    TEST_ASSERT((Helper<m3ta::ParameterPack<char, short>>::size == 2));
    TEST_ASSERT((Helper<m3ta::ParameterPack<char, short, int>>::size == 3));
    TEST_ASSERT((Helper<m3ta::ParameterPack<char, short, int, long>>::size == 4));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    basics();
    return 0;
}
