#include <stdio.h>
#include "math.h"

#define PI acos(-1.0)
double dis;
double comarea(double r1, double r2) {
    if (dis >= r1 + r2) return 0;
    if (dis <= r2 - r1) return PI*r1*r1;
    double csita1 = (r1*r1 + dis*dis - r2*r2)/(2*r1*dis);
    double csita2 = (r2*r2 + dis*dis - r1*r1)/(2*r2*dis);
    double sc1, sc2, st1, st2;
    double s2sita1 = 2 * csita1 * sqrt(1 - csita1*csita1);
    double s2sita2 = 2 * csita2 * sqrt(1 - csita2*csita2);
    sc1 = acos(csita1)*r1*r1;
    sc2 = acos(csita2)*r2*r2;
    st1 = s2sita1*r1*r1/2;
    st2 = s2sita2*r2*r2/2;
    return (sc1+sc2-st1-st2);
}
int main(int argc, const char * argv[]) {
    int T;
    double r, R;
    double s1, s2, s3;
    double x1, x2, y1, y2;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases ++) {
        scanf("%lf%lf", &r, &R);
        scanf("%lf%lf", &x1, &y1);
        scanf("%lf%lf", &x2, &y2);
        dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        if (dis) {
            s1 = comarea(R, R);
            s2 = comarea(r, r);
            s3 = comarea(r, R);
            printf("Case #%d: %.6lf\n", cases, s1 + s2 - 2 * s3);
        }
        else printf("Case #%d: %.6lf\n", cases, PI*(R*R-r*r));
    }
    return 0;
}
