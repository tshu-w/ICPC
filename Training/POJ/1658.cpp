#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
	int a[10], t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; ++i)
			scanf("%d", &a[i]);
		bool flag;
		if (a[0] - a[1] == a[1]- a[2] && a[1] - a[2] == a[2] - a[3])
			flag = true;
		else flag = false;
		if (flag) {
			a[4] = a[3] + a[3] - a[2];
		} else {
			a[4] = a[3] * a[3] / a[2];
		}
		for (int i = 0; i < 5; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}