project(Google_Tests)

add_executable(EmbeddedCalculus_Tests
        OLD___Polynomial_tests.cpp
        Polynomial/Trim_tests.cpp
        Polynomial/Split_tests.cpp
        Polynomial/ParseCoefficient_tests.cpp
        Polynomial/ParseExponent_tests.cpp
        Polynomial/SetFromString_tests.cpp)

target_link_libraries(EmbeddedCalculus_Tests gtest gtest_main)