// written at 13:14 on 11 Mar 2017
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll N, M;
    while (cin >> N >> M && N + M) {
        ll ans = (M + N - 2) * N * M;
        if (N > M) swap(N, M);
        ans += 4 * (N - 2) * (N - 1) * N / 3;
        ans += (M - N + 1) * 2 * N * (N - 1);
        cout << ans << endl;
    }
    return 0;
}