// written at 15:16 on 07 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define BREAKPOINT cerr << "Fine" << endl

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

const int maxh = 200 + 5;
const int maxw = 50 * 4 + 5; const int dx[] = {0, -1, 0, 1}; const int dy[] = {-1, 0, 1, 0};
const char code[] = "WAKJSD";

char bin[256][4];
int h, w, pic[maxh][maxw], color[maxh][maxw];
char line[maxw];

void init() {
    strcpy(bin[(int)'0'], "0000"); strcpy(bin[(int)'1'], "0001"); strcpy(bin[(int)'2'], "0010"); strcpy(bin[(int)'3'], "0011");
    strcpy(bin[(int)'4'], "0100"); strcpy(bin[(int)'5'], "0101"); strcpy(bin[(int)'6'], "0110"); strcpy(bin[(int)'7'], "0111");
    strcpy(bin[(int)'8'], "1000"); strcpy(bin[(int)'9'], "1001"); strcpy(bin[(int)'a'], "1010"); strcpy(bin[(int)'b'], "1011");
    strcpy(bin[(int)'c'], "1100"); strcpy(bin[(int)'d'], "1101"); strcpy(bin[(int)'e'], "1110"); strcpy(bin[(int)'f'], "1111");
}

void decode(const char ch, int r, int c) {
    for (int i = 0; i < 4; i++) {
        pic[r][c + i] = bin[(int)ch][i] - '0';
    }
}

void dfs(int x, int y, int c) {
    color[x][y] = c;
    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (xx < 0 || xx >= h || yy < 0 || yy >= w || pic[xx][yy] != pic[x][y] || color[xx][yy]) continue;
        dfs(xx, yy, c);
    }
}

vector<set<int>> neighbors;

void check_neighbor(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (xx < 0 || xx >= h || yy < 0 || yy >= w || color[xx][yy] == 1 || pic[xx][yy]) continue;
        neighbors[color[x][y]].insert(color[xx][yy]);
    }
}

bool cmp(const int a, const int b) {
    return code[a] < code[b];
}

int main() {
    init();
    while (scanf("%d%d", &h, &w) && h + w) {
        memset(pic, 0, sizeof pic);
        for (int i = 0; i < h; i++) {
            scanf("%s", line);
            for (int j = 0; j < w; j++)
                decode(line[j], i + 1, j * 4 + 1);
        }
        h += 2;
        w = w * 4 + 2;

        int cnt = 0;
        vector<int> cc;
        memset(color, 0, sizeof color);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                if (!color[i][j]) {
                    dfs(i, j, ++cnt);
                    if (pic[i][j]) cc.push_back(cnt);
                }
            }

        neighbors.clear();
        neighbors.resize(cnt + 1);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (pic[i][j]) check_neighbor(i, j);

        vector<int> ans;
        for (int i = 0; i < (int)cc.size(); i++)
            ans.push_back(neighbors[cc[i]].size());
        sort(ans.begin(), ans.end(), cmp);

        static int cs = 0;
        printf("Case %d: ", ++cs);
        for (auto x : ans)
            printf("%c", code[x]);
        puts("");
    }
    return 0;
}
