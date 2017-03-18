// written at 12:18 on 18 Mar 2017
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
const int MAX_N = 1e5 + 10;

int t;
string s;

int getMinString(const string &s) {  
    int len = (int)s.length();
    int i = 0, j = 1, k = 0;  
    while(i < len && j < len && k < len) {
        int t = s[(i+k)%len] - s[(j+k)%len];
        if(t == 0) k++;
        else {
            if(t > 0) i += k + 1;//getMaxString: t < 0
            else j += k + 1;
            if(i==j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        cin >> s;
        printf("%d\n", getMinString(s) + 1);
    } 
    return 0;
}