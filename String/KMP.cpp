// Source : https://cses.fi/problemset/task/1753
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
const int MOD = 1e9 + 7;

string s, t;
int n, kmp[N];
int nxt[N][26]; 
// nxt[i][c] : The length of matched prefix if already matched first i characters and add character c at the end 

void solve(){
	FOR(i, 0, n){
		kmp[i] = i <= 1 ? 0 : nxt[kmp[i - 1]][t[i] - 'a'];
		FOR(c, 0, 25)
			nxt[i][c] = i < n && t[i + 1] == c + 'a' ? i + 1 : nxt[kmp[i]][c];
	}

	int k = 0, cnt = 0;
	REP(i, s.size()){
		k = nxt[k][s[i] - 'a'];
		if (k == n) cnt++;
	}

	cout << cnt;
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
		n = t.size(); t = "#" + t;

		solve();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}