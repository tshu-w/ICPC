// written at 10:21 on 02 Oct 2017
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 100;

char s[1000];
vector<int> G[maxn], v, ansv;
int pos[maxn];
bool vis[maxn];

int main() {
    while (fgets(s, sizeof(s), stdin)) {
        if (s[0] == '#') break;
        for (int i = 0; i < maxn; i++) G[i].clear();
        v.clear();
        memset(vis, false, sizeof(vis));
        int len = strlen(s);
        for (int i = 0, j; i < len - 1; i++) {
            if (!vis[s[i] - 'A']) {
                v.push_back(s[i] - 'A'); vis[s[i] -'A'] = true;
            }
            for (j = i + 2; j < len - 1; j++)
                if (s[j] != ';') {
                    G[s[i] - 'A'].push_back(s[j] - 'A');
                    // G[s[j] - 'A'].push_back(s[i] - 'A');
                    if (!vis[s[j] - 'A']) {
                        v.push_back(s[j] - 'A'); vis[s[j] - 'A'] = true;
                    }
                }
                else break;
            i = j;
        }
        sort(v.begin(), v.end());
        int mbw = INT_MAX;
        do {
            for (int i = 0; i < SZ(v); i++) pos[v[i]] = i;
            int bw = 0;
            for (int i = 0; i < SZ(v); i++)
                for (int j = 0; j < SZ(G[v[i]]); j++) bw = max(bw, abs(pos[v[i]] - pos[G[v[i]][j]]));
            if (mbw > bw) {
                mbw = bw; ansv = v;
            }
        } while (next_permutation(v.begin(), v.end()));
        for (auto x : ansv) printf("%c ", x + 'A'); printf("-> %d\n", mbw);
    }
    return 0;
}
