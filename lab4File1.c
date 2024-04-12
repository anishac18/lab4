#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[] )
{
    
    int **sptr;
    
    int num = 3;
    int i, j;
    
    sptr = malloc (sizeof (int *) * num);
    
    for (i = 0; i < num; i++) {
        sptr [i] = malloc (sizeof(int) * 4);
    }
    
    for (i = 0; i < num; i++) {
        for (j = 0; j < 4; j++) {
            sptr [i][j] =  sptr[i][j] + i * j + num;
        }
    }
    
    for (i = 0; i < num; i++) {
        for (j = 0; j < 4; j++) {
            printf ("%d \n", sptr [i][j]);
        }
    }
    
    return 0;
}
