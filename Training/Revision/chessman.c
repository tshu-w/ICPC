#include <stdio.h>
#include <string.h>

const char chess[] = {'-', 'o', '*'};
int n, c[100];
void prtf(int step) {
	printf("Step %d: ", step);
	for (int i = 0; i < 2 * n + 2; i++)
		putchar(chess[c[i]]);
	puts("");
	return ;
}
void swap(int a, int b) {
	int temp = c[a];
	c[a] = c[b];
	c[b] = temp;
	return ;
}
int move(int k, int step) {
	if (k == 1) {
		swap(2 * k, k - 1);
		swap(2 * k + 1, k);
		prtf(step++);
		return 0;
	}
	if (k == 2) {
		swap(2 * k, k - 1);
		swap(2 * k + 1, k);
		prtf(step++);
		swap(0, 2);
		prtf(step++);
		return 0;
	}
	swap(2 * k, k - 1);
	swap(2 * k + 1, k);
	prtf(step++);
	swap(2 * k - 2, k - 1);
	swap(2 * k - 1, k);
	prtf(step++);
	if (k - 1)
		move(k - 1, step);
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		c[i] = 1;
	for (int i = n; i < 2 * n; i++)
		c[i] = 2;
	c[2 * n] = c[2 * n + 1] = 0;
	prtf(0);
	move(n, 1);	
	return 0;
}