// written at 15:46 on 26 Feb 2017 
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
const int MAX_N = 2e5 + 10;

string s, ss;
int A[MAX_N], N, M;

bool C(int k) {
    string st = s;
    rep(i, 0, k) st[A[i]] = '_';
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (st[i] == ss[j]) ++j;
        ++i;
    }
    return j == M;
}

int main(int argc, char const *argv[])
{
    cin >> s >> ss; N = s.size(); M = ss.size();
    rep(i, 0, N) scanf("%d", A + i), --A[i];
    int lb = 0, ub = N - M + 1;
    while (lb + 1 < ub) {
        int mid = (ub - lb) / 2 + lb;
        if (C(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << endl;
    return 0;
}