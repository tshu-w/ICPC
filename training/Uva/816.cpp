// written at 18:51 on 07 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define BREAKPOINT cerr << "Fine" << endl;

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 20;
const char dirs[] = "NESW";
const char turns[] = "FLR";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Node {
    int x, y, dir;
    Node (int _x = 0, int _y = 0, int _dir = 0) : x(_x), y(_y), dir(_dir) {}
};

inline int dir_id(char ch) {return strchr(dirs, ch) - dirs;}
inline int turn_id(char ch) {return strchr(turns, ch) - turns;}

Node walk(const Node &u, int turn) {
    int dir = u.dir;
    if (turn == 1) dir = (dir + 3) % 4;
    if (turn == 2) dir = (dir + 1) % 4;
    return Node(u.x + dx[dir], u.y + dy[dir], dir);
}

bool inside(int x, int y) {
    return x >= 1 && x <= 9 && y >= 1 && y <= 9;
}

char maze[100], sdir[100];
bool flag[maxn][maxn][5][5], vis[maxn][maxn][5];
int sx, sy, ex, ey;
Node p[maxn][maxn][5];

void read() {
    memset(flag, false, sizeof flag);
    memset(vis, false, sizeof vis);
    scanf("%d%d%s%d%d", &sx, &sy, sdir, &ex, &ey);
    for (int x, y; scanf("%d", &x) && x && scanf("%d", &y);) {
        for (char s[10]; scanf("%s", s) && s[0] != '*';) {
            for (int i = 1; i < (int)strlen(s); i++)
                flag[x][y][dir_id(s[0])][turn_id(s[i])] = true;
        }
    }
}

void print(Node u) {
    vector<Node> nodes;
    for (;u.dir != -1; u = p[u.x][u.y][u.dir])
        nodes.push_back(u);
    nodes.push_back(u);
    reverse(nodes.begin(), nodes.end());
    for (int i = 0; i < (int)nodes.size(); i++) {
        if (i % 10 == 0) putchar(' ');
        printf(" (%d,%d)", nodes[i].x, nodes[i].y);
        if (i % 10 == 9) printf("\n");
    }
    if (nodes.size() % 10 != 0) puts("");
}

void solve() {
    Node s = Node(sx, sy, dir_id(sdir[0]));
    s = walk(s, sdir[0]);
    vis[s.x][s.y][s.dir] = true;
    p[s.x][s.y][s.dir] = Node(sx, sy, -1);
    queue<Node> que; que.push(s);
    while (!que.empty()) {
        Node v = que.front(); que.pop();
        if (v.x == ex && v.y == ey) return print(v);
        for (int i = 0; i < 3; i++) {
            Node u = walk(v, i);
            if (flag[v.x][v.y][v.dir][i] && inside(v.x, v.y) && !vis[u.x][u.y][u.dir]) {
                vis[u.x][u.y][u.dir] = true;
                p[u.x][u.y][u.dir] = v;
                que.push(u);
            }
        }
    }
    puts("  No Solution Possible");
}

int main() {
    while (scanf("%s", maze) && strcmp(maze, "END")) {
        puts(maze);
        read();
        solve();
    }
    return 0;
}
