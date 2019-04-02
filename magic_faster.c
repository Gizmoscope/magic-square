#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int count = 0;

char check(char v[]) {
    char i, j;

    char s[16];
    
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
    
    for (i = 0; i < 13; i++) {
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

void find(char square[], char entry) {
    char i, j, begin, end;

    if (entry == 7) {
        if (check(square)) {
            count++;
        }
        return;
    }

    if (entry == 3) {
        begin = max(18 - square[1] - square[2], 1);
        end = min(33 - square[1] - square[2], 16);
    } else if (entry == 6) {
        begin = max(18 - square[0] - square[3], max(18 - square[4] - square[5], 1));
        end = min(33 - square[0] - square[3], min(33 - square[4] - square[5], 16));
    } else {
        begin = 1;
        end = 16;
    }

    for (i = begin; i <= end; i++) {
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
    char* start = (char*) malloc(7*sizeof(char));
    find(start, 0);
    free(start);
    prgende=clock();
    printf("There are %i magic squares.\n", count);
    printf("Runtime %.2f seconds\n",(float)(prgende-prgstart) / CLOCKS_PER_SEC);
}
