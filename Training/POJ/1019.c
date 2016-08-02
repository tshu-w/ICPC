#include <stdio.h>
#include <string.h>
#include <math.h>

const unsigned int dit[] = { 0, 45, 9045, 1395495, 189414495, 2464813015};
const int st[] = { 			 0, 11,  192,    2893,     38894,     488895};
int t;
unsigned int n;
int find(unsigned int m) {
	int p;
	for (p = 4; p >= 0; p--)
		if (m >= dit[p]) {
			m -= dit[p];
			break;
		}
	if (m == 0)
		return 9;

	for (int i = st[p]; m > i; i += p + 1) {
		m -= i;
	}
	//printf("%u\n", m);
	int ln, i;
	for (i = 1; ; i++) {
		ln = log(i)/log(10) + 1e-6 + 1;
		if (ln < m)
			m -= ln;
		else {
			m = ln - m;
			break;
		}
		//printf("i = %d ln = %d m = % d\n", i, ln,  2890 - m);
	}
	//printf("i = %d ln = %d m = % d\n", i, ln, 2890 - m);
	while (m) { 
		i /= 10;
		m--;
	}
	return i % 10;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--) {
		scanf("%u", &n);
		printf("%d\n", find(n));
	}


	// for (int i = 189414490; i <= 189414495 + 5; i++) {
	// 	printf("%d ", find(i));
	// }

	// unsigned int ans = 0, i = 1, j = 1;
	// while (j < 10) {
	// 	ans += i;
	// 	j++;
	// 	i += 1;
	// }
	// printf("%u %u\n", ans, i + 1);

	// i++;
	// while (j < 100) {
	// 	ans += i;
	// 	j++;
	// 	i += 2;
	// }
	// printf("%u %u\n", ans, i + 1);

	// i++;
	// while (j < 1000) {
	// 	ans += i;
	// 	j++;
	// 	i += 3;
	// }
	// printf("%u %u\n", ans, i + 1);

	// i++;
	// while (j < 10000) {
	// 	ans += i;
	// 	j++;
	// 	i += 4;
	// }
	// printf("%u %u\n", ans, i + 1);

	// i++;
	// while (j < 100000) {
	// 	ans += i;
	// 	j++;
	// 	i += 5;
	// }
	// printf("%u %u\n", ans, i + 1);
	return 0;
}