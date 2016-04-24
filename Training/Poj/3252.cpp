/*
Unfinished
*/
#include <cstdio>
#include <cstring>
#include <cmath>

unsigned int com(unsigned int n) {
	unsigned int ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= (n + i) / i;
	return ans;
}
unsigned int count(unsigned int m) {
	// if (m == 1) return 1;
	// if (m == 2) return 1;
	unsigned int k, sum = 0, bin[20], odd = 0, num = 0;
	k = log(m)/log(2) + 1e-6;
	for (int i = 2; i <= k; ++i) {
		sum += 1 << (i - 2);
		if (i % 2) {
			sum -= com(i / 2) / 2;
		}
	}
	printf("%u\n", sum);
	int p = m;
	for (int i = 0; i <= k; ++i) {
		bin[i] = p % 2;
		p /= 2;
		printf("%u", bin[i]);
	}
	puts("");
	for (int i = k - 1; i >= 0; --i) {
		if (!num && !bin[i])
			continue;
		++num;
		odd += (bin[i])? (1 << i) : 0;
	}
	printf("%u\n", num);
	//sum += count(m);
	return sum;
}
int main(int argc, char const *argv[])
{
	unsigned int start, finish;
	scanf("%u", &start);
	printf("%u\n", count(start));
	// while(scanf("%u%u", &start, &finish)) {
	// 	printf("%u\n", count(finish) - count(start - 1));
	// }
	return 0;
}