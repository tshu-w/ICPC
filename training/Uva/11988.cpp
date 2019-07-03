// written at 10:11 on 23 Jul 2017
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

const int MAX_N = 1e5 + 10;

int cur, last, nxt[MAX_N];
char s[MAX_N];

int main() {
    while (scanf("%s", s + 1) == 1) {
        cur = last = nxt[0] = 0;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == '[') cur = 0;
            else if (s[i] == ']') cur = last;
            else {
                nxt[i] = nxt[cur];
                nxt[cur] = i;
                if (cur == last) last = i;
                cur = i;
            }
        }

        for (int i = nxt[0]; i != 0; i = nxt[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
