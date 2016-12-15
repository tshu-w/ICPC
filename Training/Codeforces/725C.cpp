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

string s;
char gid[2][27];
int cnt[27], dis, l, r;
char ch;

int main(int argc, char const *argv[])
{
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (cnt[s[i] - 'A']) {
			l = cnt[s[i] - 'A'] - 1;
			r = i;
			ch = s[i];
		} else 
			cnt[s[i] - 'A'] = i + 1;
	}
	if (r - l == 1) {
		cout << "Impossible" << endl;
	} else {
		// cout << ch << endl;
		// cout << l << " " << r << endl;
		if (s.size() - r - 1 < l) {
			reverse(s.begin(), s.end());
			r = s.size() - r - 1;
			l = s.size() - l - 1;
			swap(r, l);
		}
		// cout << s << endl;
		// cout << s[r] << " " << s[l] << endl;

		int dis = r - l - 1;
		for (int i = 0; i <= dis / 2; ++i)
			gid[0][dis / 2 - i] = s[i + l];

		for (int i = dis / 2 + 1; i <= dis; ++i)
			gid[1][i - dis / 2 - 1] = s[i + l];

		for (int i = dis / 2 + 1; i <= 13 && l + dis / 2 - i >= 0; ++i)
			gid[0][i] = s[l + dis / 2 - i];
		int it = 26;
		for (int i = l + dis / 2 + 1; i < 13; ++i)
			gid[0][i] = s[it--];

		for (int i = 12; it > r; --i) 
			gid[1][i] = s[it--];

		// cout << gid[0] << endl;
		// cout << gid[1] << endl;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 13; ++j)
				if (gid[i][j])
					cout << gid[i][j];
				else cout << " ";
			cout << endl;
		}
	}
	return 0;
}