#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1010;
int main(int argc, char const *argv[])
{
	int n, a[maxn], flag[maxn], cunt[maxn], ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	memset(flag, 0, sizeof(flag));
	memset(cunt, 0, sizeof(cunt));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			if (!flag[j] && a[i] > a[j] && cunt[j] + 1 > cunt[i]) {
				cunt[i] = cunt[j] + 1;
				flag[j] = 1;
				break;
			}
		//printf("%d ", cunt[i]);
	}
	//printf("\n");
	for (int i = n - 1; i >= 0; --i) {
		if (!flag[i])
			ans += cunt[i];
		//printf("%d ", flag[i]);
	}
	printf("%d\n", ans);
	return 0;
}