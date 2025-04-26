set(SOURCES
    big_int_test.cpp
)
add_executable(big_int_test ${SOURCES})
target_link_libraries(big_int_test
    gtest_main
    big_int_lib
)

add_test(big_int_test big_int_test)

add_executable(ibusko_test test_long_number.cpp)
target_link_libraries(ibusko_test
    gtest_main
    big_int_lib
)
add_test(ibusko_test ibusko_test)