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

int V, imin = INF;
Pii A[15];

int main(int argc, char const *argv[])
{
	cin >> V;
	for (int i = 0; i < 9; ++i) {
		cin >> A[i].first;
		A[i].second = (i + 1);
		imin = min(imin, A[i].first);
	}
	int len = V / imin;
	for (int i = 0; i < len; ++i) {
		for (int j = 8; j >= 0; --j)
			if (V >= A[j].first && (V - A[j].first) / imin == len - i - 1) {
				cout << A[j].second;
				V -= A[j].first;
				break;
			}
		// cout << len - i << " " << V << endl;
	}
	if (len == 0) cout << -1;
	cout << endl;
	return 0;
}