#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 201314 + 5;
const ll MOD = 530600414;

template <typename T>
inline T sqr(T a) { return a * a;};

ll lft[MAX_N], rgh[MAX_N], f[MAX_N], cnt[MAX_N], len[MAX_N];

int main(int argc, char const *argv[])
{
    int t, cases = 0, n;
    cin >> t;
    len[1] = 1;len[2] = 2;
    cnt[1] = 1; cnt[2] = 0;
    for (int i = 3; i < MAX_N; ++i) {
        len[i] = (len[i - 1] + len[i - 2]) % MOD;
        cnt[i] = (cnt[i - 1] + cnt[i - 2]) % MOD;
    }
    lft[1] = lft[2] = 0;
    rgh[1] = 1;rgh[2] = 0;
    for (int i = 3; i < MAX_N; ++i) {
        lft[i] = (lft[i - 2] + lft[i - 1] + (len[i - 2] * cnt[i - 1]) % MOD) % MOD;
        rgh[i] = (rgh[i - 1] + rgh[i - 2] + (len[i - 1] * cnt[i - 2]) % MOD) % MOD;
    }
    f[3] = f[4] = 0;
    for (int i = 5; i < MAX_N; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + (cnt[i - 2] * lft[i - 1]) % MOD + (cnt[i - 1] * rgh[i - 2]) % MOD) % MOD;
    }
    // for (int i = 1; i < 10; ++i)
    //     cout << len[i] << ' ';
    // cout << endl;
    // for (int i = 1; i < 10; ++i)
    //     cout << cnt[i] << ' ';
    // cout << endl;
    //     for (int i = 1; i < 10; ++i)
    //     cout << lft[i] << ' ';
    // cout << endl;
    // for (int i = 1; i < 10; ++i)
    //     cout << rgh[i] << ' ';
    // cout << endl;
    while (t--) {
        cin >> n;
        cout << "Case #" << ++cases << ": " << f[n] << endl;
    }
    return 0;
}