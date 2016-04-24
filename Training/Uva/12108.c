#include <stdio.h>

int main(int argc, const char * argv[]) {
    int awake, sleep, time, n, flag, cases = 0;
    int a[15], b[15], c[15], con[15];

    while ( scanf("%d", &n) && n ) {
        awake = sleep = 0;
        time = flag = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            if ( c[i] > a[i] ) {
                con[i] = 1;
                sleep++;
            }
            else {
                con[i] = 0;
                awake++;
            }
        }
        while ( flag ) {
            time++;
            for (int i = 0; i < n; i++) {
                c[i]++;
                if (c[i] > a[i] + b[i]) {
                    c[i] = 1;
                    con[i] = 0;
                }
                if ( c[i] > a[i] && !con[i] ) {
                    if ( sleep > awake ) {
                        con[i] = 1;
                    }
                    else
                        c[i] = 1;
                }
            }
            sleep = awake = 0;
            for (int i = 0; i < n; i++)
                if (con[i]) sleep++;
                else awake++;
            if ( awake == n ) break;
            if (time > 1000) flag = 0;
        }
        printf("Case %d: ", ++cases);
        if ( flag )
            printf("%d\n", time);
        else
            printf("-1\n");
    }
    
    return 0;
}