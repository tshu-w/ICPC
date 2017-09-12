// written at 14:20 on 11 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

int t;
char s[200];

void solve() {
    stack<char> st;
    fgets(s, sizeof s, stdin);
    for (int i = 0; i < (int)strlen(s); i++)
        if (s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')' || s[i] == ']') {
            if (st.size() == 0 || (s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[')) {
                puts("No");
                return;
            }
            st.pop();
        }
    if (st.size()) puts("No"); else puts("Yes");
}

int main() {
    scanf("%d\n", &t);
    while (t--) {
        solve();
    }
    return 0;
}
