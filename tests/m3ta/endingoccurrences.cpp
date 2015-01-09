#include <complex>
#include <cstddef>
#include <type_traits>

#include <m3ta/endingoccurrences>

#include "../assert.h"
#include "../messages.h"


//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<typename T>
void functionNumeric()
{
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85)) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 0) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 1) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 2) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 4) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 9) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 85) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 85) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 9) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 4) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 2) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 1) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 0) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 0, 0) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 1, 1) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 2, 2) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 4, 4) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 9, 9) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 85, 85) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 85, 0) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 9, 1) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 4, 2) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 2, 4) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 1, 9) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 0, 85) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 0, 85) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 1, 9) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 2, 4) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 4, 2) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 9, 1) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 85, 0) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 0, 0, 0) == 3, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 1, 1, 1) == 3, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 2, 2, 2) == 3, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 4, 4, 4) == 3, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 9, 9, 9) == 3, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 85, 85, 85) == 3, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 85, 0, 0) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 9, 1, 1) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 4, 2, 2) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 2, 4, 4) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 1, 9, 9) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 0, 85, 85) == 2, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 0, 85, 0) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 1, 9, 1) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 2, 4, 2) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 4, 2, 4) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 9, 1, 9) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 85, 0, 85) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), 0, 0, 85) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), 1, 1, 9) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), 2, 2, 4) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), 4, 4, 2) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), 9, 9, 1) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), 85, 85, 0) == 0, tests::errorMessageForType<T>());
}

template<typename T>
void functionComplex()
{
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(0, 0)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(1, 1)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(2, 2)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(4, 4)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(9, 9)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(85, 85)) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(0, 0), std::complex<T>(0, 0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(1, 1), std::complex<T>(1, 1)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(2, 2), std::complex<T>(2, 2)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(4, 4), std::complex<T>(4, 4)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(9, 9), std::complex<T>(9, 9)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(85, 85), std::complex<T>(85, 85)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(0, 0), std::complex<T>(85, 85)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(1, 1), std::complex<T>(9, 9)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(2, 2), std::complex<T>(4, 4)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(4, 4), std::complex<T>(2, 2)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(9, 9), std::complex<T>(1, 1)) == 0, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(85, 85), std::complex<T>(0, 0)) == 0, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(0), std::complex<T>(0, 0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(1), std::complex<T>(1, 0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(2), std::complex<T>(2, 0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(4), std::complex<T>(4, 0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(9), std::complex<T>(9, 0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(static_cast<T>(85), std::complex<T>(85, 0)) == 1, tests::errorMessageForType<T>());
    
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(0, 0), static_cast<T>(0)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(1, 0), static_cast<T>(1)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(2, 0), static_cast<T>(2)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(4, 0), static_cast<T>(4)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(9, 0), static_cast<T>(9)) == 1, tests::errorMessageForType<T>());
    TEST_ASSERT(m3ta::endingOccurrences(std::complex<T>(85, 0), static_cast<T>(85)) == 1, tests::errorMessageForType<T>());
}

template<typename T>
void typeIntegral()
{
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 0>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 1>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 2>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 4>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 9>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 85>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 85>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 9>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 4>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 2>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 1>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 0>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 0, 0>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 1, 1>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 2, 2>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 4, 4>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 9, 9>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 85, 85>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 85, 0>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 9, 1>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 4, 2>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 2, 4>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 1, 9>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 0, 85>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 0, 85>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 1, 9>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 2, 4>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 4, 2>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 9, 1>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 85, 0>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 0, 0, 0>, std::integral_constant<std::size_t, 3>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 1, 1, 1>, std::integral_constant<std::size_t, 3>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 2, 2, 2>, std::integral_constant<std::size_t, 3>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 4, 4, 4>, std::integral_constant<std::size_t, 3>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 9, 9, 9>, std::integral_constant<std::size_t, 3>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 85, 85, 85>, std::integral_constant<std::size_t, 3>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 85, 0, 0>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 9, 1, 1>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 4, 2, 2>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 2, 4, 4>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 1, 9, 9>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 0, 85, 85>, std::integral_constant<std::size_t, 2>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 0, 85, 0>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 1, 9, 1>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 2, 4, 2>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 4, 2, 4>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 9, 1, 9>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 85, 0, 85>, std::integral_constant<std::size_t, 1>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 0, 0, 0, 85>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 1, 1, 1, 9>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 2, 2, 2, 4>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 4, 4, 4, 2>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 9, 9, 9, 1>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
    TEST_ASSERT((std::is_same<m3ta::EndingOccurrencesT<T, 85, 85, 85, 0>, std::integral_constant<std::size_t, 0>>::value), tests::errorMessageForType<T>());
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    functionNumeric<char>();
    functionNumeric<unsigned char>();
    functionNumeric<short>();
    functionNumeric<unsigned short>();
    functionNumeric<int>();
    functionNumeric<unsigned int>();
    functionNumeric<long>();
    functionNumeric<unsigned long>();
    functionNumeric<float>();
    functionNumeric<double>();
    functionNumeric<long double>();
    functionNumeric<float>();
    functionNumeric<double>();
    functionNumeric<long double>();
    
    functionComplex<float>();
    functionComplex<double>();
    functionComplex<long double>();
    
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
