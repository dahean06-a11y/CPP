#include "p248_4.hpp"

#define MAX_X 80
#define MAX_Y 40

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

// (1) 충분히 큰 배열을 선언 후 일부만 사용
static int MineMapMask[MAX_Y][MAX_X];
static int MineMapLabel[MAX_Y][MAX_X];

static int nx = 9, ny = 9;
static int nBomb = 10;

// ===== 기본 유틸 =====
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

// ===== 게임 로직 =====
static void dig(int x, int y) {
    if (isValid(x, y) && mask(x, y) != Open) {
        mask(x, y) = Open;
        if (label(x, y) == 0) {
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++)
                    if (!(dx == 0 && dy == 0))
                        dig(x + dx, y + dy);
        }
    }
}

static void mark(int x, int y) {
    if (isValid(x, y) && mask(x, y) == Hide)
        mask(x, y) = Flag;
}

static int getBombCount() {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (mask(x, y) == Flag) count++;
    return count;
}

static int countNbrBombs(int x, int y) {
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isValid(xx, yy) && label(xx, yy) == Bomb)
                count++;
    return count;
}

static void init(int width, int height, int total) {
    nx = width;
    ny = height;
    nBomb = total;

    srand((unsigned int)time(NULL));

    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            mask(x, y) = Hide;
            label(x, y) = 0;
        }

    // (2) 지뢰를 무작위로 매설
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (label(x, y) != Empty);
        label(x, y) = Bomb;
    }

    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(x, y) == Empty)
                label(x, y) = countNbrBombs(x, y);
}

// ===== 출력 =====
static void print() {
    system("clear");

    printf("   발견:%2d   전체:%2d\n", getBombCount(), nBomb);

    // (3) 열 번호 출력 (숫자)
    printf("    ");
    for (int x = 0; x < nx; x++)
        printf("%2d", x);
    printf("\n");

    // (3) 행 번호 출력 (숫자)
    for (int y = 0; y < ny; y++) {
        printf("%2d ", y);
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) == Hide) printf("□");
            else if (mask(x, y) == Flag) printf("¤");
            else {
                if (isBomb(x, y)) printf("※");
                else if (isEmpty(x, y)) printf("  ");
                else printf("%2d", label(x, y));
            }
        }
        printf("\n");
    }
}

// ===== 입력 =====
static bool getPos(int& x, int& y) {
    char cmd;
    printf("\n입력 (열 행) 또는 (p 열 행): ");

    scanf(" %c", &cmd);

    // (4) 사용자 입력 방식 변경
    if (cmd == 'p' || cmd == 'P') {
        scanf("%d %d", &x, &y); // Flag
        return true;
    } else {
        ungetc(cmd, stdin);
        scanf("%d %d", &x, &y); // Dig
        return false;
    }
}

// ===== 종료 검사 =====
static int checkDone() {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) != Open) count++;
            else if (isBomb(x, y)) return -1;
        }
    return (count == nBomb) ? 1 : 0;
}

// ===== 메인 게임 =====
void playMineSweeper(int width, int height, int total) {
    int x, y, status;

    init(width, height, total);

    do {
        print();
        bool isBomb = getPos(x, y);

        if (isBomb) mark(x, y);
        else dig(x, y);

        status = checkDone();
    } while (status == 0);

    print();

    if (status < 0)
        printf("\n실패: 지뢰 폭발!!!\n\n");
    else
        printf("\n성공: 탐색 성공!!!\n\n");
}