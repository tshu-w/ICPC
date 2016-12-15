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
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
	int n, a, ans = 0, mark[MAX_N];
	memset(mark, 0, sizeof mark);
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> a, ++mark[a];
	bool flag;
	do {
		flag = false;
		for (int i = 1; i < MAX_N; ++i)
			if (mark[i]) {
				if (flag) 
					++ans;
				--mark[i];
				flag = true;
			}
	} while (flag);
	cout << ans << endl;
	return 0;
}