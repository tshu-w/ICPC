#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;

PII st[MAXN];
int n;

int main() {
    char s[10], s1[5], s2[5];
    int tot = 0, top, topa, topb, x, fa, fb;
    while( ~scanf( "%d", &n ) && n ) {
        printf( "Case #%d:\n", ++tot );
        top = topa = topb = fa = fb = 0;
        st[top++] = make_pair( 0, 0 );
        while( n-- ) {
            scanf( "%s", s );
            if( s[1] == 'u' ) {
                scanf( "%s%d", s1, &x );
                if( s1[0] == 'A' ) {
                    st[top++] = make_pair( topa, x );
                    topa = top - 1;
                } else {
                    st[top++] = make_pair( topb, x );
                    topb = top - 1;
                }
            }
            if( s[1] == 'o' ) {
                scanf( "%s", s1 );
                if( s1[0] == 'A' ) {
                    int tmp = topa;
                    if( topa > fa ) {
                        topa = st[topa].first;
                    } else {
                        while( --topa > 0 ) if( st[topa].first != -2 ) break;
                        fa = topa;
                    }
                    printf( "%d\n", st[tmp].second );
                    st[tmp].first = st[tmp].second = -2;
                } else {
                    int tmp = topb;
                    if( topb > fb ) {
                        topb = st[topb].first;
                    } else {
                        while( --topb > 0 ) if( st[topb].first != -2 ) break;
                        fb = topb;
                    }
                    printf( "%d\n", st[tmp].second );
                    st[tmp].first = st[tmp].second = -2;
                }
                top = max( topa, topb ) + 1;
            }
            if( s[1] == 'e' ) {
                scanf( "%s%s", s1, s2 );
                if( s1[0] == 'A' ) {
                    topa = top - 1; topb = 0;
                    fa = top - 1; fb = 0;
                } else {
                    topb = top - 1; topa = 0;
                    fb = top - 1; fa = 0;
                }
            }
        }
    }
    return 0;
}