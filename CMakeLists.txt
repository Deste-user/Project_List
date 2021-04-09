cmake_minimum_required(VERSION 3.17)
project(lista)

set(CMAKE_CXX_STANDARD 14)

add_executable(lista main.cpp Lista.cpp Lista.h Utente.cpp Utente.h Product.cpp Product.h CategoryProduct.cpp CategoryProduct.h)
add_subdirectory(test)

set(SOURCE_FILES Lista.cpp Lista.h Utente.cpp Utente.h Product.cpp Product.h CategoryProduct.cpp CategoryProduct.h)
add_executable(unit_testing_ex main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(unit_testing_ex core)
