// Source : https://oj.vnoi.info/problem/graph_
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

int n, m;
vector <int> g[N];

int low[N], num[N], timedfs = 0;
bool bridge[N], joint[N];

void dfs(int u, int par){
	low[u] = num[u] = ++timedfs;
	int cnt = 0;

	for(const int& v : g[u]) if (v != par){
		if (num[v]) low[u] = min(low[u], num[v]);
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);

			if (num[v] == low[v]) bridge[v] = 1;
			if (low[v] >= num[u]) cnt++;
		}
	}

	if (par == 0) cnt--;
	if (cnt > 0) joint[u] = 1;
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
		cin >> n >> m;
		FOR(i, 1, m){
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		FOR(i, 1, n) if (!num[i]) dfs(i, 0);
		
		int ans1 = 0, ans2 = 0;
		FOR(i, 1, n){
			ans1 += bridge[i];
			ans2 += joint[i];
		}

		cout << ans2 << " " << ans1;
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}