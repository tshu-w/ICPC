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
const int MAX_N = 70000;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, x;
ll res = 0;
vector<int> A;

ll merge_count(vector<int> &a) {
	int n = a.size();
	if (n <= 1) return 0;
	ll cnt = 0;
	vector<int> b(a.begin(), a.begin() + n / 2);
	vector<int> c(a.begin() + n / 2, a.end());

	cnt += merge_count(b);
	cnt += merge_count(c);

	int ai = 0, bi = 0, ci = 0;
	while (ai < n) {
		if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
			a[ai++] = b[bi++];
		} else {
			cnt += n / 2 - bi;
			a[ai++] = c[ci++];
		}
	}
	return cnt;
}
int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf("%d", &x), A.push_back(x);
	cout << merge_count(A) << endl;
	return 0;
}