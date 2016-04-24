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
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	

	return 0;
}