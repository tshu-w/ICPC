// #include <bits/stdc++.h>
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

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};
const int digital[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1} };
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main(int argc, char const *argv[])
{
    int x[15], y[15], n = 0, a;
    char s[15];
    cin >> n;
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        a = s[i] - '0';
        // cout << a << endl;
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 3; ++k)
                if (digital[j][k] == a) {
                    x[i] = j, y[i] = k;
                    DEBUG("%d %d\n", j, k);
                }
    }
    for (int i = 0; i < 4; ++i) {
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            int xx, yy;
            xx = x[j] + dx[i];
            yy = y[j] + dy[i];
            DEBUG("%d %d\n", xx, yy);
            if (!(xx >= 0 && xx < 4 && yy >= 0 && yy < 3 && digital[xx][yy] != -1)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "NO" << endl;
            return 0;
        }
        else continue;
    }
    cout << "YES" << endl;
    return 0;
}