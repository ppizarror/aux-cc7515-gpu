#include <iostream>
#include <string>

int main (void)
{
    std::string str1 = "Hello";
    std::string str2, str3;
    int len;

    std::cout << "Write a word: ";
    std::cin >> str2;

    // Copy str1 into str3
    str3 = str1;
    std::cout << "str3 : " << str3 << std::endl;

    // Concatenates str1 and str2
    str3 = str1 + str2;
    std::cout << "str1 + str2 : " << str3 << std::endl;

    // Total length of str3 after concatenation
    len = str3.size();
    std::cout << "str3.size() :  " << len << std::endl;

    return 0;
}
