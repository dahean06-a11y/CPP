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

int main() {
    int map[5][5];
    randomMap(map);  
    printMap(map);   
    return 0;
}