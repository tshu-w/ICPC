// written at 16:44 on 21 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 110;

int d, A[MAX_N], B[MAX_N], cs[510], rs[510];
vector<int> mb, kb;

struct bign{
	static const int maxlen=5000,limit=10000,width=4;
	int len,bit[maxlen];
	int& operator[](int p){ return bit[p]; }
	void ClearBit(){ memset(bit,0,sizeof(bit)); }
	void Delete0(){ for(;!bit[len-1] && len>1;--len); }

	bign(int p=0){ *this=p; }
	bign& operator=(int p){
		ClearBit();
		len=p?0:1; for(;p;p/=limit) bit[len++]=p%limit;
		return *this;
	}
	bign(const char *p){ *this=p; }
	bign& operator=(const char *p){
	ClearBit();
		len=0; int now=0;
		for(int i=strlen(p)-1;i>=0;i-=width){
			int now=0;
			for(int j=max(0,i-width+1);j<=i;++j) now=now*10+(p[j]-'0');
			bit[len++]=now;
		}
		return *this;
	}

	bign& operator+=(bign b){
		len=max(len,b.len)+1;
		for(int i=0;i<len;++i) bit[i]+=b[i],bit[i+1]+=bit[i]/limit,bit[i]%=limit;
		Delete0(); return *this;
	}
	bign& operator-=(bign b){
		for(int i=0;i<len;++i){ bit[i]-=b[i]; if(bit[i]<0) bit[i]+=limit,--bit[i+1]; }
		Delete0(); return *this;
	}
	bign& operator*=(bign b){
		bign a=*this; ClearBit(); len=a.len+b.len;
		for(int i=0;i<a.len;++i)
			for(int j=0;j<b.len;++j)
				bit[i+j]+=a[i]*b[j],bit[i+j+1]+=bit[i+j]/limit,bit[i+j]%=limit;
		Delete0(); return *this;
	}
	bign& operator/=(int b){
		for(int i=len-1;i>0;--i) bit[i-1]+=limit*(bit[i]%b),bit[i]/=b; bit[0]/=b;
		Delete0(); return *this;
	}

	bool operator<(bign b) const{
		if(len>b.len) return false;
		if(len<b.len) return true;
		for(int i=len-1;i>=0;--i)
			if(bit[i]!=b[i]) return bit[i]<b[i];
		return bit[0]<b[0];
	}
	bool operator==(bign b) const{ return !(*this<b) && !(b<*this); }
	bool operator!=(bign b) const{ return !(*this==b); }
	bool operator>(bign b) const{ return !(*this<b) && !(*this==b); }
	bool operator<=(bign b) const{ return *this<b || *this==b; }
	bool operator>=(bign b) const{ return *this>b || *this==b; }
};
bign operator+(bign a,bign b){ return a+=b; }
bign operator-(bign a,bign b){ return a-=b; }
bign operator*(bign a,bign b){ return a*=b; }
bign operator/(bign a,int b){ return a/=b; }
istream& operator>>(istream &is,bign &p){
	string s; is>>s; p=s.c_str();
	return is;
}
ostream& operator<<(ostream &os,bign p){
	os.fill('0'); os<<p.bit[p.len-1];
	for(int i=p.len-2;i>=0;--i){ os.width(bign::width); os<<p.bit[i]; }
	return os;
}

bign sqrt(bign x){
	bign head=1,tail=x;
	while(head<=tail){
		bign mid=(head+tail)/2;
		if(x<mid*mid) tail=mid-1; else head=mid+1;
	}
	return tail;
};
bign m, k;
struct rec
{
	ll g, x, y;	
	rec(ll g = 0, ll x = 0, ll y = 0) : g(g), x(x), y(y) {}
};

rec euclid(ll a, ll b) {
	if (b == 0) return rec(a, 1, 0);
	else {
		rec ans = euclid(b, a % b);
		return rec(ans.g, ans.y, ans.x - (a / b) * ans.y);
	}
}

void ten_to_d(bign &m, vector<int> &mb) {
	while (m != 0) {
		bign mod = m - (m / d) * d;
		mb.push_back(mod.bit[0]);
		m /= d;
	}
}

Pii trans(int *cha, int hm, int hk) {
	int round = 0, cnt = 0, p = hm;
	while (true) {
		if (p == hk) break;
		else if (cnt && p == hm) {cnt = -1; break;}
		p = cha[p]; ++cnt;
	}
	if (cnt == -1) return make_pair(-1, 0);
	while (true) {
		if (round && p == hk) break;
		p = cha[p]; ++round;
	}
	return make_pair(cnt, round);
}

void solve() {
	rep(i, 1, d) scanf("%d", A + i);
	rep(i, 0, d) scanf("%d", B + i);
	cin >> m >> k;
	mb.clear(); kb.clear();
	ten_to_d(m, mb); ten_to_d(k, kb);
	if (mb.size() != kb.size()) {
		puts("NO"); return;
	}
	rep(i, 0, mb.size()) {
		Pii p;
		if (i != mb.size() - 1) p = trans(B, mb[i], kb[i]);
		else p = trans(A, mb[i], kb[i]);
		if (p.first == -1) {puts("NO"); return;}
		else cs[i] = p.first, rs[i] = p.second;
	}
	ll lm = 0, lb = 1, z;
	rep(i, 0, mb.size()) {
		rec adp = euclid(lb, rs[i]);
		if ((lm - cs[i]) % adp.g) {puts("NO"); return;}
		lb = lb / adp.g * rs[i];
		z = adp.y * ((lm - cs[i]) / adp.g);
		lm = z * rs[i] + cs[i];
		lm = ((lm % lb) + lb) % lb;
	}
	cout << lm << endl;
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &d) && d != -1)
		solve();
	return 0;
}