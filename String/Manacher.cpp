// Source : https://cses.fi/problemset/task/1111/
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

const int N = 2e6 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

string s;
char a[N];
int n, len;
int f[N];

void solve(){
	n = (int) s.size() * 2 + 1;
	FOR(i, 0, n - 1)
		a[i] = (i & 1) ? s[i / 2] : '.';

	int l = 0, r = -1, center, res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		if (i > r) j = 1; 
		else j = min(f[l + r - i], r - i) + 1;
		
		while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
		f[i] = --j;
		if (i + j > r){
			r = i + j;
			l = i - j;
		}
 
		int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
		if (len > res) {
			res = len;
			center = i;
		}
	}
	
	int pos = 0, cnt = 0;
	FOR(i, 1, n - 1) if (f[i] > f[pos]) pos = i;
	FOR(i, pos - f[pos], pos + f[pos]){
		if (a[i] != '.'){
			cout << a[i];	
			cnt++;
		} 
	}

	// cout << cnt;
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
		cin >> s;
		solve();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}