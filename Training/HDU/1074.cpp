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
const int MAX_N = 20;

template <typename T>
inline T sqr(T a) { return a * a;};

struct subject
{
	string name;
	int deadline, cost;	
};

int t, N, dp[1 << MAX_N], sum[1 << MAX_N], pre[1 << MAX_N];
subject A[MAX_N];

void sub_pnt(int k) {
	if (pre[k] == -1) return;
	sub_pnt(k - (1 << pre[k]));
	cout << A[pre[k]].name << endl;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			cin >> A[i].name >> A[i].deadline >> A[i].cost;
		memset(sum, 0, sizeof sum);
		sum[0] = 0;
		for (int i = 1; i < 1 << N; ++i)
			for (int j = 0; j < N; ++j)
				if (i >> j & 1)
					sum[i] += A[j].cost;
		memset(dp, -1, sizeof dp);
		dp[0] = 0; pre[0] = -1;
		for (int i = 1; i < 1 << N; ++i) {
			for (int j = 0; j < N; ++j)
				if (i >> j & 1) {
					int last = i - (1 << j);
					if (dp[i] == -1 || dp[i] >= dp[last] + max(sum[last] + A[j].cost - A[j].deadline, 0)) {
						dp[i] = dp[last] + max(sum[last] + A[j].cost - A[j].deadline, 0);
						pre[i] = j;
					}
				}
		}
		cout << dp[(1 << N) - 1] << endl;
		sub_pnt((1 << N) - 1);
	}	
	return 0;
}