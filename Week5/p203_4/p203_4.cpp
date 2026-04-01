#include "ranking.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <thread>

#define MAX 5 //(1) 최대 5x5

static int DIM; //(1) 퍼즐 크기 가변
static int map[MAX][MAX], initMap[MAX][MAX];
static int x, y;
static int nMove;
static char moves[1000]; //(2) 리플레이용 이동 기능
static int moveCount = 0;

using Clock = std::chrono::high_resolution_clock;
static Clock::time_point tStart;

struct SaveData {
    int DIM;
    int map[MAX][MAX];
    int x, y;
    int nMove;
    double elapsed;
    int moveCount;
    char moves[1000];
}; //(3), (4) 제임 저장/불러오기용 구조체

void display() {
    system("clear");
    printf("=== 퍼즐 (%dx%d) ===\n", DIM, DIM);

    for (int r = 0; r < DIM; r++) {
        for (int c = 0; c < DIM; c++) {
            if (map[r][c] == 0) printf("   ");
            else printf("%3c", 'A' + map[r][c] - 1);
        } //(5) 숫자 ->  문자 퍼즐 출력
        printf("\n");
    }

    auto now = Clock::now();
    double t = std::chrono::duration<double>(now - tStart).count();

    printf("\n이동:%d  시간:%.1f\n", nMove, t);
    printf("WASD 이동 | Q 저장 종료\n"); // (3) 저장 기능 안내
}

void init() {
    for (int i = 0; i < DIM * DIM - 1; i++)
        map[i / DIM][i % DIM] = i + 1;
    map[DIM - 1][DIM - 1] = 0;

    x = y = DIM - 1;
    nMove = 0;
    moveCount = 0;
    tStart = Clock::now();
}

bool move(char d) {
    if (d == 'a' && x < DIM - 1) { map[y][x] = map[y][x+1]; map[y][++x] = 0; }
    else if (d == 'd' && x > 0) { map[y][x] = map[y][x-1]; map[y][--x] = 0; }
    else if (d == 'w' && y < DIM - 1) { map[y][x] = map[y+1][x]; map[++y][x] = 0; }
    else if (d == 's' && y > 0) { map[y][x] = map[y-1][x]; map[--y][x] = 0; }
    else return false;

    moves[moveCount++] = d; // (2) 이동 기록 저장 -> 리플레이용
    nMove++;
    return true;
}

void shuffle() {
    for (int i = 0; i < 100; i++) {
        char keys[] = {'w','a','s','d'};
        if (!move(keys[rand()%4])) i--;
    }
    memcpy(initMap, map, sizeof(map)); // (2) 초기 상태 저장 (리플레이 시작점)
    moveCount = 0;
    nMove = 0;
}

bool isDone() {
    for (int i = 0; i < DIM*DIM-1; i++)
        if (map[i/DIM][i%DIM] != i+1) return false;
    return map[DIM-1][DIM-1] == 0;
}

void replay() {
    memcpy(map, initMap, sizeof(map));
    display();
    for (int i = 0; i < moveCount; i++) {
        move(moves[i]);
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
} // (2) 리플레이 기능

void saveGame() {
    FILE* fp = fopen("save.dat", "wb");

    SaveData d;
    d.DIM = DIM;
    memcpy(d.map, map, sizeof(map));
    d.x = x; d.y = y;
    d.nMove = nMove;
    d.moveCount = moveCount;
    memcpy(d.moves, moves, sizeof(moves));

    auto now = Clock::now();
    d.elapsed = std::chrono::duration<double>(now - tStart).count();

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
} // (3) 게임 저장 기능

bool loadGame() {
    FILE* fp = fopen("save.dat", "rb");
    if (!fp) return false;

    SaveData d;
    fread(&d, sizeof(d), 1, fp);

    DIM = d.DIM;
    memcpy(map, d.map, sizeof(map));
    x = d.x; y = d.y;
    nMove = d.nMove;
    moveCount = d.moveCount;
    memcpy(moves, d.moves, sizeof(moves));

    tStart = Clock::now() - std::chrono::seconds((int)d.elapsed);

    fclose(fp);
    return true;
} //(4) 이어하기 기능

int playFifteenPuzzle() {
    int sel;
    printf("1. 새게임  2. 이어하기 : ");
    scanf("%d", &sel);

    if (sel == 2 && loadGame()) {
        printf("불러오기 성공!\n");
    } else {
        printf("크기 선택 (3/4/5): "); //(1) 크기 선택 기능
        scanf("%d", &DIM);
        init();
        shuffle();
    } //(4) 이어하기

    while (!isDone()) {
        display();
        char c = getchar();
        if (c == '\n') continue;

        if (c == 'q') {
            saveGame();
            printf("저장됨!\n");
            exit(0);
        } //(3) 저장 후 종료

        move(c);
    }

    auto end = Clock::now();
    double t = std::chrono::duration<double>(end - tStart).count();

    display();
    printf("클리어!\n");

    replay(); // (2) 리플레이 실행

    return addRanking(nMove, t); //랭킹 등록
}
