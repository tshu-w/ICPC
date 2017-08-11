// written at 09:50 on 24 May 2017
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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

vector<map<int, int> > arr;
vector<int> limit;
map<string, int> mp;

int cal(string s) {
    int pos = s.find('[');
    if (pos == (int)string::npos) return stoi(s);
    string ar = s.substr(0, pos);
    int it = cal(s.substr(pos + 1, s.size() - 1));
    if (it == -1 || arr[mp[ar]].count(it) == 0)
        return -1;
    else return arr[mp[ar]][it];
}

bool operate(string s) {
    int eq = s.find('=');
    if (eq == (int)string::npos) {
        int pos = s.find('[');
        string ar = s.substr(0, pos);
        mp[ar] = arr.size();
        arr.push_back(map<int, int>());
        limit.push_back(stoi(s.substr(pos + 1, s.size() - 1)));
    } else {
        string ls = s.substr(0, eq);
        int pos = s.find('[');
        string ar = s.substr(0, pos);
        int it = cal(ls.substr(pos + 1, s.size() - 1));
        if (it == -1 || limit[mp[ar]] <= it) return false;

        string rs = s.substr(eq + 1);
        int value = cal(rs);
        if (value == -1) return false;

        // cout << it << " " << value << endl;

        arr[mp[ar]][it] = value;
    }
    return true;
}

int main(void) {
    string line;
    while (getline(cin, line) && line != ".") {
        // init
        int ans = 0, cnt = 1;
        arr.clear(); limit.clear(); mp.clear();

        // work
        if (ans == 0 && !operate(line)) ans = cnt;
        while (getline(cin, line) && line != ".") {
            cnt++;
            if (ans == 0 && !operate(line)) ans = cnt;
        }
        cout << ans << endl;
    }
    return 0;
}
