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
#include <iostream>
#include <fstream>

using namespace std;

typedef long L;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef long double LD;

const int INF = INT_MAX;
const int MAX_N = 1000;

int main(int argc, char const *argv[])
{
    int t, n, x[MAX_N], y[MAX_N], cases = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &x[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &y[i]);
        sort(x, x + n);
        sort(y, y + n);
        LL ans = 0LL;
        for (int i = 0; i < n; ++i) 
            ans += (LL)x[i] * y[n - i - 1];
        printf("Case #%d: %lld\n", ++cases, ans);
    }
    return 0;
}