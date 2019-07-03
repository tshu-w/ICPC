// written at 09:34 on 22 Feb 2017 
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
const int MAX_N = 2000 + 10;

int N;
string s;
char ss[MAX_N];

int main(int argc, char const *argv[])
{
    cin >> N >> s;
    ss[N] = 0;
    int mid = (N + 1) / 2 - 1;
    if (N & 1) {
        ss[mid] = s[0];
        rep(i, 1, N / 2 + 1) {
            ss[mid - i] = s[2 * i - 1];
            ss[mid + i] = s[2 * i];
        }
    } else {
        rep(i, 0, N / 2) {
            ss[mid - i] = s[2 * i];
            ss[mid + 1 + i] = s[2 * i + 1];
        }
    }
    puts(ss);
    return 0;
}