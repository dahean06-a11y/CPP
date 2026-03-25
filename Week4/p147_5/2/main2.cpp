#include "p147_5-2.hpp"
int main()
{
    int nTurn, nBullets;
    srand((unsigned)time(NULL));

    printf("게임 인원 (예:2) ==> ");
    scanf("%d",&nTurn);
    printf("총알 개수 ==> ");
    scanf("%d",&nBullets);
    getchar();

    for(int i = 0; i < nBullets; i++) {
    int bang = playRussianRoulette(nTurn, nBullets - i);

    printf("\n -----> %d번 참가자가 총에 맞았습니다.\n", bang);
}
}