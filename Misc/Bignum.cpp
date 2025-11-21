// Source : 
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define pii  pair<int,int>
#define fi   first
#define se   second
#define ve   vector
#define vi   ve<int>
#define vll  ve<ll>
#define el   '\n'
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define __builtin_popcount __builtin_popcountll
template<class T> bool minimize(T &a, T b){ return (a > (b) ? a = (b), 1 : 0); }
template<class T> bool maximize(T &a, T b){ return (a < (b) ? a = (b), 1 : 0); }
template<class T> T Abs(const T &x) { return (x<0?-x:x);}

const int N = 1e5 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

const int SZ = 60;
const int BASE = 1e4, K = 4;
struct bignum { // ans = ans % BASE^N
	int d[SZ];
	int sz;
	
	bignum () {
		memset(d, 0, sizeof d);
		sz = 1;
	}
	
	bignum (long long x) {
		*this = bignum();
		sz = 0;
		while (x > 0) {
			d[sz++] = x % BASE;
			x /= BASE;
		}
		if (!sz) sz = 1;
	}
	
	friend ostream &operator << (ostream &out, bignum x) {
		if (x.sz == 0) return out << 0;
		out << x.d[x.sz - 1];
		for (int i(x.sz - 2); i >= 0; --i) {
			out << setfill('0') << setw(K) << x.d[i];
		}
		return out;
	}
	
	bignum operator + (const bignum &x) const {
		bignum res(0);
		res.sz = max(sz, x.sz);
		int remain = 0;
		for (int i(0); i < res.sz; ++i) {
			res.d[i] = d[i] + x.d[i] + remain;
			remain = 0;
			if (res.d[i] > 9) {
				remain = res.d[i] / BASE;
				res.d[i] %= BASE;
			}
		}
		if (remain > 0) res.d[res.sz++] = remain;
		return res;
	}
	
	bignum operator - (const bignum &x) const {
		bignum res(0);
		int remain = 0;
		for (int i(0); i < sz; ++i) {
			res.d[i] = d[i] - x.d[i] - remain;
			remain = 0;
			if (res.d[i] < 0) res.d[i] += BASE, remain = 1;
			if (res.d[i] > 0) res.sz = i + 1;
		}
		if (res.sz > 1 && res.d[res.sz - 1] == 0) --res.sz;
		return res;
	}
	
	bignum operator * (const bignum &x) const {
		bignum res(0);
		res.sz = sz + x.sz;
		for (int i(0); i < sz; ++i) for (int j(0), lim = min(SZ - i, x.sz); j < lim; ++j) {
			res.d[i + j] += d[i] * x.d[j];
		}
		int remain = 0;
		for (int i(0); i < res.sz; ++i) {
			res.d[i] += remain;
			remain = 0;
			if (res.d[i] > 9) {
				remain = res.d[i] / BASE;
				res.d[i] %= BASE;
			}
		}
		while (res.sz > 1 && res.d[res.sz - 1] == 0) --res.sz;
		return res;
	}
	
	bignum operator / (const long long &v) const {
		bignum res = *this;
		int remain = 0;
		for (int i(res.sz - 1); i >= 0; --i) {
			long long cur = res.d[i] + remain * BASE;
			res.d[i] = cur / v;
			remain = cur % v;
		}
		while (res.sz > 1 && res.d[res.sz - 1] == 0) --res.sz;
		return res;
	}

	bool operator == (const bignum &a) const {
		if (sz != a.sz) return false;
		for (int i(sz - 1); i >= 0; --i) {
			if (d[i] != a.d[i]) return false;
		}
		return true;
	}

	bool operator < (const bignum &a) const {
		if (sz < a.sz) return true;
		if (sz > a.sz) return false;
		for (int i(sz - 1); i >= 0; --i) {
			if (d[i] < a.d[i]) return true;
			if (d[i] > a.d[i]) return false;
		}
		return false;
	}

	bool operator > (const bignum &a) const {
		return !(*this < a) && !(*this == a);
	}

	bool operator != (const bignum &a) const {
		return !(*this == a);
	}

	bool operator <= (const bignum &a) const {
		return *this < a || *this == a;
	}

	bool operator >= (const bignum &a) const {
		return *this > a || *this == a;
	}
};

signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#define NAME "TASK"
	if (fopen(NAME".inp", "r")){
		freopen(NAME".inp", "r", stdin);
   		freopen(NAME".out", "w", stdout);
	}

	bool multiTest = 0;
	int numTest = 1;

	if (multiTest) cin >> numTest;
	while(numTest--){
		
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}