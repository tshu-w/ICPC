// written at 18:41 on 18 Apr 2017
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

int cnt[30];

class MakePalindrome
{
public:
    vector <string> constructMinimal(string card) {
        memset(cnt, 0, sizeof cnt);
        vector<string> v;
        for (int i = 0; i < (int)card.size(); i++)
            cnt[card[i] - 'a']++;
        while (true) {
            string s = "";
            bool flag = false;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] != 0) flag = true;
                if (cnt[i] % 2 == 1) {
                    s += i + 'a';
                    cnt[i]--;
                    break;
                }
            }
            for (int i = 0; i < 26; i++)
                if (cnt[i] >= 2) {
                    char c = i + 'a';
                    for (int j = 0; j < cnt[i] / 2; ++j)
                        s = c + s + c;
                    cnt[i] %= 2;
                }
            if (s.size())
                v.push_back(s);
            if (!flag) break;
        }
        return v;
    }
};

int main(int argc, char *argv[])
{
    MakePalindrome test;
    cout << test.constructMinimal("aaabbbccc").size() << endl;
    return 0;
}
