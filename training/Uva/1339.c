#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int mark[26][2];
    char plan[105], mask[105];
    while (scanf("%s%s", mask, plan) == 2) {
        memset(mark, 0, sizeof(mark));
        int len1 = strlen(mask);
        int len2 = strlen(plan);
        if (len1 != len2) {
            printf("NO\n");
            continue;
        }
        
        for (int i = 0; i < len1; i ++)
            mark[mask[i] - 'A'][0]++;
        
        for (int i = 0; i < 26; i ++)
            for (int j = i + 1; j < 26; j ++)
                if (mark[i][0] > mark[j][0]) {
                    int temp = mark[i][0];
                    mark[i][0] = mark[j][0];
                    mark[j][0] = temp;
                }
        
        
        for (int i = 0; i < len2; i ++)
            mark[plan[i] - 'A'][1]++;
        
        for (int i = 0; i < 26; i ++)
            for (int j = i + 1; j < 26; j ++)
                if (mark[i][1] > mark[j][1]) {
                    int temp = mark[i][1];
                    mark[i][1] = mark[j][1];
                    mark[j][1] = temp;
                }
        
        int flag = 1;
        for (int i = 0; i < 26; i ++)
            if (mark[i][0] != mark[i][1]) {
                flag = 0;
                break;
            }
        printf((flag)? "YES\n" : "NO\n");
    }

    return 0;
}