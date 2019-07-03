#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;
const int maxn = 3e5 + 10;

int n;
string s;
map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int tmp = 0;
        for (auto ch : s)
            if (ch == '(') tmp++; else tmp--;
        bool flag = false;
        if (tmp > 0) {
            tmp = 0;
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] == '(') tmp++; else tmp--;
                if (tmp < 0) flag = true;
            }
        } else {
            tmp = 0;
            for (int i = (int)s.size() - 1; i >= 0; i--) {
                if (s[i] == '(') tmp++; else tmp--;
                if (tmp > 0) flag = true;
            }
        }
        if (flag) continue;
        mp[tmp]++;
    }
    ll ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->first <= 0) ans += 1ll * it->second * mp[-it->first];
    // ans += 1ll * mp[0] * mp[0];
    cout << ans << endl;
    return 0;
}