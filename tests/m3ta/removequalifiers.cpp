#include <type_traits>

#include <m3ta/removequalifiers>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

void type()
{
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int &>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int &>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int &>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int &>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int &&>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int &&>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int &&>, int>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int &&>, int>::value));
    
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int *>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int *>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int *>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int *>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int *&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int *&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int *&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int *&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int *&&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int *&&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int *&&>, int *>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int *&&>, int *>::value));
    
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int **>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int **>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int **>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int **>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int **&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int **&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int **&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int **&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int **&&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int **&&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int **&&>, int **>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int **&&>, int **>::value));
    
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int (&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int (&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int (&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int (&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int (&&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int (&&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int (&&)[1][2]>, int[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int (&&)[1][2]>, int[1][2]>::value));
    
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int *[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int *[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int *[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int *[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int *(&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int *(&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int *(&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int *(&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int *(&&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int *(&&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int *(&&)[1][2]>, int *[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int *(&&)[1][2]>, int *[1][2]>::value));
    
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int (*)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int (*)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int (*)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int (*)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int (*&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int (*&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int (*&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int (*&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<int (*&&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const int (*&&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<volatile int (*&&)[1][2]>, int (*)[1][2]>::value));
    TEST_ASSERT((std::is_same<m3ta::RemoveQualifiersT<const volatile int (*&&)[1][2]>, int (*)[1][2]>::value));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    type();
    return 0;
}
