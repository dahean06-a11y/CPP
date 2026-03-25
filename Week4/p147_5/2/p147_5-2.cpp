#include "p147_5-2.hpp"
int playRussianRoulette(int nTurns, int nBullets)
{
    int chamber[6] = {0};

    for(int i = 0; i < nBullets; ) {
        int idx = rand() % 6;
        if(chamber[idx] == 0) {
            chamber[idx] = 1;
            i++;
        }
    }

    int start = rand() % nTurns;
    printf("\n총을 돌렸습니다. %d번부터 시작합니다.\n", start + 1);

    int current = start;
    int bulletIndex = 0;

    while(true) {
        printf("[%d]번\t엔터를 누르면 격발됩니다...", current + 1);
        getchar();

        if(chamber[bulletIndex] == 1) {
            printf("\t빵~~~~~~~~~~!!!\n");
            return current + 1;  
        }

        printf("\t휴~~ 살았습니다!!!\n");

        current = (current + 1) % nTurns;
        bulletIndex = (bulletIndex + 1) % 6;
    }
}