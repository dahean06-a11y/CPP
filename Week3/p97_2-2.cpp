#include <iostream>
int main() {
    int num;

    std::cout << "정수를 입력하세요 (1~99999): ";
    std::cin >> num;

    if(num < 1 || num >= 100000) {
        std::cout << "1~99999 범위의 정수만 입력하세요.\n";
        return 1;
    }

    if(num / 10000 > 0) std::cout << (num / 10000) << "만 ";
  
    if((num % 10000) / 1000 > 0) std::cout << ((num % 10000) / 1000) << "천 ";
    
    if((num % 1000) / 100 > 0) std::cout << ((num % 1000) / 100) << "백 ";
   
    if((num % 100) / 10 > 0) std::cout << ((num % 100) / 10) << "십 ";
    
    if(num % 10 > 0) std::cout << (num % 10);

    std::cout << "\n";
    return 0;
}