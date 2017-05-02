#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

string line, digit;
ull n, m, len, u, d, u1, d1, u2, d2;
pair<ull, ull> ans;

template<typename T> T gcd(T a, T b) {
    //return (b)? gcd(b, a  % b) : a;
    while (b) { T t = a % b; a = b; b = t; } return a;
}
void simplify(ull &u, ull &d) {
    ull tmp = gcd(u, d);
    u /= tmp; d /= tmp;
}

int main(int argc, char const *argv[])
{
    while (cin >> line) {
        if (line == "0") break;
        digit = line.substr(2, line.length() - 5);
        len = digit.length();
        n = atoll(digit.c_str());
        ull k = 1;
        for (int i = 0; i < len; ++i, k *= 10) ;
        u = n; d = k - 1; simplify(u, d);
        ans = make_pair(u, d);
        for (ull i = 10; i <= k; i *= 10) {
            u1 = n / i * i; d1 = k; simplify(u1, d1);
            u2 = n % i; d2 = (i - 1) * k / i; simplify(u2, d2);
            u = u1 * d2 + u2 * d1; d = d1 * d2; simplify(u, d);
            if (d < ans.second)
                ans = make_pair(u, d);
        }
        cout << ans.first << "/" << ans.second << endl;
     }
    return 0;
}