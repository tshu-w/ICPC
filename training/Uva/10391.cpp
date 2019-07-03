// written at 19:56 on 09 May 2017
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

const int MAX_N = 120000 + 10;
string dict[MAX_N];

int main(void) {
    int n = 0;
    while (cin >> dict[n++]) ;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 1; j < (int)dict[i].size() && !flag; j++) {
            string s = dict[i].substr(0, j);
            if (*lower_bound(dict, dict + n, s) == s) {
                string t = dict[i].substr(j);
                if (*lower_bound(dict, dict + n, t) == t) {
                    flag = true;
                    cout << dict[i] << endl;
                }
            }
        }
    }
    return 0;
}
