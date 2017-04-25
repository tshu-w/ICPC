// written at 09:32 on 15 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename "A-large"
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

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int t, r, c;
char field[30][30];
bool f[30];

int main(int argc, char const *argv[])
{
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        memset(f, false, sizeof f);
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            cin >> field[i];
        }
        for (int i = 0; i < r; i++) {
            int lst = -1;
            for (int j = 0; j < c; j++) {
                if (field[i][j] != '?' && !f[field[i][j] - 'A']) {
                    // cout << i << " " << j << endl;
                    f[field[i][j] - 'A'] = true;
                    int m, u;
                    for (m = j + 1; m < c; m++)
                        if (field[i][m] != '?') break;
                    for (u = i - 1; u >= 0; u--)
                        if (field[u][j] != '?') break;
                    // cout << u + 1 << " " << m << endl;
                    for (int k = u + 1; k < r; k++) {
                        bool flag = true;
                        for (int l = lst + 1; l < m; l++)
                            if (field[k][l] != '?' && field[k][l] != field[i][j]) {
                                flag = false; break;
                            }
                        if (flag)
                            for (int l = lst + 1; l < m; l++)
                                field[k][l] = field[i][j];
                        else break;
                    }
                    // for (int i = 0; i < r; i++)
                    //     cout << field[i] << endl;
                    // cout << endl;
                    j = m - 1;
                }
                if (field[i][j] != '?') lst = j;
            }
        }
        printf("Case #%d:\n", _ + 1);
        for (int i = 0; i < r; i++)
            cout << field[i] << endl;
    }
    resetfile();
    return 0;
}