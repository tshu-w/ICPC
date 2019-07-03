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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 300;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, outmax, incnt;
char s[MAX_N]; 

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    scanf("%s", s);
    s[n++] = '_';
    int status = 0, last = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            outmax = max(outmax, i - last);
            status = 1;
            last = i + 1;
        }
        if (s[i] == ')') {
            if (i - last > 0) ++incnt;
            status = 0;
            last = i + 1;
        }
        if (s[i] == '_') {
            if (status) {
                if (i - last > 0)
                    ++incnt;
            }
            else outmax = max(outmax, i - last);
            last = i + 1;
        }
        // printf("%d %d %d\n", i, outmax, incnt);
    }
    printf("%d %d\n", outmax, incnt);
    return 0;
}