#include "p147_5-1.hpp"
int main()
{
    int nTurn, nBullets,n;
    srand((unsigned)time(NULL));

    printf("게임 인원 (예:2) ==> ");
    scanf("%d",&nTurn);
    printf("몇연발을 사용하시나요.");
    scanf("%d",&n);
    printf("총알 개수 ==> ");
    scanf("%d",&nBullets);
    getchar();

    int bang = playRussianRoulette(nTurn, nBullets, n);
    printf("\n -----> %d번 참가자가 총에 맞았습니다.\n", bang);
}