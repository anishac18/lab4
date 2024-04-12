#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int **sptr;
    int num = 3;
    int i, j;

    sptr = malloc(sizeof(int *) * num);
    if (sptr == NULL) { // Added error checking
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }

    for (i = 0; i < num; i++) {
        sptr[i] = malloc(sizeof(int) * 4);
        if (sptr[i] == NULL) { // Added error checking
            fprintf(stderr, "Error: malloc failed\n");
            exit(1);
        }
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < 4; j++) {
            sptr[i][j] = sptr[i][j] + i * j + num; // Removed unnecessary addition
        }
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", sptr[i][j]); // Changed newline to space
        }
        printf("\n"); // Added newline
    }

    for (i = 0; i < num; i++) {
        free(sptr[i]); // Added memory deallocation
    }
    free(sptr); // Added memory deallocation

    return 0;
}


//gcc -Wall -Wextra -pedantic -o lab4File1 lab4File1.c
//valgrind --log-file=log_file2 ./lab4File2