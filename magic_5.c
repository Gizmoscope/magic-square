#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int count = 0;

char check(char v[]) {
    char i, j;

    char s[25];
    
        s[0] = v[0];
        s[1] = v[1];
        s[2] = v[2];
        s[3] = v[3];
        s[4] = 65 - v[0] - v[1] - v[2] - v[3];
        s[5] = v[4];
        s[6] = v[5];
        s[7] = v[6];
        s[8] = v[7];
        s[9] = 65 - v[4] - v[5] - v[6] - v[7];
        s[10] = v[8];
        s[11] = v[9];
        s[12] = v[10];
        s[13] = v[11];
        s[14] = 65 - v[8] - v[9] - v[10] - v[11];
        s[16] = v[12];
        s[18] = v[13];

        s[20] = 65 - s[4] - s[8] - s[12] - s[16];
        s[21] = 65 - s[1] - s[6] - s[11] - s[16];
        s[23] = 65 - s[3] - s[8] - s[13] - s[18];
        s[24] = 65 - s[0] - s[6] - s[12] - s[18];
        s[15] = 65 - s[0] - s[5] - s[10] - s[20];
        s[19] = 65 - s[4] - s[9] - s[14] - s[24];
        s[17] = 65 - s[15] - s[16] - s[18] - s[19];
        s[22] = 65 - s[20] - s[21] - s[23] - s[24];
    
    for (i = 4; i < 25; i++) {
        if (s[i] < 1 || s[i] > 25) {
            return 0;
        }
        for (j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                return 0;
            }
        }
    }

    for (i = 0; i < 25; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        if (s[i] < 10) {
            printf("  %i", s[i]);
        } else {
            printf(" %i", s[i]);
        }
    }

    return 1;
}

int loops = 0;

void find(char square[], char entry) {
    char i, j, begin, end;

    if (entry == 14) {
        if (check(square)) {
            count++;
        }
        return;
    }

    if (entry == 7) {
        loops = loops + 1;
        printf("%.7f percent (%i found)\n", (float)(loops) / 24227280, count);
    }

    if (entry == 2) {
        begin = max(16 - square[0] - square[1], 1);
        end = min(61 - square[0] - square[1], 25);
    } else if (entry == 3) {
        begin = max(40 - square[0] - square[1] - square[2], 1);
        end = min(64 - square[0] - square[1] - square[2], 25);
    } else if (entry == 6) {
        begin = max(16 - square[4] - square[5], 1);
        end = min(61 - square[4] - square[5], 25);
    } else if (entry == 7) {
        begin = max(40 - square[4] - square[5] - square[6], 1);
        end = min(64 - square[4] - square[5] - square[6], 25);
    } else if (entry == 8) {
        begin = max(16 - square[0] - square[4], 1);
        end = min(61 - square[0] - square[4], 25);
    } else if (entry == 9) {
        begin = max(16 - square[1] - square[5], 1);
        end = min(61 - square[1] - square[5], 25);
    } else if (entry == 10) {
        begin = max(16 - square[0] - square[5], max(16 - square[2] - square[6], max(16 - square[8] - square[9], 1)));
        end = min(61 - square[0] - square[5], min(61 - square[2] - square[6], min(61 - square[8] - square[9], 25)));
    } else if (entry == 11) {
        begin = max(40 - square[8] - square[9] - square[10], 1);
        end = min(64 - square[8] - square[9] - square[10], 25);
    } else if (entry == 12) {
        begin = max(40 - square[1] - square[5] - square[9], 1);
        end = min(64 - square[1] - square[5] - square[9], 25);
    } else if (entry == 13) {
        begin = max(40 - square[3] - square[7] - square[11], max(40 - square[0] - square[5] - square[10], 1));
        end = min(64 - square[3] - square[7] - square[11], min(64 - square[0] - square[5] - square[10], 25));
    } else {
        begin = 1;
        end = 25;
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
    char* start = (char*) malloc(14*sizeof(char));
    find(start, 0);
    free(start);
    prgende=clock();
    printf("There are %i magic squares.\n", count);
    printf("Runtime %.2f seconds\n",(float)(prgende-prgstart) / CLOCKS_PER_SEC);
}
