// written at 14:49 on 08 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T> inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 52;
const char *suits = "CDHS";
const char *ranks = "A23456789TJQK";

struct Pile {
    int t, card[maxn];
    int next, prev;
    int top() { return card[t - 1];}
    int pop() { return card[--t];}
    void push(int v) { card[t++] = v;}
    bool empty() { return t == 0;}
} pile[maxn + 1];

char s[5];

int ID(char r, char s) {
    int rank = strchr(ranks, r) - ranks;
    int suit = strchr(suits, s) - suits;
    return rank * 4 + suit;
}

bool match(int a, int b) {
    return a / 4 == b / 4 || a % 4 == b % 4;
}

bool input() {
    for (int i = 0; i < maxn; i++) {
        if (scanf("%s", s) != 1) return false;
        pile[i].t = 0; pile[i].push(ID(s[0], s[1]));
        pile[i].prev = i - 1;
        pile[i].next = i + 1;
    }
    return true;
}

int pre(int i, int k) {
    for (int j = 0; j < k; j++) {
        if (i < 0) return i;
        i = pile[i].prev;
    }
    return i;
}

int main() {
    while (input()) {
        bool flag;
        do {
            flag = false;
            for (int i = 0; i < maxn && !flag; i = pile[i].next) {
                int l1 = pre(i, 1), l2 = pre(i, 2), l3 = pre(i, 3);
                if (l1 != -1 && l2 != -1 && l3 != -1 && match(pile[i].top(), pile[l3].top())) {
                    pile[l3].push(pile[i].pop());
                    flag = true;
                }
                if (!flag && l1 != -1 && match(pile[i].top(), pile[l1].top())) {
                    pile[l1].push(pile[i].pop());
                    flag = true;
                }
                if (pile[i].empty()) {
                    int r1 = pile[i].next;
                    pile[l1].next = r1; pile[r1].prev = l1;
                }
            }
        } while (flag);
        int tot = 0;
        for (int i = 0; i < maxn; i = pile[i].next) tot++;
        if (tot == 1) printf("1 pile remaining:");
        else printf("%d piles remaining:", tot);
        for (int i = 0; i < maxn; i = pile[i].next) printf(" %d", pile[i].t);puts("");
    }
    return 0;
}
