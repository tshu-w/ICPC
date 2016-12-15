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
const int MAX_N = 50000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], n;
ll sum1, sum2, res, cnt1[MAX_N], cnt2[MAX_N];

int bit[MAX_N];

int compress(int *a) {
    vector<int> v;
    for (int i = 0; i < N; ++i)
        v.push_back(a[i]);
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < N; ++i)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    
    return v.size() + 1;
}

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

void solve() {
    n = compress(A);
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    res = sum1 = sum2 = 0;
    
    memset(bit, 0, sizeof bit);
    for (int i = 0; i < N; ++i) {
        cnt1[i] += sum(A[i] - 1);
        cnt2[i] += i - sum(A[i]);
        add(A[i], 1);
    }

    reverse(A, A + N);

    memset(bit, 0, sizeof bit);
    for (int i = 0; i < N; ++i) {
        cnt1[N - i - 1] += i - sum(A[i]);
        cnt2[N - i - 1] += sum(A[i] - 1);
        add(A[i], 1);
    }

    for (int i = 0; i < N; ++i) {
    	sum1 += cnt1[i];
    	sum2 += cnt2[i];
  	}

  	sum1 /= 2; sum2 /= 2;
  	// cout << sum1 << endl;
  	// cout << sum2 << endl;

    for (int i = 0; i < N; ++i)
        res += cnt1[i] * cnt2[i];

    cout << sum1 * sum2 - res << endl;
    return ;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; ++i)
            scanf("%d", A + i);
        solve();
    }	
    return 0;
}