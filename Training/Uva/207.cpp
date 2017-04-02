// written at 16:35 on 22 Mar 2017
#include <bits/stdc++.h>

#define filename "207"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define REP(i,n) for(int i = 0; i < (n); i++)
using namespace std;

const int MAX_N = 144;
const int n_cut = 70;

struct PLAYER {
    char name[25];
    int amateur;
    int sc[4];
    int sc36, sc72, dq;
    int rnds;
} player[MAX_N];

int n;
double purse, p[n_cut];

bool cmp1(const PLAYER& p1, const PLAYER& p2) {
  if(p1.sc36 < 0 && p2.sc36 < 0) return false; // equal
  if(p1.sc36 < 0) return false; // p2 smaller
  if(p2.sc36 < 0) return true; // p1 smaller
  return p1.sc36 < p2.sc36;
}

bool cmp2(const PLAYER& p1, const PLAYER& p2) {
  if(p1.dq && p2.dq) {
    if(p1.rnds != p2.rnds) return p2.rnds < p1.rnds;
    if(p1.sc72 != p2.sc72) return p1.sc72 < p2.sc72;
    return strcmp(p1.name, p2.name) < 0;
  }
  if(p1.dq) return false;
  if(p2.dq) return true;
  if(p1.sc72 != p2.sc72) return p1.sc72 < p2.sc72;
  return strcmp(p1.name, p2.name) < 0;
}

void init() {
    scanf("%lf", &purse);
    for (int i = 0; i < n_cut; i++)
        scanf("%lf", p + i);
    char line[40];
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        fgets(line, 40, stdin);
        strncpy(player[i].name, line, 20);
        player[i].name[20] = 0;
        player[i].amateur = 0;
        if (strchr(player[i].name, '*'))
            player[i].amateur = 1;
        
        player[i].sc36 = player[i].sc72 = player[i].dq = 0;
        memset(player[i].sc, -1, sizeof(player[i].sc));
        for (int j = 0; j < 4; j++) {
            char t[5];
            for (int k = 0; k < 3; k++) t[k] = line[20 + j * 3 + k]; t[3] = '\0';
            if (!sscanf(t, "%d", &player[i].sc[j])) {
                player[i].rnds = j;
                player[i].dq = -1;
                if (j < 2) player[i].sc36 = -1;
                break;
            } else {
                player[i].sc72 += player[i].sc[j];
                if (j < 2) player[i].sc36 += player[i].sc[j];
            }
        }
    }
}

void print_result() {
    puts("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won");
    puts("-----------------------------------------------------------------------");
    int i = 0, pos = 0;
    while (i < n) {
        if (player[i].dq == -1) {
            printf("%s           ", player[i].name);
            for (int j = 0; j < player[i].rnds; j++) printf("%-5d", player[i].sc[j]);
            for (int j = 0; j < 4 - player[i].rnds; j++) printf("     ");
            printf("DQ\n");
            i++;
            continue;
        }
        int j = i;
        int m = 0;
        bool have_money = false;
        double tot = 0.0;
        while (j < n && player[i].sc72 == player[j].sc72) {
            if (!player[j].amateur) {
                m++;
                if (pos < n_cut) {
                    have_money = true;
                    tot += p[pos++];
                }
            }
            j++;
        }
        int rank = i + 1;
        double amount = purse * tot / m;
        while (i < j) {
            printf("%s ", player[i].name);
            char t[5];
            sprintf(t, "%d%c", rank, m > 1 && have_money && !player[i].amateur ? 'T' : ' ');
            printf("%-10s", t);
            for (int e = 0; e < 4; e++) printf("%-5d", player[i].sc[e]);

            if (!player[i].amateur && have_money) {
                printf("%-10d", player[i].sc72);
                printf("$%9.2lf\n", amount / 100.0);
            } else printf("%d\n", player[i].sc72);
            i++;
        }
    }
}

void solve() {
    sort(player, player + n, cmp1);
    assert(player[n_cut - 1].sc36 >= 0);
    while (n > 0 && player[n - 1].sc36 == -1) n--;
    for (int i = n_cut - 1; i < n; i++)
        if (i == n - 1 || player[i].sc36 != player[i + 1].sc36) {
            n = i + 1; break;
        }
    sort(player, player + n, cmp2);
    // for (int i = 0; i < n; i++)
    //     printf("%s %d %d %d %d %d\n", player[i].name, player[i].sc[0], player[i].sc[1], player[i].sc[2], player[i].sc[3], player[i].dq);
    print_result();
}

int main() {
    // setfile();
    int t;
    scanf("%d ", &t);
    while (t--) {
        init();
        solve();
        if (t) puts("");
    }
    // resetfile();
    return 0;
}