include(${PROJECT_SOURCE_DIR}/cmake/tests.cmake)

include_directories(../include)

create_test(
    test-m3ta-all
    NAME m3ta-all
    FILE m3ta/all.cpp
)

create_test(
    test-m3ta-any
    NAME m3ta-any
    FILE m3ta/any.cpp
)

create_test(
    test-m3ta-arithmeticoperationresult
    NAME m3ta-arithmeticoperationresult
    FILE m3ta/arithmeticoperationresult.cpp
)

create_test(
    test-m3ta-concatenate
    NAME m3ta-concatenate
    FILE m3ta/concatenate.cpp
)

create_test(
    test-m3ta-dependentbool
    NAME m3ta-dependentbool
    FILE m3ta/dependentbool.cpp
)

create_test(
    test-m3ta-endingoccurrences
    NAME m3ta-endingoccurrences
    FILE m3ta/endingoccurrences.cpp
)

create_test(
    test-m3ta-extractintegersequence
    NAME m3ta-extractintegersequence
    FILE m3ta/extractintegersequence.cpp
)

create_test(
    test-m3ta-integersequence
    NAME m3ta-integersequence
    FILE m3ta/integersequence.cpp
)

create_test(
    test-m3ta-iscomplex
    NAME m3ta-iscomplex
    FILE m3ta/iscomplex.cpp
)

create_test(
    test-m3ta-isoperatorcallable
    NAME m3ta-isoperatorcallable
    FILE m3ta/isoperatorcallable.cpp
)

create_test(
    test-m3ta-maximum
    NAME m3ta-maximum
    FILE m3ta/maximum.cpp
)

create_test(
    test-m3ta-minimum
    NAME m3ta-minimum
    FILE m3ta/minimum.cpp
)

create_test(
    test-m3ta-nestedinitializerlists
    NAME m3ta-nestedinitializerlists
    FILE m3ta/nestedinitializerlists.cpp
)

create_test(
    test-m3ta-none
    NAME m3ta-none
    FILE m3ta/none.cpp
)

create_test(
    test-m3ta-parameterpack
    NAME m3ta-parameterpack
    FILE m3ta/parameterpack.cpp
)

create_test(
    test-m3ta-pass
    NAME m3ta-pass
    FILE m3ta/pass.cpp
)

create_test(
    test-m3ta-popback
    NAME m3ta-popback
    FILE m3ta/popback.cpp
)

create_test(
    test-m3ta-power
    NAME m3ta-power
    FILE m3ta/power.cpp
)

create_test(
    test-m3ta-product
    NAME m3ta-product
    FILE m3ta/product.cpp
)

create_test(
    test-m3ta-readonlyparameter
    NAME m3ta-readonlyparameter
    FILE m3ta/readonlyparameter.cpp
)

create_test(
    test-m3ta-removequalifiers
    NAME m3ta-removequalifiers
    FILE m3ta/removequalifiers.cpp
)

create_test(
    test-m3ta-reverse
    NAME m3ta-reverse
    FILE m3ta/reverse.cpp
)
