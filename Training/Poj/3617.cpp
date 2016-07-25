#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_N = 2000 + 10;

int N;
char s[MAX_N];

void solve() {
	int a = 0, b = N - 1;
	while (a <= b) {
		bool left = false;
		for (int i = 0; a + i <= b; ++i) {
			if (s[a + i] < s[b - i]) {
				left = true;
				break;
			} else {
				left = false;
				break;
			}
		}
		if (left) putchar(s[a++]);
		else putchar(s[b--]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
		do s[i] = getchar(); while (s[i] == ' ' || s[i]  == '\n');
	solve();
	return 0;
}