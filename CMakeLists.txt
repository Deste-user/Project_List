cmake_minimum_required(VERSION 3.17)
project(lista)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)



set(SOURCE_FILES Lista.cpp Lista.h Utente.cpp Utente.h Product.cpp Product.h CategoryProduct.h Subject.h Observer.h)
add_executable(LISTA main.cpp)

add_library(core  ${SOURCE_FILES})
target_link_libraries(LISTA  core)
