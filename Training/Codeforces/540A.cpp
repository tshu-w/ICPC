#include <stdio.h>
int change(int a, int b);
int main(int argc, const char * argv[]) {
    int n, ans = 0;
    char c;
    int orig[1010], com[1010];
    scanf("%d", &n);
    c = getchar();
    for (int i = 0; i < n;i++){
        c = getchar();
        orig[i] = c-'0';
    }
    c = getchar();
    for (int i = 0; i < n;i++){
        c = getchar();
        com[i] = c-'0';
    }
    for (int i = 0; i < n;i++)
        ans +=change(orig[i], com[i]);
    printf("%d\n", ans);
    return 0;
}
int change(int a, int b){
    int p;
    p = (a > b)? a-b:b-a;
    if (p>5) p = 10-p;
    return p;
}