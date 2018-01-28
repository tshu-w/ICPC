// written at 18:35 on 20 Jan 2018
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
#include <bitset>
#include <numeric>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxm = 4000 + 10;
const int maxn = maxm * 200;

int n, m, k, id[maxn];
int lcp[maxn], sa[maxn];
int rnk [maxn], tmp[maxn];
int flag[maxn];
string s, t, ans;

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
        rnk[i] = i < n? S[i]: -1;
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

bool C(int k) {
    int res = 1, cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[sa[i]] != '#' && lcp[i] >= k) {
            if (flag[id[sa[i]]] != res) {
                cnt++;
                flag[id[sa[i]]] = res;
            }
            if (flag[id[sa[i+1]]] != res) {
                cnt++;
                flag[id[sa[i+1]]] = res;
            }
            if (cnt >= m) {
                ans = s.substr(sa[i], k);
                return true;
            }
        } else {
            cnt = 0;
            res++;
        }
    return false;
}

int main() {
    while (cin >> m && m) {
        s.clear();
        for (int i = 0; i < m; i++) {
            cin >> t;
            t = "#" + t;
            for (int j = 0; j < SZ(t); j++)
                id[s.length() + j] = i;
            s += t;
        }
        construct_sa(s, sa);
        construct_lcp(s, sa, lcp);
        n = s.length();
        int lb = 0, ub = n + 1;
        while (lb + 1 < ub) {
            int mid = (lb + ub) / 2;
            if (C(mid)) lb = mid;
            else ub = mid;
        }
        if (lb == 0) cout << "IDENTITY LOST\n";
        else cout << ans << "\n";
    }
    return 0;
}
