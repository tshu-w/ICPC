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
const int MAX_N = 50000 + 10;
const int MAX_W = 500 + 10;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};

template <typename T>
inline T sqr(T a) { return a * a;};

int M, X, Y, T, G[MAX_W][MAX_W];
bool vis[MAX_W][MAX_W];

bool check(int x, int y) {
    return (0 <= x && x < MAX_W && 0 <= y && y < MAX_W);
}
int main(int argc, char const *argv[])
{
    memset(G, -1, sizeof G);
    memset(vis, 0, sizeof vis);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &X, &Y, &T);
        for (int d = 0; d < 5; ++d) {
            int xx, yy;
            xx = X + dx[d]; yy = Y + dy[d];
            if (check(xx, yy) && (G[xx][yy] == -1 || G[xx][yy] > T))
                G[xx][yy] = T;
        }
    }
    queue<pair<Pii, int> > q;
    if (check(0, 0) && (G[0][0] == -1 || G[0][0] > 0)) {
        q.push(make_pair(Pii(0, 0), 0));
        vis[0][0] = true;
    }
    while (q.size()) {
        pair<Pii, int> p = q.front(); q.pop();
        if (G[p.first.first][p.first.second] == -1) {
            printf("%d\n", p.second);
            // cout << p.first.first << " " << p.first.second << endl;
            return 0;
        }    
        for (int i = 1; i < 6; ++i) {
            int xx, yy;
            xx = p.first.first + dx[i]; yy = p.first.second + dy[i];
            if (check(xx, yy) && !vis[xx][yy] && (G[xx][yy] == -1 || p.second + 1 < G[xx][yy])) {
                q.push(make_pair(Pii(xx, yy), p.second + 1));
                vis[xx][yy] = true;    
            }
        }
    }
    printf("-1\n");
    return 0;
}