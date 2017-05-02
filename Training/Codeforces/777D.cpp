// written at 17:51 on 24 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 5e5 + 10;

int N;
string s[MAX_N];

int main(int argc, char const *argv[])
{
    IOS;
    cin >> N;
    rep(i, 0, N) {
        cin >> s[i];
    }
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j < s[i].size(); ++j) 
            if (s[i][j] < s[i + 1][j]) break;
            else if (s[i][j] > s[i + 1][j]) {
                s[i].resize(j); break;
            }
    }
    rep(i, 0, N) cout << s[i] << endl;
    return 0;
}