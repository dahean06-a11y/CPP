#include <iostream>
int main() {
    int num;

    std::cout << "정수를 입력하세요 (1~99999): ";
    std::cin >> num;

    if(num < 1 || num >= 100000) {
        std::cout << "1~99999 범위의 정수만 입력하세요.\n";
        return 1;
    }

    int man = num / 10000;
    if(man > 1) std::cout << man << "만 ";
    else if(man == 1) std::cout << "만 ";  

    int thousands = (num % 10000) / 1000;
    if(thousands > 1) std::cout << thousands << "천 ";
    else if(thousands == 1) std::cout << "천 ";

    int hundreds = (num % 1000) / 100;
    if(hundreds > 1) std::cout << hundreds << "백 ";
    else if(hundreds == 1) std::cout << "백 ";

    int tens = (num % 100) / 10;
    if(tens > 1) std::cout << tens << "십 ";
    else if(tens == 1) std::cout << "십 ";

    int ones = num % 10;
    if(ones > 0) std::cout << ones;

    std::cout << "\n";
    return 0;
}