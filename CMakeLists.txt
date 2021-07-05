cmake_minimum_required(VERSION 3.17)
project(lista)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test/lib/googletest-master)
add_executable(Lista main.cpp Lista.cpp Lista.h Utente.cpp Utente.h Product.cpp Product.h CategoryProduct.h Subject.h Observer.h)


set(SOURCE_FILES Lista.cpp Lista.h Utente.cpp Utente.h Product.cpp Product.h CategoryProduct.h )

add_library(core ${SOURCE_FILES})
target_link_libraries(Lista core)
