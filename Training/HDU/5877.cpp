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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, root, A[MAX_N], a[MAX_N], b[MAX_N], bit[MAX_N + 1];
ll k, ans;
vector<int> G[MAX_N];
bool flag[MAX_N];

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x) {
    while (i <= N) {
        bit[i] += x;
        i += i & -i;
    }
}

int compress(int *A) {
    vector<int> v;
    for (int i = 1; i <= N; ++i)
        v.push_back(A[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 1; i <= N; ++i)
        a[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;

    v.clear();
    for (int i = 1; i <= N; ++i)
        v.push_back(A[i]);
    sort(v.begin(), v.end());
    for (int i = 1; i <= N; ++i)
        if (A[i] == 0) 
            b[i] = N;
        else 
            b[i] = upper_bound(v.begin(), v.end(), k / A[i]) - v.begin();
    
    for (int i = 1; i <= N; ++i)
        A[i] = a[i];
    sort(A + 1, A + 1 + N);

    return v.size() + 1;
}

void dfs(int p) {
    ans += sum(A[b[p]]);
    add(a[p], 1);
    for (int i = 0; i < G[p].size(); ++i) {
        int v = G[p][i];
        dfs(v);
    }
    add(a[p], -1);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &N, &k);
        memset(flag, false, sizeof flag);
        memset(bit, 0, sizeof bit);
        for (int i = 1; i <= N; ++i) {
            G[i].clear();
        }
        ans = 0;
        for (int i = 1; i <= N; ++i)
            scanf("%d", A + i);
        compress(A);
        for (int i = 1, u, v; i < N; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            flag[v] = true;
        }
        for (int i = 1; i <= N; ++i)
            if (!flag[i]) { root = i; break;}
        dfs(root);
        printf("%lld\n", ans);
    }    
    return 0;
}