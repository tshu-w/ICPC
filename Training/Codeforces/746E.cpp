// written at 10:15 on 22 Feb 2017 
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
const int MAX_N = 2e5 + 10;

int N, M, A[MAX_N], cnt, ans[MAX_N];
set<int> odd, even;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	rep(i, 0, N) {
		scanf("%d", A + i);
		if (A[i] & 1) { 
			if (odd.size() < N / 2) odd.insert(A[i]);
		}
		else {
			if (even.size() < N / 2) even.insert(A[i]);
		}
	}
	N /= 2;
	cnt = 2 * N - odd.size() - even.size();
	for (int o = 1; o <= M && odd.size() < N; o += 2) 
		odd.insert(o);
	for (int e = 2; e <= M && even.size() < N; e += 2)
		even.insert(e);
	bool flag;
	if (odd.size() == N && even.size() == N) flag = true;
	else flag = false;
	printf("%d\n", flag? cnt : -1);
	if (flag) {
		rep (i, 0, 2 * N) {
			if (odd.find(A[i]) != odd.end()) {
				ans[i] = A[i];
				odd.erase(A[i]);
			}
			if (even.find(A[i]) != even.end()) {
				ans[i] = A[i];
				even.erase(A[i]);
			}		
		}
		rep(i, 0, 2 * N) if (!ans[i]) {
			if (odd.size()) {
				auto it = odd.begin();
				ans[i] = *it; odd.erase(it);
			} else if (even.size()) {
				auto it = even.begin();
				ans[i] = *it; even.erase(it);
			}
		}
		rep(i, 0, 2 * N) printf("%d%c", ans[i], " \n"[i + 1 == 2 * N]);
	}
	return 0;
}