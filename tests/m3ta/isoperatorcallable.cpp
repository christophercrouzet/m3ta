#include <type_traits>

#include <m3ta/isoperatorcallable>

#include "../assert.h"
#include "../messages.h"


#define TEST_UNARY(OPERATOR, TYPE, EXPECTED) \
TEST_ASSERT( \
    (m3ta::isOperatorCallable<OPERATOR, TYPE>() == EXPECTED), \
    (tests::errorMessageForOperator<OPERATOR>()) \
); \
TEST_ASSERT( \
    (std::is_same< \
        m3ta::IsOperatorCallableT<m3ta::UnaryOperator, OPERATOR, TYPE>, \
        std::integral_constant<bool, EXPECTED> \
    >::value), \
    (tests::errorMessageForOperator<OPERATOR>()) \
);

#define TEST_BINARY(OPERATOR, TYPE, OTHER_TYPE, EXPECTED) \
TEST_ASSERT( \
    (m3ta::isOperatorCallable<OPERATOR, TYPE, OTHER_TYPE>() == EXPECTED), \
    (tests::errorMessageForOperator<OPERATOR>()) \
); \
TEST_ASSERT( \
    (std::is_same< \
        m3ta::IsOperatorCallableT< \
            m3ta::BinaryOperator, \
            OPERATOR, \
            TYPE, \
            OTHER_TYPE \
        >, \
        std::integral_constant<bool, EXPECTED> \
    >::value), \
    (tests::errorMessageForOperator<OPERATOR>()) \
);


enum class ClassProperties {
    empty,
    nonCopiable,
    nonMovable,
    nonCopiableNonMovable
};



//      Helpers to test inheritance of member operators.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

#define DECLARE_BASE_MEMBER_OPERATORS \
Base operator+() const; \
Base operator-() const; \
Base operator++(int) const; \
Base operator--(int) const; \
Base & operator++(); \
Base & operator--(); \
Base operator!() const; \
Base operator~() const; \
\
template<ClassProperties T_otherClassProperties> \
Base operator+(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator-(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator*(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator/(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator%(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator==(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator!=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator>(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator<(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator>=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator<=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator&&(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
bool operator||(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator&(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator|(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator^(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator<<(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base operator>>(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator+=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator-=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator*=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator/=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator%=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator&=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator|=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator^=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator<<=(const Base<T_otherClassProperties> &) const; \
template<ClassProperties T_otherClassProperties> \
Base & operator>>=(const Base<T_otherClassProperties> &) const; \


//- Base struct.

template<ClassProperties T_properties>
struct Base
{
    Base & operator=(const Base &) const;
    template<ClassProperties T_otherClassProperties>
    Base & operator=(const Base<T_otherClassProperties> &) const;
    
    DECLARE_BASE_MEMBER_OPERATORS
};

template<>
struct Base<ClassProperties::nonCopiable>
{
    Base() = default;
    Base(const Base &) = delete;
    Base(Base &&) = default;
    
    Base & operator=(const Base &) const;
    template<ClassProperties T_otherClassProperties>
    Base & operator=(const Base<T_otherClassProperties> &) const;
    
    DECLARE_BASE_MEMBER_OPERATORS
};

template<>
struct Base<ClassProperties::nonMovable>
{
    Base() = default;
    Base(const Base &) = default;
    Base(Base &&) = delete;
    
    Base & operator=(const Base &) const;
    template<ClassProperties T_otherClassProperties>
    Base & operator=(const Base<T_otherClassProperties> &) const;
    
    DECLARE_BASE_MEMBER_OPERATORS
};

template<>
struct Base<ClassProperties::nonCopiableNonMovable>
{
    Base() = default;
    Base(const Base &) = delete;
    Base(Base &&) = delete;
    
    Base & operator=(const Base &) const;
    template<ClassProperties T_otherClassProperties>
    Base & operator=(const Base<T_otherClassProperties> &) const;
    
    DECLARE_BASE_MEMBER_OPERATORS
};


//- Child struct.

template<ClassProperties T_properties>
struct Child
    : public Base<T_properties>
{
    Child & operator=(const Child &) const;
    template<ClassProperties T_otherClassProperties>
    Child & operator=(const Base<T_otherClassProperties> &) const;
};

template<>
struct Child<ClassProperties::nonCopiable>
    : public Base<ClassProperties::nonCopiable>
{
    Child(const Child &) = delete;
    Child(Child &&) = default;
    
    Child & operator=(const Child &) const;
    template<ClassProperties T_otherClassProperties>
    Child & operator=(const Base<T_otherClassProperties> &) const;
};

template<>
struct Child<ClassProperties::nonMovable>
    : public Base<ClassProperties::nonMovable>
{
    Child(const Child &) = default;
    Child(Child &&) = delete;
    
    Child & operator=(const Child &) const;
    template<ClassProperties T_otherClassProperties>
    Child & operator=(const Base<T_otherClassProperties> &) const;
};

template<>
struct Child<ClassProperties::nonCopiableNonMovable>
    : public Base<ClassProperties::nonCopiableNonMovable>
{
    Child(const Child &) = delete;
    Child(Child &&) = delete;
    
    Child & operator=(const Child &) const;
    template<ClassProperties T_otherClassProperties>
    Child & operator=(const Base<T_otherClassProperties> &) const;
};



//      Helpers to test global operators.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

#define DEFINE_OBJECT(NAME) \
template<ClassProperties T_properties> \
struct NAME \
{}; \
\
template<> \
struct NAME<ClassProperties::nonCopiable> \
{ \
    NAME() = default; \
    NAME(const NAME &) = delete; \
    NAME(NAME &&) = default; \
}; \
\
template<> \
struct NAME<ClassProperties::nonMovable> \
{ \
    NAME() = default; \
    NAME(const NAME &) = default; \
    NAME(NAME &&) = delete; \
}; \
\
template<> \
struct NAME<ClassProperties::nonCopiableNonMovable> \
{ \
    NAME() = default; \
    NAME(const NAME &) = delete; \
    NAME(NAME &&) = delete; \
}; \


DEFINE_OBJECT(ObjectA);
DEFINE_OBJECT(ObjectB);
DEFINE_OBJECT(ObjectC);



//      Global operators.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

#define DECLARE_GLOBAL_UNARY_OPERATORS(OPERATOR) \
template<ClassProperties T_properties> \
void OPERATOR(const ObjectA<T_properties> &); \
\
template<ClassProperties T_properties> \
void OPERATOR(ObjectB<T_properties>); \
\
template<ClassProperties T_properties> \
void OPERATOR(ObjectC<T_properties> &&);

#define DECLARE_GLOBAL_UNARY_OPERATORS_SPECIAL(OPERATOR, ...) \
template<ClassProperties T_properties> \
void OPERATOR(const ObjectA<T_properties> &, __VA_ARGS__); \
\
template<ClassProperties T_properties> \
void OPERATOR(ObjectB<T_properties>, __VA_ARGS__); \
\
template<ClassProperties T_properties> \
void OPERATOR(ObjectC<T_properties> &&, __VA_ARGS__);

DECLARE_GLOBAL_UNARY_OPERATORS(operator+);
DECLARE_GLOBAL_UNARY_OPERATORS(operator-);
DECLARE_GLOBAL_UNARY_OPERATORS_SPECIAL(operator++, int);
DECLARE_GLOBAL_UNARY_OPERATORS_SPECIAL(operator--, int);
DECLARE_GLOBAL_UNARY_OPERATORS(operator++);
DECLARE_GLOBAL_UNARY_OPERATORS(operator--);
DECLARE_GLOBAL_UNARY_OPERATORS(operator!);
DECLARE_GLOBAL_UNARY_OPERATORS(operator~);


#define DECLARE_GLOBAL_BINARY_OPERATORS(OPERATOR) \
template<ClassProperties T_properties, ClassProperties T_otherClassProperties> \
void OPERATOR(const ObjectA<T_properties> &, const ObjectB<T_otherClassProperties> &); \
\
template<ClassProperties T_properties, ClassProperties T_otherClassProperties> \
void OPERATOR(ObjectA<T_properties>, ObjectC<T_otherClassProperties>); \
\
template<ClassProperties T_properties, ClassProperties T_otherClassProperties> \
void OPERATOR(ObjectB<T_properties> &&, ObjectC<T_otherClassProperties> &&);


DECLARE_GLOBAL_BINARY_OPERATORS(operator+);
DECLARE_GLOBAL_BINARY_OPERATORS(operator-);
DECLARE_GLOBAL_BINARY_OPERATORS(operator*);
DECLARE_GLOBAL_BINARY_OPERATORS(operator/);
DECLARE_GLOBAL_BINARY_OPERATORS(operator%);
DECLARE_GLOBAL_BINARY_OPERATORS(operator==);
DECLARE_GLOBAL_BINARY_OPERATORS(operator!=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator>);
DECLARE_GLOBAL_BINARY_OPERATORS(operator<);
DECLARE_GLOBAL_BINARY_OPERATORS(operator>=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator<=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator&&);
DECLARE_GLOBAL_BINARY_OPERATORS(operator||);
DECLARE_GLOBAL_BINARY_OPERATORS(operator&);
DECLARE_GLOBAL_BINARY_OPERATORS(operator|);
DECLARE_GLOBAL_BINARY_OPERATORS(operator^);
DECLARE_GLOBAL_BINARY_OPERATORS(operator<<);
DECLARE_GLOBAL_BINARY_OPERATORS(operator>>);
DECLARE_GLOBAL_BINARY_OPERATORS(operator+=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator-=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator*=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator/=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator%=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator&=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator|=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator^=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator<<=);
DECLARE_GLOBAL_BINARY_OPERATORS(operator>>=);



//      Test suite.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

template<m3ta::UnaryOperator T_operator>
void unaryMemberOperator()
{
    //- Argument `T1`.
    
    //-- With `T1 = T<ClassProperties::empty>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::empty>, true);
    TEST_UNARY(T_operator, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::nonCopiable>, true);
    TEST_UNARY(T_operator, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::nonMovable>, true);
    TEST_UNARY(T_operator, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_UNARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //- Argument `T1 &&`.
    
    //-- With `T1 = T<ClassProperties::empty>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::empty> &&, true);
    TEST_UNARY(T_operator, Child<ClassProperties::empty> &&, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::nonCopiable> &&, true);
    TEST_UNARY(T_operator, Child<ClassProperties::nonCopiable> &&, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::nonMovable> &&, true);
    TEST_UNARY(T_operator, Child<ClassProperties::nonMovable> &&, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_UNARY(T_operator, Base<ClassProperties::nonCopiableNonMovable> &&, true);
    TEST_UNARY(T_operator, Child<ClassProperties::nonCopiableNonMovable> &&, true);
}

template<m3ta::UnaryOperator T_operator>
void unaryGlobalOperator()
{
    //- Argument `T1`.
    
    //-- With `T1 = T<ClassProperties::empty>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::empty>, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::empty>, true);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::nonCopiable>, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::nonCopiable>, false);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::nonMovable>, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::nonMovable>, true);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //- Argument `T1 &&`.
    
    //-- With `T1 = T<ClassProperties::empty>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::empty> &&, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::empty> &&, true);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::empty> &&, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::nonCopiable> &&, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::nonCopiable> &&, true);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::nonCopiable> &&, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::nonMovable> &&, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::nonMovable> &&, false);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::nonMovable> &&, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_UNARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable> &&, true);
    TEST_UNARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable> &&, false);
    TEST_UNARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable> &&, true);
}

template<m3ta::BinaryOperator T_operator>
void binaryMemberOperator()
{
    //- Arguments `T1` and `T2`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //- Arguments `T1` and `T2 &&`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //- Arguments `T1 &&` and `T2`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //- Arguments `T1 &&` and `T2 &&`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::empty>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::empty>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonMovable>, true);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Base<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Base<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, Child<ClassProperties::nonCopiableNonMovable>, Child<ClassProperties::nonCopiableNonMovable>, true);
}

template<m3ta::BinaryOperator T_operator>
void binaryGlobalOperator()
{
    //- Arguments `T1` and `T2`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //- Arguments `T1` and `T2 &&`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //- Arguments `T1 &&` and `T2`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //- Arguments `T1 &&` and `T2 &&`.
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::empty>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::empty>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::empty>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::empty>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::empty>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonMovable>, false);
    
    
    //-- With `T1 = T<ClassProperties::nonCopiableNonMovable>` and `T2 = T<ClassProperties::nonCopiableNonMovable>`.
    
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, true);
    TEST_BINARY(T_operator, ObjectA<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectC<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectB<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectA<ClassProperties::nonCopiableNonMovable>, false);
    TEST_BINARY(T_operator, ObjectC<ClassProperties::nonCopiableNonMovable>, ObjectB<ClassProperties::nonCopiableNonMovable>, false);
}

template<m3ta::UnaryOperator T_operator>
void unaryOperator()
{
    unaryMemberOperator<T_operator>();
    unaryGlobalOperator<T_operator>();
}

template<m3ta::BinaryOperator T_operator>
void binaryOperator()
{
    binaryMemberOperator<T_operator>();
    binaryGlobalOperator<T_operator>();
}



//      Main procedure.
// 
//   O-(''Q)
// -----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    unaryOperator<m3ta::UnaryOperator::plus>();
    unaryOperator<m3ta::UnaryOperator::minus>();
    unaryOperator<m3ta::UnaryOperator::postfixIncrement>();
    unaryOperator<m3ta::UnaryOperator::postfixDecrement>();
    unaryOperator<m3ta::UnaryOperator::prefixIncrement>();
    unaryOperator<m3ta::UnaryOperator::prefixDecrement>();
    unaryOperator<m3ta::UnaryOperator::logicalNot>();
    unaryOperator<m3ta::UnaryOperator::bitwiseNot>();
    
    binaryMemberOperator<m3ta::BinaryOperator::assignment>();
    binaryOperator<m3ta::BinaryOperator::addition>();
    binaryOperator<m3ta::BinaryOperator::subtraction>();
    binaryOperator<m3ta::BinaryOperator::multiplication>();
    binaryOperator<m3ta::BinaryOperator::division>();
    binaryOperator<m3ta::BinaryOperator::modulo>();
    binaryOperator<m3ta::BinaryOperator::equalTo>();
    binaryOperator<m3ta::BinaryOperator::notEqualTo>();
    binaryOperator<m3ta::BinaryOperator::greaterThan>();
    binaryOperator<m3ta::BinaryOperator::lessThan>();
    binaryOperator<m3ta::BinaryOperator::greaterThanOrEqualTo>();
    binaryOperator<m3ta::BinaryOperator::lessThanOrEqualTo>();
    binaryOperator<m3ta::BinaryOperator::logicalAnd>();
    binaryOperator<m3ta::BinaryOperator::logicalOr>();
    binaryOperator<m3ta::BinaryOperator::bitwiseAnd>();
    binaryOperator<m3ta::BinaryOperator::bitwiseOr>();
    binaryOperator<m3ta::BinaryOperator::bitwiseXor>();
    binaryOperator<m3ta::BinaryOperator::bitwiseLeftShift>();
    binaryOperator<m3ta::BinaryOperator::bitwiseRightShift>();
    binaryOperator<m3ta::BinaryOperator::additionAssignment>();
    binaryOperator<m3ta::BinaryOperator::subtractionAssignment>();
    binaryOperator<m3ta::BinaryOperator::multiplicationAssignment>();
    binaryOperator<m3ta::BinaryOperator::divisionAssignment>();
    binaryOperator<m3ta::BinaryOperator::moduloAssignment>();
    binaryOperator<m3ta::BinaryOperator::bitwiseAndAssignment>();
    binaryOperator<m3ta::BinaryOperator::bitwiseOrAssignment>();
    binaryOperator<m3ta::BinaryOperator::bitwiseXorAssignment>();
    binaryOperator<m3ta::BinaryOperator::bitwiseLeftShiftAssignment>();
    binaryOperator<m3ta::BinaryOperator::bitwiseRightShiftAssignment>();
    
    return 0;
}
