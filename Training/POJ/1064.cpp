#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;
const int INF = INT_MAX;

int N, k;
double L[MAX_N];

bool C(double x) {
    int num = 0;
    for (int i = 0; i < N; ++i)
        num += (int)(L[i] / x);
    return num >= k;
}

int main(void) {
    scanf("%d%d", &N, &k);
    for (int i = 0; i < N; ++i)
        scanf("%lf", &L[i]);
    double lb = 0, ub = INF;
    for (int i = 0; i < 100; ++i) {
        double mid = (lb + ub) / 2;
        if (C(mid)) lb = mid;
        else ub = mid;
    }
    printf("%.2f\n", floor(ub * 100) / 100);
    return 0;
}
