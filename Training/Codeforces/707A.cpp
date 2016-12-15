#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
	#define DEBUG(...) printf(__VA_ARGS__)
#else
	#define DEBUG(...)
#endif	
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 100 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, M;
char s[5];
bool flag;

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int i = 0; i < M; ++i) {
			scanf("%s", s);
			if (s[0] != 'B' && s[0] != 'W' && s[0] != 'G')
				flag = true;
		}
	}
	if (flag) cout << "#Color" << endl;
	else cout << "#Black&White" << endl;
	return 0;
}