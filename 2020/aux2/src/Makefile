all: helloworld variables if_else while_for functions strings pointer reference complexv1 complexv1sep complexv2 complexv3 stack tests

helloworld:
	g++ 01_helloworld.cpp -o 01_helloworld

variables:
	g++ 02_variables.cpp -o 02_variables

if_else:
	g++ 03_if_else.cpp -o 03_if_else

while_for:
	g++ 04_while_for.cpp -o 04_while_for

functions:
	g++ 05_functions.cpp -o 05_functions

strings:
	g++ 06_strings.cpp -o 06_strings

pointer:
	g++ 07_pointer.cpp -o 07_pointer

reference:
	g++ 08_reference.cpp -o 08_reference

complexv1:
	g++ 09_complex_v1.cpp -o 09_complex_v1

complexv1sep:
	g++ 10_complex_v1_sep.cpp 10_main.cpp -o 10_complex_v1_sep

complexv2:
	g++ 11_complex_v2.cpp 11_main.cpp -o 11_complex_v2

complexv3:
	g++ 12_complex_v3.cpp 12_main.cpp -o 12_complex_v3

stack:
	g++ 13_stack.h 12_complex_v3.cpp 13_main.cpp -o 13_stack

tests:
	g++ 14_tests.cpp 12_complex_v3.cpp -o 14_tests

clean:
	rm -f 01_helloworld 02_variables 03_if_else 04_while_for 05_functions 06_strings 07_pointer 08_reference 09_complex_v1 10_complex_v1_sep 11_complex_v2 12_complex_v3 13_stack 14_tests
