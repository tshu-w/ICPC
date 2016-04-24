//Tips : 多组数据 mask.part 未初始化
#include <stdio.h>

typedef struct ip {
    int part[4];
} IP;

int toBitN(int n) {
    int res;
    for ( res = 0; n; res++)
        n /= 2;
    return res;
}
int IsMax(const IP a, const IP b) {
    for (int i = 0; i < 4; i++)
        if ( a.part[i] != b.part[i])
            return a.part[i] > b.part[i];
    return 0;
}
int IsMin(const IP a, const IP b) {
    for (int i = 0; i < 4; i++)
        if ( a.part[i] != b.part[i])
            return a.part[i] < b.part[i];
    return 0;
}
int getMinBit( const IP a, const IP b) {
    int res = 32;
    for (int i = 0; i < 4; i++)
        if ( a.part[i] != b.part[i]) {
            res = 8 - toBitN( a.part[i] ^ b.part[i]);
            res += 8 * i;
            break;
        }
    return res;
}
int main(int argc, char *argv[]) {
    int m;
    IP mask, max, min, cur;
    while ( ~scanf("%d", &m)) {
        scanf("%d.%d.%d.%d", &max.part[0], &max.part[1], &max.part[2], &max.part[3]);
        for (int i = 0; i < 4; i++) {
            min.part[i] = max.part[i];
            mask.part[i] = 0;
        }
        
        for (int i = 1; i < m; i++) {
            scanf("%d.%d.%d.%d", &cur.part[0], &cur.part[1], &cur.part[2], &cur.part[3]);
            if ( IsMax(cur, max) )
                for (int j = 0; j < 4; j++)
                    max.part[j] = cur.part[j];
            if ( IsMin(cur, min))
                for (int j = 0; j < 4; j++)
                    min.part[j] = cur.part[j];
        }
        
        int bit = getMinBit( min, max);
        int site = bit / 8;
        for (int i = 0; i < site; i++)
            mask.part[i] = 255;
        int nzeor = 8 - (bit - 8 * site);
        mask.part[site] = ( 255 >> nzeor) << nzeor;
        for (int i = 0; i < 4; i++)
            min.part[i] = min.part[i] & mask.part[i];
        printf("%d.%d.%d.%d\n", min.part[0], min.part[1], min.part[2], min.part[3]);
        printf("%d.%d.%d.%d\n", mask.part[0], mask.part[1], mask.part[2], mask.part[3]);
    }

    return 0;
}