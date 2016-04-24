#include <stdio.h>

int main(void) {
    int doub=1;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", doub ? "``" : "''");
            doub =! doub;
        }
        else printf("%c",c);
    }
    return 0;
}