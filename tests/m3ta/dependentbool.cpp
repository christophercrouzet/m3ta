#include <m3ta/dependentbool>

#include "../assert.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

void function()
{
    TEST_ASSERT((m3ta::dependentBool<int>(false) == false));
    TEST_ASSERT((m3ta::dependentBool<short, long>(false) == false));
    TEST_ASSERT((m3ta::dependentBool<int>(true) == true));
    TEST_ASSERT((m3ta::dependentBool<short, long>(true) == true));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    function();
    return 0;
}
