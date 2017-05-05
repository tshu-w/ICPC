// written at 14:25 on 03 May 2017
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

void parse_address(const string &s, string &user, string &mta) {
    int k = s.find("@");
    user = s.substr(0, k);
    mta = s.substr(k + 1);
}

int main(void) {
    string s, t, mta1, user1, mta2, user2;
    set<string> addr;
    int n;
    while (cin >> s && s != "*") {
        cin >> s >> n;
        while (n--) { cin >> t; addr.insert(t + "@" + s); }
    }

    while (cin >> s && s != "*") {
        parse_address(s, user1, mta1);

        set<string> vis;
        map<string, vector<string> > dest;
        vector<string> mta;
        while (cin >> t && t != "*") {
            parse_address(t, user2, mta2);
            if (vis.count(t)) continue;
            vis.insert(t);
            if (!dest.count(mta2)) { mta.push_back(mta2); dest[mta2] = vector<string>();}
            dest[mta2].push_back(user2);
        }
        getline(cin, t);

        string data;
        while (getline(cin, t) && t != "*") data += "     " + t + "\n";

        for (int i = 0; i < (int)mta.size(); i++) {
            mta2 = mta[i];
            vector<string> users = dest[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 << endl;
            cout << "     HELO " << mta1 << endl;
            cout << "     250" << endl;
            cout << "     MAIL FROM:<" << s << ">" << endl;
            cout << "     250" << endl;
            bool flag = false;
            for (int i = 0; i < (int)users.size(); i++) {
                t = users[i] + "@" + mta2;
                cout << "     RCPT TO:<" << t << ">" << endl;
                if (addr.count(t)) { flag = true; cout << "     250" << endl;}
                else cout << "     550" << endl;
            }
            if (flag) {
                cout << "     DATA" << endl;
                cout << "     354" << endl;
                cout << data;
                cout << "     ." << endl;
                cout << "     250" << endl;
            }
            cout << "     QUIT" << endl;
            cout << "     221" << endl;
        }
    }
    return 0;
}
