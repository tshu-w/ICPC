// written at 17:49 on 06 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

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

const int maxn = 1e3 + 10;

int v, sum[maxn], cs;

void build(int p) {
    scanf("%d", &v);
    if (v == -1) return;
    sum[p] += v;
    build(p - 1); build(p + 1);
}

bool init() {
    scanf("%d", &v);
    if (v == -1) return false;
    memset(sum, 0, sizeof sum);
    int p = maxn / 2;
    sum[p] += v;
    build(p - 1);
    build(p + 1);
    return true;
}

int main() {
    while (init()) {
        int p = 0;
        while (!sum[p]) p++;
        printf("Case %d:\n%d", ++cs, sum[p++]);
        while (sum[p]) printf(" %d", sum[p++]);
        puts("\n");
    }
    return 0;
}
