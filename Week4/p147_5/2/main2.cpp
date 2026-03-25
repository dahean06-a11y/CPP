#include "p147_5-2.hpp"

int main()
{
    int nTurn, nBullets;
    srand((unsigned)time(NULL));

    printf("게임 인원 ==> ");
    scanf("%d",&nTurn);
    printf("총알 개수(6미만) ==> ");
    scanf("%d",&nBullets);
    getchar();

    playRussianRoulette(nTurn, nBullets);
}