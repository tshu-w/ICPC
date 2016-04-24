#include "stdio.h"

#ifndef MAXN
#define MAXN 10010
#endif
void quicksort(int a[], int left, int right) {
	int i = left;
	int j = right;
	int temp = a[left];
	if (left >= right)
		return;
	while (i != j) {
		while (i < j && a[j] >= temp)
			j--;
		if (j > i) 
			a[i] = a[j];
		while ( i < j && a[i] <= temp)
			i++;
		if (i < j)
			a[j] = a[i];
	}
	a[i] = temp;
	quicksort(a, left, i - 1);
	quicksort(a, i+1, right);
}

int main(int argc, char const *argv[])
{
	int t, n, m, k, x[MAXN], p[MAXN];
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]);
		int sum = 0, max = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &p[i]);
 			if (k > x[ p[i] - 1 ]) {
 				k -= x[ p[i] - 1 ];
 				max++;
 				x[ p[i] - 1 ] = 0;
 			}
 			else k = 0;
		}
		quicksort(x, 0, n-1);
		for (int i = 0;k > 0 && i < n; i++)
			if ( k > x[i] ) {
				max++;
				k -= x[i];
			}
			else k = 0;
		if (max < m) 
			printf("%d\n", -1);
		else
			printf("%d\n", max - m);
	}
	return 0;
}