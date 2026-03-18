#include <iostream>
int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= 5 - i; ++j)
        {
            std::cout << " ";
        }

        for(int j = 1; j <= i; ++j)
        {
            std::cout << i - j + 1;
        }

        std::cout << "\n";
    }
}