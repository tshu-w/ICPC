#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

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

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;


const int ST_SIZE = 1 << 18;

int N, M, l, r, k, A[MAX_N], nums[MAX_N];
vector<int> data[ST_SIZE];

void init(int k, int l, int r) {
	if (l + 1 == r)
		data[k].push_back(A[l]);
	else {
		int lch = 2 * k + 1, rch = 2 * k + 2;
		init(lch, l, (l + r) / 2);
		init(rch, (l + r) / 2, r);
		data[k].resize(r - l);
		merge(data[lch].begin(), data[lch].end(), data[rch].begin(), data[rch].end(), data[k].begin());
	}
}

int query(int a, int b, int x, int k, int l, int r) {
	if (b <= l || r <= a)
		return 0;
	else 
		if (a <= l && r <= b) 
			return upper_bound(data[k].begin(), data[k].end(), x) - data[k].begin();
		else 
			return query(a, b, x, 2 * k + 1, l, (l + r) / 2) + query(a, b, x, 2 * k + 2, (l + r) / 2, r);
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	init(0, 0, N);

	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &l, &r, &k); --l;
		int lb = -1, ub = N - 1;
		while (lb + 1 < ub) {
			int mid = (lb + ub) / 2;
			if (query(l, r, nums[mid], 0, 0, N) >= k) ub = mid;
			else lb = mid;
		}
		printf("%d\n", nums[ub]);
	}

	return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <memory.h>
// #include <cstring>
// using namespace std;
// #define maxn 100010
// #define maxm 20
// int n,m;
// int a[maxn];
// int sorted[maxm][maxn];
// struct node{
//     int l,r,d;
//     node* lc,*rc;
// };
// node mem[maxm*maxn];
// int pos;
// node *root;
// int b,e,k;
// node* maketree(int l,int r,int d){
//     if(l>r)return 0;
//     node* n1=&mem[pos++];
//     n1->l=l,n1->r=r,n1->d=d;
//     if(l==r){
//         sorted[d][l]=a[l];
//         return n1;
//     }
//     int mid=(l+r)/2;
//     n1->lc=maketree(l,mid,d+1);
//     n1->rc=maketree(mid+1,r,d+1);
//     int i,j,k;
//     i=l,j=mid+1,k=l;
//     while(i<=mid&&j<=r){
//         if(sorted[d+1][i]<sorted[d+1][j])
//             sorted[d][k++]=sorted[d+1][i++];
//         else
//             sorted[d][k++]=sorted[d+1][j++];
//     }
//     while(i<=mid)sorted[d][k++]=sorted[d+1][i++];
//     while(j<=r)sorted[d][k++]=sorted[d+1][j++];
//     return n1;
// }
// int search2(int l,int r,int d,int u){
//     if(l==r+1)return l;
//     int mid=(l+r)/2;
//     if(u<=sorted[d][mid])return search2(l,mid-1,d,u);
//     else return search2(mid+1,r,d,u);
// }
// int query(int u,node *n1){
//     if(b<=n1->l&&n1->r<=e){
//         return search2(n1->l,n1->r,n1->d,u)-n1->l;
//     }
//     else{
//         int ret=0;
//         int mid=(n1->l+n1->r)/2;
//         if(b<=mid)ret+=query(u,n1->lc);
//         if(e>=mid+1)ret+=query(u,n1->rc);
//         return ret;
//     }
// }
// int search1(int l,int r){
//     if(l==r+1){
//         return r;
//     }
//     int mid=(l+r)/2;
//     //cout<<"l="<<l<<",r="<<r<<endl;
//     //cout<<"mid="<<mid<<endl;
//     int x=query(sorted[1][mid],root);
//     //cout<<"x="<<x<<endl;
//     //cout<<"k="<<k<<endl;
//     if(x<=k)return search1(mid+1,r);
//     else return search1(l,mid-1);
// }
// int main(){
//     scanf("%d%d",&n,&m);
//     int i,j;
//     for(i=1;i<=n;i++)scanf("%d",&a[i]);
//     pos=0;
//     root=maketree(1,n,1);
//     /*for(i=1;i<=10;i++){
//         for(j=1;j<=7;j++)
//             printf("%d ",sorted[i][j]);
//         cout<<endl;
//     }*/
//     for(i=1;i<=m;i++){
//         scanf("%d%d%d",&b,&e,&k);
//         k--;
//         printf("%d\n",sorted[1][search1(1,n)]);
//     }
// }


// const int B = 1000;

// int N, M, l, r, k;
// int A[MAX_N], nums[MAX_N];
// vector<int> bucket[MAX_N / B];

// int main(int argc, char const *argv[])
// {
// 	scanf("%d%d", &N, &M);
// 	for (int i = 0; i < N; ++i) {
// 		scanf("%d", A + i);
// 		bucket[i / B].push_back(A[i]);
// 		nums[i] = A[i];
// 	}
// 	sort(nums, nums + N);
// 	for (int i = 0; i < N / B; ++i)
// 		sort(bucket[i].begin(), bucket[i].end());
// 	for (int i = 0; i < M; ++i) {
// 		scanf("%d%d%d", &l, &r, &k); --l;

// 		int lb = -1, ub = N - 1;
// 		while (lb + 1 < ub) {
// 			int mid = (lb + ub) / 2;
// 			int x = nums[mid];
// 			int tl = l, tr = r, c = 0;

// 			while (tl < tr && tl % B != 0) if (A[tl++] <= x) ++c;
// 			while (tl < tr && tr % B != 0) if (A[--tr] <= x) ++c;

// 			while (tl < tr) {
// 				int b = tl / B;
// 				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
// 				tl += B;
// 			}

// 			if (c >= k) ub = mid;
// 			else lb = mid;
// 		}

// 		printf("%d\n", nums[ub]);
// 	}

// 	return 0;
// }