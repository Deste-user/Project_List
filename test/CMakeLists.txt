cmake_minimum_required(VERSION 3.17)

add_subdirectory(./lib/googletest-master/googletest)
set(GTEST_SOURCE_DIR, ./lib/googletest-master/googletest)
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})


set(TEST_SOURCE_FILES UtenteTest.cpp ListaTest.cpp RunAllTest.cpp )
add_executable(RUN_ALL_TESTS ${TEST_SOURCE_FILES})
target_link_libraries(RUN_ALL_TESTS gtest gtest_main core)



