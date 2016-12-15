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
const int MAX_N = 505;

template <typename T>
inline T sqr(T a) { return a * a;};

class GroupSRMDiv2
{
public:
	int FindGroups(vector <int> t) {
		int flag[MAX_N];
		memset(flag, 0, sizeof flag);
		for (int i = 0; i < t.size(); ++i)
			++flag[t[i]];
		int ans = 0;
		for (int i = 1; i < MAX_N; ++i)
			if (flag[i] % i == 0) 
				ans += flag[i] / i;
			else 
				return -1;
		return ans;
	}
};
int main(int argc, char const *argv[])
{
	
	return 0;
}