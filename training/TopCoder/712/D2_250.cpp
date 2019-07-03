// written at 18:40 on 18 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

class RepeatNumberCompare
{
public:
    string compare(int x1, int k1, int x2, int k2) {
        string s1 = to_string(x1);
        string s2 = to_string(x2);
        string ss1 = "", ss2 = "";
        for (int i = 0; i < k1; i++)
            ss1 += s1;
        for (int i = 0; i < k2; i++)
            ss2 += s2;
        if (ss1.length() == ss2.length())
            if (ss1 < ss2) return "Less";
            else if (ss1 == ss2) return "Equal";
            else return "Greater";
        else if (ss1.length() < ss2.length()) return "Less";
        else if (ss1.length() > ss2.length()) return "Greater";
        return "Wrong";
    }
};


int main(int argc, char *argv[])
{
    RepeatNumberCompare test;
    cout << test.compare(12, 4, 1212, 2) << endl;
    return 0;
}
