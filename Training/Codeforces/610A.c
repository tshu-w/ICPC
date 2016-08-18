#include "stdio.h"

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	if (n % 2) printf("%d\n", 0);
	else 
		printf("%d\n",(n / 2 - 1) / 2);
	return 0;
}