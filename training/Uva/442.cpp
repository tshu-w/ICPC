// written at 20:33 on 31 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

Pii matrix[30];
string s;
int n;

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char ch;
        scanf("%c", &ch);
        scanf("%d%d\n", &matrix[ch - 'A'].first, &matrix[ch - 'A'].second);
    }
    while (cin >> s) {
        stack<Pii> st;
        ll ans = 0;
        bool flag = true;
        for (auto ch : s) {
            if (ch == ')') {
                Pii p1 = st.top(), p2; st.pop();
                while (st.top().first != -1) {
                    p2 = st.top(); st.pop();
                    if (p2.second != p1.first) {
                        flag = false; break;
                    } else {
                        ans += 1ll * p2.first * p2.second * p1.second;
                        p2.second = p1.second;
                    }
                }
                st.pop();
                st.push(p2);
                if (!flag) break;
            } else {
                if (ch == '(') st.push(Pii(-1, -1));
                else st.push(matrix[ch - 'A']);
            }
        }
        if (flag) cout << ans << endl;
        else cout << "error\n";
    }
    return 0;
}
