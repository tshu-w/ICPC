// 统计数字
#include "cstdio"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[200020];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int now = a[0], num = 0;
	for (int i = 0; i < n; i++) {
		if (now == a[i]) num++;
		else {
			printf("%d %d\n", now, num);
			num = 1;
			now = a[i];
		}
	}
	printf("%d %d\n", now, num);
	return 0;
}