#include "p248_4.hpp"

int main()
{
    int width, height, total;

    printf(" <Mine Sweeper>\n");

    // (1) 맵 크기 입력 (가로 x 세로)
    printf(" 맵 크기 입력 (가로 세로, 최대 80 40): ");
    scanf("%d %d", &width, &height);

    // (2) 지뢰 개수 입력
    printf(" 매설할 지뢰 개수 입력: ");
    scanf("%d", &total);

    playMineSweeper(width, height, total);

    return 0;
}