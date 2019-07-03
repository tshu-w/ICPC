#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int sum[10];
    int t;

    scanf("%d", &t);
    while (t--){
        int num;
        scanf("%d", &num);
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= num; i++){
            int k = i;
            while (k != 0){
                sum[k % 10]++;
                k = k / 10;
            }
        }
        for (int i = 0; i < 9; i++) printf("%d ", sum[i]);
        printf("%d\n", sum[9]);
    }
    
    return 0;
}