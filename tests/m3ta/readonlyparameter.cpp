#include <type_traits>

#include <m3ta/readonlyparameter>

#include "../assert.h"
#include "../messages.h"



//      Helpers to test custom structures.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

struct Small { char data; };
struct Big { double data[512]; };

namespace tests
{

template<>
struct TypeName<Small>
{ static constexpr const char *value = "Small"; };

template<>
struct TypeName<Big>
{ static constexpr const char *value = "Big"; };

} // namespace tests.



//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void type()
{
    if (std::is_void<T>::value || sizeof(T) <= sizeof(void *)) {
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T &>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T &>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T &>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T &>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T &&>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T &&>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T &&>, T>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T &&>, T>::value), tests::errorMessageForType<T>());
    }
    else {
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T &>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T &>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T &>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T &>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T &&>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T &&>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T &&>, const T &>::value), tests::errorMessageForType<T>());
        TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T &&>, const T &>::value), tests::errorMessageForType<T>());
    }
    
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T *>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T *>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T *>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T *>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T *&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T *&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T *&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T *&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T *&&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T *&&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T *&&>, T *>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T *&&>, T *>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T **>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T **>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T **>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T **>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T **&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T **&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T **&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T **&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T **&&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T **&&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T **&&>, T **>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T **&&>, T **>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T (&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T (&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T (&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T (&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T (&&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T (&&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T (&&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T (&&)[1][2]>, T[1][2]>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T *[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T *[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T *[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T *[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T *(&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T *(&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T *(&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T *(&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T *(&&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T *(&&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T *(&&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T *(&&)[1][2]>, T *[1][2]>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T (*)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T (*)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T (*)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T (*)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T (*&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T (*&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T (*&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T (*&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<T (*&&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const T (*&&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<volatile T (*&&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<const volatile T (*&&)[1][2]>, T (*)[1][2]>::value), tests::errorMessageForType<T>());
}

void typeSpecial()
{
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<void>, void>::value));
    TEST_ASSERT((std::is_same<m3ta::ReadOnlyParameterT<void *>, void *>::value));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    type<char>();
    type<short>();
    type<int>();
    type<long>();
    type<float>();
    type<double>();
    type<long double>();
    type<std::complex<float>>();
    type<std::complex<double>>();
    type<std::complex<long double>>();
    type<Small>();
    type<Big>();
    
    typeSpecial();
    
    return 0;
}
