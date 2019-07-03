// written at 20:58 on 10 May 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;


int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<Pii> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].second;
            v[i].first = i;
        }
        int it = 0;
        for (int i = 0; i < n; i++) {
            int imax = it;
            for (int j = it + 1; j < (int)v.size(); j++)
                if (v[j].second > v[imax].second) imax = j;

            for (; it < imax; it++)
                v.push_back(v[it]);
            if (v[it++].first == m) {
                cout << i + 1 << endl;
            }
        }
    }
    return 0;
}
