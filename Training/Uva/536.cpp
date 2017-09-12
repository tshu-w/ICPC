// written at 16:05 on 11 Aug 2017
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

const int maxn = 30;

int n;
char preord[maxn], inord[maxn];

void build(int l1, int r1, int l2, int r2) {
    int u = 0;
    for (int i = l2; i < r2; i++)
        if (inord[i] == preord[l1]) {
            u = i;
            break;
        }
    if (l2 < u) build(l1 + 1, l1 + u - l2 + 1, l2, u);
    if (u + 1 < r2) build(r1 - (r2 - u - 1), r1, u + 1, r2);
    putchar(preord[l1]);
}

int main() {
    while (~scanf("%s%s", preord, inord)){
        n = strlen(preord);
        build(0, n, 0, n);
        printf("\n");
    }
    return 0;
}
