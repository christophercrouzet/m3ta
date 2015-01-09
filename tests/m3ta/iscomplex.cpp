#include <complex>
#include <type_traits>

#include <m3ta/iscomplex>

#include "../assert.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

void function()
{
    TEST_ASSERT(m3ta::isComplex<void>() == false);
    TEST_ASSERT(m3ta::isComplex<void *>() == false);
    TEST_ASSERT(m3ta::isComplex<char>() == false);
    TEST_ASSERT(m3ta::isComplex<unsigned char>() == false);
    TEST_ASSERT(m3ta::isComplex<short>() == false);
    TEST_ASSERT(m3ta::isComplex<unsigned short>() == false);
    TEST_ASSERT(m3ta::isComplex<int>() == false);
    TEST_ASSERT(m3ta::isComplex<unsigned int>() == false);
    TEST_ASSERT(m3ta::isComplex<long>() == false);
    TEST_ASSERT(m3ta::isComplex<unsigned long>() == false);
    TEST_ASSERT(m3ta::isComplex<float>() == false);
    TEST_ASSERT(m3ta::isComplex<double>() == false);
    TEST_ASSERT(m3ta::isComplex<long double>() == false);
    
    TEST_ASSERT(m3ta::isComplex<std::complex<float>>() == true);
    TEST_ASSERT(m3ta::isComplex<std::complex<double>>() == true);
    TEST_ASSERT(m3ta::isComplex<std::complex<long double>>() == true);
    TEST_ASSERT(m3ta::isComplex<const std::complex<float>>() == true);
    TEST_ASSERT(m3ta::isComplex<const std::complex<double>>() == true);
    TEST_ASSERT(m3ta::isComplex<const std::complex<long double>>() == true);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<float>>() == true);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<double>>() == true);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<long double>>() == true);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<float>>() == true);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<double>>() == true);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<long double>>() == true);
    
    TEST_ASSERT(m3ta::isComplex<const std::complex<float> &>() == false);
    TEST_ASSERT(m3ta::isComplex<const std::complex<double> &>() == false);
    TEST_ASSERT(m3ta::isComplex<const std::complex<long double> &>() == false);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<float> &>() == false);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<double> &>() == false);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<long double> &>() == false);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<float> &>() == false);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<double> &>() == false);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<long double> &>() == false);
    
    TEST_ASSERT(m3ta::isComplex<std::complex<float> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<std::complex<double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<std::complex<long double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<const std::complex<float> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<const std::complex<double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<const std::complex<long double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<float> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<volatile std::complex<long double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<float> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<double> &&>() == false);
    TEST_ASSERT(m3ta::isComplex<const volatile std::complex<long double> &&>() == false);
}

void type()
{
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<void>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<void *>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<char>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<unsigned char>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<short>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<unsigned short>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<int>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<unsigned int>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<long>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<unsigned long>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<float>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<double>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<long double>, std::integral_constant<bool, false>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<float>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<long double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<float>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<long double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<float>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<long double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<float>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<double>>, std::integral_constant<bool, true>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<long double>>, std::integral_constant<bool, true>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<float> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<long double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<float> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<long double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<float> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<long double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<float> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<double> &>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<long double> &>, std::integral_constant<bool, false>>::value));
    
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<float> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<std::complex<long double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<float> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const std::complex<long double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<float> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<volatile std::complex<long double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<float> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<double> &&>, std::integral_constant<bool, false>>::value));
    TEST_ASSERT((std::is_same<m3ta::IsComplexT<const volatile std::complex<long double> &&>, std::integral_constant<bool, false>>::value));
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    function();
    type();
    return 0;
}
