/*
ID: volekin1
PROG: ride
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
#define filename "ride"
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
const int MOD = 47;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);
	string comet, group;
	int a, b;
	cin >> comet >> group;
	a = b = 1;
	for (int i = 0; i < comet.size(); ++i)
		a = (a * (comet[i] - 'A' + 1)) % MOD;
	for (int i = 0; i < group.size(); ++i)
		b = (b * (group[i] - 'A' + 1)) % MOD;
	(a == b)? cout << "GO" : cout << "STAY";
	cout << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}