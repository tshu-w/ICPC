#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, A[] = {8, 10, 4, 3, 1, 6, 5, 9, 2, 7}, B[10000], cnt[10000];
void merge_sort(int l, int r) {
	if (l >= r) return ;
	int mid = (r - l) / 2 + l;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);

	int i, j, k;
	i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (A[i] > A[j]) {
			B[k] = A[i];
			cnt[A[i]] += r - j + 1;
			++i;
		} else {
			B[k] = A[j];
			++j;
		}
		++k;
	}
	while (i <= mid) {
		B[k] = A[i++];
		++k;
	}
	while (j <= r) {
		B[k] = A[j++];
		++j;
	}
	for (int i = l; i <= r; ++i)
		A[i] = B[i];
	return ;
}
int main(int argc, char const *argv[])
{
	n = 10;
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	};
	printf("\n");

	merge_sort(0, n - 1);
	
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	};
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	};
	printf("\n");
	printf("\n");

	return 0;
}