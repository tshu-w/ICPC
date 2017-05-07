// written at 18:46 on 07 May 2017
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

class RemovingParenthesis
{
public:
    int countWays(string s) {
        int ans = 1, n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt++;
            else {
                ans *= cnt;
                cnt--;
            }
        }
        return ans;
    }
};


int main(void) {

    return 0;
}
