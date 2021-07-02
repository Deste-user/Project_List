cmake_minimum_required(VERSION 3.17)

add_subdirectory(./lib/googletest-master/googletest)
set(gtest_sorgente_dir, ./lib/googletest-master/googletest)
include_directories(${gtest_sorgente_dir}/include ${gtest_sorgente_dir})


set(TEST_SOURCE_FILES ListaTest.cpp )
add_executable(run_all_test ${TEST_SOURCE_FILES})
target_link_libraries(run_all_test gtest_main core)



