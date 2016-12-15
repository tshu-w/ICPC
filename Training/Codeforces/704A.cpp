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
const int MAX_N = 300000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, q, x, t, cnt;
set<Pii> s;
set<int> A[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &t, &x);
		if (t == 1) {
			A[x].insert(++cnt);
			s.insert(Pii(cnt, x));	
		} else if (t == 2) {
			while (A[x].size()) {
				int p = *A[x].begin();
				s.erase(s.find(Pii(p, x)));
				A[x].erase(A[x].begin());		
			}
		} else {
			while (s.size()) {
				Pii p = *s.begin();
				if (p.first <= x) {
					s.erase(s.begin());
					A[p.second].erase(A[p.second].find(p.first));
				} else break;
			}	
		}
		printf("%lu\n", s.size());
	}
	return 0;
}