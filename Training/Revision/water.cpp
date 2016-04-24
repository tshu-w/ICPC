#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, r, tm[10010], tape[100], ans = 0;
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &tm[i]);
	memset(tape, 0, sizeof(tape));

	sort(tm, tm + n);

	for (int i = 0; i < n; i++) {
		tape[i % r] += tm[i];
		ans += tape[i % r];
	}

	printf("%d\n", ans);
	return 0;
}