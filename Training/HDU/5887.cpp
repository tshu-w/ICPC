#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100 + 10;
const int MAX_T = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, W, w[MAX_N], c[MAX_N];
ll f[MAX_T];

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &W)) {
        memset(f, 0, sizeof f);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", w + i, c + i);
            w[i] /= 10000;
        }
        W /= 10000;
        for (int i = 0; i < N; ++i)
            for (int j = W; j >= w[i]; --j)
                f[j] = max(f[j - w[i]] + c[i], f[j]);
        printf("%lld\n", f[W]);
    }
    return 0;
}
// void swap(int i, int j) {
//     int tmp;
//     tmp = v[i];
//     v[i] = v[j];
//     v[j] = tmp;
//     tmp  = w[i];
//     w[i] = w[j];
//     w[j] = tmp;
//     double tmp2;
//     tmp2 = rate[i];
//     rate[i] = rate[j];
//     rate[j] = tmp2;
// }


// void sort() {
//     for (int i = 0; i < n; ++ i) {
//         for (int j = i + 1; j < n; ++ j) {
//             if (rate[i] < rate[j]) swap(i, j);
//         }
//     }
// }

// bool can_cut(int k, int _vCurrent, long long _wCurrent) {
//     long double vCurrent = _vCurrent;
//     long double wCurrent = _wCurrent;
//     for (int i = k; i < n && vCurrent < vLimit; ++ i) {
//         if (vCurrent + v[i] < vLimit) {
//             vCurrent += v[i];
//             wCurrent += w[i];
//         } else {
//             wCurrent += rate[i] * (vLimit - vCurrent);
//             vCurrent = vLimit;
//         }
//     }
//     return wCurrent < wBest;
// }

// void search(int k, int vSum, long long wSum) {
//     if (wSum > wBest) {
//         wBest = wSum;
//     }
//     if (k < n && !can_cut(k, vSum, wSum)) {
//         if ((long long)vSum + v[k] <= vLimit) {
//             search(k + 1, vSum + v[k], wSum + w[k]);
//         }
//         search(k + 1, vSum, wSum);
//     }
// }

// int main() {
//     while (scanf("%d%d", &n, &vLimit) != EOF) {
//         for (int i = 0; i < n; ++ i) {
//             scanf("%d%d", &v[i], &w[i]);
//             rate[i] = (long double)w[i] / (long double)v[i];
//         }
//         sort();
//         wBest = 0;
//         search(0, 0, 0);
//         std::cout << wBest << std::endl;
//     }
// }