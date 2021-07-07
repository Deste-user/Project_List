cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest-master)
set(GTEST_SOURCE_DIR, ./lib/googletest-master/googletest/)
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})


set(TEST_SOURCE_FILES UtenteTest.cpp ListaTest.cpp  RunAllTest.cpp )
add_executable(runalltest ${TEST_SOURCE_FILES})
target_link_libraries(runalltest gtest gtest_main core)