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

namespace Modular_Inverse{
	
	/*
		Nếu là MOD là số nguyên tố: a ^ (m - 2) đồng dư với a ^ (-1) mod MOD
		Nếu MOD không là số nguyên tố nhưng a và m là số nguyên tố cùng nhau: 
			Cách 1: a ^ (phi(m) - 1) đồng dư với a ^ (-1) mod MOD
			Cách 2: giải phương trình a * x + MOD * y = 1 (dùng ext_gcd) -> nghiệm x của phương trình là nghịch đảo modulo của a
		else: không có
	*/
	
	// Với MOD <= 1e6
	const int MOD = 1e6 + 7;
	int inv_mod[MOD + 5]; // inv_mod[i] = i ^ (-1)
	void build_array(){
		inv_mod[1] = 1;
		FOR(i, 2, MOD - 1)
			inv_mod[i] = (MOD - (MOD / i) * inv_mod[MOD % i] % MOD) % MOD; 
	}
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