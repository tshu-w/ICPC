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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M, num = 0, X[MAX_N], Y[MAX_N];
char s[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> s[i];
		for (int j = 0; j < M; ++j)
			if (s[i][j] == '*') {
				++num; ++X[i]; ++Y[j];
			}
	}	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (num + ((s[i][j] == '*')? 1 : 0) == X[i] + Y[j]) {
				cout << "YES" << endl;
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}