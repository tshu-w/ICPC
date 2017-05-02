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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N; 
ll A[MAX_N], dp[MAX_N][2];
string s[MAX_N], ss, sc;

int main(int argc, char const *argv[])
{
    IOS;
    cin >> N;
    for (int i = 0; i < N; ++i) 
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> s[i];
    for (int i = 0; i < N; ++i)
        dp[i][0] = dp[i][1] = LLONG_MAX / 3;
    dp[0][0] = 0; dp[0][1] = A[0];
    for (int i = 1; i < N; ++i) {
        ss = s[i - 1];
        reverse(ss.begin(), ss.end());
        if (s[i] >= s[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i] >= ss)
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        sc = s[i];
        reverse(sc.begin(), sc.end());
        if (sc >= s[i - 1]) 
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + A[i]);
        if (sc >= ss)
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + A[i]);
    }
    if (dp[N - 1][0] == LLONG_MAX / 3 && dp[N - 1][1] == LLONG_MAX / 3)
        cout <<  -1  << "\n";
    else cout << min(dp[N - 1][0], dp[N - 1][1]) << "\n";
    return 0;
}