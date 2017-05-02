#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define __DEBUG__
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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, cases = 0, k, n;
char S[MAX_N], X;

int sa[MAX_N], lcp[MAX_N], rnk[MAX_N], tmp[MAX_N], nxt[MAX_N];//sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); lcp[2..n]

int wv[MAX_N], wd[MAX_N], r[MAX_N];

//O(nlogn)
//调用da(S, len+1, m);//m为字符个数略大//s 为待处理的串
int cmp(int *r, int a, int b, int x) {
    return r[a] == r[b] && r[a + x] == r[b + x];
}

void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
    int i, j, k, p, *x = rnk, *y = lcp, *t;
    for(i = 0; i < m; i++) wd[i] = 0;
    for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
    for(i = 1; i < m; i++) wd[i] += wd[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) wd[i] = 0;
        for(i = 0; i < n; i++) wd[wv[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }

    for(i = 0, k = 0; i < n; i++) rnk[sa[i]] = i;
    for(i = 0; i < n - 1; lcp[rnk[i++]] = k) {
        for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
    }
}

bool compare_sa(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    else {
        int ri = i + k <= n ? rnk[i + k] : -1;
        int rj = j + k <= n ? rnk[j + k] : -1;
        return ri < rj;
    }
}
void construct_sa(int *sa) {
    // n = strlen(S) - 1;

    for (int i = 0; i <= n; ++i) {
        sa[i] = i;
        rnk[i] = i < n ? S[i] : -1;
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n + 1, compare_sa);

        tmp[sa[0]] = 0;
        for (int i= 1; i <= n; ++i) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i])? 1 : 0);
        }
        for (int i = 0; i <= n; ++i) {
            rnk[i] = tmp[i];
        }
    }
}
void construct_lcp(int *sa, int *lcp) {
    // n = strlen(S) - 1;
    for (int i = 0; i <= n; ++i) rnk[sa[i]] = i;

    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int j = sa[rnk[i] - 1];

        if (h > 0) h--;
        for (; j + h < n && i + h < n; h++) {
            if (S[j + h] != S[i + h]) break;
        }

        lcp[rnk[i] - 1] = h;
    }
    lcp[n] = 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        // construct_sa(sa);
        // construct_lcp(sa, lcp);

        // for (int i = 0; i <= n; ++i)
        //     DEBUG("%d%c", sa[i], i == n ? '\n' : ' ');
        // for (int i = 0; i <= n; ++i)
        //     DEBUG("%d%c", lcp[i], i == n ? '\n' : ' ');

        do X = getchar(); while (X == ' ' || X == '\n');
        scanf("%s", S);
        int last;
        last = n = strlen(S);
        for (int i = n; i >= 0; --i) {
            if (S[i] == X)
                last = i;
            nxt[i] = last;
        }

        for (int i = 0; i < n; i++) {
            r[i] = S[i] - 'a' + 1;
        }
        r[n] = 0;

        da(r, n + 1, 30);


        // for (int i = 0; i <= n; ++i)
        //     DEBUG("%d%c", sa[i], i == n ? '\n' : ' ');
        // for (int i = 0; i <= n; ++i)
        //     DEBUG("%d%c", lcp[i], i == n ? '\n' : ' ');

        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += n - max(nxt[sa[i]], sa[i] + lcp[i]);
        printf("Case #%d: %lld\n", ++cases, ans);
    }    
    return 0;
}