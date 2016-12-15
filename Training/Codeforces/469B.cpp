#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

const double PI = acos(-1.0);

int main(int argc, char const *argv[])
{
	int p, q, l, r, a[55], b[55], c[55], d[55], ans = 0;
	bool flag[MAX_N];
	fill(flag, flag + MAX_N, false);
	scanf("%d%d%d%d", &p, &q, &l, &r);
	for (int i = 0; i < p; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		for (int j = a[i]; j <= b[i]; ++j)
			flag[j] = true;
	}
	for (int i = 0; i < q; ++i)
		scanf("%d%d", &c[i], &d[i]);
	for (int i = l; i <= r; ++i) {
		int flg = false;
		for (int j = 0; j < q && !flg; ++j)
			for (int k = c[j] + i; k <= 1000 && k <= d[j] + i; ++k)
				if (flag[k]) {
					flg = true;
					break;
				}
		if (flg) ans++;
	}
	printf("%d\n", ans);
	return 0;
}