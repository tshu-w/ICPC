#include "stdio.h"
#include "string.h"
#define NotFound -1;

int pre[1000];
int BinarySearch( const int A[], int x, int n) {
    int mid, left, right;
    left = 0; right = n - 1;
    while ( left <= right ) {
        mid = ( left + right ) / 2;
        if ( x > A[mid] )
            left = mid + 1;
        else
            if ( x < A[mid] )
                right = mid - 1;
            else return mid;
    }
    return NotFound;
}
int find(int x)
{ 
    int r=x;
    while ( pre[r] != r )                                                                                           
          r = pre[r];
    int i = x, j ;
    while( i != r )                                                           
    {
         j = pre[ i ];
         pre[ i ]= r ;
         i = j;
    }
    return r ;
}
void join(int x,int y)    
{
    int fx = find(x), fy = find(y);
    if(fx != fy)
        pre[fx] = fy;
}
int main(int argc, char const *argv[])
{
	int fib[50], nfib, n, m, k[1005], family[1005], u, v;
	fib[0] = 1;fib[1] = 1;
	nfib = 1;
	while (fib[nfib] < 1000000000) {
		nfib++;
		fib[nfib] = fib[nfib - 1] + fib[nfib - 2];
	};
	while (~scanf("%d%d", &n, &m)) {
		int max = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &k[i]);
		for (int i = 1; i <= n; i++) 
			pre[i] = i;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &u, &v);
			join(u, v);
		}
		memset(family, 0, sizeof(family));
		for (int i = 1; i <= n; i++)
			if ( BinarySearch(fib, k[i], nfib) != -1) {
				int f = find(i);
				family[f]++;
				if (family[f] > max) max = family[f];
			}
		printf("%d\n", max);
	}
	return 0;
}

