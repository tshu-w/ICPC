#include <stdio.h>
#include "string.h"

int main(int argc, const char * argv[]) {
    char DNA[55][1010];
    int mark[4];
    int t, m, n;

    scanf("%d", &t);
    while (t--) {
        int dis = 0;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%s", DNA[i]);
        for (int j = 0; j < n; j++) {
            memset(mark, 0, sizeof(mark));
            for (int i = 0; i < m; i++)
                switch (DNA[i][j]) {
                    case 'A':   mark[0]++;break;
                    case 'C':   mark[1]++;break;
                    case 'G':   mark[2]++;break;
                    case 'T':   mark[3]++;break;
                }
            int max = 0, base = 0;
            for (int j = 0; j < 4; j++)
                if (mark[j] > max) {max = mark[j]; base = j;}
            dis += m - max;
            switch (base) {
                case 0:     putchar('A');break;
                case 1:     putchar('C');break;
                case 2:     putchar('G');break;
                case 3:     putchar('T');break;
            }
        }
        putchar('\n');
        printf("%d\n", dis);
    }
    
    return 0;
}