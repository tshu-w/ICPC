//2 的幂次方
#include "stdio.h"
#include "math.h"

int find(int n) {
	int k = log(n)/log(2), j = pow(2, k);
	if (n == 0) {
	 	printf("0");
	 	return 0;
	}
	while (k >= 0) {
		if (n >= j) {
			if (j == 2) printf("2");
			else {
				printf("2(");
				find(k);
				printf(")");
			}
			n -= j;
			if (n > 0)
				printf("+");
		}
		k--;
		j = j / 2;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	find(n);
	return 0;
}