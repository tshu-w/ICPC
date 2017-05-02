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
const int MAX_N = 50000;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, a;
set<int> s;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        s.insert(a);
    }
    while (true) {
        int tmp = *s.rbegin();
        bool flag = true;
        while (tmp)
            if (s.count(tmp) == 0) break;
            else tmp /= 2;

        // cout << tmp << endl;
        if (tmp) {
            s.erase(*s.rbegin());
            s.insert(tmp);
        } else break;
    }
    for (auto it : s)
        printf("%d ", it);
    printf("\n");
    return 0;
}