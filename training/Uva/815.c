#include <stdio.h>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    int altitude[10000];
    int n, m, cases = 0, water_volume;
    double water_level;
    
    while (scanf("%d%d", &m, &n) && m && n) {
        for (int i = 0; i < n*m; i++)
            scanf("%d", &altitude[i]);
        scanf("%d", &water_volume);
        sort(altitude, altitude + m*n);
        int now, i;
        for (i = 1; i < m*n; i++) {
            now = i * 100 * (altitude[i] - altitude[i-1]);
            if ( now > water_volume) {
                water_level = (double)altitude[i-1] + (double)water_volume / (double)(i*100);
                water_volume = 0;
                break;
            }
            else water_volume -= now;
        }
        if (water_volume > 0)
            water_level = (double)altitude[m*n-1] + (double)water_volume / (double)(m*n*100);
        printf("Region %d\n", ++cases);
        printf("Water level is %.2lf meters.\n", water_level);
        printf("%.2lf percent of the region is under water.\n\n", (i*100.0) / (m*n));
    }

    return 0;
}