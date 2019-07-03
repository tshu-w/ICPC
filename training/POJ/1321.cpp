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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, K, ans;
bool line[MAX_N];
char maze[MAX_N][MAX_N];
void dfs(int k, int cur) {
    if (k == K) {
        ++ans;
        return ;
    }
    int res = 0;
    for (int i = cur; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (maze[i][j] == '#' && !line[j]) {
                line[j] = true;
                dfs(k + 1, i + 1);
                line[j] = false;
            }
}
int main(int argc, char const *argv[])
{
    while (~scanf("%d%d%*c", &N, &K) && N != -1 && K != -1) {
        for (int i = 0; i < N; ++i) 
            gets(maze[i]);
        ans = 0;
        memset(line, false, sizeof line);
        dfs(0, 0);        
        printf("%d\n", ans);
    }
    return 0;
}