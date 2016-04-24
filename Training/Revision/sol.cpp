//士兵站队
#include "cstdio"
#include "algorithm"
#include "cstdlib"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, x[10010], y[10010], mid, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i], &y[i]);

	sort(x, x+n);
	mid = x[n / 2];
	for (int i = 0; i < n; i++)
		ans += abs(x[i] - mid);
	sort(y, y+n);
	for (int i = 0; i < n; i++)
		y[i] -= i; 
	sort(y, y+n);
	mid =  y[n /2];
	for (int i = 0; i < n; i++)
		ans += abs(y[i] - mid);

	printf("%d\n", ans);
	return 0;
}