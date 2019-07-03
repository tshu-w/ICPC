// written at 22:19 on 06 Oct 2017
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2500 + 10;

int n, m, q, hs;
map<pair<Pii, Pii>, ll> mp;
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

inline ll rd(int a, int b, int c, int d) {
    if (mp.find(make_pair(Pii(a, b), Pii(c, d))) != mp.end()) return mp[make_pair(Pii(a, b), Pii(c, d))];
    else return mp[make_pair(Pii(a, b), Pii(c, d))] = rand() << 15 | rand();
}

int main() {
    std::srand(std::time(0));
    scanf("%d%d%d", &n, &m, &q);
    int t, r1, r2, c1, c2;
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        if (t == 1) {
            add(r1, c1, r2, c2, rd(r1, c1, r2, c2));
        } else if (t == 2) {
            add(r1, c1, r2, c2, -rd(r1, c1, r2, c2));
        } else {
            if (get(r1, c1, r1, c1) == get(r2, c2, r2, c2)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
