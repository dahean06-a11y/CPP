#include <iostream>
int main() {
    int n;
    double pi = 0.0;

    std::cout << "정수 n을 입력하세요: ";
    std::cin >> n;

    for(int i = 0; i <= n; i++) {

        double term = 1.0 / (2 * i + 1);

        if(i % 2 == 0)
            pi += term;
        else
            pi -= term;
    }

    pi *= 4;

    std::cout << "근사한 π 값: " << pi << "\n";

    return 0;
}