// written at 19:52 on 9 Feb 2017 
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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
const string ss = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyz";
const string ss2 = "aabbcdefghij";
const string ss3 = "aabbccddeeaabb";
const string ss4 = "aabbccddee";
vector<string> v;
string s;

class BuildingStrings
{
public:
    vector <string> findAny(int K) {
        while (K >= 50 * 26) {
            v.push_back(ss);
            K -= 50 * 26;
        }
        while (K >= 12 * 10) {
            v.push_back(ss2);
            K -= 12 * 10;
        }
        while (K >= 5 * 14) {
            v.push_back(ss3);
            K -= 5 * 14;
        }
        if (K < 70 && K >= 50) {
            v.push_back(ss4);
            K -= 5 * 10;
        }
        if (K <= 50 && K) {
            s = "";
            rep(i, 0, K) s += 'a';
            v.push_back(s);
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    BuildingStrings b;
    b.findAny(50000);
    return 0;
}