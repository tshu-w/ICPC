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
const double eps = 1e-6;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
	pair<double, double> p[4];
	int m, l, r;
	while (cin >> p[0].first >> p[0].second) {
		for (int i = 1; i < 4; ++i)
			cin >> p[i].first >> p[i].second;

        if(p[0] == p[3]) {  
            swap(p[0],p[1]);  
            swap(p[2],p[3]);  
        }  
        else if(p[0] == p[2])  
            swap(p[0],p[1]);  
        else if(p[1] == p[3])  
            swap(p[2],p[3]);  
        printf("%.3lf %.3lf\n", p[3].first - p[2].first + p[0].first, p[3].second - p[2].second + p[0].second);  
	}	
	return 0;
}