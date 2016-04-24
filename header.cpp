#include <bits/stdc++.h>
using namespace std;
inline namespace Infinity {
	inline namespace IO {
		const char CR = '\n';
		const char SP = ' ';
		inline void write(const int n) { 
			printf("%d", n); 
		}
		inline void write(const unsigned n) { 
			printf("%u", n); 
		}
		inline void write(const long long n) { 
			cout << n; 
		}
		inline void write(const unsigned long long n) { 
			cout << n; 
		}
		inline void writef(const double a, const int n = 15) { 
			printf("%.*f", n, a); 
		}
		inline void writef(const long double a, const int n = 18) { 
			cout << setprecision(n) << fixed << a; 
		}
		inline void write(const char c) { 
			printf("%c", c); 
		}
		inline void write(const char s[]) { 
			printf("%s", s); 
		}
		inline void write(const string &s) { 
			cout << s; 
		}
		inline void write(const pair<int, int> &p) { 
			printf("%d %d", p.first, p.second); 
		}
		template<class T> inline void write(const T a) { 
			for (auto i : a) write(i), write(SP); 
		}
		inline void writeln() { 
			write(CR); 
		}
		template<typename T> inline void writeln(const T &a) { 
			write(a); write(CR); 
		}
		inline void writefln(const double a, int n) { 
			printf("%.*f", n, a); write(CR); 
		}
		inline void writefln(const long double a, int n = 18) { 
			cout << setprecision(n) << fixed << a << endl; 
		}
		inline void writesln(const int *a, const int l, const int r) { 
			for (int i = l; i <= r; i++) printf("%d ", a[i]); writeln(CR); 
		}
		template<class T> inline void writelns(const T a) { 
			for (__typeof a.begin() i = a.begin(); i != a.end(); i++) writeln(*i); 
		}
		template<typename T, typename... types> inline void write(const T &a, const types &...args) { 
			write(a); write(args...); 
		}
		template<typename... types> inline void writeln(const types &...args) { 
			write(args...); write(CR); 
		}
		inline void writelnYN(bool b) { 
			writeln(b ? "YES" : "NO"); 
		}
		inline void writelnyn(bool b) { 
			writeln(b ? "Yes" : "No"); 
		}
		string caseSharpSpace(int n) { 
			return "Case #" + to_string(n) + ": "; 
		}
		string caseNoSharpSpace(int n) { 
			return "Case " + to_string(n) + ": "; 
		}
		string caseSharpNoSpace(int n) { 
			return "Case #" + to_string(n) + ":"; 
		}
		string caseNoSharpNoSpace(int n) { 
			return "Case " + to_string(n) + ":"; 
		}
		inline int read(int &n) { 
			return scanf("%d", &n); 
		}
		inline int read(long long &n) { 
			return cin >> n ? 1 : -1; 
		}
		template<typename T, typename... types> inline int read(T &n, types &...args) { 
			read(n); return read(args...); 
		}
		inline char getcc() { 
			char c; do c = getchar(); while (c == ' ' || c == '\n'); return c; 
		}
		inline int getint() { 
			int n; read(n); return n; 
		}
		inline long long getll() { 
			long long n; read(n); return n; 
		}
		inline double getdouble() { 
			double n; scanf("%lf", &n); return n; 
		}
		inline vector<int> getints(int n) { 
			vector<int> v(n); for (int i = 0; i < n; i++) v[i] = getint(); return v; 
		}
		inline vector<pair<int, int>> getpairs(int n) { 
			vector<pair<int, int>> v(n); for (int i = 0; i < n; i++) { int a = getint(), b = getint(); v[i] = pair<int, int>(a, b); } return v; 
		}
		inline void read(string &str, const unsigned size) { 
			char s[size]; scanf("%s", s); str = string(s); 
		}
		inline string getstr(const unsigned size = 1048576) { 
			string s; read(s, size + 1); return s; 
		}
		inline string getln(const unsigned size = 1048576) { 
			char s[size + 1]; scanf("%[^\n]", s); getchar(); return string(s); 
		}	
	} // namespace Infinity::IO
	inline namespace Functions {
		inline constexpr int ctoi(const char c) { 
			return c - '0'; 
		}
		inline constexpr char itoc(const int n)	{ 
			return n + '0'; 
		}
		inline int dtoi(const double d) { 
			return round(d); 
		}
		template<typename T> inline bool in(T x, T l, T r) { 
			return l <= x && x <= r; 
		}
		template<class T> inline int size(const T &a) { 
			return a.size(); 
		}
		template<typename T1, typename T2> inline pair<T1, T2> mkp(const T1 &a, const T2 &b) { 
			return make_pair(a, b); 
		}
		template<class T> inline void sort(T &a) { 
			std::sort(a.begin(), a.end()); 
		}
		template<class T1, class T2> inline void sort(T1 &a, T2 comp) { 
			std::sort(a.begin(), a.end(), comp); 
		}
		template<class T1, typename T2> inline int lbound(const T1 &a, const T2 k) { 
			return lower_bound(a.begin(), a.end(), k) - a.begin(); 
		}
		template<class T1, typename T2> inline int ubound(const T1 &a, const T2 k) { 
			return upper_bound(a.begin(), a.end(), k) - a.begin(); 
		}
		template<class T1, class T2> int count(T1 &a, T2 k)	{ 
			return ubound(a, k) - lbound(a, k); 
		}
		// returning the index of the first element matched, -1 otherwise
		template<class T1, class T2> int find(T1 &a, T2 k) { 
			return count(a, k) ? lbound(a, k) : -1; 
		}
		template<typename T> inline void clear(T &a) { 
			memset(a, 0, sizeof a); 
		}
		template<typename T> T gcd(T a, T b) { 
			while (b) { T t = a % b; a = b; b = t; } return a; 
		}
		template<typename T> T lcm(T a, T b) { 
			return a / gcd(a, b) * b; 
		}
		long long qpow(long long a, long long b, long long c) { 
			return b ? qpow(a * a % c, b >> 1, c) * (b & 1 ? a : 1) % c : 1; 
		}
		// find (x, y) s.t. a x + b y = gcd(a, b) = d
		template<typename T> T exGcd(T a, T b, T &x, T &y) { 
			T d = a; if (b) { d = exGcd(b, a % b, y, x); y -= a / b * x; } else { x = 1; y = 0; } return d; 
		}
		// returning count of nk in range [l, r]
		template<typename T> T mps(T l, T r, T k) { 
			return ((r - (r % k + k) % k) - (l + (k - l % k) % k)) / k + 1; 
		}
		template<typename T> T sgn(T a) { 
			return a == 0 ? 0 : a > 0 ? 1 : -1; 
		}
		template<typename T> constexpr T sq(T a) { 
			return a * a; 
		}
	} // namespace Infinity::Functions
	inline namespace TypeDefine {
		typedef unsigned int uint;
		typedef long long int ll;
		typedef unsigned long long int ull;
		typedef long double ld;
		typedef pair<int, int> pii;
	} // namespace Infinity::TypeDefine
	inline namespace Constant {
		const int maxint = INT_MAX;
		const long long maxll = LLONG_MAX;
	}
} // namespace Infinity