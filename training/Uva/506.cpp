// written at 09:43 on 10 Aug 2017
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

const int maxn = 1e4 + 10;

int cnt;
map<string, int> mp;
string name[maxn];

vector<int> depend[maxn], depended[maxn];
int status[maxn];
vector<int> installed;

int ID(const string &s) {
    if (mp.find(s) == mp.end()) {
        mp[s] = cnt;
        name[cnt++] = s;
    }
    return mp[s];
}

void install(int item, bool st) {
    if (!status[item]) {
        for (int i = 0; i < (int)depend[item].size(); i++)
            install(depend[item][i], false);
        cout << "   Installing " << name[item] << "\n";
        status[item] = st? 1 : 2;
        installed.push_back(item);
    }
}

bool needed(int item) {
    for (int i = 0; i < (int)depended[item].size(); i++)
        if (status[depended[item][i]]) return true;
    return false;
}

void remove(int item, bool st) {
    if ((status[item] == 2 || st) && !needed(item)) {
        cout << "   Removing " << name[item] << "\n";
        status[item] = 0;
        installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
        for (int i = 0; i < (int)depend[item].size(); i++)
            remove(depend[item][i], false);
    }
}

void lst() {
    for (int i = 0; i < (int)installed.size(); i++)
        cout << "   " << name[installed[i]] << "\n";
}

int main() {
    string line, cmd;
    memset(status, 0, sizeof status);
    while (getline(cin, line)) {
        cout << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if (cmd[0] == 'E') break;
        string item1, item2;
        if (cmd[0] == 'L') lst();
        else {
            ss >> item1;
            int i1 = ID(item1);
            if (cmd[0] == 'D') {
                while (ss >> item2) {
                    int i2 = ID(item2);
                    depend[i1].push_back(i2);
                    depended[i2].push_back(i1);
                }
            } else if (cmd[0] == 'I') {
                if(status[i1]) cout << "   " << item1 << " is already installed.\n";
                else install(i1, true);
            } else {
                if(!status[i1]) cout << "   " << item1 << " is not installed.\n";
                else if(needed(i1)) cout << "   " << item1 << " is still needed.\n";
                else remove(i1, true);
            }
        }
    }
    return 0;
}
