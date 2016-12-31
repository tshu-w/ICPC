#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

const double PI = acos(-1.0);

class Point
{
public:
	double x, y;
	friend double dis(Point a, Point b) {
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	}
	friend double pldis(Point p, Point a, Point b) {
		double A = b.y - a.y, B = a.x - b.x, C = b.x * a.y - a.x * b.y;
		return fabs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
	}
};

int main(int argc, char const *argv[])
{
	int n;
	Point p, e[MAX_N];
	double dmin, dmax;
	scanf("%d%lf%lf", &n, &p.x, &p.y);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &e[i].x, &e[i].y);
		if (i == 0) {
			dmin = dis(p, e[i]);
			dmax = dis(p, e[i]);
		} else {
			dmin = min(dmin, dis(p, e[i]));
			dmax = max(dmax, dis(p, e[i]));
		}
	}
	for (int i = 0; i < n; ++i) {
			int j = (i + 1) % n;
			double d1 = dis(p, e[i]), d2 = dis(p, e[j]), d;
			d = pldis(p, e[i], e[j]);
			// printf("%d %d %lf %lf %lf\n", i, j, d, d1, d2);
			if (sqrt(d1 * d1 - d * d) + sqrt(d2 * d2 - d * d) - dis(e[i], e[j]) < 1e-8) {
				dmin = min(dmin, d);
				// dmax = max(dmax, d);
				// printf("Done");
			}
			else {
				dmin = min(dmin, d1);
				dmin = min(dmin, d2);
			}
			// printf("%f %f\n", dmin, dmax);
		}
	// printf("%lf\n", dmax);
	// printf("%lf\n", dmin);
	printf("%.10lf\n", PI * (dmax * dmax - dmin * dmin));
	return 0;
}