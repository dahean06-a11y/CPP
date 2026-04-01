#include "ranking.hpp"

extern int playFifteenPuzzle();

int main() {
    loadRanking("ranking.dat");

    int rank = playFifteenPuzzle();

    printRanking();
    storeRanking("ranking.dat");

    return 0;
}
