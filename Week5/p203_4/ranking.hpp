#ifndef RANKING_H
#define RANKING_H

struct PlayInfo {
    char name[200];
    int nMove;
    double tElapsed;
};

void loadRanking(const char* filename);
void storeRanking(const char* filename);
void printRanking();
int addRanking(int nMove, double tElap);

#endif
