// written at 09:17 on 24 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename "D-small-practice"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 100 + 10;

struct Chs {
    char ch;
    int x, y;
    Chs(char _ch, int _x, int _y) : ch(_ch), x(_x), y(_y) {
    };
};

int t, n, m, ans;
int bishops[MAX_N][MAX_N], rooks[MAX_N][MAX_N], brd[MAX_N][MAX_N]; // +: bishops, x: rooks, o: queens
vector<Chs> chess;

void init() {
    memset(bishops, 0, sizeof bishops);
    memset(rooks, 0, sizeof rooks);
    memset(brd, 0, sizeof brd);
    chess.clear();
    ans = 0;
}

void addRooks() {
    bool rw[MAX_N], cl[MAX_N];
    memset(rw, false, sizeof rw);
    memset(cl, false, sizeof cl);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (rooks[i][j]) rw[i] = cl[j] = true;
    for (int i = 0; i < n; i++)
        if (!rw[i]) {
            for (int j = 0; j < n; j++)
                if (!cl[j]) {
                    brd[i][j]++;
                    rw[i] = cl[j] = true;
                    break;
                }
        }
}

void addBishops() {
    bool rw[MAX_N * 2], cl[MAX_N * 2];
    memset(rw, false, sizeof rw);
    memset(cl, false, sizeof cl);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (bishops[i][j]) {
                rw[i + j] = cl[i - j + n] = true;
            }

    while (true) {
        int imin = -1, rr;
        for (int r = 0; r < 2 * n - 1; r++) if (!rw[r]) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int j = r - i;
                if (0 <= j && j < n && !cl[i - j + n]) ++cnt;
            }
            if (cnt > 0) if (imin == -1 || imin > cnt) {
                imin = cnt;
                rr = r;
            }
        }
        // cout << imin << " " << rr << endl;
        if (imin == -1) break;
        for (int i = 0; i < n; i++) {
            int j = rr - i;
            if (0 <= j && j < n && !cl[i - j + n]) {
                // cout << i << ", " << j << endl;
                rw[i + j] = cl[i - j + n] = true;
                brd[i][j] += 2;
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {

        init();

        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            char ch; int x, y;
            while ((ch = getchar()) != '\n') ;
            scanf("%c%d%d", &ch, &x, &y);
            --x, --y;
            if (ch == 'x') rooks[x][y] = 1;
            if (ch == '+') bishops[x][y] = 2;
            if (ch == 'o') rooks[x][y] = 1, bishops[x][y] = 2;
        }

        addRooks();
        addBishops();

        //for (int i = 0; i < n; i++)
        //    for (int j = 0; j < n; j++)
        //        printf("%d%c", brd[i][j], " \n"[j + 1 == n]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                bool flag = brd[i][j];
                brd[i][j] += bishops[i][j] + rooks[i][j];
                if (brd[i][j] == 1) {
                    if (flag) chess.push_back(Chs('x', i + 1, j + 1));
                    ans++;
                }
                if (brd[i][j] == 2) {
                    if (flag) chess.push_back(Chs('+', i + 1, j + 1));
                    ans++;
                }
                if (brd[i][j] == 3) {
                    if (flag) chess.push_back(Chs('o', i + 1, j + 1));
                    ans += 2;
                }
            }

        printf("Case #%d: %d %d\n", _ + 1, ans, (int)chess.size());
        for (int i = 0; i < (int)chess.size(); i++)
            printf("%c %d %d\n", chess[i].ch, chess[i].x, chess[i].y);
    }
    resetfile();
    return 0;
}
