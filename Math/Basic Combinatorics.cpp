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

namespace smallN{
	const int N = 1000 + 5;
	int C[N][N];

	void build(int n){
		FOR(i, 0, n){
			C[i][0] = 1;
			FOR(j, 1, i - 1)
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
	int query(int n, int k){
		if (k > n) return 0;
		return C[n][k];
	}
}

namespace Standard_Combinatorics{
	// Assume MOD is a prime number and n < MOD
	// else use other methods (i.e. : Diophantine equation,..) to calculate inverse modulo

	int fact[N], inv[N];

	int binPow(int a, int b){
		int ans = 1;
		while(b > 0){
			if (b & 1) ans = 1ll * ans * a % MOD;
			a = 1ll * a * a % MOD; b >>= 1;
		}
		return ans;
	}
	void build(int n){
		fact[0] = 1;
		FOR(i, 1, n) fact[i] = 1ll * fact[i - 1] * i % MOD;

		inv[n] = binPow(fact[n], MOD - 2);
		FORD(i, n, 1) inv[i - 1] = 1ll * inv[i] * i % MOD;
	}
	int query(int n, int k){
		if (k > n) return 0;
		return 1ll * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
	}
}

namespace Lucas{
	// Assume MOD is a prime number and n > MOD

	int query(int n, int k){
	    if (k > n) return 0;
	    int res = 1;
	    while (n > 0){
	        res = 1LL * res * Standard_Combinatorics :: query(n % MOD, k % MOD) % MOD;
	        n /= MOD; k /= MOD;
	    }
	    return res;
	}
}

namespace Extended_Lucas{
	// Assume MOD is a exponent of prime
	// Pending
}

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