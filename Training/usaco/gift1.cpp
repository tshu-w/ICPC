/*
ID: volekin1
PROG: gift1
LANG: C++11
*/
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif	
#define filename "gift1"
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

int main(int argc, char const *argv[])
{
	freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);
	int n, tot, div;
	string mark[15], s;
	map<string, int> m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		m[s] = 0;
		mark[i] = s;
	}
	while (cin >> s) {
		cin >> tot >> div;
		if (div != 0) {
			m[s] -= (tot - tot % div);
		for (int i = 0; i < div; ++i)
			cin >> s, m[s] += tot / div;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << mark[i] << " " << m[mark[i]] << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}