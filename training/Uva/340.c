#include <stdio.h>
#define MAXN 1010

int main(int argc, const char * argv[]) {
    int n, A, B, flag, kase = 0;
    int guess[MAXN], ans[MAXN];

    while (scanf("%d", &n)==1 && n) {
        printf("Game %d:\n", ++kase);
        for (int i = 0; i < n; i++) scanf("%d", &ans[i]);
        do{
            flag = 0;
            A = 0;B = 0;
            for (int  i = 0; i < n; i++){
                scanf("%d", &guess[i]);
                if (guess[i] != 0) flag = 1;
                if (guess[i] == ans[i]) A++;
            }
            for (int i = 0; i <= 9; i++){
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++){
                    if (ans[j] == i) c1++;
                    if (guess[j] == i) c2++;
                };
                B += (c1 < c2)? c1 : c2;
            }
            if (flag) printf("    (%d,%d)\n", A, B-A);
        }while (flag);
    }
    
    return 0;
}