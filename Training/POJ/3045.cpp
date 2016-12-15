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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, sum, ans;
vector<pair<int, Pii> > v;

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0, w, s; i < N; ++i) {
		scanf("%d%d", &w, &s);
		v.push_back(make_pair(w + s, Pii(w, s)));
	}
	sort(v.begin(), v.end());
	ans = INT_MIN;
	for (int i = 0; i < N; ++i) {
		ans = max(sum - v[i].second.second, ans);
		sum += v[i].second.first;
	}
	printf("%d\n", ans);
	return 0;
}