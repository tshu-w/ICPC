#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[30];
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int now = a[n - 1];
	ans += now;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == now) 
			a[i]--;
		now = a[i];
		if (now > 0) 
			ans += now;
	}
	printf("%lld\n", ans);
	return 0;
}