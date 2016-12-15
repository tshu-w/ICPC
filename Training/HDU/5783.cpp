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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e6 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N];

int main() {
    while(~scanf("%d", &N)) {
        int tot = 0;
        ll sum = 0;
        bool flag = false;
        for(int i = 0; i < N; ++i) scanf("%d", A + i);
        for(int i = N - 1; i >= 0; --i) {
            if(!flag) {
                if(A[i] >= 0) ++tot;
                else {
                    sum = A[i];
                    flag = true;
                }
            } else {
                sum += A[i];
                if(sum >= 0) { ++tot; flag = false;}
            }
        }
        printf("%d\n", tot);
    }
    return 0;
}