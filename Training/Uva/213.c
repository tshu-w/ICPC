#include <stdio.h>
#include <string.h>

char code[8][1<<8];
int readchar() {
    for (;;) {
        char ch = getchar();
        if (ch != '\r' && ch != '\n') return ch;
    }
}
int readcodes() {
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    for (int len = 2; len <= 7; len++) {
        for (int i = 0; i < (1 << len)-1; i++) {
            char ch = getchar();
            if (ch == EOF) return 0;
            if (ch == '\n' || ch == '\r') return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}
int readint(int n) {
    int v = 0;
    while (n--) v = v*2 + readchar() - '0';
    return v;
}
int main(int argc, const char * argv[]) {
    while (readcodes()) {
        for (;;) {
            int len = readint(3);
            if (len == 0) break;
            for(;;) {
                int v = readint(len);
                if (v == (1 << len)-1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}