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
#include <numeric>

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

int n, len;
ull num;

vector<int> prime_factor(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        int tmp = 0;
        while (n % i == 0) {
            ++tmp;
            n /= i;
        }
        res.push_back(tmp);
    }
    if (n != 1) res.push_back(1);
    return res;
}

ull factor(int n) {
    ull res = 1;
    for (int i = 1; i <= n; ++i)
        res *= i;
    return res;
}

int main(int argc, char const *argv[])
{
    while (cin >> n) {
        vector<int> fac = prime_factor(n);
        len = accumulate(fac.begin(), fac.end(), 0);
        num = factor(len);
        for (int i = 0; i < fac.size(); ++i) {
            num /= factor(fac[i]);
        }
        cout << len << " " << num << "\n";
    }    
    return 0;
}