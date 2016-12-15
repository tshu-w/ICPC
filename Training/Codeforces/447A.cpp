#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 300;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int n, p, h[MAX_N], x;
	scanf("%d%d", &p, &n);
	fill(h, h + p, 0);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		if (h[x % p]) {
			printf("%d\n", i);
			return 0;
		} else h[x % p] = 1;
	}
	printf("-1\n");
	return 0;
}