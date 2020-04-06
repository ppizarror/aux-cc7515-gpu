# Propiedades del make
cmake_minimum_required(VERSION 3.10)
project(CC7515-AUX-1)
set(CMAKE_CXX_STANDARD 11)

# Crea un set, contiene varios archivos que permiten compilar al principal
set(AUX1_EX10
        src/10_complex_v1_sep.cpp)

set(AUX1_STACK
        src/13_stack.h
        src/12_complex_v3.cpp)

# Define ejecutables
add_executable(EX-1-HELLO-WORLD src/01_helloworld.cpp)
add_executable(EX-2-VARIABLES src/02_variables.cpp)
add_executable(EX-3-IF-ELSE src/03_if_else.cpp)
add_executable(EX-4-WHILE-FOR src/04_while_for.cpp)
add_executable(EX-5-FUNCTIONS src/05_functions.cpp)
add_executable(EX-6-STRINGS src/06_strings.cpp)
add_executable(EX-7-POINTER src/07_pointer.cpp)
add_executable(EX-8-REFERENCE src/08_reference.cpp)
add_executable(EX-9-COMPLEX-V1 src/09_complex_v1.cpp)
add_executable(EX-10-COMPLEX-V1-SEP src/10_main.cpp ${AUX1_EX10})
add_executable(EX-11-COMPLEX-V2 src/11_main.cpp src/11_complex_v2.cpp)
add_executable(EX-12-COMPLEX-V3 src/12_main.cpp src/12_complex_v3.cpp)
add_executable(EX-13-STACK src/13_main.cpp ${AUX1_STACK})
add_executable(EX-14-TESTS src/14_tests.cpp)

# Agregamos geometría
add_executable(PUNTO geom/geom_main.cpp geom/punto.h)