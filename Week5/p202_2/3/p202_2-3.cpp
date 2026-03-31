#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomMap(int map[5][5]) {  
    srand(time(NULL)); 

    for (int i = 0; i < 5; i++) {  
                                  
      for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;
        }        
    }
}

void printMap(int map[5][5]) {
    printf("+---+---+---+---+---+\n");  
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
    
            printf("| %d ", map[i][j]); 
        }

        printf("|\n+---+---+---+---+---+\n"); 
    }
}

void checkMap(int map[5][5]) {
    int i, j;  
    int found = 0;   
    
    for (i = 0; i < 5; i++) {  

        if (map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][2] == map[i][3] && map[i][3] == map[i][4]) {

            printf("%d번째 행이 모두 %d입니다.\n", i + 1, map[i][0]);
            found = 1;
        }
    }
    
    for (j = 0; j < 5; j++) {  

        if (map[0][j] == map[1][j] && map[1][j] == map[2][j] && map[2][j] == map[3][j] && map[3][j] == map[4][j]) {
            
            printf("%d번째 열이 모두 %d입니다.\n", j + 1, map[0][j]);
            found = 1;
        }
    }
    
    if (map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[2][2] == map[3][3] && map[3][3] == map[4][4]) {
        printf("우하향 대각선이 모두 %d입니다.\n", map[0][0]);
        found = 1;
    }
 
    if (map[0][4] == map[1][3] && map[1][3] == map[2][2] && map[2][2] == map[3][1] && map[3][1] == map[4][0]) {
        printf("우상향 대각선이 모두 %d입니다.\n", map[0][4]);
        found = 1;
    }
    
    if (!found) {
        printf("가로나 세로 또는 대각선이 모두 같은 성분인 경우가 없습니다.\n");
    }
}

int main() {
    int map[5][5];
    randomMap(map);
    printMap(map);
    checkMap(map);
    return 0;
}