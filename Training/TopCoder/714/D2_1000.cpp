// written at 19:34 on 07 May 2017
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

class Saleswoman
{
public:
    int minMoves(vector <int> pos, vector <int> delta) {
        int n = pos.size(), ans = pos[n - 1];
        int pre = 0, res = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (flag && res + delta[i] < 0) {
                flag = false;
                pre = i;
            }
            res += delta[i];
            if (res >= 0 && !flag) {
                ans += 2 * (pos[i] - pos[pre]);
                flag = true;
            }
        }
        return ans;
    }
};

int main(void) {

    return 0;
}
