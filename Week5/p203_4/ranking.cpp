#include "ranking.hpp"
#include <cstdio>
#include <cstring>

#define NUM_MVP 10 //(6) 상위 10개 랭킹

static PlayInfo MVP[NUM_MVP];

static void initRanking() {
    for (int i = 0; i < NUM_MVP; i++) {
        strcpy(MVP[i].name, "Player");
        MVP[i].nMove = 9999;
        MVP[i].tElapsed = 9999.0;
    }
}

void loadRanking(const char* fname) {
    FILE* fp = fopen(fname, "rb"); //(6) 이진 파일 로드
    if (!fp) initRanking();
    else {
        fread(MVP, sizeof(PlayInfo), NUM_MVP, fp);
        fclose(fp);
    }
}

void storeRanking(const char* fname) {
    FILE* fp = fopen(fname, "wb"); //(6) 이진 파일 저장
    if (!fp) return;
    fwrite(MVP, sizeof(PlayInfo), NUM_MVP, fp);
    fclose(fp);
}

void printRanking() {
    printf("\n===== 랭킹 =====\n");
    for (int i = 0; i < NUM_MVP; i++)
        printf("[%2d위] %4d  %-10s %5.1f초\n",
               i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
}

int addRanking(int nMove, double tElap) {
    if (nMove < MVP[NUM_MVP - 1].nMove) {
        int pos = NUM_MVP - 1;
        for (; pos > 0; pos--) {
            if (nMove >= MVP[pos - 1].nMove) break;
            MVP[pos] = MVP[pos - 1];
        }
        MVP[pos].nMove = nMove;
        MVP[pos].tElapsed = tElap;

        printf("%d위! 이름 입력: ", pos + 1);
        scanf("%s", MVP[pos].name);
        return pos + 1;
    }
    return 0;
}
