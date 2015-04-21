#include <m3ta/parameterpack>

#include "../assert.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

void size()
{
    TEST_ASSERT((m3ta::ParameterPack<>::size() == 0));
    TEST_ASSERT((m3ta::ParameterPack<char>::size() == 1));
    TEST_ASSERT((m3ta::ParameterPack<char, short>::size() == 2));
    TEST_ASSERT((m3ta::ParameterPack<char, short, int>::size() == 3));
    TEST_ASSERT((m3ta::ParameterPack<char, short, int, long>::size() == 4));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    size();
    return 0;
}
