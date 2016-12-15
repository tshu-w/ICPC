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
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, n, a[MAX_N];

int solve(int n) {
    int dp[MAX_N];
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; ++i)
        *upper_bound(dp, dp + n, a[i]) = a[i];// lds: -a[i]
    // printf("%ld\n", lower_bound(dp, dp + n, INF) - dp);
    return (int)(lower_bound(dp, dp + n, INF) - dp);
}
int main(int argc, char const *argv[])
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		int in, de;
		in = solve(n);
		for (int i = 0; i < n; ++i)
			a[i] = -a[i];
		de = solve(n);
		// cout << in << " " << de << endl;
		if (in >= n - 1 || de >= n - 1) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}