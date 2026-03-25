#include "p147_5-2.hpp"

void playRussianRoulette(int nTurns, int nBullets)
{
    int chamber[6] = {0};

    for(int i = 0; i < nBullets; ) {
        int idx = rand() % 6;
        if(chamber[idx] == 0) {
            chamber[idx] = 1;
            i++;
        }
    }

    int alive[100] = {0};
    for(int i = 0; i < nTurns; i++) alive[i] = 1;

    int aliveCount = nTurns;

    int current = rand() % nTurns;
    int bulletIndex = 0;
    int deadCount = 0;

    printf("\n게임 시작!\n");

    while(deadCount < nBullets && aliveCount > 0) {

        if(alive[current] == 0) {
            current = (current + 1) % nTurns;
            continue;
        }

        printf("[%d]번\t엔터를 누르면 격발...", current + 1);
        getchar();

        if(chamber[bulletIndex] == 1) {
            printf("\t💥 %d번 사망\n", current + 1);

            alive[current] = 0;
            deadCount++;
            aliveCount--;
        } else {
            printf("\t휴~~ 살았습니다!!!\n");
        }

        current = (current + 1) % nTurns;
        bulletIndex = (bulletIndex + 1) % 6;
    }

    printf("\n게임 종료!\n");
    printf("생존자: ");
    for(int i = 0; i < nTurns; i++) {
        if(alive[i] == 1) printf("%d번 ", i + 1);
    }
    printf("\n");
}