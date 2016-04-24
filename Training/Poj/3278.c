/*
起点终点相同
0 100000
*/
#include <stdio.h>
#include <string.h>

const int maxn = 200010;
int main(int argc, char const *argv[])
{	
	int n, k, l[maxn][2], next;
	int vis[maxn];
	scanf("%d%d", &n, &k);
	memset(l, 0, sizeof(l));
	memset(vis, 0, sizeof(vis));
	l[0][0] = n;
	l[0][1] = 0;
	vis[n] = 1;
	int head = 0, tail = 1;
	while (head < tail) {
		//printf("%d\n", l[head][0]);
		next = l[head][0] + 1;
		if (next >= 0 && next < 100002 && !vis[next]) {
			l[tail][0] = next;
			l[tail][1] = l[head][1] + 1;
			vis[next] = 1;
			tail++;
		}
		next = l[head][0] - 1;
		if (next >= 0 && next < 100002 && !vis[next]) {
			l[tail][0] = next;
			l[tail][1] = l[head][1] + 1;
			vis[next] = 1;
			tail++;
		}
		next = l[head][0] * 2;
		if (next >= 0 && next < 100002 && !vis[next]) {
			l[tail][0] = next;
			l[tail][1] = l[head][1] + 1;
			vis[next] = 1;
			tail++;
		}
		if (vis[k]) {
			//printf("%d\n", tail);
			if (n != k)
				printf("%d\n", l[head][1] + 1);
			else
				printf("0\n");
			break;
		}
		head++;
	}
	return 0;
}