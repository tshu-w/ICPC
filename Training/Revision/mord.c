#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int b, p, k, bin[35], len_bin, rest, temp;
	scanf("%d%d%d", &b, &p, &k);
	len_bin = log(p)/log(2);
	for(int i = 0; i <= len_bin; i++) {
		bin[len_bin - i - 1] = p % 2; 
		p /= 2;
	}
	rest = 1;
	for (int i = 0; i <= len_bin; i++) {
		temp = rest * rest % k;
		if (bin[i]) 
			rest = b % k * temp % k;
		else
			rest = temp; 
	}
	printf("%d\n", rest);
	return 0;
}