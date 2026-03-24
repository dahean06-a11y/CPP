#include <algorithm>
#include "p147_2-5.hpp" 

std::string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::string s;
    std::cout << "숫자를 입력하시오:";
    std::cin >> s;

    std::cout << "역순: ";
    std::cout << reverse(s) <<std::endl;
}