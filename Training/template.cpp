#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>

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
const int MAX_V = MAX_N;
const int MAX_E = 100010;

template <typename T>
inline T sqr(T a) { return a * a;};

struct edge {
    int u, v;
    int dis;
};
vector<edge> g[MAX_V];
vector<edge> es;
bool vis[MAX_V];
int d[MAX_N], V, E, pre[MAX_V];
int cost[MAX_V][MAX_V];

class Point {
public:
    double x, y;
    friend double dis(Point A, Point B) {
        return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
    }
    void print() {
        printf("(%.2f, %.2f)\n", x, y);
    }
};

void dijkstra(int s) {
    //
    // fill(d, d + V, INF);
    // fill(vis, vis + V, false);
    // d[s] = 0;
    // while (true) {
    //     int v = -1;
    //     for (int u = 0; u < V; ++u) 
    //         if (!vis[u] && (v == -1 || d[u] < d[v])) v = u;
    //     if (v == -1) break;
    //     vis[v] = true;
    //     for (int u = 0; u < V; ++u) {
    //         d[u] = min(d[v] + cost[v][u], d[u]);
    //     }
    // }
    //
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;// fisrt 是最短距离，second 是顶点编号
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(Pii(0, s));
    while (!que.empty()) {
        Pii p = que.top();que.pop();
        int u = p.second;
        if (d[u] < p.first) continue;
        for (int i = 0; i < g[u].size(); i++) {
            edge e = g[u][i];
            if (d[e.v] > d[u] + e.dis) {
                d[e.v] = d[u] + e.dis;
                que.push(Pii(d[e.v], e.v));
            }
        }
    } 
}
void bellman_ford(int s) {
    fill(d, d + V, INF);
    d[s] = 0;
    //
    // for (int i = 0; i < V; ++i
    //     for (int j = 0; j < E; ++j) {
    //         int u, v;
    //         u = es[j].u;
    //         v = es[j].v;
    //         if (d[u] != INF)
    //             d[v] = min(d[u] + es[j].dis, d[v]);
    //         if (d[v] != INF)
    //             d[u] = min(d[v] + es[j].dis, d[u]);
    //     }
    //
    while (true) {
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (d[e.u] != INF && d[e.u] + e.dis < d[e.v]) {
                update = true;
                d[e.v] = d[e.u] + e.dis;
            }
        }
        if (!update) break;
    }
}
void spfa(int s) {
    queue<int> que;
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[s] = 0;
    que.push(s);
    vis[s] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].v;
            if (d[v] > d[u] + g[u][i].dis) {
                d[v] = d[u] + g[u][i].dis;
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}
int prim() {
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[0] = 0;
    int res = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < V; ++u) {
            if(!vis[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        vis[v] = true;
        res += d[v];
        for (int u = 0; u < V; u++)
            d[u] = min(d[u], cost[v][u]);
    }
    return res;
}
bool cmp(edge &e1, edge &e2) {
    return e1.dis < e2.dis;
}
// int kruskal() {
//     sort(es, es + E, cmp);
//     init(V);
//     int res = 0;
//     for (int i = 0; i < E; ++i) {
//         edge e = es[i];
//         if (!same(e.u, e.v)) {
//             unite(e.u, e.v);
//             res += e.dis;
//         }
//     }
//     return res;
// }
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return n != 1;
}
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
map<int, int> primeFactor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}
int prime[MAX_N];
bool is_prime[MAX_N + 1];
int seive(int n) {
    int p = 0;
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) 
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    return p;
}
const int MAX_L = 1e5, MAX_SQRT_R = 1e3;
bool seg_prime_small[MAX_L];
bool seg_prime[MAX_SQRT_R];
// the number of prime in [L, r)
// 对区间 [l, r）内的整数执行筛法，prime[i - l] = true <=> i 是素数
void segmentSieve(ll l, ll r) {
    for (int i = 0; (ll)i * i < r; ++i) seg_prime_small[i] = true;
    for (int i = 0; i < r - l; ++i) seg_prime[i] = true;
    for (int i = 2; (ll)i * i < r; ++i) {
        if (seg_prime_small[i]) {
            for (int j = 2 * i; (ll)j * j <= r; j += i) seg_prime_small[j] = false;
            for (ll j = max(2LL, (l + i - 1) / i) * i; j < r; j += i) seg_prime[j - l] = false;
        }
    }
}
int getMaxString(const string &str) {
    int len = (int)str.length();
    int i = 0, j = 1, k = 0;
    while (i < len && j < len && k < len) {
        int t = str[(i + k) % len] - str[(j + k) % len];
        if (t == 0) ++k;
        else { 
            if (t > 0) j += k + 1;
            else i += k + 1;
            if (i == j) ++j;
            k = 0;
        }
    }
    return min(i, j);
}
int nxt[MAX_N];
void getNext(const string &str) {
    int j = 0, k, len = str.length();
    nxt[0] = k = -1;
    while (j < len) {
        if (k == -1 || str[j] == str[k])
            nxt[++j] = ++k;
        else k = nxt[k];
    }
}
int kmp(const string &tar, const string &pat) {
    getNext(pat);
    int j, k, res;
    int lenT = tar.length(), lenP = pat.length();
    res = j = k = 0;
    while (j < lenT) {
        if (k == -1 || tar[j] == pat[k])
            ++j, ++k;
        else k = nxt[k];
        if (k == lenP) {
            res = max(res, j - lenP + 1);
            k = nxt[k];
        }
    }
    return res;
}

// int extNext[MAX_N];
// void getExtNext(const string &str) {
//     int j = 0, k, len = str.length();
//     k = exNext[0] = -1;
//     while (j < len) {
//         while (k != -1 && str[j] != str[k])
//             k = exNext[k];
//         ++j, ++k;
//         if (str[j] == str[k])
//             exNext[j] = exNext[k];
//         else exNext[j] = k;
//     }
// }
// int extKmp(const string &tar, const string &pat) {
//     getExtNext(pat);
//     int l, r, j, k;
//     int lenT = tar.length(), lenP = pat.length();
//     while (j < lenT) {

//     }
// }

// void Cal_next (const char *pattern,int len)  //改进写法,next[]有多个-1    
// {    
//     int i=0,j=-1;    
//     next[0]=-1;    
//     while (i<len)    
//     {    
//         while (j>=0 && pattern[i]!=pattern[j])    
//             j=next[j];    
//         j++,i++;    
//         if (pattern[j]==pattern[i])    
//             next[i]=next[j];    
//         else    
//             next[i]=j;    
//     }    
// } 
// void exKMP (char s[],char t[]) //s为主串，t为模板串  
// {  
//     int i,j=0,p,L;  
//     int lens=strlen(s);  
//     int lent=strlen(t);  
//     next[0]=lent;  
      
//     while (j+1<lent && t[j]==t[j+1])  
//         j++;  
//     next[1]=j;  
      
//     int a=1;  
//     for (i=2;i<lent;i++)  
//     {  
//         p=next[a]+a-1;  
//         L=next[i-a];  
//         if (i+L<p+1) next[i]=L;  
//         else  
//         {  
//             j=max(0,p-i+1);  
//             while (i+j<lent && t[i+j]==t[j])  
//                 j++;  
//             next[i]=j;  
//             a=i;  
//         }  
//     }  
  
//     j=0;  
//     while (j<lens && j<lent && s[j]==t[j])  
//         j++;  
//     extend[0]=j;  
//     a=0;  
//     for (i=1;i<lens;i++)  
//     {  
//         p=extend[a]+a-1;  
//         L=next[i-a];  
//         if (L+i<p+1) extend[i]=L;  
//         else  
//         {  
//             j=max(0,p-i+1);  
//             while (i+j<lens && j<lent && s[i+j]==t[j])  
//                 j++;  
//             extend[i]=j;  
//             a=i;  
//         }  
//     }  
// }  
// void GetExtand(const EleType str[], int strLen, int extand[], const EleType mode[], int modeLen, int next[])
// {
//     int i, a, p, j(-1);
    
//     for (i = 0; i < strLen; ++i, --j)
//     {
//         if (j < 0 || i + next[i - a] >= p)
//         {
//             if (j < 0) j = 0, p = i;
//             while (p < strLen && j < modeLen && str[p] == mode[j])
//                 ++p, ++j;
//             extand[i] = j, a = i;
//         }
//         else extand[i] = next[i - a];
//     }
// }

int lis[MAX_N], a[MAX_N];
void solve(int n) {
    int dp[MAX_N];
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; ++i)
        *lower_bound(dp, dp + n, a[i]) = a[i];// lds: -a[i]
    printf("%ld\n", lower_bound(dp, dp + n, INF) - dp);
}

int main(void) {

    return 0;
}
