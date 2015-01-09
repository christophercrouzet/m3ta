#ifndef TESTS_ASSERT_H
#define TESTS_ASSERT_H

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>


namespace tests
{

void
printAssertError(
    const std::string &header,
    const std::string &code,
    const std::string &routine,
    const std::string &file,
    int line,
    const std::string &message = ""
)
{
    std::cerr << header << ": "
              << "(" << code << "), "
              << "function " << routine << ", "
              << "file " << file << ", "
              << "line " << line << ".";
    
    if (!message.empty()) {
        std::cerr << " " << message;
    }
    
    std::cerr << std::endl;
}

} // namespace tests.


#define TEST_GET_MACRO_OVERLOAD(_1, _2, NAME, ...) NAME

#define TEST_ASSERT_MESSAGE(CONDITION, MESSAGE) \
do { \
    if (!(CONDITION)) { \
        tests::printAssertError("Assertion failed", #CONDITION, \
                                __func__, __FILE__, __LINE__, (MESSAGE)); \
        std::abort(); \
    } \
} while (false)

#define TEST_ASSERT_NO_MESSAGE(CONDITION) \
TEST_ASSERT_MESSAGE(CONDITION, "")

#define TEST_ASSERT(...) \
TEST_GET_MACRO_OVERLOAD( \
    __VA_ARGS__, \
    TEST_ASSERT_MESSAGE, \
    TEST_ASSERT_NO_MESSAGE, \
    void \
)(__VA_ARGS__)

#endif // TESTS_ASSERT_H
