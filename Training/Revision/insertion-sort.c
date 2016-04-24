#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int n, a[1000];
	
	n = 20;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (n * 10);

	for (int i = 1; i < n; i++) {
		int tmp = a[i], j;
		for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
			a[j+1] = a[j];
		}
		a[++j] = tmp;
 	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}