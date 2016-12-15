#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;
const int INF = INT_MAX;

int N, M, X[MAX_N];

bool C(int d) {
    int last = 0;
    for (int i = 1; i < M; ++i) {
        int crt = last + 1;
        while (crt < N && X[crt] - X[last] < d) ++crt;
        if (crt == N) return false;
        last = crt;
    }
    return true;
}

int main(void) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%d", X + i);
    sort(X, X + N);
    int lb = 0, ub = INF;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (C(mid)) lb = mid;
        else ub = mid;
        // cout << lb << " " << ub << " " << mid << endl;
    }
    printf("%d\n", lb);
    return 0;
}
