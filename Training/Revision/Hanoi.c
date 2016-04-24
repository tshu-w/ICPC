#include "stdio.h"

int move(int n, char x, char y, char z) {
	if (!n) return 0;
	move(n - 1, x, z, y);
	printf("%c -> %c\n", x, z);
	move(n - 1, y, x, z);
	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	char x, y, z;
	scanf("%d", &n);
	x = 'a';	y = 'b';	z = 'c';
	move(n, x, y, z);
	return 0;
}