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

int N, k, W[MAX_N], V[MAX_N];
pair<double, int> d[MAX_N];
vector<int> v;

bool C(double avg) {
	for (int i = 0; i < N; ++i)
		d[i] = make_pair(V[i] - W[i] * avg, i);
	sort(d, d + N);
	v.clear();
	double res = 0.;
	for (int i = 0; i < k; ++i) {
		v.push_back(d[N - i - 1].second);
		res += d[N - i - 1].first;
		if (res < 0.) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &k);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", V + i, W + i);
	double lb = 0, ub = INF;
	while(ub - lb > 1e-6) {
		double mid = (lb + ub) / 2;
		if (C(mid)) lb = mid;
		else ub = mid;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		printf("%d%c", v[i] + 1, i + 1 == v.size() ? '\n' : ' ');
	return 0;
}