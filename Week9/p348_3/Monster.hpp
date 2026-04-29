#pragma once
#include "Canvas.hpp"
#define DIM 40

class Monster {
    string name, icon;
    int x, y, nItem;
    int nEnergy;   // 🔥 에너지 추가

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;   // 먹으면 증가
        }
        else {
            nEnergy -= 1;   // 못 먹으면 감소
            if (nEnergy < 0) nEnergy = 0;
        }
    }

public:
    // 🔥 생성자 초기화 리스트
    Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}

    ~Monster() {
        cout << "\t" << name << icon << " 물러갑니다~~~\n";
    }

    void draw(Canvas& canvas) {
        canvas.draw(x, y, icon);
    }

    void move(int map[DIM][DIM], int maxx, int maxy) {
        switch (rand() % 8) {
        case 0: y--; break;
        case 1: x++; y--; break;
        case 2: x++; break;
        case 3: x++; y++; break;
        case 4: y++; break;
        case 5: x--; y++; break;
        case 6: x--; break;
        case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }

    void print() {
        cout << "\t" << name << icon
             << ": 아이템=" << nItem
             << " 에너지=" << nEnergy << endl;
    }
};