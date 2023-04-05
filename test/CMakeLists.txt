project(Google_Tests)

add_executable(EmbeddedCalculus_Tests Lexer/Lexer_tests.cpp)

target_link_libraries(EmbeddedCalculus_Tests gtest gtest_main)