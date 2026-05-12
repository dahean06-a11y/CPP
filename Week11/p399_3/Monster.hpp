#pragma once
#include <iostream>
#include <string>
#include "Canvas.hpp"

using namespace std;

class Monster {
protected:
    string name;
    string icon;

    int x, y;

    int nEnergy;

    static int count;

public:
    Monster(string n = "몬스터",
        string i = "※",
        int px = 0,
        int py = 0,
        int energy = 30)
        : name(n), icon(i),
        x(px), y(py),
        nEnergy(energy) {

        count++;
    }

    Monster(const Monster& m)
        : name(m.name), icon(m.icon),
        x(m.x), y(m.y),
        nEnergy(m.nEnergy) {

        count++;
    }

    virtual ~Monster() {
        count--;
    }

    virtual bool move(int** map, int maxx, int maxy) {

        int dir = rand() % 4;

        switch (dir) {

        case 0:
            if (x < maxx - 1) x++;
            break;

        case 1:
            if (x > 0) x--;
            break;

        case 2:
            if (y < maxy - 1) y++;
            break;

        case 3:
            if (y > 0) y--;
            break;
        }

        nEnergy--;

        return eat(map);
    }

    virtual bool eat(int** map) {

        if (map[y][x] == 1) {

            map[y][x] = 0;

            nEnergy += 4;

            return true;
        }

        return false;
    }

    virtual void draw(Canvas& canvas) {
        canvas.draw(x, y, icon);
    }

    virtual void print() {

        cout << name << "(" << icon << ") "
            << "위치:(" << x << "," << y << ") "
            << "에너지:" << nEnergy << endl;
    }

    int getEnergy() {
        return nEnergy;
    }

    static void printCount() {

        cout << "현재 몬스터 수 = "
            << count << endl;
    }
};

int Monster::count = 0;