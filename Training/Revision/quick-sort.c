#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quicksort(int * a, int l, int r) {
	int i = l, j = r, x = a[(l+r) / 2];
	while (i <= j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r) quicksort(a, i, r);
	if (l < j) quicksort(a, l, j);
	return 0;
}
int main(int argc, char const *argv[])
{
	int n, a[1000];
	
	n = 200;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (n * 10);

	quicksort(a, 0, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	

	return 0;
}