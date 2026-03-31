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

int main() {
    int map[5][5];  

    randomMap(map);
 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", map[i][j]);  
        }       
        printf("\n");  
    }
    
    return 0;
}