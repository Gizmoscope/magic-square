#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int check(int v[]) {
    int i, j;
    int s[16];
    
        s[0] = -34 + v[0] + v[3] + v[4] + v[5] + v[6];
        s[1] = -34 + v[0] - v[1] + v[2] + v[3] + v[5] + 2 * v[6];
        s[2] = 68 - v[0] + v[1] - v[2] - v[3] - v[4] - 2 * v[5] - 2 * v[6];
        s[3] = 34 - v[0] - v[3] - v[6];
        s[4] = 0 - v[0] + v[1] + v[2];
        s[5] = 68 - v[0] - v[2] - v[3] - v[4] - v[5] - 2 * v[6];
        s[6] = -34 + v[0] - v[1] + v[3] + v[4] + v[5] + 2 * v[6];
        s[7] = v[0];
        s[8] = 34 - v[1] - v[2] - v[3];
        s[9] = v[1];
        s[10] = v[2];
        s[11] = v[3];
        s[12] = 34 - v[4] - v[5] - v[6];
        s[13] = v[4];
        s[14] = v[5];
        s[15] = v[6];
    
    for (i = 0; i < 16; i++) {
        if (s[i] < 1 || s[i] > 16) {
            return 0;
        }
        for (j = i + 1; j < 16; j++) {
            if (s[i] == s[j]) {
                return 0;
            }
        }
    }
    return 1;
}

void find(int square[], int entry) {
    int i, j;
    if (entry == 7) {
        if (check(square)) {
            count++;
        }
        return;
    }
    for (i = 1; i <= 16; i++) {
        for (j = 0; j < entry; j++) {
            if (square[j] == i) {
                goto A;
            }
        }
        square[entry] = i;
        find(square, entry + 1);
        A: i=i;
    }
}

void main() {
    clock_t prgstart, prgende;
    prgstart=clock();
    int* start = (int*) malloc(7*sizeof(int));
    find(start, 0);
    free(start);
    prgende=clock();
    printf("There are %i magic squares.\n", count);
    printf("Runtime %.2f seconds\n",(float)(prgende-prgstart) / CLOCKS_PER_SEC);
}
