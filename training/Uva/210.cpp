// written at 19:23 on 28 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 20;

struct program {
    int id;
    string stmt[30];
    int l, r;
}prg[MAX_N];
deque<program> rque, bque;

int n, t[10], q, T, var[30];

void solve() {
    bool flag = false;
    while (rque.size()) {
        int qq = q;
        program prgm = rque.front(); rque.pop_front();
        int &l = prgm.l, &r = prgm.r;
        while (qq > 0 && l < r) {
            int tt;
            if (prgm.stmt[l].substr(0, 2) == "pr") {
                char ch = prgm.stmt[l][6];
                printf("%d: %d\n", prgm.id, var[ch - 'a']);
                tt = t[2];
            } else if (prgm.stmt[l].substr(0, 2) == "lo") {
                if (!flag) {
                    flag = true;
                } else {
                    bque.push_back(prgm);
                    break;
                }
                tt = t[3];
            } else if (prgm.stmt[l].substr(0, 2) == "un") {
                flag = false;
                if (bque.size()) {
                    rque.push_front(bque.front());
                    bque.pop_front();
                }
                tt = t[4];
            } else if (prgm.stmt[l].substr(0, 2) == "en") {
                tt = t[5];
            } else {
                char ch = prgm.stmt[l][0];
                var[ch - 'a'] = stoi(prgm.stmt[l].substr(4));
                tt = t[1];
            }
            l++;
            qq -= tt;
        }
        if (qq <= 0 && l < r) rque.push_back(prgm);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(var, 0, sizeof var);
        scanf("%d", &n);
        for (int i = 1; i <= 5; i++) scanf("%d", t + i);
        scanf("%d\n", &q);
        for (int i = 1; i <= n; i++) {
            prg[i].id = i;
            prg[i].l = prg[i].r = 0;
            static string line;
            while (getline(cin, line)) {
                prg[i].stmt[prg[i].r++] = line;
                if (line == "end") break;
            }
            rque.push_back(prg[i]);
        }
        solve();
        if (T) puts("");
    }
    return 0;
}
