#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2, str3;
    int len;

    std::cout << "Write a word: ";
    std::cin >> str2;

    // Copia str1 en str3
    str3 = str1;
    std::cout << "str3 : " << str3 << std::endl;

    // Concatena str1 y str2
    str3 = str1 + str2;
    std::cout << "str1 + str2 : " << str3 << std::endl;

    // Largo total de str3 después de concatenar
    len = str3.size();
    std::cout << "str3.size() :  " << len << std::endl;

    return 0;
}