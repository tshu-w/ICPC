#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pieces
{
    int x, y, p;
    char c;
}b[20], w[20];

int power(char ch) {
    switch (ch) {
        case 'K' : case 'k' : return 1;
        case 'Q' : case 'q' : return 2;
        case 'R' : case 'r' : return 3;
        case 'B' : case 'b' : return 4;
        case 'N' : case 'n' : return 5;
        case 'P' : case 'p' : return 6;
    }
    return 0;
}
bool cmp_b(Pieces a, Pieces b) {
    if (a.p != b.p) return a.p < b.p;
    if (a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}
bool cmp_w(Pieces a, Pieces b) {
    if (a.p != b.p) return a.p < b.p;
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int main(int argc, char const *argv[])
{
    int sum_b = 0, sum_w = 0;
    char s[100];
    for (int i = 8; i > 0; i--) {
        gets(s);
        gets(s);
        for (int j = 0; j < 8; j++)
            if (s[j * 4 + 2] != ':' && s[j * 4 + 2] != '.') {
                if (s[j * 4 + 2] >= 'a' && s[j * 4 + 2] <= 'z') {
                    b[sum_b].x = i;
                    b[sum_b].y = j;
                    b[sum_b].c = s[j * 4 + 2] - 32;
                    b[sum_b++].p = power(s[j * 4 + 2]);
                }
                else {
                    w[sum_w].x = i;
                    w[sum_w].y = j;
                    w[sum_w].c = s[j * 4 + 2];
                    w[sum_w++].p = power(s[j * 4 + 2]);
                }
            }
    }
    gets(s);

    sort(b, b + sum_b, cmp_b);
    sort(w, w + sum_w, cmp_w);

    printf("White: ");
    for (int i = 0; i < sum_w; i++) {
        if (w[i].c != 'P') printf("%c", w[i].c);
        printf("%c%d%c", w[i].y + 'a', w[i].x, (i == sum_w - 1)? '\n' : ',');
    }
    printf("Black: ");
    for (int i = 0; i < sum_b; i++) {
        if (b[i].c != 'P') printf("%c", b[i].c);
        printf("%c%d%c", b[i].y + 'a', b[i].x, (i == sum_b - 1)? '\n' : ',');
    }
    return 0;
}