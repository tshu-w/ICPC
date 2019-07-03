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
const int MAX_N = 1000 + 10;
const int dx[] = {1, 2};
const int dy[] = {2, 1};

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, type, t, k;

int king(int n, int m) {
    return ((n & 1) && (m & 1))? 1 : 0;
}
int queen(int n, int m) {
    bool flag[MAX_N];
    memset(flag, 0, sizeof flag);
    int gap = 0;
    for (int i = 1; i <= n; ++i)
        if (!flag[i] && i + gap <= m) {
            flag[i] = flag[i + gap] = true;
            if (i == n && i + gap == m)    
                return 1;
            ++gap;
        }
    return 0;
}
int rook(int n, int m) {
    return (n == m)? 1 : 0; 
}
int knight(int n, int m) {
    if (n == m && (n + m - 2) % 6 == 0)
        return 1;
    else
        if (n % 3 == 2 && m % 3 == 0 && m / 3 == n / 3 + 1) 
            return 0;
        else return 2;
}
int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--) {
        scanf("%d%d%d", &type, &N, &M);
        if (N > M) swap(N, M);
        switch (type) {
            case 1: k = king(N, M);break;
            case 2: k = rook(N, M);break;
            case 3: k = knight(N, M);break;
            case 4: k = queen(N, M);break; 
        }
        switch (k) {
            case 0: cout << "B" << endl;break;
            case 1: cout << "G" << endl;break;
            case 2: cout << "D" << endl;break;
        }
    }
    return 0;
}