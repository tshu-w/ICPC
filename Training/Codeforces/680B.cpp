#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	int n, a, t[MAX_N], ans = 0;
	cin >> n >> a;
	for (int i = 1; i <= n; ++i)
		cin >> t[i];
	if (t[a])
		++ans;
	// cout << ans << endl;
	int imin = min(a - 1, n - a), imax = max(a - 1, n - a);
	// cout << imin << " " << imax << endl;
	for (int i = 1; i <= imin; ++i)
		if (t[a - i] && t[a + i])
			ans += 2;
	// cout << ans << endl;
	for (int i = imin + 1; i <= imax; ++i)
		if (a + i > 0 && a + i <= n && t[a + i])
			++ans;
		else if (a - i > 0 && a - i <= n && t[a - i])
			++ans;
	cout << ans << endl;
	return 0;
}