// written at 09:05 on 24 May 2017
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

typedef pair<string, string> book;
set<book> library;
set<book> unorder;
map<string, string> mp;

int main(void) {
    string line;
    while (getline(cin, line) && line != "END") {
        int pos = line.find("by");
        string author, title;
        author = line.substr(pos + 3);
        title = line.substr(0, pos - 1);
        library.insert(book(author, title));
        mp[title] = author;
    }
    while (getline(cin, line) && line != "END") {
        if (line[0] == 'B') {
            string author, title;
            title = line.substr(7);
            author = mp[title];
            // cout << name << " " << author << endl;
            library.erase(book(author, title));
        }
        if (line[0] == 'R') {
            string author, title;
            title = line.substr(7);
            author = mp[title];
            unorder.insert(book(author, title));
            // cout << name << " " << author << endl;
        }
        if (line[0] == 'S') {
            while (unorder.size()) {
                book b = *unorder.begin();
                library.insert(b);
                auto it = library.find(b);
                unorder.erase(b);
                if (it == library.begin()) {
                    cout << "Put " << b.second << " first" << endl;
                } else {
                    cout << "Put " << b.second << " after " << (--it)->second << endl;
                }
            }
            cout << "END" << endl;
        }
    }
    return 0;
}
