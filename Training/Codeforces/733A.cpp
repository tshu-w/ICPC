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

string s;
int ans = 0;

int main(int argc, char const *argv[])
{
	cin >> s;
	int last = -1, cur;
	for(;;) {
		cur = last + 1;
		while (cur < s.size() && (s[cur] != 'A' && s[cur] != 'E' && s[cur] != 'I' && s[cur] != 'O' && s[cur] != 'U' && s[cur] != 'Y'))
			++cur;
		// cout << last << " " << cur << endl;
		ans = max(ans, cur - last);
		if (cur == s.size()) break;
		last = cur;
	}
	cout << ans << endl;
	return 0;
}