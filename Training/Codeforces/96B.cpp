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
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;

int generate(int k) {
	int res = 0;
	for (int i = 0; i < k; ++i)
		if (i < (k + 1) / 2)
			res = res * 10 + 7;
		else 
			res = res * 10 + 4;
	return res;
}

int main(int argc, char const *argv[])
{
	cin >> N;
	int k = log(N) / log(10) + 1;
	if (k & 1 || N > generate(k)) {
		if (!(k & 1)) k += 2;
		for (int i = 0; i < (k + 1) / 2; ++i)
			cout << 4;
		for (int i = 0; i < (k + 1) / 2; ++i)
			cout << 7;
		cout << endl;
	}
	else {
		int ans = generate(k), res, cnt;
		for (int i = 0; i < (1 << k); ++i) {
			res = cnt = 0;
			for (int j = 0; j < k; ++j)
				if (i >> j & 1) res = res * 10 + 4, ++cnt;
				else res = res * 10 + 7;
			if (res >= N && cnt * 2 == k) ans = min(res, ans);
		}
		cout << ans << endl;
	}
	return 0;
}