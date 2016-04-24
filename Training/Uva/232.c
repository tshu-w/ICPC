#include <stdio.h>
#include "string.h"
#define MAXN 15

int main(int argc, const char * argv[]) {
    int r, c, t = 0;
    char word[MAXN][MAXN];
    int num[MAXN][MAXN];

    while (scanf("%d%d", &r, &c) == 2) {
        for (int i = 0; i < r; i++) scanf("%s", word[i]);
        memset(num, 0, sizeof(num));
        int cases = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                if (!i|| !j|| word[i-1][j] == '*'|| word[i][j-1] == '*')
                    if (word[i][j] != '*')
                        num[i][j] = ++cases;
        }
        if (t) putchar('\n');
        printf("puzzle #%d:\n", ++t);
        printf("Across\n");
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (num[i][j])
                if (j == 0|| word[i][j-1] == '*') {
                    int k = j;
                    printf("%3d.", num[i][j]);
                    while (k < c && word[i][k] != '*') putchar(word[i][k++]);
                    putchar('\n');
                }
        printf("Down\n");
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if(num[i][j])
                if (i == 0|| word[i-1][j] == '*') {
                    int k = i;
                    printf("%3d.", num[i][j]);
                    while (k < r && word[k][j] != '*') putchar(word[k++][j]);
                    putchar('\n');
                }
    }
    
    return 0;
}