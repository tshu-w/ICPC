#include <stdio.h>

struct NODE {
    int h, w;
}a[6];

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main (void) {

    while (scanf("%d%d", &a[0].h, &a[0].w) == 2) {
        if (a[0].h > a[0].w) swap(&a[0].h, &a[0].w);
        for (int i = 1; i < 6; i++) {
            scanf("%d%d", &a[i].h, &a[i].w);
            if (a[i].h > a[i].w) swap(&a[i].h, &a[i].w);
        }
        for  (int i = 0; i < 6; i++)
            for (int j = i + 1; j < 6; j++)
                if ((a[i].h == a[j].h && a[i].w > a[j].w) || a[i].h > a[j].h) {
                    swap(&a[i].h, &a[j].h);
                    swap(&a[i].w, &a[j].w);
                }
        /*for (int i = 0 ; i < 6; i++)
            printf("%d %d\n", a[i].h, a[i].w);
        //*/
        int flag = 1;
        int x = a[0].h, y = a[0].w, z = a[2].w;
        
        if (x != a[1].h || x != a[2].h || x != a[3].h) flag = 0;
        if (y != a[1].w || y != a[4].h || y != a[5].h) flag = 0;
        if (z != a[3].w || z != a[4].w || z != a[5].w) flag = 0;
        
        printf( (flag)? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }

    return 0;
}