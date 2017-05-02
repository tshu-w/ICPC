#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int swap(int &x, int &y) {
    if (x > y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int a, b, t = 0, tmp;
    scanf("%d%d", &a, &b);
    while (a && b) {
        swap(a ,b);
        if (a == 1 && b == 1)
            t--;
        if (b == 1 || b == 2)
            break;
        tmp = (b - 1) / 2;
        a += tmp;
        t += tmp;
        b -= tmp * 2;
        //printf("%d %d\n", a, b);
    }
    printf("%d\n", t + 1);
    return 0;
}