// written at 17:12 on 25 Mar 2017 
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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
const int MAX_N = 1e5 + 10;

class SquareMaking 
{
public:
    int getMinimalPrice(int a, int b, int c, int d) {
        int ans = INF;
        for (int i = 1; i <= 1e6; i++) {
            ans = min(ans, abs(i - a) + abs(i - b) + abs(i - c) + abs(i - d));
        }
        return ans;
    }
};

int main() {
    
    return 0;
}