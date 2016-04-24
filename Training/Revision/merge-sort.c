#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, a[10000], b[10000];
int merge_sort(int l, int r) {
	if (l == r) 
		return 0;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i, j, k;
	i = l; j = mid + 1; k = l;
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			b[k] = a[i++];
		}
		else {
			b[k] = a[j++];
		}
		k++;
	}
	while (i <= mid) {
		b[k] = a[i++];
		k++;
	}
	while (j <= r) {
		b[k] = a[j++];
		k++;
	}
	for (int i = l; i <= r; i++)
		a[i] = b[i];
	return 0;
}
int main(int argc, char const *argv[])
{
	n = 200;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (n * 10);

	merge_sort(0, n - 1);
	
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	};
	printf("\n");

	return 0;
}