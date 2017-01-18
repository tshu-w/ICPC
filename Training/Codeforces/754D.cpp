// written at 20:25 on 17 Jan 2017 
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
const int MAX_N = 3e5 + 10;

struct Tri
{
	int f, s, id;
};
int N, K, ans, L, R;
Tri A[MAX_N];
set<Pii> s;
vector<int> v;

bool cmp(const Tri a, const Tri b) {
	return a.f < b.f || (a.f == b.f && a.s > b.s);
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &K);
	rep(i, 0, N)
		scanf("%d%d", &A[i].f, &A[i].s), A[i].id = i;
	sort(A, A + N, cmp);
	rep(i, 0, K - 1) s.insert(Pii(A[i].s, i));
	rep(i, K - 1, N) {
		s.insert(Pii(A[i].s, i));
		while (s.size() > K) s.erase(s.begin());
		int l = A[i].f;
		int r = s.begin()->first;
		if (r - l + 1 > ans) {
			ans = r - l + 1;
			L = l, R = r;
		}
	}
	printf("%d\n", ans);
	if (ans) {
		rep(i, 0, N) if (A[i].f <= L && A[i].s >= R) v.push_back(A[i].id + 1);
		rep(i, 0, K) printf("%d%c", v[i], i + 1 == K? '\n' : ' ');
	} else 
		rep(i, 0, K) printf("%d%c", i + 1, i + 1 == K? '\n' : ' ');
	return 0;
}