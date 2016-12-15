#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;
typedef pair<Pii, string> Piis;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;
const int MAX_M = 20005;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, m, a, N;

Piis P[MAX_N];
map<string, Pii> s2p;
set<Piis> working, noWorking;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    char name[30], name2[30], ch[5];
    for (int i = 0; i < n; ++i)	{
        scanf("%s%d", name, &a);
        P[i] = make_pair(Pii(a, i), name);
        s2p[name] = Pii(a, i);
    }
    sort(P, P + n, greater<Piis>());
    int i = 0;
    for (; i < n / 5; ++i)
        working.insert(P[i]);
    for (; i < n; ++i)
        noWorking.insert(P[i]);
    scanf("%d", &m); N = n;
    for (int i = 0; i < m; ++i) {
        scanf("%s", ch);
        if (ch[0] == '+') {
            scanf("%s%d", name, &a);
            Pii pii = Pii(a, i + N);
            s2p[name] = pii;
            ++n;
            if (n / 5 > working.size()) { // add a new person to working
                if (noWorking.size() && pii > noWorking.rbegin()->first) {
                    working.insert(make_pair(pii, name));
                    printf("%s is working hard now.\n", name);
                } else {
                    noWorking.insert(make_pair(pii, name));
                    Piis tmp = *noWorking.rbegin();
                    noWorking.erase(*noWorking.rbegin());
                    working.insert(tmp);
                    // name2 = tmp.second.c_str();
                    printf("%s is not working now.\n", name);
                    printf("%s is working hard now.\n", tmp.second.c_str());
                }
            } else {
                if (working.size() && pii > working.begin()->first) {
                    working.insert(make_pair(pii, name));
                    Piis tmp = *working.begin();
                    working.erase(*working.begin());
                    noWorking.insert(tmp);
                    // name2 = tmp.second.c_str();
                    printf("%s is working hard now.\n", name);
                    printf("%s is not working now.\n", tmp.second.c_str());
                } else {
                    noWorking.insert(make_pair(pii, name));
                    printf("%s is not working now.\n", name);
                }
            }
        } else {
            scanf("%s", name);
            --n;
            Pii pii = s2p[name];
            if (n / 5 < working.size()) { // remove a person from working
                if (working.size() && pii < working.begin()->first) { // in noWorking
                    noWorking.erase(make_pair(pii, name));
                    Piis tmp = *working.begin();
                    working.erase(*working.begin());
                    noWorking.insert(tmp);
                    // name2 = tmp.second.c_str();
                    printf("%s is not working now.\n", tmp.second.c_str());
                } else {
                    working.erase(make_pair(pii, name));
                    // printf("%s is not working now.\n", name);
                }
            } else {
                if (working.size() == 0 || pii < working.begin()->first) {
                    noWorking.erase(make_pair(pii, name));
                } else {
                    working.erase(make_pair(pii, name));
                    Piis tmp = *noWorking.rbegin();
                    noWorking.erase(*noWorking.rbegin());
                    working.insert(tmp);
                    printf("%s is working hard now.\n", tmp.second.c_str());
                }
            }
        }
    }
    return 0;
}