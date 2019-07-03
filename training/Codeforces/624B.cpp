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
const int MAX_N = 30;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", A + i);
    int last = INF;
    ll ans = 0;
    sort(A, A + N);
    for (int i = N - 1; i >= 0 && last; --i) {
        if (last > A[i]) ans += A[i], last = A[i];
        else ans += --last;
    }
    cout << ans << endl;
    return 0;
}