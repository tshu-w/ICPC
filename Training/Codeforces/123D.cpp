// written at 19:27 on 18 Mar 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

string S;
int n, k;
int lcp[MAX_N], sa[MAX_N];
int rnk[MAX_N], tmp[MAX_N];

bool compare_sa(int i, int j) {
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    else {
        int ri = i + k <= n? rnk[i + k] : -1;
        int rj = j + k <= n? rnk[j + k] : -1;
        return ri < rj;
    }
}
void construct_sa(string S, int *sa) {
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
void construct_lcp(string S, int *sa, int *lcp) {
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

inline ll cnt(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    cin >> S;
    construct_sa(S, sa);
    construct_lcp(S, sa, lcp);
    for (int i = 0; i <= n + 1; i++) 
        cout << S.substr(sa[i]) << endl;
    for (int i = 0; i <= n + 1; i++)
        cout << sa[i] << " ";
    cout << endl;
    for (int i = 0; i <= n + 1; i++) 
        cout << lcp[i] << " ";
    cout << endl;
    vector<pair<Pii, int> > v; // height, len, id;
    ll ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (!v.empty() && v.back().first.second > lcp[i - 1]) {
            auto &end = v.back();
            if (end.first.first < lcp[i - 1]) {
                ans += (end.first.second - lcp[i - 1]) * cnt(i - end.second);
                end.first.second = lcp[i - 1];
            } else {
                ans += (end.first.second - end.first.first) * cnt(i - end.second);
                v.pop_back();
            }
        } 
        v.push_back({{lcp[i - 1], n - sa[i]}, i});
    }
    cout << ans << endl;
    return 0;
}