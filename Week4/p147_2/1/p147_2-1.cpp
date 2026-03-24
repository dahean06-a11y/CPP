#include <iostream>
#include <algorithm>

int reverse(int x)
{
    int reverse_Number = 0;

    while(x)
    { 
    int digit = x % 10;
    reverse_Number = reverse_Number * 10 + digit;
    x /=10;
    }

    return reverse_Number;
} 

std::string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    int x;
    std::cin >>x;

    std::cout << reverse(x) << std::endl;

    std::string s;
    std::cin >> s;

    std::cout << reverse(s) <<std::endl;
}