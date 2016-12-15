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


int main(int argc, char const *argv[])
{
	int n, h[MAX_N], imax, ans[MAX_N];
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &h[i]);
	ans[n - 1] = 0;imax = h[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (imax >= h[i])
			ans[i] = imax - h[i] + 1;
		else ans[i] = 0;
		imax = max(h[i], imax);
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}