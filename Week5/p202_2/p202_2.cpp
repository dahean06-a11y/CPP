#include <iostream>
#include <cstdlib>
#include "p202_2.hpp"

using namespace std;

void randomMap(int map[5][5]) {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            map[i][j] = rand() % 2;
}

void printMap(int map[5][5]) {
    cout << "\n[ MAP ]\n";
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
}

void cheakMap(int map[5][5]) {
    bool same;

    for(int i = 0; i < 5; i++) {
        same = true;
        for(int j = 1; j < 5; j++)
            if(map[i][j] != map[i][0]) same = false;
        if(same) cout << "가로 " << i+1 << "줄 동일\n";
    }

    for(int j = 0; j < 5; j++) {
        same = true;
        for(int i = 1; i < 5; i++)
            if(map[i][j] != map[0][j]) same = false;
        if(same) cout << "세로 " << j+1 << "줄 동일\n";
    }
}
