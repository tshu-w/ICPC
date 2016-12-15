#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
	int n, a[MAX_N];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j + 1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				cout << j + 1 << " " << j + 2 << endl;
			}
	return 0;
}