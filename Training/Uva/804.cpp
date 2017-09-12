// written at 19:05 on 06 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1e2 + 10;

int np, nt, nf, tokens[maxn];
vector<int> input[maxn], output[maxn];

void remove(int it) {
    for (int i = 0; i < (int)input[it].size(); i++)
        tokens[input[it][i]]--;
}

void resume(int it) {
    for (int i = 0; i < (int)input[it].size(); i++)
        tokens[input[it][i]]++;
}

void action(int it) {
    remove(it);
    for (int i = 0; i < (int)output[it].size(); i++)
        tokens[output[it][i]]++;
}

bool trigger(int it) {
    bool ok = true;
    remove(it);
    for (int i = 1; i <= np; i++)
        ok &= tokens[i] >= 0;
    resume(it);
    return ok;
}

int simulate() {
    for (int i = 0; i < nf; i++) {
        bool flag = false;
        for (int j = 0; j < nt; j++)
            if (trigger(j)) {
                action(j);
                flag = true;
                break;
            }
        if (!flag) return printf("dead after %d transitions\n", i);
    }
    return printf("still live after %d transitions\n", nf);
}

int main() {
    while (scanf("%d", &np) && np) {
        for (int i = 1; i <= np; i++)
            scanf("%d", tokens + i);
        scanf("%d", &nt);
        for (int i = 0, x; i < nt; i++) {
            input[i].clear(); output[i].clear();
            while (scanf("%d", &x) && x)
                if (x < 0) input[i].push_back(-x);
                else output[i].push_back(x);
        }
        scanf("%d", &nf);
        static int cs = 0;
        printf("Case %d: ", ++cs);
        simulate();
        printf("Places with tokens:");
        for (int i = 1; i <= np; i++)
            if (tokens[i]) printf(" %d (%d)", i, tokens[i]);
        printf("\n\n");
    }
    return 0;
}
