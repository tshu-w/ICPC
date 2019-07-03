# 一切的开始

## Vimrc

```
set nu si mouse=a sw=2 ts=2 sts=2
set mp=g++\ -O2\ -Wall\ --std=c++11\ -Wno-unused-result\ %:r.cpp\ -o\ %:r
nmap <F2> :vs %:r.in <CR>
nmap <F8> :!time ./%:r < %:r.in <CR>
nmap <F9> :w <CR> :make<CR>
```

## 快速读

### 关同步

```c++
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define endl "\n"
```

### 读入挂

#### getchar 版

```c++
inline void read(int &x) { // 可根据情况去掉负数
	int t = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') t = -1; ch = getchar();}
	x = 0;
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch -'0'; ch = getchar();}
	x *= t;
}
void print(int i){
	if(i < 10) {
		putchar('0' + i);
		return ;
	}
	print(i / 10);
	putchar('0' + i % 10);
}
```

#### freed 版

```c++
namespace fastIO {
#define BUF_SIZE 100000 // 本地小数据测试改为1
  //fread -> read
  bool IOerror = 0;
  inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if(p1 == pend) {
      p1 = buf;
      pend = buf + fread(buf, 1, BUF_SIZE, stdin);
      if(pend == p1) {
        IOerror = 1;
        return -1;
      }
    }
    return *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  inline void read(int &x) {
    char ch;
    while(blank(ch = nc()));
    if(IOerror)
      return;
    for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
  }
#undef BUF_SIZE
};
using namespace fastIO;
// while (read(n), !fastIO::IOerror) {}
```

## Assert Patch

```c++
#ifdef ONLINE_JUDGE
#define assert(condition) if (!(condition)) { int x = 1, y = 0; cout << x / y << endl; }
#endif
```

# 数据结构

## 堆

```c++
int heap[maxn], sz = 0;
void push(int x) {
  int i = sz++;
  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap[p] <= x) break;
    heap[i] = heap[p];
    i = p;
  }
  heap[i] = x;
}
int pop() {
  int ret = heap[0], x = heap[--sz], i = 0;
  while (i * 2 + 1 < sz) {
    int a = i * 2 + 1, b = i * 2 + 2;
    if (b < sz && heap[b] < heap[a]) a = b;
    if (heap[a] >= x) break;
    heap[i] = heap[a];
    i = a;
  }
  heap[i] = x;
  return ret;
}
```

## 并查集

```c++
int par[maxn];
int rnk[maxn];
void init(int n) {
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}
int find(int x) {
  return par[x] == x? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
  return find(x) == find(y);
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}
```

## 线段树

```c++
// Segment Tree
const int maxn = 1 << 17;
int n, dat[2 * maxn - 1];
void init(int _n) {
  n = 1;
  while (n < _n) n <<= 1;
  for (int i = 0; i < 2 * n - 1; ++i)
    dat[i] = INF;
}
void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
  }
}
// query [a, b), index k in [l, r)
// query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INF;
  if (a <= l && r <= b) return dat[k];
  else {
    int v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(v1, v2);
  }
}
```

```c++
// RMQ
int n, dat[2 * maxn - 1];
void init(int _n) {
  n = 1;
  while (n < _n) n <<= 1;
  for (int i = 0; i < 2 * n - 1; ++i)
    dat[i] = INF;
}
void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
  }
}
// query [a, b), index k in [l, r)
// query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INF;
  if (a <= l && r <= b) return dat[k];
  else {
    int v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(v1, v2);
  }
}
```

```c++
// IntervalTree2D
// UVa11297 Census：带build的版本
// Rujia Liu
#include<algorithm>
using namespace std;

const int INF = 1<<30;
const int maxn = 2000 + 10;

int A[maxn][maxn];

struct IntervalTree2D {
  int Max[maxn][maxn], Min[maxn][maxn], n, m;
  int xo, xleaf, row, x1, y1, x2, y2, x, y, v, vmax, vmin; // 参数、查询结果和中间变量

  void query1D(int o, int L, int R) {
    if(y1 <= L && R <= y2) {
      vmax = max(Max[xo][o], vmax); vmin = min(Min[xo][o], vmin);
    } else {
      int M = L + (R-L)/2;
      if(y1 <= M) query1D(o*2, L, M);
      if(M < y2) query1D(o*2+1, M+1, R);
    }
  }

  void query2D(int o, int L, int R) {
    if(x1 <= L && R <= x2) { xo = o; query1D(1, 1, m); }
    else {
      int M = L + (R-L)/2;
      if(x1 <= M) query2D(o*2, L, M);
      if(M < x2) query2D(o*2+1, M+1, R);
    }
  }

  void modify1D(int o, int L, int R) {
    if(L == R) {
      if(xleaf) { Max[xo][o] = Min[xo][o] = v; return; }
      Max[xo][o] = max(Max[xo*2][o], Max[xo*2+1][o]);
      Min[xo][o] = min(Min[xo*2][o], Min[xo*2+1][o]);
    } else {
      int M = L + (R-L)/2;
      if(y <= M) modify1D(o*2, L, M);
      else modify1D(o*2+1, M+1, R);
      Max[xo][o] = max(Max[xo][o*2], Max[xo][o*2+1]);
      Min[xo][o] = min(Min[xo][o*2], Min[xo][o*2+1]);
    }
  }

  void modify2D(int o, int L, int R) {
    if(L == R) { xo = o; xleaf = 1; modify1D(1, 1, m); }
    else {
      int M = L + (R-L)/2;
      if(x <= M) modify2D(o*2, L, M);
      else modify2D(o*2+1, M+1, R);
      xo = o; xleaf = 0; modify1D(1, 1, m);
    }
  }

  // 只构建xo为叶子（即x1=x2）的y树
  void build1D(int o, int L, int R) {
    if(L == R) Max[xo][o] = Min[xo][o] = A[row][L];
    else {
      int M = L + (R-L)/2;
      build1D(o*2, L, M);
      build1D(o*2+1, M+1, R);
      Max[xo][o] = max(Max[xo][o*2], Max[xo][o*2+1]);
      Min[xo][o] = min(Min[xo][o*2], Min[xo][o*2+1]);
    }
  }

  void build2D(int o, int L, int R) {
    if(L == R) { xo = o; row = L; build1D(1, 1, m); }
    else {
      int M = L + (R-L)/2;
      build2D(o*2, L, M);
      build2D(o*2+1, M+1, R);
      for(int i = 1; i <= m*4; i++) {
      Max[o][i] = max(Max[o*2][i], Max[o*2+1][i]);
      Min[o][i] = min(Min[o*2][i], Min[o*2+1][i]);
      }
    }
  }

  void query() {
    vmax = -INF; vmin = INF;
    query2D(1, 1, n);
  }

  void modify() { modify2D(1, 1, n); }

  void build() { build2D(1, 1, n); }
};

IntervalTree2D t;

#include<cstdio>

int main() {
  int n, m, Q, x1, y1, x2, y2, x, y, v;
  char op[10];
  scanf("%d%d", &n, &m);
  t.n = n; t.m = m;
  for(int i = 1; i <= n; i++)
  for(int j = 1; j <= m; j++)
    scanf("%d", &A[i][j]);
  t.build();

  scanf("%d", &Q);
  while(Q--) {
    scanf("%s", op);
    if(op[0] == 'q') {
      scanf("%d%d%d%d", &t.x1, &t.y1, &t.x2, &t.y2);
      t.query();
      printf("%d %d\n", t.vmax, t.vmin);
    } else {
      scanf("%d%d%d", &t.x, &t.y, &t.v);
      t.modify();
    }
  }
  return 0;
}
```

## ST 表

```c++
//Sparse Table
const int maxn = 1e5 + 10;
const int MAX_K = 31 - __builtin_clz(maxn);

int n, ST[maxn][MAX_K + 1], A[maxn];
void build(int N) {
  for (int i = 0; i < N; ++i)
    ST[i][0] = A[i];
  int k = 31 - __builtin_clz(N);
  for (int j = 1; j <= k; ++j)
    for (int i = 0; i <= N - (1 << j); ++i)
      ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
int query(int l, int r) {
  if (l >= r) return 0;
  int ans = INF, k = 31 - __builtin_clz(r - l);
  for (int j = k; j >= 0; --j)
    if (l + (1 << j) - 1 <= r) {
      ans = min(ans, ST[l][j]);
      l += 1 << j;
    }
  return ans;
}
int RMQ(int l, int r) {
  if (l >= r) return 0;
  int k = 31 - __builtin_clz(r - l);
  return min(ST[l][k], ST[r - (1 << k)][k]);
}
```

## 树状数组

```c++
// lowbit
int lowbit(int i) {
  return ~i & i + 1;
}
```

```c++
// 单点修改/查询
int bit[maxn];
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}
void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}
```

```c++
// 区间修改/查询
struct bit {
  int bit[maxn];
  int sum(int i) {
    int s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, int x) {
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
   }
}a, b;
inline void add(int l, int r, int t) {
  a.add(l,t); a.add(r+1,-t);
  b.add(l,-t*(l-1)); b.add(r+1,t*r);
}
inline int get(int i) {
  return a.sum(i)*i+b.sum(i);
}
inline int get(int l, int r) {
  return get(r)-get(l - 1);
}
```

```c++
// 二维单点修改/查询
int bit[maxn][maxn];
int sum(int x, int y) {
  int res = 0;
  for (int i = x; i > 0; i -= i & -i)
    for (int j = y; j > 0; j -= j & -j)
      res += bit[i][j];
  return res;
}
void add(int x, int y, int k) {
  for (int i = x; i <= n; i += i & -i)
    for (int j = y; j <= n; j += j & -j)
      bit[i][j] += k;
}
```

```c++
// 二维区间修改/查询
struct bit {
  int a[maxn][maxn];
  inline int lowbit(int x) {
    return x&(-x);
  }
  inline void add(int x,int y,int t) {
    int i,j;
    for(i=x;i<maxn;i+=lowbit(i)) {
      for(j=y;j<maxn;j+=lowbit(j))a[i][j]+=t;
    }
  }
  inline int get(int x,int y) {
    int ans=0;
    int i,j;
    for(i=x;i>0;i-=lowbit(i)) {
      for(j=y;j>0;j-=lowbit(j))ans+=a[i][j];
    }
    return ans;
  }
}a,b,c,d;
inline void add(int x1,int y1,int x2,int y2,int t) {
  a.add(x1,y1,t),a.add(x1,y2+1,-t);
  a.add(x2+1,y1,-t),a.add(x2+1,y2+1,t);

  b.add(x1,y1,t*x1); b.add(x2+1,y1,-t*(x2+1));
  b.add(x1,y2+1,-t*x1); b.add(x2+1,y2+1,t*(x2+1));

  c.add(x1,y1,t*y1); c.add(x2+1,y1,-t*y1);
  c.add(x1,y2+1,-t*(y2+1)); c.add(x2+1,y2+1,t*(y2+1));

  d.add(x1,y1,t*x1*y1); d.add(x2+1,y1,-t*(x2+1)*y1);
  d.add(x1,y2+1,-t*x1*(y2+1)); d.add(x2+1,y2+1,t*(x2+1)*(y2+1));
}
inline int get(int x,int y) {
  return a.get(x,y)*(x+1)*(y+1)-b.get(x,y)*(y+1)-(x+1)*c.get(x,y)+d.get(x,y);
}
inline int get(int x1,int y1,int x2,int y2) {
  return get(x2,y2)-get(x2,y1-1)-get(x1-1,y2)+get(x1-1,y1-1);
}
```

# 动态规划

## 最长上升子序列

```c++
int A[maxn];
long lis(int n) {
  int dp[maxn];
  fill(dp, dp + n, INF);
  for (int i = 0; i < n; ++i)
    *lower_bound(dp, dp + n, A[i]) = A[i];// lds: -A[i]; ln: upper_bound
  return lower_bound(dp, dp + n, INF) - dp;
}
```

## 背包

+ 0/1 背包

  $$f[i, j] = max(f[i - 1, j], f[i - 1, j - w[i]] + v[i])$$

  ```c++
  for (int i = 0; i < N; ++i)
    for (int j = W; j >= w[i]; --j)
      f[j] = max(f[j - w[i]] + c[i], f[j]);
  ```

+ 完全背包

  $$f[i, j] = max(f[i - 1, j], f[i, j - w[i]] + v[i])$$

  ```c++
  for (int i = 0; i < N; ++i)
    for (int j = w[i]; j <= W; ++j)
      f[j] = max(f[j - w[i]] + c[i], f[v]);
  ```

+ 多重背包

  $$f[i, j] = max(f[i - 1, j - w[i] * k] + v[i] * k | 0 <= k <= m[i])$$

  优化：转化为 01 背包问题
  * 将第 i 件物品分成若干件物品，每件物品的系数分别为：$1,2,4,\ldots,2^{(k - 1)},n[i]-2^k$
  * 根据 w，v 范围改变 DP 对象，可以考虑针对不同价值计算最小的重量。（ $f[i][j]$，其中 j 代表价值总和）

  ```c++
  for (int i = 0; i < N; ++i) {
    int num = m[i];
    for (int k = 1; num > 0; k <<= 1) {
      int mul = min(k, num);
      for (int j = W; j >= w[i] * mul; --j) {
        f[j] = max(f[j - w[i] * mul] + v[i] * mul, f[j]);
      }
      num -= mul;
    }
  }
  ```

+ 超大背包

  $$1 \leq n \leq 40，1 \leq w_i, v_i \leq 10^{15}, 1 \leq W \leq 10^{15}$$

  ```c++
  int n;
  ll w[maxn], v[maxn], W;
  Pll ps[1 << (maxn / 2)]; // (w, v);
  
  void solve() {
    int n2 = n / 2;
    for (int i = 0; i < 1 << n2; ++i) {
      ll sw = 0, sv = 0;
      for (int j = 0; j < n2; ++j)
        if (i >> j & 1) {
          sw += w[j];
          sv += v[j];
        }
      ps[i] = Pll(sw, sv);
    }
    sort(ps, ps + (1 << n2));
    int m = 1;
    for (int i = 1; i < 1 << n2; ++i)
      if (ps[m - 1].second < ps[i].second)
        ps[m++] = ps[i];
  
    ll res = 0;
    for (int i = 0; i < 1 << (n - n2); ++i) {
      ll sw = 0, sv = 0;
      for (int j = 0; j < n - n2; ++j)
        if (i >> j & 1) {
          sw += w[n2 + j];
          sv += v[n2 + j];
        }
      if (sw <= W) {
        ll tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;
        res = max(res, sv + tv);
      }
    }
    printf("%lld\n", res);
  }
  ```

+ 二维费用背包

  $$f[i, j, k] = max(f[i - 1, j, k], f[i - 1, j - a[i], k - b[i]] + c[i])$$

  二维费用可由最多取 m 件等方式隐蔽给出。

+ 分组背包

  $$f[k, j] = max(f[k - 1, j], f[k - 1, j - w[i]] + v[i]| i \in K)​$$

  ```c++
  for (int k = 0; k < K; ++k)
    for (j = W; j >= 0; --j)
      for (int i = 0; i <= m[k]; ++i)
        f[j] = max(f[j - w[i]] + v[i], f[j]);
  ```

+ 方案总数

  $$f[i, j] = sum(f[i - 1, j], f[i - 1, j - w[i]] + v[i]),f[0, 0] = 0$$

# 图论

## 最短路

```c++
void dijkstra(int s) {
  // fisrt 是最短距离，second 是顶点编号
  priority_queue<Pii, vector<Pii>, greater<Pii> > que;
  fill(dist, dist + V, INF);
  dist[s] = 0; que.push(Pii(0, s));
  while (!que.empty()) {
    Pii p = que.top(); que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (dist[e.to] > dist[v] + e.dis) {
        dist[e.to] = dist[v] + e.dis;
        que.push(Pii(dist[e.to], e.to));
      }
    }
  }
}
void bellman_ford(int s) {
  fill(dist, dist + V, INF);
  dist[s] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < E; ++i) {
      edge e = es[i];
      if (dist[e.from] != INF && dist[e.from] + e.dis < dist[e.to]) {
        update = true;
        dist[e.to] = dist[e.from] + e.dis;
      }
    }
    if (!update) break;
  }
}
bool dfs(int v) {
  vis[v] = true; mark[v] = true;
  for (int i = 0; i < (int)G[v].size(); i++) {
    edge e = G[v][i];
    if (dist[e.to] > dist[v] + e.dis) {
      if (mark[e.to]) return true;
      dist[e.to] = dist[v] + e.dist;
      if (dfs(e.to)) return true;
    }
  }
  mark[v] =false; 
  return false;
}
bool find_negative_loop() {
  memset(dist, 0, sizeof dist);
  // for (int i = 0; i < V; ++i)
  //   for (int j = 0; j < E; ++j) {
  //     edge e = es[j];
  //     if (d[e.to] > d[e.from] + e.dis) {
  //       d[e.to] = d[e.from] + e.dis;
  //       if (i == V - 1) return true;
  //     }
  //   }
  for (int i = 0; i < n; i++)
    if (!vis[i] && dfs(i)) return true;
  return false;
}
void spfa(int s) {
  queue<int> que;
  fill(dist, dist + V, INF);
  fill(vis, vis + V, false);
  dist[s] = 0; que.push(s); vis[s] = true;
  while (!que.empty()) {
    int v = que.front(); que.pop();
    vis[v] = false;
    for (int i = 0; i < G[v].size(); ++i) {
      int u = G[v][i].to;
      if (dist[u] > dist[v] + G[v][i].dis) {
        dist[u] = dist[v] + G[v][i].dis;
        if (!vis[u]) {
          que.push(u);
          vis[u] = true;
        }
      }
    }
  }
}
```

## 生成树

```c++
int prime() {
  priority_queue<Pii, vector<Pii>, greater<Pii> > que;
  int res = 0;
  fill(dist, dist + V, INF);
  fill(vis, vis + V, false);
  dist[0] = 0;
  que.push(Pii(0, 0));
  while (!que.empty()) {
    Pii p = que.top(); que.pop();
    int v = p.second;
    if (vis[v] || dist[v] < p.first) continue;
    res += dist[v]; vis[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i];
      if (dist[e.to] > e.dis) {
        dist[e.to] = e.dis;
        que.push(Pii(dist[e.to], e.to));
      }
    }
  }
  return res;
}

bool cmp(const edge e1, const edge e2) {
  return e1.dis < e2.dis;
}
int kruskal() {
  sort(es.begin(), es.end(), cmp);
  init(V);
  int res = 0;
  for (int i = 0; i < E; ++i) {
    edge e = es[i];
    if (!same(e.from, e.to)) {
      unite(e.from, e.to);
      res += e.dis;
    }
  }
  return res;
}
```

生成树相关的一些问题：

+ 度限制生成树：求一棵最小生成树，其中 $v$ 连接的边不能超过 $k$ 个或只能刚好 $k$ 个
  1. 去掉所有和 $v$ 连接的边，对每个连通分量求最小生成树
  2. 如果除去点 $v$ 外共有 $t$ 个连通分量，且 $t > k$，则无解
  3. 于是现在有一个最小 $t$ 度生成树，然后用 $dp[u]$ 计算出该点到 $v$ 的路径上，权值最大的边是多少，再枚举和 $v$ 连接的没有使用过的边，找出一条边，使得用那条边替换已有的边，增加的权值最小，不停替换直到 $v$ 出度为 $k$ 

+ 次小生成树：求一棵次小生成树，要求权值之和必须大于等于或严格大于其最小生成树
  1. 求最小生成树
  2. 找一个根然后 dp，求出每个点往上走 $2^L$ 能到达的祖先是谁，以及这段路径上的最大边和次大边（如果仅要求大于等于的话就不需要次大边）
  3. 枚举没有使用过的边，利用上面得到的信息，在 $O(logN)$ 时间内对每条边计算出其能够替换的已有的最大和次大边，然后找出最佳替换方式

+ 最优比例生成树：求一棵生成树，使得 $\frac{\sum{benifit_i}}{\sum{cost_i}}$ 最大
  1. 01 分数规划：$z(l) = \sum{benifit_i * x_i} - l * \sum{cost_i * x_i}$
  2. $z$ 单调递减，且 $z = 0$ 时 $l$ 取最大

+ 最小乘积生成树：设每个点有两个权值，求一棵生成树，使得 $\sum{x_i} * \sum{y_i}$ 最小
  1. 每个生成树可看出平面上的一个点$(\sum{x_i}, \sum{y_i})$，先分别求出单一权值的最小生成树A、B
  2. 找直线 AB 左下方的最远点（生成树） C，每个点的权值是可根据面积（叉积）最大求出
  3. 继续找直线 AC、BC 左下方的最远点对，不断递归

+ 斯坦纳树：求一棵包含指定的 $k$ 个特殊点的最小生成树，其他点不一定在树中

  1. 用 $dp[mask][x]$​ 记录树根在点 $x$，$mask$ 所对应的特殊点集在树中的最小权值之和

  2. 将 $dp[][]$ 初始化为正无穷，只有 $dp[1<<i][Ai]$​ 被初始化为 $0$，$A_i$ 为第 $i$ 个特殊点 

  3. 先求出所有点对间最短路，然后枚举 $mask$，依次做两种转移：

     3.1 枚举 $x$ 和 $mask$ 的子集 $sub$，合并两棵子树 

     ​  $$dp[mask][x]=min(dp[mask][x], dp[sub][x] + dp[mask^sub][x])$$

     3.2. 枚举 $x$ 和 $y$，计算结点从 $y$ 移动到 $x$ 的花费

     ​  $$dp[mask][x]=min(dp[mask][x], dp[mask][y]+dist(y, x))$$
     在上面的转移中，也可以把这些点同时放到队列里，用 spfa 更新最短路 

+ 生成树计数：给定一个无权的无向图 G，求生成树的个数
  1. 令矩阵 $D[][]$ 为度数矩阵，其中$D[i][i]$ 为结点 $i$ 的度，其他位置的值为 $0$
  2. 令矩阵 $A[][]$ 为邻接矩阵，当结点 $i$ 和 $j$ 之间有 $x$ 条边时，$A[i][j] = A[j][i] = x$
  3. 令矩阵 C = D - A，矩阵 C' 为矩阵 C 抽去第 $k$ 行和第 $k$ 列后的一个 $n-1$ 阶的子矩阵
     其中 $k$ 可以任意设定，构造完 C' 后，生成树的个数即为 C' 行列式的值

## Prufer 序列

+ 构造：对于一棵无根树 T，每次找到树中标号最小的叶子结点，删除这个结点以及与它相邻的边，将与叶子结点相连的点加入数列中。迭代删点，直到原图中只剩下两个点。
+ 转化：点的初始序列为 $G={1,\cdots, n}$。每次找到 G 在 Prufer 序列中未出现的最小点 x，x 向 Prufer 序列首项 y 连边，然后将 x 和 Prufer 首项删除。不断重复，直到 G 中只有两个点，连一条边。
+ 性质：
  1. 设树中每个点度数为 $d_i$，那么点 $i$ 会在 Prufer 序列中出现 $d_{i}−1$次。ps $\sum{d_i} = 2 * n - 2$
  2. 不同的 Prufer 序列对应不同的无根树（树形不同或标号不同）。
+ Cayley 定理：一个完全图 $K_n$ 有 $n^{n−2}$ 个生成树，亦即 $n$ 个节点的带标号的无根树有 $n^{n−2}$ 个

## 强联通分量

```c++
int V, cmp[MAX_V];
vector<int> G[MAX_V], rG[MAX_V], vs;
bool used[MAX_V];

void add_edge(int from, int to) {
  G[from].push_back(to); rG[to].push_back(from);
}
void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i)
    if (!used[G[v][i]]) dfs(G[v][i]);
  vs.push_back(v);
}
void rdfs(int v, int k) {
  used[v] = true;
  cmp[v] = k;
  for (int i = 0; i < rG[v].size(); ++i)
    if (!used[rG[v][i]]) rdfs(rG[v][i], k);
}
int scc() {
  memset(used, 0, sizeof used);
  vs.clear();
  for (int v = 0; v < V; ++v)
    if (!used[v]) dfs(v);
  memset(used, 0, sizeof used);
  int k = 0;
  for (int i = vs.size() - 1; i >= 0; --i)
    if (!used[vs[i]]) rdfs(vs[i], k++);
  return k;
}
```

## 二分图匹配

```c++
void add_edge(int u, int v) {
  G[u].push_back(v); G[v].push_back(u);
}
bool dfs(int v) {
  used[v] = true;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int u = G[v][i], w = match[u];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[v] = u; match[u] = v;
      return true;
    }
  }
  return false;
}
int bipartite_matching() {
  int res = 0;
  memset(match, -1, sizeof match);
  for (int v = 0; v < V; v++)
    if (match[v] < 0) {
      memset(used, false, sizeof used);
      if (dfs(v)) ++res;
    }
  return res;
}
```

## 稳定婚姻匹配

Gale - Shapley 算法

第一轮，每个男人都选择自己名单上排在首位的女人，并向她表白。这种时候会出现两种情况：

1. 该女士还没有被男生追求过，则该女士接受该男生的请求。
2. 若该女生已经接受过其他男生的追求，那么该女生会将该男士与她的现任男友进行比较，若更喜欢她的男友，那么拒绝这个人的追求，否则，抛弃其男友

第一轮结束后，有些男人已经有女朋友了，有些男人仍然是单身。在第二轮追女行动中，每个单身男都**从所有还没拒绝过他的女孩中**选出自己最中意的那一个，并向她表白，不管她现在是否是单身。这种时候还是会遇到上面所说的两种情况，还是同样的解决方案。直到所有人都不再是单身。

## 网络流

```c++
struct edge{
  int to, cap, rev;
};
vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];
void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, static_cast<int>(G[to].size())});
  G[to].push_back((edge){from, 0, static_cast<int>(G[from].size() - 1)});
}
// Ford-Fulkerson
int dfs(int v, int t, int f) {
  if (v == t) return f;
  flag[v] = true;
  for (int i = 0; i < (int)G[v].size(); i++) {
    edge &e = G[v][i];
    if (!flag[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int s, int t) {
  int flow = 0;
  for(;;) {
    memset(flag, false, sizeof flag);
    int f = dfs(s, t, INF);
    if (!f) return flow;
    flow += f;
  }
}
// Dinic
void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0; que.push(s);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int i = 0; i < G[v].size(); ++i) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}
int dfs(int v, int t, int f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < G[v].size(); ++i) {
    edge &e = G[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int s, int t) {
  int flow = 0;
  for (;;) {
    bfs(s);
    if (level[t] < 0) return flow;
    memset(iter, 0, sizeof iter);
    int f;
    while ((f = dfs(s, t, INF)) > 0) {
      flow += f;
    }
  }
}
```

```c++
// UVa11248 Frequency Hopping：使用ISAP算法，加优化
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn]; // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[maxn];     // BFS使用
  int d[maxn];        // 从起点到i的距离
  int cur[maxn];      // 当前弧指针
  int p[maxn];        // 可增广路上的上一条弧
  int num[maxn];      // 距离标号计数

  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(t);
    vis[t] = 1;
    d[t] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]^1];
        if(!vis[e.from] && e.cap > e.flow) {
          vis[e.from] = 1;
          d[e.from] = d[x] + 1;
          Q.push(e.from);
        }
      }
    }
    return vis[s];
  }

  void ClearAll(int n) {
    this→n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  int Augment() {
    int x = t, a = INF;
    while(x != s) {
      Edge& e = edges[p[x]];
      a = min(a, e.cap-e.flow);
      x = edges[p[x]].from;
    }
    x = t;
    while(x != s) {
      edges[p[x]].flow += a;
      edges[p[x]^1].flow -= a;
      x = edges[p[x]].from;
    }
    return a;
  }

  int Maxflow(int s, int t, int need) {
    this→s = s; this→t = t;
    int flow = 0;
    BFS();
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; i++) num[d[i]]++;
    int x = s;
    memset(cur, 0, sizeof(cur));
    while(d[s] < n) {
      if(x == t) {
        flow += Augment();
        if(flow >= need) return flow;
        x = s;
      }
      int ok = 0;
      for(int i = cur[x]; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(e.cap > e.flow && d[x] == d[e.to] + 1) { // Advance
          ok = 1;
          p[e.to] = G[x][i];
          cur[x] = i; // 注意
          x = e.to;
          break;
        }
      }
      if(!ok) { // Retreat
        int m = n-1; // 初值注意
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(e.cap > e.flow) m = min(m, d[e.to]);
        }
        if(--num[d[x]] == 0) break;
        num[d[x] = m+1]++;
        cur[x] = 0; // 注意
        if(x != s) x = edges[p[x]].from;
      }
    }
    return flow;
  }

  vector<int> Mincut() { // call this after maxflow
    BFS();
    vector<int> ans;
    for(int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if(!vis[e.from] && vis[e.to] && e.cap > 0) 
        ans.push_back(i);
    }
    return ans;
  }

  void Reduce() {
    for(int i = 0; i < edges.size(); i++) 
      edges[i].cap -= edges[i].flow;
  }

  void print() {
    printf("Graph:\n");
    for(int i = 0; i < edges.size(); i++)
      printf("%d→%d, %d, %d\n", edges[i].from, edges[i].to , edges[i].cap, edges[i].flow);
  }
};
ISAP g;

int main() {
  int n, e, c, kase = 0;
  while(scanf("%d%d%d", &n, &e, &c) == 3 && n) {
    g.ClearAll(n);
    while(e--) {
      int b1, b2, fp;
      scanf("%d%d%d", &b1, &b2, &fp);
      g.AddEdge(b1-1, b2-1, fp);
    }
    int flow = g.Maxflow(0, n-1, INF);
    printf("Case %d: ", ++kase);
    if(flow >= c) printf("possible\n");
    else {
      vector<int> cut = g.Mincut();
      g.Reduce();
      vector<Edge> ans;
      for(int i = 0; i < cut.size(); i++) {
        Edge& e = g.edges[cut[i]];
        e.cap = c;
        g.ClearFlow();
        if(flow + g.Maxflow(0, n-1, c-flow) >= c) ans.push_back(e);
        e.cap = 0;
      }
      if(ans.empty()) printf("not possible\n");
      else {
        sort(ans.begin(), ans.end());
        printf("possible option:(%d,%d)", ans[0].from+1, ans[0].to+1);
        for(int i = 1; i < ans.size(); i++)
          printf(",(%d,%d)", ans[i].from+1, ans[i].to+1);
        printf("\n");
      }
    }
  }
  return 0;
}
```

## 费用流

```c++
// min_cost_flow dijkstra
void add_edge(int from, int to, int cap, int cost) {
  G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
  G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
int min_cost_flow(int s, int t, int f) {
  int res = 0;
  fill(h, h + V, 0);
  while (f > 0) {
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;
    fill(dist, dist + V, INF);
    dist[s] = 0; que.push(Pii(0, s));
    while (!que.empty()) {
      Pii p = que.top(); que.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (int i = 0; i < (int)G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(Pii(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == INF) return -1;
    for (int v = 0; v < V; v++) h[v] += dist[v];
    int d = f;
    for (int v = t; v != s; v = prevv[v])
      d = min(d, G[prevv[v]][preve[v]].cap);
    f -= d;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}
```

## 无向图最小割

```c++
// stoer_wagner
void search() {
  memset(vis, false, sizeof vis);
  memset(wet, 0, sizeof wet);
  S = T = -1;
  int imax, tmp;
  for (int i = 0; i < V; i++) {
    imax = -INF;
    for (int j = 0; j < V; j++)
      if (!cmb[j] && !vis[j] && wet[j] > imax) {
        imax = wet[j];
        tmp = j;
      }
    if (T == tmp) return;
    S = T; T = tmp;
    mc = imax;
    vis[tmp] = true;
    for (int j = 0; j < V; j++)
      if (!cmb[j] && !vis[j])
        wet[j] += G[tmp][j];
  }
}
int stoer_wagner() {
  memset(cmb, false, sizeof cmb);
  int ans = INF;
  for (int i = 0; i < V - 1; i++) {
    search();
    ans = min(ans, mc);
    if (ans == 0) return 0;
    cmb[T] = true;
    for (int j = 0; j < V; j++)
      if (!cmb[j]) {
        G[S][j] += G[T][j];
        G[j][S] += G[j][T];
      }
  }
  return ans;
}
```

**最小割树**

无向图的任意两点之间的最小割可以用一颗树来表示。

构造方法：在当前的连通集合中任取两点（若当前连通集合仅有一个点退出），并在原图中求这两点之间的最小割。然后在最小割树上连接这两个点，边权为刚才求出的最小割。将当前的连通集合根据刚才的割划分为两部分，递归处理。

求出最小割树之后，两个点之间的最小割即为最小割树上两个点之间的路径上的边权最小值。

## LCA

```c++
// LCA--Doubling
const int MAX_LOG_V = 32 - __builtin_clz(MAX_V);

vector<int> G[MAX_V];
int root, parent[MAX_LOG_V][MAX_V], depth[MAX_V];

void dfs(int v, int p, int d) {
  parent[0][v] = p;
  depth[v] = d;
  for (int i = 0; i < G[v].size(); i++)
    if (G[v][i] != p) dfs(G[v][i], v, d + 1);
}
void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < MAX_LOG_V; k++)
    for (int v = 0; v < V; v++)
      if (parent[k][v] < 0) parent[k + 1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < MAX_LOG_V; k++)
    if ((depth[v] - depth[u]) >> k & 1)
      v = parent[k][v];
  if (u == v) return u;
  for (int k = MAX_LOG_V - 1; k >= 0; k--)
    if (parent[k][u] != parent[k][v])
      u = parent[k][u], v = parent[k][v];
  return parent[0][u];
}
// LCA--RMQ
vector<int> G[MAX_V];
int root, vs[MAX_V * 2 - 1], depth[MAX_V * 2 - 1], id[MAX_V];

int ST[2 * MAX_V][MAX_K];
void rmq_init(int* A, int N) {
  for (int i = 0; i < N; i++)
    ST[i][0] = i;
  int k = 31 - __builtin_clz(N);
  for (int j = 1; j <= k; j++)
    for (int i = 0; i <= N - (1 << j); ++i)
      if (A[ST[i][j - 1]] <= A[ST[i + (1 << (j - 1))][j - 1]])
        ST[i][j] = ST[i][j - 1];
      else ST[i][j] = ST[i + (1 << (j - 1))][j - 1];
}
int query(int l, int r) {
  if (l >= r) return -1;
  int k = 31 - __builtin_clz(r - l);
  return (depth[ST[l][k]] <= depth[ST[r - (1 << k)][k]]) ? ST[l][k] : ST[r - (1 << k)][k];
}
void dfs(int v, int p, int d, int &k) {
  id[v] = k;
  vs[k] = v;
  depth[k++] = d;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] != p) {
      dfs(G[v][i], v, d + 1, k);
      vs[k] = v;
      depth[k++] = d;
    }
  }
}
void init(int V) {
  int k = 0;
  dfs(root, -1, 0, k);
  rmq_init(depth, 2 * V - 1);
}
int lca(int u, int v) {
  return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}
```

## 树上路径交

```c++
int intersection(int x, int y, int xx, int yy) {
    int t[4] = {lca(x, xx), lca(x, yy), lca(y, xx), lca(y, yy)};
    sort(t, t + 4);
    int r = lca(x, y), rr = lca(xx, yy);
    if (dep[t[0]] < min(dep[r], dep[rr]) || dep[t[2]] < max(dep[r], dep[rr]))
        return 0;
    int tt = lca(t[2], t[3]);
    int ret = 1 + dep[t[2]] + dep[t[3]] - dep[tt] * 2;
    return ret;
}
```

## 树分治

```c++
//uva 12161
struct edge {
  int to, damage, length, next;
};
int G[maxn], En, N, M, T;
edge E[maxn * 2];

void add_edge(int from, int to, int damage, int length) {
  edge e = {to, damage, length, G[from]};
  E[En] = e;
  G[from] = En++;
}

int ans, subtree_size[maxn];
bool flag[maxn];

int s, t;
Pii ds[maxn];

int compute_subtree_size(int v, int p) {
  int c = 1;
  for (int j = G[v]; ~j; j = E[j].next) {
    int w = E[j].to;
    if (w == p || flag[w]) continue;
    c += compute_subtree_size(w, v);
  }
  return subtree_size[v] = c;
}

Pii search_centroid(int v, int p, int t) {
  Pii res = Pii(INT_MAX, -1);
  int s = 1, m = 0;
  for (int j = G[v]; ~j; j = E[j].next) {
    int w = E[j].to;
    if (w == p || flag[w]) continue;
    res = min(res, search_centroid(w, v, t));
    m = max(subtree_size[w], m);
    s += subtree_size[w];
  }
  m = max(m, t - s);
  res = min(res, Pii(m, v));
  return res;
}

void enumrate_path(int v, int p, int damage, int length) {
  ds[t++] = Pii(damage, length);
  for (int j = G[v]; ~j; j = E[j].next) {
    int w = E[j].to;
    if (w == p || flag[w]) continue;
    if (damage + E[j].damage <= M) {
      enumrate_path(w, v, damage + E[j].damage, length + E[j].length);
    }
  }
}

void remove_useless(int s, int &t) {
  if (s == t) return;
  int tt;
  for (int i = tt = s + 1; i < t; i++) {
    if (ds[i].first == ds[tt - 1].first) continue;
    if (ds[i].second <= ds[tt - 1].second) continue;
    ds[tt++] = ds[i];
  }
  t = tt;
}

void solve_sub_problem(int v) {
  compute_subtree_size(v, -1);
  int c = search_centroid(v, -1, subtree_size[v]).second;
  flag[c] = true;
  for (int j = G[c]; ~j; j = E[j].next) {
    if (flag[E[j].to]) continue;
    solve_sub_problem(E[j].to);
  }

  s = t = 0;
  for (int j = G[c]; ~j; j = E[j].next) {
    int w = E[j].to;
    if (flag[w]) continue;
    if (E[j].damage <= M)
      enumrate_path(w, v, E[j].damage, E[j].length);
    if (s > 0) {
      sort(ds + s, ds + t);
      remove_useless(s, t);
      for (int l = 0, r = t - 1; l < s && r >= s; l++) {
        while (r >= s && ds[l].first + ds[r].first > M) r--;
        if (r >= s)
          ans = max(ans, ds[l].second + ds[r].second);
      }
    }
    sort(ds, ds + t);
    remove_useless(0, t);
    s = t;
  }

  flag[c] = false;
}
int solve() {
  solve_sub_problem(0);
  return ans;
}
```

## 最小环

```c++
int floyd() {
  int res = INF;
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        if (res < d[i][j] + G[j][k] + G[k][i]) {
          res = d[i][j] + G[j][k] + G[k][i];
          int p = j; path.clear();
          for (int p = j; p != i; p = pre[i][p])
            path.push_back(p);
          path.push_back(i); path.push_back(k);
        }
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          pre[i][j] = pre[k][j];
        }
  }
  return res;
}
```

## 三元环

统计每个点的度数，入度$\le \sqrt{m}$的分为第一类，入度$\ge \sqrt{m}$的分为第二类。对于第一类，暴力每个点，然后暴力这个点的任意两条边，再判断这两条边的另一个端点是否连接。对于第二类，直接暴力任意三个点，判断这三个点是否构成环。复杂度 $O(m\sqrt{m})$

另外如果一个无向图中的结点数量超过 5 个，那么这张图中必然存在三元环或者反三元环。

## 弦图

相关定义
1. 子图：原图点集的子集 + 原图边集的子集
2. 诱导子图：原图点集的子集 + 这些点在原图中所连出的边集
3. 团：原图的一个子图，且是完全图
4. 极大团：此团不是其他团的子集
5. 最大团：点数最多的团 → 团数
6. 最小染色：用最少的颜色给点染色使相邻点颜色不同 → 色数
7. 最大独立集：原图点集的子集，任意两点在原图中没有边相连
8. 最小团覆盖：用最少个数的团覆盖所有的点
   推论：团数 ≤ 色数，最大独立集数 ≥ 最小团覆盖数
9. 弦：连接环中不相邻的两个点的边
10. 弦图：图中任意长度大于 3 的环都至少有 1 个弦
   推论：弦图的每一个诱导子图一定是弦图
   ​            弦图的任一个诱导子图不同构于 Cn(n > 3)
11. 单纯点：记 $N(v)$ 为点 $v$ 相邻点的集合，若 $N(v)+{v}$ 是一个团，则 $v$ 为单纯点
    引理：任何一个弦图都至少有一个单纯点
    ​            不是完全图的弦图至少有两个不相邻的单纯
12. 完美消除序列：点的序列 $v_1,v_2,\cdots,v_n$，满足 $v_i$ 在 ${v_i,v_{i+1},\cdots,v_n}$ 中是单纯点
     定理：一个无向图是弦图，当且仅当它有一个完美消除序列
     构造算法：令 $cnt[i]$ 为第 $i$ 个点与多少个已标记的点相邻，初值全为零。每次选择一个 $cnt[i]$ 最大的结点并打上标记，标记顺序的逆序则为完美消除序列
     判定算法：对于每个 $v_i$，其出边为 $v_{i_1},v_{i_2},\cdots,v_{i_k}$
     然后判断 $v_{i_1}$ 与 $v_{i_2},v_{i_3},\cdots,v_{i_k}$ 是否都相邻
     若存在不相邻的情况，则说明不是完美消除序列
13. 弦图各类算法：
    最小染色算法：按照完美消除序列，从后向前，依次染上可以染的最小颜色
    最大独立集算法：按照完美消除序列，从前向后，能选则选
    最小团覆盖算法：求出最大独立集，记为 ${p_1,p_2,\cdots,p_k}$，则 ${N(p_1)+{p_1},N(p_2)+{p_2},\cdots,N(p_k)+{p_k}}$ 即为解
14. 区间图：坐标轴上的一些区间看作点，任意两个交集非空的区间之间有边
    定理：区间图一定是弦图

```c++
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

bool mat[maxn][maxn], vis[maxn];
int label[maxn], num[maxn];
int n, m;

void maximumCardinalitySearch() {
    memset(vis + 1, 0, n * sizeof(bool));
    memset(label + 1, 0, n * sizeof(int));
    for(int i = n; i > 0; --i) {
        int u = -1;
        for(int v = 1; v <= n; ++v) if(!vis[v])
            if(u == -1 || label[u] < label[v]) u = v;
        vis[u] = true;
        num[i] = u;
        for(int v = 1; v <= n; ++v) if(!vis[v] && mat[u][v])
            label[v]++;
    }
}

bool isPrefect() {
    for(int u = 1; u <= n; ++u) {
        int t = u + 1;
        while(t <= n && !mat[num[u]][num[t]]) ++t;
        if(t > n) continue;
        for(int v = t + 1; v <= n; ++v) if(mat[num[u]][num[v]])
            if(!mat[num[t]][num[v]]) return false;
    }
    return true;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        memset(mat, 0, sizeof(mat));
        for(int i = 0, u, v; i < m; ++i) {
            scanf("%d%d", &u, &v);
            mat[u][v] = mat[v][u] = true;
        }
        maximumCardinalitySearch();
        puts(isPrefect() ? "Perfect" : "Imperfect");
        puts("");
    }
}
```

## 平面图转对偶图

```c++
/* BZOJ-3051: [wc2013]平面图
 *   平面图对偶图+点定位 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

const double pi = acos(-1), eps = 1.0e-8;
const int MaxL = 18, MaxN = 200010, MaxM = MaxN << 1, MaxQ = MaxM;

bool cmp(double a, double b) { return a - b < eps && a - b > -eps; }
struct point_t {
  double x, y;
  point_t(double x = 0, double y = 0) : x(x), y(y) {}
  point_t operator - (const point_t& r) const {
    return point_t(x - r.x, y - r.y);
  }

  friend double cross(const point_t& a, const point_t& b) {
    return a.x * b.y - a.y * b.x;
  }
};

int n, m;

namespace planar_graph {
  point_t pts[MaxN];

  struct edge_t {
    int u, v, len;
    double angle;
    edge_t(int u = 0, int v = 0, int len = 0) : u(u), v(v), len(len) {
      point_t z = pts[v] - pts[u];
      angle = atan2(z.y, z.x);
      if(angle < 0) angle += 2.0 * pi;
    }
  } edges[MaxM];

  using std::vector;
  using std::pair;
  using std::make_pair;

  int region_tot, inf_area;
  vector<int> et[MaxN];
  int rank[MaxM], near[MaxM], vis[MaxM];

  void read() {
    for(int i = 1; i <= n; ++i)
      std::scanf("%lf %lf", &pts[i].x, &pts[i].y);

    for(int i = 0; i != m; ++i) {
      int u, v, w;
      std::scanf("%d %d %d", &u, &v, &w);
      edges[i << 1] = edge_t(u, v, w);
      edges[(i << 1) + 1] = edge_t(v, u, w);
    }
  }

  void find_region(int x, int eid) {
    if(vis[eid]) return;
    double area = 0;
    while(!vis[eid]) {
      area += cross(pts[x], pts[edges[eid].v]);
      vis[eid] = 1;
      near[eid] = region_tot;
      x = edges[eid].v;
      if(!rank[eid ^ 1]) eid = et[x].back();
      else eid = et[x][rank[eid ^ 1] - 1];
    }

    if(area < 0) inf_area = region_tot;
    ++region_tot;
  }

  void work() {
    read();

    pair<double, int> *tmp = new pair<double, int>[m << 1];
    for(int i = 0; i != m << 1; ++i)
      tmp[i] = make_pair(edges[i].angle, i);
    sort(tmp, tmp + (m << 1));
    for(int i = 0; i != m << 1; ++i) {
      int eid = tmp[i].second;
      edge_t e = edges[eid];
      rank[eid] = et[e.u].size();
      et[e.u].push_back(eid);
    }

    delete[] tmp;

    for(int i = 1; i <= n; ++i) {
      for(int j = 0; j != et[i].size(); ++j)
        find_region(i, et[i][j]);
    }
  }
}

namespace scanning_line {
  struct ques_t {
    int id;
    point_t pt;
    bool operator < (const ques_t& r) const {
      return pt.x < r.pt.x;
    }
  } ques[MaxQ];

  struct key_point_t {
    int id;
    point_t pt;
    bool operator < (const key_point_t& r) const {
      if(cmp(pt.x, r.pt.x)) 
        return id < r.id;
      return pt.x < r.pt.x;
    }
  } kpt[MaxM];

  double nowx;
  struct info_t {
    int id;
    double k, x, y;
    info_t(int id, point_t a, point_t b) : id(id), x(a.x), y(a.y) {
      k = (a.y - b.y) / (a.x - b.x);
    }

    bool operator < (const info_t& r) const {
      double y0 = k * (nowx - x) + y;
      double y1 = r.k * (nowx - r.x) + r.y;
      if(!cmp(y0, y1)) return y0 < y1;
      return k < r.k;
    }
  };

  using std::swap;
  using std::set;
  typedef set<info_t>::iterator iter_t;
  set<info_t> s;
  iter_t it[MaxM];
  int area[MaxQ];

  int ques_tot;
  void read() {
    std::scanf("%d", &ques_tot);
    for(int i = 0; i != ques_tot << 1; ++i) {
      ques[i].id = i;
      std::scanf("%lf %lf", &ques[i].pt.x, &ques[i].pt.y);
    }
  }

  void work() {
    using namespace planar_graph;

    read();
    int tot = 0;
    for(int i = 0; i != m; ++i) {
      int a = i << 1;
      if(pts[edges[a].u].x > pts[edges[a].v].x)
        a |= 1;

      if(!cmp(pts[edges[a].u].x, pts[edges[a].v].x)) {
        kpt[tot].id = a + 1;
        kpt[tot++].pt = pts[edges[a].u];
        kpt[tot].id = -(a + 1);
        kpt[tot++].pt = pts[edges[a].v];
      }
    }
    
    std::sort(kpt, kpt + tot);
    std::sort(ques, ques + (ques_tot << 1));

    for(int i = 0, j = 0; i != ques_tot << 1; ++i) {
      for(; j != tot && kpt[j].pt.x <= ques[i].pt.x; ++j) {
        nowx = kpt[j].pt.x;
        int id = kpt[j].id;
        if(id < 0) {
          s.erase(it[-id - 1]);
        } else {
          --id;
          it[id] = s.insert(info_t(id, pts[edges[id].u], pts[edges[id].v])).first;
        }
      }

      nowx = ques[i].pt.x;
      point_t a = ques[i].pt, b = a;
      b.x += 1;
      iter_t pos = s.lower_bound(info_t(0, a, b));
      if(pos == s.end()) area[ques[i].id] = inf_area;
      else area[ques[i].id] = near[pos→id ^ 1];
    }
  }
}

namespace mst {
  struct edge_t {
    int u, v, w;
    bool operator < (const edge_t& r) const {
      return w < r.w;
    }
  } edges[MaxM];

  int gf[MaxN];

  int find(int v) {
    if(gf[v] == v) return gf[v] = v;
    return gf[v] = find(gf[v]);
  }

  void read() {
    for(int i = 0; i != m; ++i) {
      int a = i << 1;
      edges[i].u = planar_graph::near[a];
      edges[i].v = planar_graph::near[a ^ 1];
      edges[i].w = planar_graph::edges[a].len;
    }
  }

  int total;
  int head[MaxN], next[MaxM], point[MaxM], weight[MaxM];
  int que[MaxN], dist[MaxL][MaxN], fa[MaxL][MaxN], depth[MaxN];

  void add_edge(int u, int v, int w) {
    weight[++total] = w;
    point[total] = v;
    next[total] = head[u];
    head[u] = total;
  }

  void bfs(int u) {
    int qhead = 0, qtail = 0;
    que[qtail++] = u;
    depth[u] = 0;
    while(qhead != qtail) {
      int u = que[qhead++];
      for(int i = 1; i != MaxL; ++i) {
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
        dist[i][u] = std::max(dist[i - 1][u], dist[i - 1][fa[i - 1][u]]);
      }

      for(int k = head[u]; k; k = next[k]) {
        int v = point[k];
        if(fa[0][u] != v) {
          fa[0][v] = u;
          dist[0][v] = weight[k];
          depth[v] = depth[u] + 1;
          que[qtail++] = v;
        }
      }
    }
  }

  int ask(int u, int v) {
    if(u == planar_graph::inf_area)
      return -1;
    if(find(u) != find(v)) return -1;

    int ans = 0;
    if(depth[u] < depth[v]) 
      std::swap(u, v);
    int diff = depth[u] - depth[v];
    for(int l = 0; diff; diff >>= 1, ++l) {
      if(diff & 1) {
        ans = std::max(ans, dist[l][u]);
        u = fa[l][u];
      }
    }

    for(int p = MaxL - 1; u != v; p ? --p : 0) {
      if(!p || fa[p][u] != fa[p][v]) {
        ans = std::max(ans, dist[p][u]);
        ans = std::max(ans, dist[p][v]);
        u = fa[p][u]; v = fa[p][v];
      }
    }

    return ans;
  }

  void work() {
    read();
    std::sort(edges, edges + m);
    for(int i = 0; i != planar_graph::region_tot; ++i)
      gf[i] = i;
    for(int i = 0; i != m; ++i) {
      int u = edges[i].u, v = edges[i].v;
      if(u == planar_graph::inf_area || v == planar_graph::inf_area)
        continue;
      u = find(u), v = find(v);
      if(u != v) {
        gf[u] = v;
        add_edge(edges[i].u, edges[i].v, edges[i].w);
        add_edge(edges[i].v, edges[i].u, edges[i].w);
      }
    }

    std::memset(fa[0], -1, sizeof(fa[0]));
    for(int i = 0; i <= planar_graph::region_tot; ++i)
      if(fa[0][i] == -1) bfs(i);
  }
}

int main() {
  std::scanf("%d %d", &n, &m);
  planar_graph::work();
  scanning_line::work();
  mst::work();

  using namespace scanning_line;
  for(int i = 0; i != ques_tot; ++i) {
    int a = i << 1;
    std::printf("%d\n", mst::ask(area[a], area[a ^ 1]));
  }
  return 0;
}
```

# 字符串

## Todo

EXtend KMP, trie 树，Manacher，AC 自动机，后缀树，后缀自动机，回文自动机

## 最小最大表示

```c++
int getMinString(const string &s) {
  int len = (int)s.length();
  int i = 0, j = 1, k = 0;
  while(i < len && j < len && k < len) {
    int t = s[(i + k) % len] - s[(j + k) % len];
    if(t == 0) k++;
    else {
      if(t > 0) i += k + 1;//getMaxString: t < 0
      else j += k + 1;
      if(i == j) j++;
      k = 0;
    }
  }
  return min(i, j);
}
```

## 后缀数组

```c++
// Suffix Array & LCP Array
int n, k;
int lcp[maxn], sa[maxn];
int rnk[maxn], tmp[maxn];

bool compare_sa(int i, int j) {
  if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
  else {
    int ri = i + k <= n? rnk[i + k] : -1;
    int rj = j + k <= n? rnk[j + k] : -1;
    return ri < rj;
  }
}
void construct_sa(string &S, int *sa) {
  n = S.length();
  for (int i = 0; i <= n; i++) {
    sa[i] = i;
    rnk[i] = i < n? S[i] : -1;
  }
  for (k = 1; k <= n; k *= 2) {
    sort(sa, sa + n + 1, compare_sa);
    tmp[sa[0]] = 0;
    for (int i = 1; i <= n; i++)
      tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
    memcpy(rnk, tmp, sizeof(int) * (n + 1));
  }
}
void construct_lcp(string &S, int *sa, int *lcp) {
  n = S.length();
  for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
  int h = 0;
  lcp[0] = 0;
  for (int i = 0; i < n; i++) {
    int j = sa[rnk[i] - 1];
    if (h > 0) h--;
    for (; j + h < n && i + h < n; h++)
      if (S[j + h] != S[i + h]) break;
    lcp[rnk[i] - 1] = h;
  }
}
```

## ShiftAnd

主串 s[0...n] 模式串 t[0..m]
bitset D 中 D[j] = 1 表示模式串前缀 $t_0,...,t_j$ 是主串 $s_0,...,s_i$ 的后缀。
D = (D << 1 | 1) & B[s[i + 1]]

```c++
bitset<maxm> D, S[256];
void shiftAnd(int n, int m) {
  D.reset();
  for (int i = 0; i < n; i++) {
    D <<= 1; D.set(0);
    D &= B[s[i]];
    if (D[m - 1]) {
      char tmp = s[i + 1];
      s[i + 1] = '\0';
      puts(s + (i - n + 1));
      s[i + 1] = tmp;
    }
  }
}
```

# 数学

**注意中间乘法溢出**

```c++
// returning count of nk in range [l, r], from Infinity
template<typename T> T mps(T l, T r, T k) {
  return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1;
}
template<typename T> T gcd(T a, T b) {
  // return (b)? gcd(b, a  % b) : a;
  while (b) { T t = a % b; a = b; b = t; } return a;
}
template<typename T> T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
// find (x, y) s.t. a x + b y = gcd(a, b) = d
template<typename T> T exgcd(T a, T b, T &x, T &y) {
  T d = a;
  if (b) {
    d = exgcd(b, a % b, y, x);
    y -= a / b * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}
template<typename T> T modular_linear(T a, T b, T n) {
  T d, e, x, y;
  d = exgcd(a, n, x, y);
  if (b % d)
    return -1;
  e = x * (b / d) % n + n;
  return e % (n / d);
}
ll mod_mul(ll a, ll b, ll mod) {
  return (a * b - ll((long double) a * b / mod) * mod + mod) % mod;
}
template<typename T> T mod_mult(T a, T b, T mod) {
  T res = 0;
  while (b) {
    if (b & 1) {
      res += a;
      if (res >= mod) res -= mod;
    }
    a <<= 1;
    if (a >= mod) a -= mod;
    b >>= 1;
  }
  return res;
}
template<typename T> T mod_pow(T x, T n, T mod) {
  // return b ? mod_pow(a * a % mod, b >> 1, mod) * (b & 1 ? a : 1) % mod : 1;
  T res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
template<typename T> T mod_inverse(T a, T m) {
  T x, y;
  exgcd(a, m, x, y);
  return (m + x % m) % m;
}
template<typename T> T mod_inv(T x, T mod) {
  return x == 1 ? 1 : (mod - (mod / x)) * inv(mod % x) % mod;
}
void init_inverse(int maxn) {
  inv[1] = 1;
  for (int i = 2; i < maxn; i++)
    inv[i] = (MOD - (MOD / i)) * inv[MOD % i] % MOD;
}
// A[i] * x % M[i] = B[i]
template<typename T>
pair<T, T> linear_congruence(const vector<T>& A, const
                             vector<T>& B, const vector<T>& M){
  T x = 0, m = 1;
  for (int i = 0; i < (int)A.size(); i++) {
    T a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
    if (b % d != 0) return make_pair(0, -1); // 无解
    T t = b / d * mod_inverse(a / d, M[i] / d) % (M[i] / d);
    x = x + m * t;
    m *= M[i] / d;
  }
  return make_pair(x % m, m);
}
template<typename T>
T CRT(const vector<T>& a, const vector<t>& m) {
  T M = 1, res = 0;
  for (int i = 0; i < (int)m.size(); i++)
    M *= m[i];
  for (int i = 0; i < (int)m.size(); i++) {
    T Mi, Ti;
    Mi = M / m[i]; Ti = mod_inverse(Mi, m[i]);
    res = (res + a[i] * (Mi * Ti % M) % M) % M;
  }
  return res;
}
void init_factorial(int maxn) {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++)
    fact[i] = fact[i - 1] * i % MOD;
  iact[maxn - 1] = mod_pow(fact[maxn - 1], mod - 2, mod);
  for (int i = maxn - 2; i >= 0; i--)
    iact[i] = iact[i + 1] * (i + 1) % mod;
}
template<typename T> T mod_fact(T n, T p, T& e) {
  e = 0;
  if (n == 0) return 1;
  T = res = mod_fact(n / p, p, e);
  e += n / p;
  if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
  return res * fact[n % p] % p;
}
template<typename T> T mod_comb(T n, T k, T p) {
  if (n < 0 || k < 0 || n < k) return 0;
  if (n == 0) return 1;
  T e1, e2, e3;
  T a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
  if (e1 > e2 + e3) return 0;
  return a1 * mod_inverse(a2 * a3 % p, p) % p;
}
template<typename T> lucas(T n, T k, const T &p) {
  if (n < 0 || k < 0 || n < k) return 0;
  if (n == 0) return 1;
  return lucas(n / p, k / p, p) * mod_comb(n % p, k % p, p);
}
```

## 素数

```c++
// Miller_Rabin
bool check(ll a, ll n, ll x, ll t) {
  ll res = mod_pow(a, x, n);
  ll last = res;
  for (int i = 1; i <= t; ++i) {
    res = mod_mult(res, res, n);
    if (res == 1 && last != 1 && last != n - 1) return true;
    last = res;
  }
  if (res != 1) return true;
  return false;
}
bool Miller_Rabin(ll n) {
  if (n < maxn) return isPrime[n]; // small number may get wrong answer?!
  if (n < 2) return false;
  if (n == 2) return true;
  if ((n & 1) == 0) return false;
  ll x = n - 1, t = 0;
  while ((x & 1) == 0) {
    x >>= 1;
    ++t;
  }
  for (int i = 0; i < S; ++i) {
    ll a = rand() % (n - 1) + 1;
    if (check(a, n, x, t))
      return false;
  }
  return true;
}
// find factors
vector<ll> factor;
ll Pollard_rho(ll x, ll c) {
  ll i = 1, k = 2;
  ll x0 = rand() % x;
  ll y = x0;
  while (true) {
    ++i;
    x0 = (mod_mult(x0, x0, x) + c) % x;
    ll d;
    if (y == x0) d = 1;
    else
      if (y > x0)
        d = gcd(y - x0, x);
      else d = gcd(x0 - y, x);
    if (d != 1 && d != x) return d;
    if (y == x0) return x;
    if (i == k) {
      y = x0;
      k += k;
    }
  }
}
void find_factor(ll n) {
  if (n == 1) return ;
  if (Miller_Rabin(n)) {
    factor.push_back(n);
    return ;
  }
  ll p = n;
  while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
  find_factor(p);
  find_factor(n / p);
}
```

```c++
// Meisell-Lehmer n <= 1e11
const int maxn = 5e6 + 2;
bool np[maxn];
int prime[maxn], pi[maxn];
int getprime() {
  int cnt = 0;
  np[0] = np[1] = true;
  pi[0] = pi[1] = 0;
  for(int i = 2; i < maxn; ++i) {
    if(!np[i]) prime[++cnt] = i;
    pi[i] = cnt;
    for(int j = 1; j <= cnt && i * prime[j] < maxn; ++j) {
      np[i * prime[j]] = true;
      if(i % prime[j] == 0)   break;
    }
  }
  return cnt;
}
const int M = 7;
const int PM = 2 * 3 * 5 * 7 * 11 * 13 * 17;
int phi[PM + 1][M + 1], sz[M + 1];
void init() {
  getprime();
  sz[0] = 1;
  for(int i = 0; i <= PM; ++i)  phi[i][0] = i;
  for(int i = 1; i <= M; ++i) {
    sz[i] = prime[i] * sz[i - 1];
    for(int j = 1; j <= PM; ++j) phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
  }
}
int sqrt2(ll x) {
  ll r = (ll)sqrt(x - 0.1);
  while(r * r <= x)   ++r;
  return int(r - 1);
}
int sqrt3(ll x) {
  ll r = (ll)cbrt(x - 0.1);
  while(r * r * r <= x)   ++r;
  return int(r - 1);
}
ll getphi(ll x, int s) {
  if(s == 0) return x;
  if(s <= M) return phi[x % sz[s]][s] + (x / sz[s]) * phi[sz[s]][s];
  if(x <= prime[s]*prime[s]) return pi[x] - s + 1;
  if(x <= prime[s]*prime[s]*prime[s] && x < maxn) {
    int s2x = pi[sqrt2(x)];
    ll ans = pi[x] - (s2x + s - 2) * (s2x - s + 1) / 2;
    for(int i = s + 1; i <= s2x; ++i) ans += pi[x / prime[i]];
    return ans;
  }
  return getphi(x, s - 1) - getphi(x / prime[s], s - 1);
}
ll getpi(ll x) {
  if(x < maxn)   return pi[x];
  ll ans = getphi(x, pi[sqrt3(x)]) + pi[sqrt3(x)] - 1;
  for(int i = pi[sqrt3(x)] + 1, ed = pi[sqrt2(x)]; i <= ed; ++i) ans -= getpi(x / prime[i]) - i + 1;
  return ans;
}
ll lehmer_pi(ll x) {
  if(x < maxn)   return pi[x];
  int a = (int)lehmer_pi(sqrt2(sqrt2(x)));
  int b = (int)lehmer_pi(sqrt2(x));
  int c = (int)lehmer_pi(sqrt3(x));
  ll sum = getphi(x, a) +(ll)(b + a - 2) * (b - a + 1) / 2;
  for (int i = a + 1; i <= b; i++) {
    ll w = x / prime[i];
    sum -= lehmer_pi(w);
    if (i > c) continue;
    ll lim = lehmer_pi(sqrt2(w));
    for (int j = i; j <= lim; j++) 
      sum -= lehmer_pi(w / prime[j]) - (j - 1);
  }
  return sum;
}
int main() {
  init();
  ll n;
  while(~scanf("%lld",&n)) {
    printf("%lld\n",lehmer_pi(n));
  }
  return 0;
}
```

## 矩阵快速幂

```c++
typedef vector<int> vec;
typedef vector<vec> mat; // mat A(n, vec(n))

mat mat_mul(mat &A, mat &B) {
  mat C(A.size(), vec(B[0].size()));
  for (int i = 0; i < A.size(); ++i)
    for (int k = 0; k < B.size(); ++k)
      for (int j = 0; j < B[0].size(); ++j)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD + MOD) % MOD;
  return C;
}
mat mat_pow(mat A, ll n) {
  mat B(A.size(), vec(A.size()));
  for (int i = 0; i < A.size(); ++i)
    B[i][i] = 1;
  while (n > 0) {
    if (n & 1) B = mat_mul(B, A);
    A = mat_mul(A, A);
    n >>= 1;
  }
  return B;
}
```

## 高斯消元

```c++
const double eps = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_joedan(const mat &A, const vec& b) {
  int n = A.size();
  mat B(n, vec(n + 1));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) B[i][j] = A[i][j];
  for (int i = 0; i < n; ++i) B[i][n] = b[i];

  for (int i = 0; i < n; ++i) {
    int pivot = i;
    for (int j = i; j < n; ++j)
      if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
    if (i != pivot) swap(B[i], B[pivot]);

    if (abs(B[i][i]) < eps) return vec();

    for (int j = i + 1; j <= n; ++j) B[i][j] /= B[i][i];
    for (int j = 0; j < n; ++j) if (i != j)
      for (int k = i + 1; k <= n; ++k) B[j][k] -= B[j][i] * B[i][k];
  }

  vec x(n);
  for (int i = 0; i < n; ++i) x[i] = B[i][n];
  return x;
}

typedef vector<int> vec;
typedef vector<vec> mat;
vec gauss_joedan_xor(const mat& A, const vec& b) {
  int n = A.size();
  mat B(n, vec(n + 1));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) B[i][j] = A[i][j];
  for (int i = 0; i < n; ++i) B[i][n] = b[i];

  for (int i = 0; i < n; ++i) {
    int pivot = i;
    for (int j = i; j < n; ++j)
      if (B[j][i]) {
        pivot = j;
        break;
      }
    if (pivot != i) swap(B[i], B[pivot]);

    for (int j = 0; j < n; ++j) if (i != j && B[j][i])
        for (int k = i + 1; k <= n; ++k) B[j][k] ^= B[i][k];
      }
  }

  vec x(n);
  for (int i = 0; i < n; ++i) x[i] = B[i][n];
  return x;
}
```

## 类欧几里得

- $m = \lfloor \frac{an+b}{c} \rfloor$.
- $f(a,b,c,n)=\sum_{i=0}^n\lfloor\frac{ai+b}{c}\rfloor$: 当 $a \ge c$ or $b \ge c$ 时，$f(a,b,c,n)=(\frac{a}{c})n(n+1)/2+(\frac{b}{c})(n+1)+f(a \bmod c,b \bmod c,c,n)$；否则 $f(a,b,c,n)=nm-f(c,c-b-1,a,m-1)$。
- $g(a,b,c,n)=\sum_{i=0}^n i \lfloor\frac{ai+b}{c}\rfloor$: 当 $a \ge c$ or $b \ge c$ 时，$g(a,b,c,n)=(\frac{a}{c})n(n+1)(2n+1)/6+(\frac{b}{c})n(n+1)/2+g(a \bmod c,b \bmod c,c,n)$；否则 $g(a,b,c,n)=\frac{1}{2} (n(n+1)m-f(c,c-b-1,a,m-1)-h(c,c-b-1,a,m-1))$。
- $h(a,b,c,n)=\sum_{i=0}^n\lfloor \frac{ai+b}{c} \rfloor^2$: 当 $a \ge c$ or $b \ge c$ 时，$h(a,b,c,n)=(\frac{a}{c})^2 n(n+1)(2n+1)/6 +(\frac{b}{c})^2 (n+1)+(\frac{a}{c})(\frac{b}{c})n(n+1)+h(a \bmod c, b \bmod c,c,n)+2(\frac{a}{c})g(a \bmod c,b \bmod c,c,n)+2(\frac{b}{c})f(a \bmod c,b \bmod c,c,n)$；否则 $h(a,b,c,n)=nm(m+1)-2g(c,c-b-1,a,m-1)-2f(c,c-b-1,a,m-1)-f(a,b,c,n)$。

## 欧拉函数

```c++
int euler_phi(int n) {
  int res = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res = res / i * (i - 1);
      for (; n % i == 0; n /= i);
    }
  }
  if (n != 1) res = res / n * (n - 1);
  return res;
}
int euler[maxn];
void euler_phi_sieve() {
  for (int i = 0; i < maxn; ++i) euler[i] = i;
  for (int i = 2; i < maxn; ++i)
    if (euler[i] == i)
      for (int j = i; j < maxn; j += i) 
        euler[j] = euler[j] / i * (i - 1);
}
```

当 $x\geq\phi(p)$ 时有 $a^x\equiv a^{x \; mod \; \phi(p) + \phi(p)}\pmod p$

## 莫比乌斯

如果 $$F(n) = \sum_{d|n}f(d)$$，则 $$f(n) = \sum_{d|n}\mu(d)F(\frac{n}{d})$$

对于 $\mu(d)$ 函数，有如下性质：

$$\sum_{d|n}\mu(d) = \begin{cases}
1& \text{n = 1}\\
0& \text{n > 1}
\end{cases}$$

$$\sum_{d|n}\frac{\mu(d)}{d} = \frac{\phi(n)}{n}$$

```c++
int mu[maxn];
void moebius() {
  int cnt = 0; mu[1] = 1;
  memset(vis, 0, sizeof vis);
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) {
      prime[cnt++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < cnt && i * prime[j] < maxn; ++j) {
      vis[i * prime[j]] = true;
      if (i % prime[j])
        mu[i * prime[j]] = -mu[i];
      else
        mu[i * prime[j]] = 0, break;
    }
  }
}

map<int, int> moebius(int n) {
  map<int, int> res;
  vector<int> primes;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      primes.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n != 1) primes.push_back(n);

  int m = primes.size();
  for (int i = 0; i < (1 << m); ++i) {
    int mu = 1, d = 1;
    for (int j = 0; j < m; ++j) {
      if (i >> j & 1) {
        mu *= -1;
        d *= primes[j];
      }
    }
    res[d] = mu;
  }
  return res;
}
```

## 自适应 Simpson

Simpson 公式——二次函数近似原函数积分:

$$\int^b_af(x)dx \approx \frac{b - a}6*\left(f(a) + 4f(\frac{a + b}2) + f(b)\right)$$

```c++
// simpson 公式用到的函数
double F(double x) {
  return sqrt(1 + 4*a*a*x*x);
}

// 三点 simpson 法。
double simpson(double a, double b) {
  double c = a + (b-a)/2;
  return (F(a)+4*F(c)+F(b))*(b-a)/6;
}

// 自适应Simpson公式（递归过程）。已知整个区间[a,b]上的三点simpson值A
double asr(double a, double b, double eps, double A) {
  double c = a + (b-a)/2;
  double L = simpson(a, c), R = simpson(c, b);
  if(fabs(L+R-A) <= 15*eps) return L+R+(L+R-A)/15.0;
  return asr(a, c, eps/2, L) + asr(c, b, eps/2, R);
}

// 自适应Simpson公式（主过程）
double asr(double a, double b, double eps) {
  return asr(a, b, eps, simpson(a, b));
}
```

## 单纯形

```c++
// UVa10498 Happiness!
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;

// 改进单纯性法的实现
// 参考：http://en.wikipedia.org/wiki/Simplex_algorithm
// 输入矩阵a描述线性规划的标准形式。a为m+1行n+1列，其中行0~m-1为不等式，行m为目标函数（最大化）。列0~n-1为变量0~n-1的系数，列n为常数项
// 第i个约束为a[i][0]*x[0] + a[i][1]*x[1] + ... <= a[i][n]
// 目标为max(a[m][0]*x[0] + a[m][1]*x[1] + ... + a[m][n-1]*x[n-1] - a[m][n])
// 注意：变量均有非负约束x[i] >= 0
const int maxm = 500; // 约束数目上限
const int maxn = 500; // 变量数目上限
const double INF = 1e100;
const double eps = 1e-10;

struct Simplex {
  int n; // 变量个数
  int m; // 约束个数
  double a[maxm][maxn]; // 输入矩阵
  int B[maxm], N[maxn]; // 算法辅助变量

  void pivot(int r, int c) {
    swap(N[c], B[r]);
    a[r][c] = 1 / a[r][c];
    for(int j = 0; j <= n; j++) if(j != c) a[r][j] *= a[r][c];
    for(int i = 0; i <= m; i++) if(i != r) {
      for(int j = 0; j <= n; j++) if(j != c) a[i][j] -= a[i][c] * a[r][j];
      a[i][c] = -a[i][c] * a[r][c];
    }
  }

  bool feasible() {
    for(;;) {
      int r, c;
      double p = INF;
      for(int i = 0; i < m; i++) if(a[i][n] < p) p = a[r = i][n];
      if(p > -eps) return true;
      p = 0;
      for(int i = 0; i < n; i++) if(a[r][i] < p) p = a[r][c = i];
      if(p > -eps) return false;
      p = a[r][n] / a[r][c];
      for(int i = r+1; i < m; i++) if(a[i][c] > eps) {
        double v = a[i][n] / a[i][c];
        if(v < p) { r = i; p = v; }
      }
      pivot(r, c);
    }
  }

  // 解有界返回1，无解返回0，无界返回-1。b[i]为x[i]的值，ret为目标函数的值
  int simplex(int n, int m, double x[maxn], double& ret) {
    this->n = n;
    this->m = m;
    for(int i = 0; i < n; i++) N[i] = i;
    for(int i = 0; i < m; i++) B[i] = n+i;
    if(!feasible()) return 0;
    for(;;) {
      int r, c;
      double p = 0;
      for(int i = 0; i < n; i++) if(a[m][i] > p) p = a[m][c = i];
      if(p < eps) {
        for(int i = 0; i < n; i++) if(N[i] < n) x[N[i]] = 0;
        for(int i = 0; i < m; i++) if(B[i] < n) x[B[i]] = a[i][n];
        ret = -a[m][n];
        return 1;
      }
      p = INF;
      for(int i = 0; i < m; i++) if(a[i][c] > eps) {
        double v = a[i][n] / a[i][c];
        if(v < p) { r = i; p = v; }
      }
      if(p == INF) return -1;
      pivot(r, c);
    }
  }
};

//////////////// 题目相关
#include<cmath>
Simplex solver;

int main() {
  int n, m;
  while(scanf("%d%d", &n, &m) == 2) {
    for(int i = 0; i < n; i++) scanf("%lf", &solver.a[m][i]); // 目标函数
    solver.a[m][n] = 0; // 目标函数常数项
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n+1; j++)
        scanf("%lf", &solver.a[i][j]);
    double ans, x[maxn];
    assert(solver.simplex(n, m, x, ans) == 1);
    ans *= m;
    printf("Nasa can spend %d taka.\n", (int)floor(ans + 1 - eps));
  }
  return 0;
}
```

## 线性递推

```c++
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int _,n;
namespace linear_seq {
  const int N=10010;
  ll res[N],base[N],_c[N],_md[N];

  vector<int> Md;
  void mul(ll *a,ll *b,int k) {
    rep(i,0,k+k) _c[i]=0;
    rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
    for (int i=k+k-1;i>=k;i--) if (_c[i])
      rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
    rep(i,0,k) a[i]=_c[i];
  }
  int solve(ll n,VI a,VI b) {
    ll ans=0,pnt=0;
    int k=SZ(a);
    assert(SZ(a)==SZ(b));
    rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
    Md.clear();
    rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
    rep(i,0,k) res[i]=base[i]=0;
    res[0]=1;
    while ((1ll<<pnt)<=n) pnt++;
    for (int p=pnt;p>=0;p--) {
      mul(res,res,k);
      if ((n>>p)&1) {
        for (int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
        rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
      }
    }
    rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
    if (ans<0) ans+=mod;
    return ans;
  }
  VI BM(VI s) {
    VI C(1,1),B(1,1);
    int L=0,m=1,b=1;
    rep(n,0,SZ(s)) {
      ll d=0;
      rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
      if (d==0) ++m;
      else if (2*L<=n) {
        VI T=C;
        ll c=mod-d*powmod(b,mod-2)%mod;
        while (SZ(C)<SZ(B)+m) C.pb(0);
        rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
        L=n+1-L; B=T; b=d; m=1;
      } else {
        ll c=mod-d*powmod(b,mod-2)%mod;
        while (SZ(C)<SZ(B)+m) C.pb(0);
        rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
        ++m;
      }
    }
    return C;
  }
  int gao(VI a,ll n) {
    VI c=BM(a);
    c.erase(c.begin());
    rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
    return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
  }
};

int main() {
  for (scanf("%d",&_);_;_--) {
    scanf("%d",&n);
    printf("%d\n",linear_seq::gao(VI{2,24,96,416,1536,5504,18944,64000,},n-1));
  }
}
```

# 计算几何

## TODO

多边形面积并，圆面积并和交

## 大礼包

```c++
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;
typedef pair<int,int> Pii;
const double pi = acos(-1.);
const double eps = 1e-10;

inline int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
inline double getDistance(double x, double y) { return sqrt(x * x + y * y); }
inline double torad(double deg) { return deg / 180 * pi; }

struct Point {
  double x, y;
  Point (double x = 0, double y = 0): x(x), y(y) {}
  void read () { scanf("%lf%lf", &x, &y); }
  void write () { printf("(%f, %f)\n", x, y); }

  bool operator == (const Point& u) const { return sgn(x - u.x) == 0 && sgn(y - u.y) == 0; }
  bool operator != (const Point& u) const { return !(*this == u); }
  bool operator < (const Point& u) const { return sgn(x - u.x) < 0 || (sgn(x-u.x)==0 && sgn(y-u.y) < 0); }
  bool operator > (const Point& u) const { return u < *this; }
  bool operator <= (const Point& u) const { return *this < u || *this == u; }
  bool operator >= (const Point& u) const { return *this > u || *this == u; }
  Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
  Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
  Point operator * (const double u) { return Point(x * u, y * u); }
  Point operator / (const double u) { return Point(x / u, y / u); }
  double dot(Point p) { return x * p.x + y * p.y; }// 点积
  double crs(Point p) { return x * p.y - y * p.x; }// 外积
  double operator ^ (const Point u) { return x * u.y - y * u.x; }
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Line {
  double a, b, c;
  Line (double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
};

struct DirLine {
  Point p; Vector v; double ang;
  DirLine () {}
  DirLine (Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
  bool operator < (const DirLine& u) const { return ang < u.ang; }
};

struct Circle {
  Point o; double r;
  Circle () {}
  Circle (Point o, double r = 0): o(o), r(r) {}
  void read () { o.read(), scanf("%lf", &r); }
  Point point(double rad) { return Point(o.x + cos(rad)*r, o.y + sin(rad)*r); }
  double getArea (double rad) { return rad * r * r / 2; }
};

namespace Vectorial {
  /* 点积: 两向量长度的乘积再乘上它们夹角的余弦, 夹角大于90度时点积为负 */
  double getDot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
  /* 叉积: 叉积等于两向量组成的三角形有向面积的两倍, cross(v, w) = -cross(w, v) */
  double getCross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
  double getDistance(Point a, Point b) { double x=a.x-b.x, y=a.y-b.y; return sqrt(x*x + y*y); }
  double getLength(Vector a) { return sqrt(getDot(a, a)); }
  double getPLength(Vector a) { return getDot(a, a); }
  double getAngle(Vector u) { return atan2(u.y, u.x); }
  double getAngle(Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
  Vector rotate(Vector a, double rad) { return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }
  /* 单位法线 */
  Vector getNormal(Vector a) { double l = getLength(a); return Vector(-a.y/l, a.x/l); }

};

namespace ComplexVector {
  typedef complex<double> Point;
  typedef Point Vector;

  double getDot(Vector a, Vector b) { return real(conj(a)*b); }
  double getCross(Vector a, Vector b) { return imag(conj(a)*b); }
  Vector rotate(Vector a, double rad) { return a*exp(Point(0, rad)); }
};

namespace Linear {
  using namespace Vectorial;

  Line getLine(double x1, double y1, double x2, double y2) { return Line(y2-y1, x1-x2, y1*x2-x1*y2); }
  Line getLine(double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }

  bool getIntersection(Line p, Line q, Point& o) {
    if (fabs(p.a * q.b - q.a * p.b) < eps) return false;
    o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
    o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
    return true;
  }

  /* 直线pv和直线qw的交点 */
  bool getIntersection(Point p, Vector v, Point q, Vector w, Point& o) {
    if (sgn(getCross(v, w)) == 0) return false;
    Vector u = p - q;
    double k = getCross(w, u) / getCross(v, w);
    o = p + v * k;
    return true;
  }

  /* 点p到直线ab的距离 */
  double getDistanceToLine(Point p, Point a, Point b) { return fabs(getCross(b-a, p-a) / getLength(b-a)); }

  double getDistanceToSegment(Point p, Point a, Point b) {
    if (a == b) return getLength(p-a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (sgn(getDot(v1, v2)) < 0) return getLength(v2);
    else if (sgn(getDot(v1, v3)) > 0) return getLength(v3);
    else return fabs(getCross(v1, v2) / getLength(v1));
  }

  /* 点p在直线ab上的投影 */
  Point getPointToLine(Point p, Point a, Point b) { Vector v = b-a; return a+v*(getDot(v, p-a) / getDot(v,v)); }

  /* 判断线段是否存在交点 */
  bool haveIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1=getCross(a2-a1, b1-a1), c2=getCross(a2-a1, b2-a1), c3=getCross(b2-b1, a1-b1), c4=getCross(b2-b1,a2-b1);
    return sgn(c1)*sgn(c2) < 0 && sgn(c3)*sgn(c4) < 0;
  }

  /* 判断点是否在线段上 */
  bool onSegment(Point p, Point a, Point b) { return sgn(getCross(a-p, b-p)) == 0 && sgn(getDot(a-p, b-p)) < 0; }
  bool onLeft(DirLine l, Point p) { return sgn(l.v ^ (p-l.p)) >= 0; }
}

namespace Triangular {
  using namespace Vectorial;

  double getAngle(double a, double b, double c) { return acos((a*a+b*b-c*c) / (2*a*b)); }
  double getArea(double a, double b, double c) { double s =(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
  double getArea(double a, double h) { return a * h / 2; }
  double getArea(Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
  double getDirArea(Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }
};

namespace Polygonal {
  using namespace Vectorial;
  using namespace Linear;

  double getArea(Point* p, int n) {
    double ret = 0;
    for (int i = 0; i < n - 1; i++)
      ret += (p[i] - p[0]) ^ (p[i+1] - p[0]);
    return fabs(ret / 2);
  }

  /* 凸包 */
  int getConvexHull(Point* ps, int n, Point* ch) {
    /* 可共线删去两个 =，需要先去除重点! */
    sort(ps, ps + n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
      while (k > 1 && sgn(getCross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])) <= 0) k--;
      ch[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; --i) {
      while (k > t && sgn(getCross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])) <= 0) k--;
      ch[k++] = ps[i];
    }
    if (n > 1) k--;
    return k;
  }

  int isPointInPolygon(Point o, Point* p, int n) {
    int wn = 0;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      if (onSegment(o, p[i], p[j]) || o == p[i]) return 0; // 边界上
      int k = sgn(getCross(p[j] - p[i], o-p[i]));
      int d1 = sgn(p[i].y - o.y);
      int d2 = sgn(p[j].y - o.y);
      if (k > 0 && d1 <= 0 && d2 > 0) wn++;
      if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    return wn ? -1 : 1;
  }

  /* 旋转卡壳 */
  void rotatingCalipers(Point *p, int n, vector<Pii>& sol) {
    sol.clear();
    int j = 1; p[n] = p[0];
    for (int i = 0; i < n; i++) {
      while (getCross(p[j+1]-p[i+1], p[i]-p[i+1]) > getCross(p[j]-p[i+1], p[i]-p[i+1]))
        j = (j + 1) % n;
      sol.push_back(make_pair(i, j));
      sol.push_back(make_pair(i + 1, j + 1));
    }
  }

  void rotatingCalipersGetRectangle(Point *p, int n, double& area, double& perimeter) {
    p[n] = p[0];
    int l = 1, r = 1, j = 1;
    area = perimeter = 1e20;

    for (int i = 0; i < n; i++) {
      Vector v = (p[i+1]-p[i]) / getLength(p[i+1]-p[i]);
      while (sgn(getDot(v, p[r%n]-p[i]) - getDot(v, p[(r+1)%n]-p[i])) < 0) r++;
      while (j < r || sgn(getCross(v, p[j%n]-p[i]) - getCross(v,p[(j+1)%n]-p[i])) < 0) j++;
      while (l < j || sgn(getDot(v, p[l%n]-p[i]) - getDot(v, p[(l+1)%n]-p[i])) > 0) l++;
      double w = getDot(v, p[r%n]-p[i])-getDot(v, p[l%n]-p[i]);
      double h = getDistanceToLine(p[j%n], p[i], p[i+1]);
      area = min(area, w * h);
      perimeter = min(perimeter, 2 * w + 2 * h);
    }
  }

  /* 计算半平面相交可以用增量法，o(n^2)，初始设置4条无穷大的半平面 */
  /* 用有向直线A->B切割多边形u，返回左侧。可能退化成单点或线段 */
  Polygon cutPolygon(Polygon u, Point a, Point b) {
    Polygon ret;
    int n = u.size();
    for (int i = 0; i < n; i++) {
      Point c = u[i], d = u[(i+1)%n];
      if (sgn((b-a)^(c-a)) >= 0) ret.push_back(c);
      if (sgn((b-a)^(c-d)) != 0) {
        Point t;
        getIntersection(a, b-a, c, d-c, t);
        if (onSegment(t, c, d))
          ret.push_back(t);
      }
    }
    return ret;
  }

  /* 半平面相交 */
  int halfPlaneIntersection(DirLine* li, int n, Point* poly) {
    sort(li, li + n);

    int first, last;
    Point* p = new Point[n];
    DirLine* q = new DirLine[n];
    q[first=last=0] = li[0];

    for (int i = 1; i < n; i++) {
      while (first < last && !onLeft(li[i], p[last-1])) last--;
      while (first < last && !onLeft(li[i], p[first])) first++;
      q[++last] = li[i];

      if (sgn(q[last].v ^ q[last-1].v) == 0) {
        last--;
        if (onLeft(q[last], li[i].p)) q[last] = li[i];
      }

      if (first < last)
        getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
    }

    while (first < last && !onLeft(q[first], p[last-1])) last--;
    if (last - first <= 1) { delete [] p; delete [] q; return 0; }
    getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

    int m = 0;
    for (int i = first; i <= last; i++) poly[m++] = p[i];
    delete [] p; delete [] q;
    return m;
  }

  /* 去除多边形共线点 */
  Polygon simplify(const Polygon& poly) {
    Polygon ret;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
      Point a = poly[i];
      Point b = poly[(i+1)%n];
      Point c = poly[(i+2)%n];
      if (sgn((b-a)^(c-b)) != 0 && (ret.size() == 0 || b != ret[ret.size()-1]))
        ret.push_back(b);
    }
    return ret;
  }
};

namespace Circular {
  using namespace Linear;
  using namespace Vectorial;
  using namespace Triangular;

  /* 直线和圆的交点 */
  int getLineCircleIntersection(Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
    Vector v = q - p;
    /* 使用前需清空sol */
    //sol.clear();
    double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
    double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-O.r*O.r;
    double delta = f*f - 4*e*g;
    if (sgn(delta) < 0) return 0;
    if (sgn(delta) == 0) {
      t1 = t2 = -f / (2 * e);
      sol.push_back(p + v * t1);
      return 1;
    }

    t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
    t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
    return 2;
  }

  /* 圆和圆的交点 */
  int getCircleCircleIntersection(Circle o1, Circle o2, vector<Point>& sol) {
    double d = getLength(o1.o - o2.o);

    if (sgn(d) == 0) {
      if (sgn(o1.r - o2.r) == 0) return -1;
      return 0;
    }

    if (sgn(o1.r + o2.r - d) < 0) return 0;
    if (sgn(fabs(o1.r-o2.r) - d) > 0) return 0;

    double a = getAngle(o2.o - o1.o);
    double da = acos((o1.r*o1.r + d*d - o2.r*o2.r) / (2*o1.r*d));

    Point p1 = o1.point(a-da), p2 = o1.point(a+da);

    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
  }

  /* 过定点作圆的切线 */
  int getTangents(Point p, Circle o, Vector* v) {
    Vector u = o.o - p;
    double d = getLength(u);
    if (d < o.r) return 0;
    else if (sgn(d - o.r) == 0) {
      v[0] = rotate(u, pi / 2);
      return 1;
    } else {
      double ang = asin(o.r / d);
      v[0] = rotate(u, -ang);
      v[1] = rotate(u, ang);
      return 2;
    }
  }

  /* a[i] 和 b[i] 分别是第i条切线在O1和O2上的切点 */
  int getTangents(Circle o1, Circle o2, Point* a, Point* b) {
    int cnt = 0;
    if (sgn(o1.r - o2.r) < 0) { swap(o1, o2); swap(a, b); }
    double d2 = getPLength(o1.o - o2.o);
    double rdif = o1.r - o2.r, rsum = o1.r + o2.r;
    if (sgn(d2 - rdif * rdif) < 0) return 0;
    if (sgn(d2) == 0 && sgn(rdif) == 0) return -1;

    double base = getAngle(o2.o - o1.o);
    if (sgn(d2 - rdif * rdif) == 0) {
      a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
      return cnt;
    }

    double ang = acos(rdif / sqrt(d2));
    a[cnt] = o1.point(base+ang); b[cnt] = o2.point(base+ang); cnt++;
    a[cnt] = o1.point(base-ang); b[cnt] = o2.point(base-ang); cnt++;

    if (sgn(d2 - rsum * rsum) == 0) {
      a[cnt] = o1.point(base); b[cnt] = o2.point(pi+base); cnt++;
    } else if (sgn(d2 - rsum * rsum) > 0) {
      double ang = acos(rsum / sqrt(d2));
      a[cnt] = o1.point(base+ang); b[cnt] = o2.point(pi+base+ang); cnt++;
      a[cnt] = o1.point(base-ang); b[cnt] = o2.point(pi+base-ang); cnt++;
    }
    return cnt;
  }

  /* 三点确定外切圆 */
  Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
    double Bx = p2.x - p1.x, By = p2.y - p1.y;
    double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
    double D = 2 * (Bx * Cy - By * Cx);
    double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
    double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
    Point p = Point(cx, cy);
    return Circle(p, getLength(p1 - p));
  }

  /* 三点确定内切圆 */
  Circle InscribedCircle(Point p1, Point p2, Point p3) {
    double a = getLength(p2 - p3);
    double b = getLength(p3 - p1);
    double c = getLength(p1 - p2);
    Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
    return Circle(p, getDistanceToLine(p, p1, p2));
  }

  /* 三角形一顶点为圆心 */
  double getPublicAreaToTriangle(Circle O, Point a, Point b) {
    if (sgn((a-O.o)^(b-O.o)) == 0) return 0;
    int sig = 1;
    double da = getLength(O.o-a), db = getLength(O.o-b);
    if (sgn(da-db) > 0) {
      swap(da, db); swap(a, b); sig = -1;
    }

    double t1, t2;
    vector<Point> sol;
    int n = getLineCircleIntersection(a, b, O, t1, t2, sol);

    if (sgn(da-O.r) <= 0) {
      if (sgn(db-O.r) <= 0)  return getDirArea(O.o, a, b) * sig;

      int k = 0;
      if (n == 2 && getPLength(sol[0]-b) > getPLength(sol[1]-b)) k = 1;

      double ret = getArea(O.o, a, sol[k]) + O.getArea(getAngle(sol[k]-O.o, b-O.o));
      double tmp = (a-O.o)^(b-O.o);
      return ret * sig * sgn(tmp);
    }

    double d = getDistanceToSegment(O.o, a, b);
    if (sgn(d-O.r) >= 0) {
      double ret = O.getArea(getAngle(a-O.o, b-O.o));
      double tmp = (a-O.o)^(b-O.o);
      return ret * sig * sgn(tmp);
    }

    double ret1 = O.getArea(getAngle(a-O.o, b-O.o));
    double ret2 = O.getArea(getAngle(sol[0]-O.o, sol[1]-O.o)) - getArea(O.o, sol[0], sol[1]);
    double ret = (ret1 - ret2), tmp = (a-O.o)^(b-O.o);
    return ret * sig * sgn(tmp);
  }

  double getPublicAreaToPolygon(Circle O, Point* p, int n) {
    if (sgn(O.r) == 0) return 0;
    double area = 0;
    for (int i = 0; i < n; i++) {
      int u = (i + 1) % n;
      area += getPublicAreaToTriangle(O, p[i], p[u]);
    }
    return fabs(area);
  }

  Circle minimumCoveringCircle(Point* p, int n) {
    random_shuffle(p, p + n);
    Circle O(p[0], 0);
    for (int i = 0; i < n; i++)
      if (sgn(getDistance(O.o, p[i]) - O.r) > 0) {
        O.o = p[i]; O.r = 0;
        for (int j = 0; j < i; j++)
          if (sgn(getDistance(O.o, p[j]) - O.r) > 0) {
            O.o = (p[i] + p[j]) / 2;
            O.r = getDistance(p[i], p[j]) / 2;
            for (int k = 0; k < j; k++)
              if (sgn(getDistance(O.o, p[k]) - O.r) > 0)
                O = CircumscribedCircle(p[i], p[j], p[k]);
          }
      }
    return O;
  }

  // 一条不过反演中心的直线，反形是一个过反演中心的圆；
  // 一个不过反演中心的圆，反形也是一个不过反演中心的圆，反演中心是它们的位似中心
  // 两个图形存在相切关系，那么反演后仍然满足相切关系。（特别地，如果以两圆切点作为反演中心，那么反演后的两条直线平行）
  // r2 反演半径的平方
  Circle inv(Circle O, Point p, double r2 = 25.0) {
    double d = getDistance(O.o, p);
    double a = 1 / (d - O.r);
    double b = 1 / (d + O.r);
    O.r = (a - b) / 2 * r2;
    O.o = p + (O.o - p) * (a + b) * r2 / 2 / d;
    return O;
  }

  Circle inv(Point a, Point b, Point p, double r2 = 25.0) {
    Vector v = Vector(b.y - a.y, a.x - b.x);
    Point x;
    getIntersection(p, v, a, b - a, x);
    double d = getDistance(x, p);
    if (sgn(d) == 0) return Circle(Point(0, 0), 0);
    double r = r2 / d / 2;
    Point o = p + (x - p) * (r / d);
    return Circle(o, r);
  }

  // 经纬度求球面最短距离
  double Dist(double la1, double lo1, double la2, double lo2, double R) {
    la1 *= PI / 180, lo1 *= PI / 180,la2 *= PI / 180,lo2 *= PI / 180;
    double x1 = cos(la1) * sin(lo1), y1 = cos(la1) * cos(lo1), z1 = sin(la1); 
    double x2 = cos(la2) * sin(lo2), y2 = cos(la2) * cos(lo2), z1 = sin(la2); 
    return R * acos(x1 * x2 + y1 * y2 + z1 * z2);
  }
};
```

## 曼哈顿最小生成树

曼哈顿距离有特殊性质，在最小生成树中可以得出这样一个结论：**以一个点为原点建立直角坐标系，在每45度内只会向距离该点最近的一个点连边**

```c++
// LA 3662
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n,pn,cnt,b[maxn],fa[maxn];

struct Point {
  int x,y;
  int id;
  bool operator < (const Point& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
} p[maxn];

struct Edge {
  int u,v;
  LL d;
  bool operator < (const Edge& rhs) const {
    return d < rhs.d;
  }
} e[maxn<<2];

void addEdge(int u,int v,LL d) {
  e[cnt].u = u; e[cnt].v = v; e[cnt++].d = d;
}

struct Bit {
  int mn,pos;
  void init() {
    mn = INF;
    pos = -1;
  }
} bit[maxn];

inline int lowbit(int x) {
  return x&-x;
}

void update(int x,int mn,int pos) {
  for(int i=x;i>0;i-=lowbit(i)) {
    if(bit[i].mn > mn) {
      bit[i].mn = mn;
      bit[i].pos = pos;
    }
  }
}

int query(int x) {
  int mn = INF,pos = -1;
  for(int i=x;i<=pn;i+=lowbit(i)) {
    if(bit[i].mn < mn) {
      mn = bit[i].mn;
      pos = bit[i].pos;
    }
  }
  return pos;
}

int find(int x) {
  return fa[x] == x?x:fa[x] = find(fa[x]);
}

LL solve() {
  cnt = 0;
  for(int dir=0;dir<4;++dir) {
    if(dir&1) for(int i=0;i<n;++i) swap(p[i].x,p[i].y);
    if(dir==2) for(int i=0;i<n;++i) p[i].x = -p[i].x;
    sort(p,p+n);
    for(int i=0;i<n;++i) b[i] = p[i].y - p[i].x;
    sort(b,b+n);
    pn = unique(b,b+n) - b;
    for(int i=1;i<=pn;++i) bit[i].init();
    for(int i=n-1;i>=0;--i) {
      int pos = lower_bound(b,b+pn,p[i].y - p[i].x) - b + 1;
      int po = query(pos);
      if(po != -1)
        addEdge(p[i].id,p[po].id,abs(p[i].x-p[po].x) + abs(p[po].y-p[i].y));
      update(pos,p[i].y + p[i].x,i);
    }
  }
  LL res = 0;
  for(int i=0;i<n;++i) fa[i] = i;
  sort(e,e+cnt);
  for(int i=0;i<cnt;++i) {
    int u = find(e[i].u),v = find(e[i].v);
    if(u != v) {
      fa[u] = v;
      res += e[i].d;
    }
  }
  return res;
}

int main() {
  int kase = 1;
  while(scanf("%d",&n) == 1 && n) {
    for(int i=0;i<n;++i) {
      scanf("%d %d",&p[i].x,&p[i].y);
      p[i].id = i;
    }
    LL ans = solve();
    printf("Case %d: Total Weight = %lld\n",kase++,ans);
  }
  return 0;
}
```

## PLSG
```c++
// LA 2797
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);
  double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
  return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

bool OnSegment(const Point& p, const Point& a, const Point& b) {
  return dcmp(Cross(a-p, b-p)) == 0 && dcmp(Dot(a-p, b-p)) < 0;
}

const int maxn = 200 + 5;
int n, V;
int G[maxn][maxn], vis[maxn];
Point p1[maxn], p2[maxn];

bool OnAnySegment(const Point& p) {
  for(int i = 0; i < n; ++i)
    if(OnSegment(p, p1[i], p2[i]))  return true;
  return false;
}

bool IntersectionWithAnySegment(const Point& a, const Point& b) {
  for(int i = 0; i < n; ++i)
    if(SegmentProperIntersection(a, b, p1[i], p2[i])) return true;
  return false;
}

bool dfs(int u) {
  if(u == 1)  return true;
  vis[u] = 1;
  for(int v = 0; v < V; ++v)
    if(G[u][v] && !vis[v] && dfs(v))  return true;
  return false;
}

bool find_path() {
  vector<Point> vertices;
  vertices.push_back(Point(0.0, 0.0));
  vertices.push_back(Point(1e5, 1e5));
  for(int i = 0; i < n; ++i) {
    if(!OnAnySegment(p1[i])) vertices.push_back(p1[i]);
    if(!OnAnySegment(p2[i])) vertices.push_back(p2[i]);
  }
  V = vertices.size();
  memset(G, 0, sizeof(G));
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < V; ++i)
    for(int j = i+1; j < V; ++j)
      if(!IntersectionWithAnySegment(vertices[i], vertices[j]))
        G[i][j] = G[j][i] = 1;
  return dfs(0);
}

int main(void) {
  while(scanf("%d", &n) == 1 && n) {
    double x1, y1, x2, y2;
    for(int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      Point a = Point(x1, y1);
      Point b = Point(x2, y2);
      double l = Length(a-b);
      Vector v0 = (a-b) / l * 1e-6;
      p1[i] = a + v0;
      p2[i] = b - v0;
    }
    if(find_path()) puts("no");
    else puts("yes");
  }
  return 0;
}
```

```c++
// LA3218/UVa1340 Find the Border
// Rujia Liu
// 注意：本题可以直接使用“卷包裹”法求出外轮廓。本程序只是为了演示 PSLG 的实现
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;

const double eps = 1e-8;
double dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}

struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) {
  return Vector(A.x+B.x, A.y+B.y);
}

Vector operator - (Point A, Point B) {
  return Vector(A.x-B.x, A.y-B.y);
}

Vector operator * (Vector A, double p) {
  return Vector(A.x*p, A.y*p);
}

// 理论上这个“小于”运算符是错的，因为可能有三个点a, b, c, a和b很接近（即a<b和b<a都不成立），b和c很接近，但a和c不接近
// 所以使用这种“小于”运算符的前提是能排除上述情况
bool operator < (const Point& a, const Point& b) {
  return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}

bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
double Length(Vector A) { return sqrt(Dot(A, A)); }

typedef vector<Point> Polygon;

Point GetLineIntersection(const Point& P, const Vector& v, const Point& Q, const Vector& w) {
  Vector u = P-Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}

bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

// 多边形的有向面积
double PolygonArea(Polygon poly) {
  double area = 0;
  int n = poly.size();
  for(int i = 1; i < n-1; i++)
    area += Cross(poly[i]-poly[0], poly[(i+1)%n]-poly[0]);
  return area/2;
}

struct Edge {
  int from, to; // 起点，终点，左边的面编号
  double ang;
};

const int maxn = 10000 + 10; // 最大边数

// 平面直线图（PSGL）实现
struct PSLG {
  int n, m, face_cnt;
  double x[maxn], y[maxn];
  vector<Edge> edges;
  vector<int> G[maxn];
  int vis[maxn*2];  // 每条边是否已经访问过
  int left[maxn*2]; // 左面的编号
  int prev[maxn*2]; // 相同起点的上一条边（即顺时针旋转碰到的下一条边）的编号

  vector<Polygon> faces;
  double area[maxn]; // 每个polygon的面积

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
    faces.clear();
  }

  // 有向线段from->to的极角
  double getAngle(int from, int to) {
    return atan2(y[to]-y[from], x[to]-x[from]);
  }

  void AddEdge(int from, int to) {
    edges.push_back((Edge){from, to, getAngle(from, to)});
    edges.push_back((Edge){to, from, getAngle(to, from)});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  // 找出faces并计算面积
  void Build() {
    for(int u = 0; u < n; u++) {
      // 给从u出发的各条边按极角排序
      int d = G[u].size();
      for(int i = 0; i < d; i++)
        for(int j = i+1; j < d; j++) // 这里偷个懒，假设从每个点出发的线段不会太多
          if(edges[G[u][i]].ang > edges[G[u][j]].ang) swap(G[u][i], G[u][j]);
      for(int i = 0; i < d; i++)
        prev[G[u][(i+1)%d]] = G[u][i];
    }

    memset(vis, 0, sizeof(vis));
    face_cnt = 0;
    for(int u = 0; u < n; u++)
      for(int i = 0; i < G[u].size(); i++) {
        int e = G[u][i];
        if(!vis[e]) { // 逆时针找圈
          face_cnt++;
          Polygon poly;
          for(;;) {
            vis[e] = 1; left[e] = face_cnt;
            int from = edges[e].from;
            poly.push_back(Point(x[from], y[from]));
            e = prev[e^1];
            if(e == G[u][i]) break;
            assert(vis[e] == 0);
          }
          faces.push_back(poly);
        }
      }

    for(int i = 0; i < faces.size(); i++) {
      area[i] = PolygonArea(faces[i]);
    }
  }
};

PSLG g;

const int maxp = 100 + 5;
int n, c;
Point P[maxp];

Point V[maxp*(maxp-1)/2+maxp];

// 在V数组里找到点p
int ID(Point p) {
  return lower_bound(V, V+c, p) - V;
}

// 假定poly没有相邻点重合的情况，只需要删除三点共线的情况
Polygon simplify(const Polygon& poly) {
  Polygon ans;
  int n = poly.size();
  for(int i = 0; i < n; i++) {
    Point a = poly[i];
    Point b = poly[(i+1)%n];
    Point c = poly[(i+2)%n];
    if(dcmp(Cross(a-b, c-b)) != 0) ans.push_back(b);
  }
  return ans;
}

void build_graph() {
  c = n;
  for(int i = 0; i < n; i++)
    V[i] = P[i];

  vector<double> dist[maxp]; // dist[i][j]是第i条线段上的第j个点离起点（P[i]）的距离
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      if(SegmentProperIntersection(P[i], P[(i+1)%n], P[j], P[(j+1)%n])) {
        Point p = GetLineIntersection(P[i], P[(i+1)%n]-P[i], P[j], P[(j+1)%n]-P[j]);
        V[c++] = p;
        dist[i].push_back(Length(p - P[i]));
        dist[j].push_back(Length(p - P[j]));
      }

  // 为了保证“很接近的点”被看作同一个，这里使用了sort+unique的方法
  // 必须使用前面提到的“理论上是错误”的小于运算符，否则不能保证“很接近的点”在排序后连续排列
  // 另一个常见的处理方式是把坐标扩大很多倍（比如100000倍），然后四舍五入变成整点（计算完毕后再还原），用少许的精度损失换来鲁棒性和速度。
  sort(V, V+c);
  c = unique(V, V+c) - V;

  g.init(c); // c是平面图的点数
  for(int i = 0; i < c; i++) {
    g.x[i] = V[i].x;
    g.y[i] = V[i].y;
  }
  for(int i = 0; i < n; i++) {
    Vector v = P[(i+1)%n] - P[i];
    double len = Length(v);
    dist[i].push_back(0);
    dist[i].push_back(len);
    sort(dist[i].begin(), dist[i].end());
    int sz = dist[i].size();
    for(int j = 1; j < sz; j++) {
      Point a = P[i] + v * (dist[i][j-1] / len);
      Point b = P[i] + v * (dist[i][j] / len);
      if(a == b) continue;
      g.AddEdge(ID(a), ID(b));
    }
  }

  g.Build();

  Polygon poly;
  for(int i = 0; i < g.faces.size(); i++)
    if(g.area[i] < 0) { // 对于连通图，惟一一个面积小于零的面是无限面
      poly = g.faces[i];
      reverse(poly.begin(), poly.end()); // 对于内部区域来说，无限面多边形的各个顶点是顺时针的
      poly = simplify(poly); // 无限面多边形上可能会有相邻共线点
      break;
    }

  int m = poly.size();
  printf("%d\n", m);

  // 挑选坐标最小的点作为输出的起点
  int start = 0;
  for(int i = 0; i < m; i++)
    if(poly[i] < poly[start]) start = i;
  for(int i = start; i < m; i++)
    printf("%.4lf %.4lf\n", poly[i].x, poly[i].y);
  for(int i = 0; i < start; i++)
    printf("%.4lf %.4lf\n", poly[i].x, poly[i].y);
}

int main() {
  while(scanf("%d", &n) == 1 && n) {
    for(int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      P[i] = Point(x, y);
    }
    build_graph();
  }
  return 0;
}
```

## 点线对偶

利用对偶性，可以将点问题与线问题互相转化。方程为 $y=kx+b$ 的直线与坐标为 $(k,b)$ 的点是对偶的。（改为$(-k,b)$对偶完以后的直线与凸包凹凸性一致）

例如典型的半平面交问题，可以做如下变换：按半平面的方向将所有的半平面分成两部分，分别是朝 $y$ 的正方向和朝 $y$ 的负方向。对所有方向向上的半平面对偶出来的点取上凸包，对所有方向向下的半平面对偶出来的点取下凸包，则得到的两个半凸包包含了哪些点就意味着半平面交得到的两个半凸包包含了哪些直线。这对于半平面交的存在性判定非常有帮助。不过其中平行于 $y$ 轴的直线会存在问题。可以做一些特殊处理：将 $x=b$ 换成 $y=\inf x-b\inf$ 的形式。若方向向左，则认为它是方向向上；若方向向右，则认为它是方向向下。但这样是不可能做到精确的。 

例题：有 $n$ 条垂直于水平线的竖直线段，问能否找到一条直线，使之可以穿过的线段。注：如果某条直线恰好穿过了线段的端点也表示它穿过了这个线段。 

可以证明，可以把每个线段上端点对偶成向下的半平面，下端点对偶成向上的半平面，转化该问题为半平面交问题，如果半平面交为空则不存在一条直线满足题意。（半平面交为一个点也算是不为空）接着我们再做一次对偶，把两个半平面交问题转化为两个半凸包问题，只要得到的两个半凸包的交为空，则存在这样的直线。（交成一个点也算是为空） 

但是这种做法只适用于所有的线段平行的情形下。如果是任意的线段，那该问题在对偶为半平面交的问题时，会存在 double edge 的情况，那么在对偶到凸包问题时是有问题的，不能简单地用 $y$ 高度来决定它是属于上端点还是下端点。类似地我们要把半平面交的“或”的情况加上去，这种“或”的结果就是两个端点的归属是可以互换的。 

所以在对于不平行的情况下，问题其实就是在每个线段中选一个端点组成一个集合，另外一个组成一个集合，求两个集合的半凸包，只要存在一个这样的集合方案使得凸包没有交，那么就答案就是存在。这就是一个可分割性的问题了。 

## 三维

```c++
struct Point3 {
  double x,y,z;
  Point3(double _x = 0,double _y = 0,double _z = 0){
    x = _x; y = _y; z = _z;
  }
  void input(){ scanf("%lf%lf%lf",&x,&y,&z); }
  void output(){ scanf("%.2lf␣%.2lf␣%.2lf\n",x,y,z); }
  bool operator ==(const Point3 &b)const{
    return sgn(x−b.x) == 0 && sgn(y−b.y) == 0 && sgn(z−b.z) == 0;
  }
  bool operator <(const Point3 &b)const{
    return sgn(x−b.x)==0?(sgn(y−b.y)==0?sgn(z−b.z)<0:y<b.y):x<b .x;
  }
  double len(){ return sqrt(x*x+y*y+z*z); }
  double len2(){ return x*x+y*y+z*z; }
  double distance(const Point3 &b)const{
    return sqrt((x−b.x)*(x−b.x)+(y−b.y)*(y−b.y)+(z−b.z)*(z−b.z) );
  }
  Point3 operator -(const Point3 &b)const{
    return Point3(x−b.x,y−b.y,z−b.z); 
  }
  Point3 operator +(const Point3 &b)const{ 
    return Point3(x+b.x,y+b.y,z+b.z);
  }
  Point3 operator *(const double &k)const{
    return Point3(x*k,y*k,z*k); }
  Point3 operator /(const double &k)const{ return Point3(x/k,y/k,z/k);
  }
  //点乘
  double operator *(const Point3 &b)const{
    return x*b.x+y*b.y+z*b.z; 
  }
  //叉乘
  Point3 operator ^(const Point3 &b)const{
    return Point3(y*b.z−z*b.y,z*b.x−x*b.z,x*b.y−y*b.x); 
  }
  double rad(Point3 a,Point3 b){
    Point3 p = (*this);
    return acos( ( (a−p)*(b−p) )/ (a.distance(p)*b.distance(p)));
  }
  //变换长度
  Point3 trunc(double r){
    double l = len();
    if(!sgn(l))return *this; 
    r /= l;
    return Point3(x*r,y*r,z*r);
  }
};
struct Line3 {
  Point3 s,e;
  Line3(){}
  Line3(Point3 _s,Point3 _e) {
    s = _s; e = _e; 
  }
  bool operator ==(const Line3 v) {
    return (s==v.s)&&(e==v.e); 
  }
  void input() { s.input(); e.input(); }
  double length() { return s.distance(e); }
  //点到直线距离
  double dispointtoline(Point3 p) {
    return ((e−s)^(p−s)).len()/s.distance(e); 
  }
  //点到线段距离
  double dispointtoseg(Point3 p) {
    if(sgn((p−s)*(e−s)) < 0 || sgn((p−e)*(s−e)) < 0) return min(p.distance(s),e.distance(p));
    return dispointtoline(p); 
  }
  //返回点 p 在直线上的投影 
  Point3 lineprog(Point3 p) {
    return s + ( ((e−s)*((e−s)*(p−s)))/((e−s).len2()) ); 
  }
  //p 绕此向量逆时针 arg 角度
  Point3 rotate(Point3 p,double ang) {
    if (sgn(((s−p)^(e−p)).len()) == 0) return p;
    Point3 f1 = (e−s)^(p−s);
    Point3 f2 = (e−s)^(f1);
    double len = ((s−p)^(e−p)).len()/s.distance(e);
    f1 = f1.trunc(len); f2 = f2.trunc(len);
    Point3 h = p+f2;
    Point3 pp = h+f1;
    return h + ((p−h)*cos(ang)) + ((pp−h)*sin(ang));
  }
  //点在直线上
  bool pointonseg(Point3 p) {
    return sgn( ((s−p)^(e−p)).len() ) == 0 && sgn((s−p)*(e−p)) == 0;
  }
};

struct Plane {
  Point3 a,b,c,o;//平面上的三个点，以及法向量
  Plane(){}
  Plane(Point3 _a,Point3 _b,Point3 _c) {
    a=_a;
    b=_b;
    c=_c;
    o = pvec();
  }
  Point3 pvec() {
    return (b−a)^(c−a);
  }
  //ax+by+cz+d = 0
  Plane(double _a,double _b,double _c,double _d) {
    o = Point3(_a,_b,_c);
    if(sgn(_a) != 0)
      a = Point3((−_d−_c−_b)/_a,1,1);
    else if(sgn(_b) != 0)
      a = Point3(1,(−_d−_c−_a)/_b,1);
    else if(sgn(_c) != 0)
      a = Point3(1,1,(−_d−_a−_b)/_c);
  }
  //点在平面上的判断
  bool pointonplane(Point3 p) {
    return sgn((p−a)*o) == 0;
  }
  //两平面夹角
  double angleplane(Plane f) {
    return acos(o*f.o)/(o.len()*f.o.len());
  }
  //平面和直线的交点，返回值是交点个数
  int crossline(Line3 u,Point3 &p) {
    double x = o*(u.e−a);
    double y = o*(u.s−a);
    double d = x−y;
    if(sgn(d) == 0)return 0;
    p = ((u.s*x)−(u.e*y))/d;
    return 1;
  }
  //点到平面最近点 (也就是投影)
  Point3 pointtoplane(Point3 p) {
    Line3 u = Line3(p,p+o);
    crossline(u,p);
    return p;
  }
  //平面和平面的交线
  int crossplane(Plane f,Line3 &u) {
    Point3 oo = o^f.o;
    Point3 v = o^oo;
    double d = fabs(f.o*v);
    if(sgn(d) == 0)return 0;
    Point3 q = a + (v*(f.o*(f.a−a))/d); u = Line3(q,q+oo);
    return 1;
  }
};
```

### 三维凸包

```c++
/*
HDU 4273 Rescue
给一个三维凸包，求重心到表面的最短距离
模板题：三维凸包+多边形重心+点面距离
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
const int MAXN=550;
const double eps=1e-8;

struct Point {
    double x,y,z;
    Point(){}
    Point(double xx,double yy,double zz):x(xx),y(yy),z(zz){}
    //两向量之差
    Point operator -(const Point p1) {
        return Point(x-p1.x,y-p1.y,z-p1.z);
    }
    //两向量之和
    Point operator +(const Point p1) {
        return Point(x+p1.x,y+p1.y,z+p1.z);
    }
    //叉乘
    Point operator *(const Point p) {
        return Point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    Point operator *(double d) {
        return Point(x*d,y*d,z*d);
    }
    Point operator / (double d) {
        return Point(x/d,y/d,z/d);
    }
    //点乘
    double operator ^(Point p) {
        return (x*p.x+y*p.y+z*p.z);
    }
};

struct CH3D {
    struct face {
        //表示凸包一个面上的三个点的编号
        int a,b,c;
        //表示该面是否属于最终凸包上的面
        bool ok;
    };
    //初始顶点数
    int n;
    //初始顶点
    Point P[MAXN];
    //凸包表面的三角形数
    int num;
    //凸包表面的三角形
    face F[8*MAXN];
    //凸包表面的三角形
    int g[MAXN][MAXN];
    //向量长度
    double vlen(Point a) {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }
    //叉乘
    Point cross(const Point &a,const Point &b,const Point &c) {
        return Point((b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y),
                     (b.z-a.z)*(c.x-a.x)-(b.x-a.x)*(c.z-a.z),
                     (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)
                     );
    }
    //三角形面积*2
    double area(Point a,Point b,Point c) {
        return vlen((b-a)*(c-a));
    }
    //四面体有向体积*6
    double volume(Point a,Point b,Point c,Point d) {
        return (b-a)*(c-a)^(d-a);
    }
    //正：点在面同向
    double dblcmp(Point &p,face &f) {
        Point m=P[f.b]-P[f.a];
        Point n=P[f.c]-P[f.a];
        Point t=p-P[f.a];
        return (m*n)^t;
    }
    void deal(int p,int a,int b) {
        int f=g[a][b];//搜索与该边相邻的另一个平面
        face add;
        if(F[f].ok) {
            if(dblcmp(P[p],F[f])>eps)
              dfs(p,f);
            else {
                add.a=b;
                add.b=a;
                add.c=p;//这里注意顺序，要成右手系
                add.ok=true;
                g[p][b]=g[a][p]=g[b][a]=num;
                F[num++]=add;
            }
        }
    }
    //递归搜索所有应该从凸包内删除的面
    void dfs(int p,int now) {
         F[now].ok=0;
         deal(p,F[now].b,F[now].a);
         deal(p,F[now].c,F[now].b);
         deal(p,F[now].a,F[now].c);
    }
    bool same(int s,int t) {
        Point &a=P[F[s].a];
        Point &b=P[F[s].b];
        Point &c=P[F[s].c];
        return fabs(volume(a,b,c,P[F[t].a]))<eps &&
               fabs(volume(a,b,c,P[F[t].b]))<eps &&
               fabs(volume(a,b,c,P[F[t].c]))<eps;
    }
    //构建三维凸包
    void create() {
        int i,j,tmp;
        face add;
        num=0;
        if(n<4)return;
    //**********************************************
        //此段是为了保证前四个点不共面
        bool flag=true;
        for(i=1;i<n;i++) {
            if(vlen(P[0]-P[i])>eps) {
                swap(P[1],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)return;
        flag=true;
        //使前三个点不共线
        for(i=2;i<n;i++) {
            if(vlen((P[0]-P[1])*(P[1]-P[i]))>eps) {
                swap(P[2],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)return;
        flag=true;
        //使前四个点不共面
        for(int i=3;i<n;i++) {
            if(fabs((P[0]-P[1])*(P[1]-P[2])^(P[0]-P[i]))>eps) {
                swap(P[3],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)return;
    //*****************************************
        for(i=0;i<4;i++) {
            add.a=(i+1)%4;
            add.b=(i+2)%4;
            add.c=(i+3)%4;
            add.ok=true;
            if(dblcmp(P[i],add)>0)swap(add.b,add.c);
            g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;
            F[num++]=add;
        }
        for(i=4;i<n;i++) {
            for(j=0;j<num;j++) {
                if(F[j].ok&&dblcmp(P[i],F[j])>eps) {
                    dfs(i,j);
                    break;
                }
            }
        }
        tmp=num;
        for(i=num=0;i<tmp;i++)
          if(F[i].ok)
            F[num++]=F[i];
    }
    //表面积
    double area() {
        double res=0;
        if(n==3) {
            Point p=cross(P[0],P[1],P[2]);
            res=vlen(p)/2.0;
            return res;
        }
        for(int i=0;i<num;i++)
          res+=area(P[F[i].a],P[F[i].b],P[F[i].c]);
        return res/2.0;
    }
    double volume() {
        double res=0;
        Point tmp(0,0,0);
        for(int i=0;i<num;i++)
           res+=volume(tmp,P[F[i].a],P[F[i].b],P[F[i].c]);
        return fabs(res/6.0);
    }
    //表面三角形个数
    int triangle() {
        return num;
    }
    //表面多边形个数
    int polygon() {
        int i,j,res,flag;
        for(i=res=0;i<num;i++) {
            flag=1;
            for(j=0;j<i;j++)
              if(same(i,j)) {
                  flag=0;
                  break;
              }
            res+=flag;
        }
        return res;
    }
    //三维凸包重心
    Point barycenter() {
        Point ans(0,0,0),o(0,0,0);
        double all=0;
        for(int i=0;i<num;i++) {
            double vol=volume(o,P[F[i].a],P[F[i].b],P[F[i].c]);
            ans=ans+(o+P[F[i].a]+P[F[i].b]+P[F[i].c])/4.0*vol;
            all+=vol;
        }
        ans=ans/all;
        return ans;
    }
    //点到面的距离
    double ptoface(Point p,int i) {
        return fabs(volume(P[F[i].a],P[F[i].b],P[F[i].c],p)/vlen((P[F[i].b]-P[F[i].a])*(P[F[i].c]-P[F[i].a])));
    }
};
CH3D hull;
int main() {
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    while(scanf("%d",&hull.n)==1) {
        for(int i=0;i<hull.n;i++) {
            scanf("%lf%lf%lf",&hull.P[i].x,&hull.P[i].y,&hull.P[i].z);
        }
        hull.create();
        Point p=hull.barycenter();
        double ans1=1e20;
        for(int i=0;i<hull.num;i++) {
            ans1=min(ans1,hull.ptoface(p,i));
        }
        scanf("%d",&hull.n);
        for(int i=0;i<hull.n;i++) {
            scanf("%lf%lf%lf",&hull.P[i].x,&hull.P[i].y,&hull.P[i].z);
        }
        hull.create();
        p=hull.barycenter();
        double ans2=1e20;
        for(int i=0;i<hull.num;i++) {
            ans2=min(ans2,hull.ptoface(p,i));
        }
        printf("%.5f\n",ans1+ans2);
    }
    return 0;
}
```

### 长方体表面两点最短距离

```c++
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double a,b,c,x,y,z,ans,l,w,h;
double f(double x) {
  return (double(x*x));
}

double min(double x,double y) {
  if(x>y) return y;
  else return x;
}

void count1() {
  ans=sqrt(double(f(a-x)+f(b-y)+f(c-z)));
}

void count2() {
  double ans1,ans2;
  if(b==0||b==w) {
    ans1=sqrt(double(min(f(h-z+w+h-c),f(z+w+c))+f(x-a)));
    ans2=sqrt(double(min(f(l-x+w+l-a),f(x+w+a))+f(c-z)));
  } else if(a==0||a==l) {
    ans1=sqrt(double(min(f(w-y+l+w-b),f(y+l+b))+f(c-z)));
    ans2=sqrt(double(min(f(h-z+l+h-c),f(z+l+c))+f(b-y)));
  } else {
    ans1=sqrt(double(min(f(w-y+h+w-b),f(y+h+b))+f(x-a)));
    ans2=sqrt(double(min(f(l-x+h+l-a),f(x+h+a))+f(b-y)));
  }
  ans=min(ans1,ans2);
}

void count3() {
  if(a==0||a==l) {
    if(y==0||y==w) 
      ans=sqrt(double(f(labs(x-a)+labs(b-y))+f(c-z)));
    else 
      ans=sqrt(double(f(labs(z-c)+labs(x-a))+f(b-y)));
  } else if(b==0||b==w) {
    if(x==0||x==l)
      ans=sqrt(double(f(labs(x-a)+labs(b-y))+f(c-z)));
    else
      ans=sqrt(double(f(labs(c-z)+labs(b-y))+f(a-x)));
  } else {
    if(x==0||x==l)
      ans=sqrt(double(f(labs(c-z)+labs(x-a))+f(b-y)));
    else
      ans=sqrt(double(f(labs(c-z)+labs(b-y))+f(a-x)));
  }
}

int main() {
  cin>>l>>w>>h;
  cin>>a>>b>>c>>x>>y>>z;
  if((a==x&&(a==0||a==l))||(b==y&&(b==0||b==w))||(c==z&&(c==0||c==h)))
    count1();
  else if((a==0&&x==l)||(b==0&&y==w)||(c==0&&z==h)||(a==l&&x==0)||(b==w&&y==0)||(c==h&&z==0))
    count2();
  else
    count3();
  cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
  return 0;
}
```

# 杂项

## 集合相关

### 子集枚举

```c++
int sub = sup;
do {
    sub = (sub - 1) & sup;
} while (sub != sup); // -1 & sup = sup;
```

### 势为 k 的集合枚举

```c++
int comb = (1 << k) - 1;
while (comb < 1 << n) {
    int x = comb & -comb, y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
}
```

### 排列组合

```c++
do {

} while (next_permutation(A, A + N)); // prev_permutation
```

### 高维前缀和

```c++
// 子集和
for (int i = 0; i < k; i++)
    for (int s = 0; s < 1 << k; s++)
        if (s >> i & 1) cnt[s] += cnt[s ^ (1 << i)];
// 超集和
for (int i = 0; i < k; i++)
    for (int s = 0; s < 1 << k; s++)
        if (!(s >> i & 1)) cnt[s] += cnt[s | (1 << i)];
```

## BuiltIn Function

```c++
int __builtin_ffs (unsigned int x)
//返回x的最后一位1的是从后向前第几位，比如7368（1110011001000）返回4。
int __builtin_clz (unsigned int x)
// 返回前导的0的个数。
int __builtin_ctz (unsigned int x)
// 返回后面的0个个数，和__builtiin_clz相对。
int __builtin_popcount (unsigned int x)
// 返回二进制表示中1的个数。
int __builtin_parity (unsigned int x)
// 返回x的奇偶校验位，也就是x的1的个数模2的结果。
```

## Rope

可持久化平衡树

```c++
#include <ext/rope>
using namespace __gnu_cxx;
// size()/length() 返回 x 的大小
// push_back(x) 在末尾添加 x
// append(s) 在结尾插入 s
// insert(pos, s) 在 pos 位置插入 s
// erase(pos, num) 从 pos 开始删除 num 个元素
// replace(pos, s) 将位置为 pos 的元素换成 s
// copy(pos, len, s) 从 pos 开始 len 个字符提取到 s
// substr(pow, len) 提取 pos 开始的 len 个元素
// at(x)/[x] 访问第 x 个元素
rope<int> *f[maxn];
// 可持久化
f[i] = new rope<int>(*f[i-1]);
```

## pb_ds

见 saffah PPT

## Bitset

==, !=, [], &=, |=, ^=, ~, <<=, >>=, <<, >> &, |, ^

test(), all(), any(), none(), count(), size(), set(), reset(), flips(), to_string(), to_ulong(), to_ullong()

## DLX

```c++
// LA2659 Sudoku
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxr = 5000;
const int maxn = 2000;
const int maxnode = 20000;

// 行编号从1开始，列编号为1~n，结点0是表头结点; 结点1~n是各列顶部的虚拟结点
struct DLX {
  int n, sz; // 列数，结点总数
  int S[maxn]; // 各列结点数

  int row[maxnode], col[maxnode]; // 各结点行列编号
  int L[maxnode], R[maxnode], U[maxnode], D[maxnode]; // 十字链表

  int ansd, ans[maxr]; // 解

  void init(int n) { // n是列数
  this->n = n;

  // 虚拟结点
  for(int i = 0 ; i <= n; i++) {
    U[i] = i; D[i] = i; L[i] = i-1, R[i] = i+1;
  }
  R[n] = 0; L[0] = n;

  sz = n + 1;
  memset(S, 0, sizeof(S));
  }

  void addRow(int r, vector<int> columns) {
  int first = sz;
  for(int i = 0; i < columns.size(); i++) {
    int c = columns[i];
    L[sz] = sz - 1; R[sz] = sz + 1; D[sz] = c; U[sz] = U[c];
    D[U[c]] = sz; U[c] = sz;
    row[sz] = r; col[sz] = c;
    S[c]++; sz++;
  }
  R[sz - 1] = first; L[first] = sz - 1;
  }

  // 顺着链表A，遍历除s外的其他元素
  #define FOR(i,A,s) for(int i = A[s]; i != s; i = A[i])

  void remove(int c) {
  L[R[c]] = L[c];
  R[L[c]] = R[c];
  FOR(i,D,c)
    FOR(j,R,i) { U[D[j]] = U[j]; D[U[j]] = D[j]; --S[col[j]]; }
  }

  void restore(int c) {
  FOR(i,U,c)
    FOR(j,L,i) { ++S[col[j]]; U[D[j]] = j; D[U[j]] = j; }
  L[R[c]] = c;
  R[L[c]] = c;
  }

  // d为递归深度
  bool dfs(int d) {
  if (R[0] == 0) { // 找到解
    ansd = d; // 记录解的长度
    return true;
  }

  // 找S最小的列c
  int c = R[0]; // 第一个未删除的列
  FOR(i,R,0) if(S[i] < S[c]) c = i;

  remove(c); // 删除第c列
  FOR(i,D,c) { // 用结点i所在行覆盖第c列
    ans[d] = row[i];
    FOR(j,R,i) remove(col[j]); // 删除结点i所在行能覆盖的所有其他列
    if(dfs(d+1)) return true;
    FOR(j,L,i) restore(col[j]); // 恢复结点i所在行能覆盖的所有其他列
  }
  restore(c); // 恢复第c列

  return false;
  }

  bool solve(vector<int>& v) {
  v.clear();
  if(!dfs(0)) return false;
  for(int i = 0; i < ansd; i++) v.push_back(ans[i]);
  return true;
  }

};

////////////// 题目相关
#include<cassert>

DLX solver;

const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;

// 行/列的统一编解码函数。从1开始编号
int encode(int a, int b, int c) {
  return a*256+b*16+c+1;
}

void decode(int code, int& a, int& b, int& c) {
  code--;
  c = code%16; code /= 16;
  b = code%16; code /= 16;
  a = code;
}

char puzzle[16][20];

bool read() {
  for(int i = 0; i < 16; i++)
  if(scanf("%s", puzzle[i]) != 1) return false;
  return true;
}

int main() {
  int kase = 0;
  while(read()) {
  if(++kase != 1) printf("\n");
  solver.init(1024);
  for(int r = 0; r < 16; r++)
    for(int c = 0; c < 16; c++)
    for(int v = 0; v < 16; v++)
      if(puzzle[r][c] == '-' || puzzle[r][c] == 'A'+v) {
      vector<int> columns;
      columns.push_back(encode(SLOT, r, c));
      columns.push_back(encode(ROW, r, v));
      columns.push_back(encode(COL, c, v));
      columns.push_back(encode(SUB, (r/4)*4+c/4, v));
      solver.addRow(encode(r, c, v), columns);
      }

  vector<int> ans;
  assert(solver.solve(ans));

  for(int i = 0; i < ans.size(); i++) {
    int r, c, v;
    decode(ans[i], r, c, v);
    puzzle[r][c] = 'A'+v;
  }
  for(int i = 0; i < 16; i++)
    printf("%s\n", puzzle[i]);
  }
  return 0;
}
```


## $\alpha-\beta$ 剪枝 ##
```c++
// LA4451 House of Cards
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int UP = 0;
const int FLOOR = 1;
const int DOWN = 2;

const int maxn = 20;
int n, deck[maxn*2];

struct State {
  int card[8], type[8]; // 两张相同的FLOOR牌代表一张真实的FLOOR牌
  int hold[2];
  int pos;
  int score; // MAX游戏者(即Axel)的得分

  State child() const {
  State s;
  memcpy(&s, this, sizeof(s));
  s.pos = pos + 1;
  return s;
  }

  State() {
  for(int i = 0; i < 8; i++) {
    card[i] = deck[i];
    type[i] = i % 2 == 0 ? UP : DOWN;
  }
  hold[0] = hold[1] = score = 0;
  pos = 8;
  }

  bool isFinal() {
  if(pos == 2*n) {
    score += hold[0] + hold[1];
    hold[0] = hold[1] = 0;
    return true;
  }
  return false;
  }

  int getScore(int c1, int c2, int c3) const {
  int S = abs(c1) + abs(c2) + abs(c3);
  int cnt = 0;
  if(c1 > 0) cnt++; if(c2 > 0) cnt++; if(c3 > 0) cnt++;
  return cnt >= 2 ? S : -S;
  }

  void expand(int player, vector<State>& ret) const {
  int cur = deck[pos];

  // 决策1：拿在手里
  if(hold[player] == 0) {
    State s = child();
    s.hold[player] = cur;
    ret.push_back(s);
  }

  // 决策2：摆楼面牌
  for(int i = 0; i < 7; i++) if(type[i] == DOWN && type[i+1] == UP) {
    // 用当前的牌
    State s = child();
    s.score += getScore(card[i], card[i+1], cur);
    s.type[i] = s.type[i+1] = FLOOR;
    s.card[i] = s.card[i+1] = cur;
    ret.push_back(s);

    if(hold[player] != 0) {
    // 用手里的牌
    State s = child();
    s.score += getScore(card[i], card[i+1], hold[player]);
    s.type[i] = s.type[i+1] = FLOOR;
    s.card[i] = s.card[i+1] = hold[player];
    s.hold[player] = cur;
    ret.push_back(s);
    }
  }

  // 决策3：新的山峰
  if(hold[player] != 0)
    for(int i = 0; i < 7; i++) if(type[i] == FLOOR && type[i+1] == FLOOR && card[i] == card[i+1]) {
    State s = child();
    s.score += getScore(card[i], hold[player], cur);
    s.type[i] = UP; s.type[i+1] = DOWN;
    s.card[i] = cur; s.card[i+1] = hold[player]; s.hold[player] = 0;
    ret.push_back(s);

    swap(s.card[i], s.card[i+1]);
    ret.push_back(s);
    }
  }
};

// 带alpha-beta剪枝的对抗搜索
int alphabeta(State& s, int player, int alpha, int beta) {
  if(s.isFinal()) return s.score; // 终态

  vector<State> children;
  s.expand(player, children); // 扩展子结点

  int n = children.size();
  for(int i = 0; i < n; i++) {
  int v = alphabeta(children[i], player^1, alpha, beta);
  if(!player) alpha = max(alpha, v); else beta = min(beta, v);
  if(beta <= alpha) break; // alpha-beta剪枝
  }
  return !player ? alpha : beta;
}

const int INF = 1000000000;

int main() {
  int kase = 0;
  char P[10];
  while(scanf("%s", P) == 1 && P[0] != 'E') {
  scanf("%d", &n);
  for(int i = 0; i < n*2; i++) {
    char ch;
    scanf("%d%c", &deck[i], &ch);
    if(ch == 'B') deck[i] = -deck[i];
  }
  State initial;
  int first_player = deck[0] > 0 ? 0 : 1;
  int score = alphabeta(initial, first_player, -INF, INF);

  if(P[0] == 'B') score = -score;
  printf("Case %d: ", ++kase);
  if(score == 0) printf("Axel and Birgit tie\n");
  else if(score > 0) printf("%s wins %d\n", P, score);
  else printf("%s loses %d\n", P, -score);
  }
  return 0;
}
```

