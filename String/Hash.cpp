// Source : https://cses.fi/problemset/task/1753/
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

const int N = 1e6 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;

string s, t;
int n;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 13;
const int BASE1 = 137;
const int BASE2 = 359;

int pw1[N], pw2[N];
int h1[N], h2[N];

void build(){
	pw1[0] = pw2[0] = 1;
	FOR(i, 1, n){
		h1[i] = (1ll * h1[i - 1] * BASE1 + s[i - 1] - 'a' + 1) % MOD1;
		h2[i] = (1ll * h2[i - 1] * BASE2 + s[i - 1] - 'a' + 1) % MOD2;
		pw1[i] = 1ll * pw1[i - 1] * BASE1 % MOD1;
		pw2[i] = 1ll * pw2[i - 1] * BASE2 % MOD2;
	}
}
pii gethash(int l, int r){
	return mp((1ll * h1[r] - 1ll * h1[l - 1] * pw1[r - l + 1] + 1ll * MOD1 * MOD1) % MOD1,
			  (1ll * h2[r] - 1ll * h2[l - 1] * pw2[r - l + 1] + 1ll * MOD2 * MOD2) % MOD2);
}
int find_pattern(const string& str){
	int sz = (int) str.size();
	int hash1 = 0, hash2 = 0;
	REP(i, sz){
		hash1 = (1ll * hash1 * BASE1 + str[i] - 'a' + 1) % MOD1;
		hash2 = (1ll * hash2 * BASE2 + str[i] - 'a' + 1) % MOD2;
	}

	int cnt = 0;
	FOR(i, 1, n - sz + 1){
		pii tmp = gethash(i, i + sz - 1);
		if (hash1 == tmp.fi && hash2 == tmp.se) cnt++;
	}

	return cnt;
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
		cin >> s >> t;
		n = (int) s.size();
		build();

		cout << find_pattern(t);
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}