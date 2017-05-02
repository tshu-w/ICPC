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
ll sum = 0, ans = 0, lmax = 0, A[MAX_N];

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
        lmax = max(A[i], lmax);
    }
    ans = sum / (N - 1) + (sum % (N - 1)? 1 : 0);
    cout << max(ans, lmax) << endl;
    return 0;
}
