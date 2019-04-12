#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int count = 0;

char check(char v[]) {
    char i, j, a, b, c, d;

    char s[16];
    
        s[0] = v[0];
        s[1] = v[1];
        s[2] = v[2];
        s[3] = 34 - v[0] - v[1] - v[2];
        s[4] = v[3];
        s[5] = v[4];
        s[6] = v[5];
        s[7] = 34 - v[3] - v[4] - v[5];
        s[10] = v[6];
        s[14] = 34 - v[2] - v[5] - v[6];
        s[15] = 34 - v[0] - v[4] - v[6];
        s[11] = 34 - s[3] - s[7] - s[15];

        a = 34 - s[10] - s[11];
        b = 34 - s[14] - s[15];
        c = 34 - s[3] - s[6];
        d = 34 - s[0] - s[4];

        s[8] = (a - c + d) / 2;
        s[9] = (a + c - d) / 2;
        s[12] = (c + d - a) / 2;
        s[13] = b + (a - c - d) / 2;
    
    for (i = 3; i < 16; i++) {
        if (s[i] < 1 || s[i] > 16) {
            return 0;
        }
        for (j = 0; j < i; j++) {
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

    if (entry == 2) {
        begin = max(18 - square[0] - square[1], 1);
        end = min(33 - square[0] - square[1], 16);
    } else if (entry == 5) {
        begin = max(18 - square[3] - square[4], 1);
        end = min(33 - square[3] - square[4], 16);
    } else if (entry == 6) {
        begin = max(18 - square[0] - square[4], max(18 - square[2] - square[5], 1));
        end = min(33 - square[0] - square[4], min(33 - square[2] - square[5], 16));
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
    int i;
    for(i = 1; i<=8; i++) {
        start[0] = i;
        find(start, 1);
    }
    free(start);
    prgende=clock();
    printf("There are %i magic squares.\n", 2 * count);
    printf("Runtime %.2f seconds\n",(float)(prgende-prgstart) / CLOCKS_PER_SEC);
}
