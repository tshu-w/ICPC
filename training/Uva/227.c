#include <stdio.h>
#include "string.h"
#define N 5

int main(int argc, const char * argv[]) {
    char maps[N][N];
    char cmd[1005];
    int x_space, y_space, cases = 0;
    
    while (gets(maps[0])) {
        if (maps[0][0] == 'Z') break;
        for (int i = 1; i < N; i++) {
            gets(maps[i]);
            //if (strlen(maps[i]) == 4) maps[i][4] = ' ';
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (maps[i][j]==' '){
                    x_space = i;
                    y_space = j;
                    break;
                }
        int count = 0;
        while (~scanf("%c", &cmd[count]))
            if (cmd[count] != '0') count++;
            else break;
        cmd[count] = 0;
        getchar();
        
        int xx, yy, flag = 1;
        for (int i = 0; cmd[i]; i++){
            switch (cmd[i]){
                case 'A':     xx = x_space - 1; yy = y_space;break;
                case 'B':     xx = x_space + 1; yy = y_space;break;
                case 'L':     xx = x_space; yy = y_space - 1;break;
                case 'R':     xx = x_space; yy = y_space + 1;break;
            }
            if (xx < 0|| xx > 4|| yy < 0|| yy > 4) {
                flag = 0;
                break;
            }
            maps[x_space][y_space] = maps[xx][yy];
            maps[xx][yy] = ' ';
            x_space = xx;
            y_space = yy;
            
        }
        
        if (cases) putchar('\n');
        printf("Puzzle #%d:\n", ++cases);
        
        if (flag)
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N - 1; j++) printf("%c ", maps[i][j]);
                printf("%c\n", maps[i][N-1]);
            }
        else printf("This puzzle has no final configuration.\n");
    }
    return 0;
}