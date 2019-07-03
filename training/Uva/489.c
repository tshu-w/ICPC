#include <stdio.h>
#include <string.h>

#define MAXN 1024
int main(int argc, const char * argv[]) {
    int T;
    int left, chance;
    char puzzle[MAXN], guess[MAXN];
    int win, lose;

    while (scanf("%d", &T)) {
        if (T == -1) break;
        scanf("%s%s", puzzle, guess);
        win = lose = 0;
        chance = 7;
        int p_len = strlen(puzzle);
        int g_len = strlen(guess);
        left = p_len;
        for (int i = 0; i < g_len; i++) {
            int bad = 1;
            for (int j = 0; j < p_len; j++)
                if (guess[i] == puzzle[j]) {
                    left--;
                    bad = 0;
                    puzzle[j] = ' ';
                }
            if (bad) chance--;
            if (!chance) lose = 1;
            if (!left) win = 1;
            if ( win|| lose) break;
        }
        printf("Round %d\n", T);
        if(win) printf("You win.\n");
        else
            if(lose) printf("You lose.\n");
            else printf("You chickened out.\n");
    }

    return 0;
}