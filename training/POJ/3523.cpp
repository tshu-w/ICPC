// written at 16:59 on 8 Mar 2017 
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
typedef pair<unsigned short, int > Psi;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};

inline unsigned short h(const int &s, const unsigned short d_min[3][256], const int &N) {
    unsigned short l = 0;
    for (int i = 0; i < N; i++) 
        l = max(l, d_min[i][(s >> (i << 3)) & 0xff]);
    return l;
}

int move(int N, char grid[16][20], int cur, int dir[3]) {
    int nxt = 0;
    for (int i = 0; i < N; i++) {
        const int from = (cur >> (i << 3)) & 0xff;
        const int xx = (from >> 4) + dx[dir[i]];
        const int yy = (from & 0xf) + dy[dir[i]];
        if (grid[xx][yy] == '#') return -i - 1;
        const int tmp = (xx << 4) | yy;
        for (int j = 0; j < i; j++) {
            const int pre = (nxt >> (j << 3)) & 0xff;
            if (tmp == pre) return 0;
            if (tmp == ((cur >> (j << 3)) & 0xff) && pre == from) return 0; 
        }
        nxt |= tmp << (i << 3);
    }
    return nxt;
}

int main(int argc, char const *argv[])
{
    int W, H, N;
    while (scanf("%d%d%d ", &W, &H, &N), N) {
        int bgn = 0, end = 0;
        char grid[16][20];
        for (int i = 0; i < H; i++) {
            scanf("%[^\n]%*c", grid[i]);
            for (int j = 0; j < W; j++) {
                if (islower(grid[i][j])) {
                    bgn |= (i << 4 | j) << ((grid[i][j] - 'a') << 3);
                    grid[i][j] = ' ';
                } else if (isupper(grid[i][j])) {
                    end |= (i << 4 | j) << ((grid[i][j] - 'A') << 3);
                    grid[i][j] = ' ';
                }
            }
        }
        const int A = N >= 0? 5 : 1;
        const int B = N >= 1? 5 : 1;
        const int C = N >= 2? 5 : 1;

        static unsigned short int d_min[3][256];
        for (int i = 0; i < N; i++) {
            memset(d_min[i], 0xff, 256 * sizeof(unsigned short int));
            queue<int> q;
            int pos = (end >> (i << 3)) & 0xff;
            q.push(pos);
            d_min[i][pos] = 0;
            while (q.size()) {
                const int cur = q.front(); q.pop();
                const int x = cur >> 4;
                const int y = cur & 0xf;
                for (int d = 1; d < 5; d++) {
                    const int xx = x + dx[d];
                    const int yy = y + dy[d];
                    const int to = (xx << 4) | yy;
                    if (grid[xx][yy] != '#' && d_min[i][cur] + 1 < d_min[i][to]) {
                        d_min[i][to] = d_min[i][cur] + 1;
                        q.push(to);
                    }
                }
            }
        }

        static unsigned short dist[256 * 256 * 256];
        memset(dist, 0xff, sizeof(dist));
        dist[bgn] = 0;
        priority_queue<Psi, vector<Psi>, greater<Psi > > que;
        que.push(Psi(h(bgn, d_min, N), bgn));
        while (que.size()) {
            const unsigned short cost = que.top().first;
            const int cur = que.top().second;
            que.pop();
            if (cur == end) {
                printf("%d\n", cost);
                break;
            }
            const unsigned short d = cost - h(cur, d_min, N);
            if (d > dist[cur]) continue;

            int dir[3];

            for (dir[0] = 0; dir[0] < A; dir[0]++) {
                for (dir[1] = 0; dir[1] < B; dir[1]++) {
                    for (dir[2] = 0; dir[2] < C; dir[2]++) {
                        const int nxt = move(N, grid, cur, dir);
                        if (nxt == 0) continue;
                        else if (nxt < 0) {
                            if (nxt == -1)
                                goto SKIP_A;
                            else if (nxt == -2)
                                goto SKIP_B;
                            else continue;
                        }
                        if (d + 1 < dist[nxt]) {
                            dist[nxt] = d + 1;
                            que.push(Psi(dist[nxt] + h(nxt, d_min, N), nxt));
                        }
                    }
                    SKIP_B:;
                }
                SKIP_A:;
            }
        }
    } 
    return 0;
}