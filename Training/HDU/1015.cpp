#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, len;
char s[MAX_N];

void find() {
    for (int i = 0; i < len; ++i) 
        for (int j = 0; j < len; ++j) if (i != j)
            for (int k = 0; k < len; ++k) if (i != k && j != k)
                for (int l = 0; l < len; ++l) if (i != l && j != l && k != l)
                    for (int m = 0; m < len; ++m) if (i != m && j != m && k != m && l != m) {
                        int v, w, x, y, z;
                        v = s[i] - 'A' + 1;
                        w = s[j] - 'A' + 1;
                        x = s[k] - 'A' + 1;
                        y = s[l] - 'A' + 1;
                        z = s[m] - 'A' + 1;
                        if (v - sqr(w) + sqr(x) * x - sqr(sqr(y)) + sqr(sqr(z)) * z == N) {
                            printf("%c%c%c%c%c\n", s[i], s[j], s[k], s[l], s[m]);
                            return ;
                        }
                    }
    printf("no solution\n");
    return ;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%d%s", &N, s) && N) {
        len = strlen(s);
        sort(s, s + len);
        reverse(s, s + len);
        find();
    }
    return 0;
}