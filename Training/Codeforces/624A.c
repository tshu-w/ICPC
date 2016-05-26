#include <stdio.h>

int main(int argc, char const *argv[])
{
	int d, l, v1, v2;
	scanf("%d%d%d%d", &d, &l, &v1, &v2);
 	double t;
 	t = (double)(l - d) / (double)(v1 + v2);
 	printf("%lf\n", t);
 	return 0;
}