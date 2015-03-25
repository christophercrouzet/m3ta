#ifndef TESTS_MESSAGES_H
#define TESTS_MESSAGES_H

#include <sstream>
#include <string>

#include "operators.h"
#include "typename.h"


namespace tests
{

template<typename T>
std::string
errorMessageForType()
{
    std::ostringstream message;
    message << "Error for type '" << TypeName<T>::value() << "'.";
    return message.str();
}

template<m3ta::UnaryOperator T_operator>
std::string
errorMessageForOperator()
{
    std::ostringstream message;
    message << "Error for operator '"
            << UnaryOperator<T_operator>::value() << "'.";
    
    return message.str();
}

template<m3ta::BinaryOperator T_operator>
std::string
errorMessageForOperator()
{
    std::ostringstream message;
    message << "Error for operator '"
            << BinaryOperator<T_operator>::value() << "'.";
    
    return message.str();
}

} // namespace tests.

#endif // TESTS_MESSAGES_H
