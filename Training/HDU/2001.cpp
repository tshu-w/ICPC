#include <stdio.h>
#include "math.h"

int main(void) {
    double x1, x2, y1, y2;
    while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) == 4) {
    	printf("%.2lf\n", sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    }
    return 0;
}