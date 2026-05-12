#pragma once

#include <iostream>
#include <unistd.h>

#include "Monster.hpp"
#include "Matrix.hpp"

#define MAXMONS 20

using namespace std;

class MonsterWorld {

    Matrix world;

    Monster* pMon[MAXMONS];

    int nMon;

    int xMax, yMax;

    int nMove;

    int nEat;

public:
    MonsterWorld(int w, int h)
        : world(h, w),
        xMax(w), yMax(h) {

        nMon = 0;

        nMove = 0;

        nEat = 0;

        world.setZero();

        for (int i = 0; i < MAXMONS; i++)
            pMon[i] = NULL;
    }

    ~MonsterWorld() {

        for (int i = 0; i < nMon; i++)
            delete pMon[i];
    }

    int& Map(int x, int y) {
        return world.elem(x, y);
    }

    void add(const Monster& m) {

        if (nMon < MAXMONS)
            pMon[nMon++] = new Monster(m);
    }

    void createFood(int count = 1) {

        for (int i = 0; i < count; i++) {

            int x = rand() % xMax;

            int y = rand() % yMax;

            if (Map(x, y) == 0) {

                Map(x, y) = 1;

                nEat++;
            }
        }
    }

    void moveAll() {

        for (int i = 0; i < nMon; i++) {

            bool ate =
                pMon[i]->move(
                    world.Data(),
                    xMax,
                    yMax
                );

            if (ate)
                nEat--;

            nMove++;
        }
    }

    void checkStarvation() {

        for (int i = 0; i < nMon; ) {

            if (pMon[i]->getEnergy() <= 0) {

                delete pMon[i];

                pMon[i] = pMon[nMon - 1];

                pMon[nMon - 1] = NULL;

                nMon--;

                cout << "Monster 하나가 굶어죽습니다.\n";
            }
            else {
                i++;
            }
        }
    }

    void print() {

        Canvas canvas(xMax, yMax);

        canvas.clear();

        for (int y = 0; y < yMax; y++) {

            for (int x = 0; x < xMax; x++) {

                if (Map(x, y) == 1)
                    canvas.draw(x, y, "♣ ");
            }
        }

        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(canvas);

        canvas.print(
            "[ Monster World (Dynamic World) ]"
        );

        cout << "전체 이동 횟수 = "
            << nMove << endl;

        cout << "남은 아이템 수 = "
            << nEat << endl;

        for (int i = 0; i < nMon; i++)
            pMon[i]->print();

        Monster::printCount();
    }

    void play(int maxwalk = 500, int wait = 100) {

        for (int i = 0; i < maxwalk; i++) {

            createFood();

            moveAll();

            checkStarvation();

            print();

            if (nMon <= 0) {

                cout << "모든 몬스터가 사라졌습니다.\n";

                break;
            }

            usleep(wait * 1000);
        }
    }
};