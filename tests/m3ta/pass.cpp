#include <type_traits>

#include <m3ta/pass>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void type()
{
    TEST_ASSERT((std::is_same<m3ta::PassT<T>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PassT<T, void>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PassT<T, bool>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PassT<T, int>, T>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::PassT<T, void, bool, int>, T>::value), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    type<void>();
    type<char>();
    type<unsigned char>();
    type<short>();
    type<unsigned short>();
    type<int>();
    type<unsigned int>();
    type<long>();
    type<unsigned long>();
    type<float>();
    type<double>();
    type<long double>();
    return 0;
}
