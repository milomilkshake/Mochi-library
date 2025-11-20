// Source : https://cses.fi/problemset/task/2106
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

int n;
string s;
 
int sa[N], pos[N], tmp[N];
int lcp[N];
int gap;

bool cmp(int i, int j){
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += gap; j += gap;
	return i <= n && j <= n ? pos[i] < pos[j] : i > j;
}
void build(){
	FOR(i, 1, n) sa[i] = i, pos[i] = s[i];
	for(gap = 1; ; gap <<= 1){
		sort(sa + 1, sa + n + 1, cmp);
 
		tmp[1] = 1;
		FOR(i, 2, n) tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
		FOR(i, 1, n) pos[sa[i]] = tmp[i];
 
		if (tmp[n] == n) break;
	}
 
	int k = 0;
	FOR(i, 1, n) if (pos[i] != n){
		int j = sa[pos[i] + 1];
		while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
        lcp[pos[i]] = k; if (k > 0) k--;
	}
}
void solve(void){
	build();
 
	int ans = 0, res = 0;
	FOR(i, 1, n - 1) if (maximize(ans, lcp[i])) res = sa[i];
 
	if (ans == 0) return cout << -1, void();	
	FOR(i, 0, ans - 1) cout << s[res + i];	
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
		n = s.size(); s = "#" + s;
	 
		solve();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}