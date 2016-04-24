#include "stdio.h"

int main(int argc, char const *argv[])
{
	int a, b, c, cost, n, rem, v;
	while (~scanf("%d%d%d%d", &n, &a, &b, &c)) {
		rem = 0;
		cost = 0;
		while (n--) {
			scanf("%d", &v);
			rem += v;
			if (rem >= a) {
				if (rem < b) cost += 2;
				else 
					if (rem < c) cost += 3;
					else cost += 4;
				rem = 0;
			}
		}
		printf("%d\n", cost);
	}
	return 0;
}