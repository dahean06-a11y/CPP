#include <iostream>
#include <cstdlib>
#include <ctime>
#include "p202_2.hpp"

using namespace std;

int main() {
    int map[5][5];

    srand(time(0));

    randomMap(map);
    printMap(map);
    cheakMap(map);

    return 0;
}
