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

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	

	return 0;
}