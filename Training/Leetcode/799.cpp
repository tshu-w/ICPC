#include <bits/stdc++.h>
class Solution {
public:
    double h[100][100];
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(h, 0, sizeof h);
        h[0][0] = poured;
        for (int i = 0; i < 99; i++)
            for (int j = 0; j < 99; j++)
                if (h[i][j] > 1) {
                    h[i + 1][j] += (h[i][j] - 1) / 2;
                    h[i + 1][j + 1] += (h[i][j] - 1) / 2;
                    h[i][j] = 1;
                }
        return h[query_row][query_glass];
    }
};
