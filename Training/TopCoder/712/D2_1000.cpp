// written at 18:42 on 18 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 55;

class AverageVarianceSubset
{
public:
    double average(vector <int> s, int R) {
        sort(s.begin(), s.end());
        int n = s.size();

        ll subset_cnt = 0;
        double var_sum = 0;

        ll seg_cnt[MAX_N];
        double sqr_sum[MAX_N], sum_sqr[MAX_N], sum[MAX_N];

        int last_ptr = -1;
        for (int i = 0; i < n; i++) {
            fill(seg_cnt, seg_cnt + MAX_N, 0);
            fill(sqr_sum, sqr_sum + MAX_N, 0);
            fill(sum_sqr, sum_sqr + MAX_N, 0);
            fill(sum, sum + MAX_N, 0);
            seg_cnt[0] = 1;
            int j;
            for (j = i; j < n && s[j] - s[i] <= R; j++) {
                for (int k = MAX_N - 1; k >= 0; k--) if (seg_cnt[k]) {
                    seg_cnt[k + 1] += seg_cnt[k];
                    sqr_sum[k + 1] += sqr_sum[k] + (double)s[j] * s[j] * seg_cnt[k];
                    sum_sqr[k + 1] += sum_sqr[k] + (double)s[j] * s[j] * seg_cnt[k] + 2.0 * s[j] * sum[k];
                    sum[k + 1] += sum[k] + (double)s[j] * seg_cnt[k];

                    if (j >= last_ptr) {
                        subset_cnt += seg_cnt[k];
                        var_sum += (
                            (sqr_sum[k] + (double)s[j] * s[j] * seg_cnt[k])
                            - (sum_sqr[k] + (double)s[j] * s[j] * seg_cnt[k] + 2.0 * s[j] * sum[k]) / (double)(k + 1)
                            ) / (k + 1);
                    }
                }
            }
            last_ptr = j;
        }
        return var_sum / subset_cnt;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}
