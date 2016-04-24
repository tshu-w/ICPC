#include "stdio.h"
#include "string.h"

#ifndef MAXN
#define MAXN 100000005
#endif
int main(int argc, char const *argv[])
{
	int t, n, arr[10000], narr = 0;
	memset(arr, 0, sizeof(arr));
	scanf("%d", &t);
	for (int i = 2; i * i < MAXN; i++) {
		int flag = 1;
		for(int j = 0; flag && j < narr; j++)
			if ( !(i % arr[j])) flag = 0;
		if (flag) arr[narr++] = i;
	}
	while(t--) {
		scanf("%d", &n);
		int i;
		for (i = 0; i < narr; i++)
			if (arr[i] * arr[i] > n) break;
		if (i == 0 || arr[i] * arr[i] - n < n - arr[i-1] * arr[i-1]) 
			printf("%d\n", arr[i] * arr[i]);
		else 
			printf("%d\n", arr[i-1]*arr[i-1]);
	}
	return 0;
}