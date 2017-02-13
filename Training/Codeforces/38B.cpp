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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;
const int dx[] = {1,  1, 2,  2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1,  2, -2,  1, -1};

template <typename T>
inline T sqr(T a) { return a * a;};

bool flag[10][10];
int r_x, r_y, k_x, k_y;


int main(int argc, char const *argv[])
{
	char ch;
	cin >> ch >> r_y;
	r_x = ch - 'a';
	--r_y;
	cin >> ch >> k_y;
	k_x = ch - 'a';
	--k_y;
	memset(flag, false, 0);
	flag[r_x][r_y] = flag[k_x][k_y] = true;
	for (int i = 0; i < 8; ++i) {
		flag[r_x][i] = flag[i][r_y] = true;
	}
	for (int i = 0; i < 8; ++i) {
		int xx, yy;
		xx = r_x + dx[i]; yy = r_y + dy[i];
		if (0 <= xx && xx < 8 && 0 <= yy && yy < 8)
			flag[xx][yy] = true;
		xx = k_x + dx[i]; yy = k_y + dy[i];
		if (0 <= xx && xx < 8 && 0 <= yy && yy < 8)
			flag[xx][yy] = true;
	}
	int ans = 0;	
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			if (!flag[i][j]) 
				++ans;
	cout << ans << endl;
	return 0;
}