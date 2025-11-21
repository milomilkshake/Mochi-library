// Source : https://oj.vnoi.info/problem/twosat
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
vi g[N];

int num[N], low[N], root[N];
bool del[N];
stack <int> st;

int getID(int x){
	return (x < 0) ? m-x : x;
}

int timeDfs = 0, scc = 0;
void dfs(int u){
	num[u] = low[u] = ++timeDfs;
	st.push(u);

	for(const int& v : g[u]) if (!del[v]){
		if (num[v]) minimize(low[u], num[v]);
		else{
			dfs(v);
			minimize(low[u], low[v]);
		}
	}

	if (num[u] == low[u]){
		scc++;

		while(1){
			int v = st.top(); st.pop();
			del[v] = 1; root[v] = scc;
			if (v == u) break;
		}
	}
}
void solve(void){
	FORD(i, m, -m) if (i != 0){
		int u = getID(i);
		if (!num[u]) dfs(u);
	}	
	
	FOR(i, 1, m){
		int u = getID(i), uu = getID(-i);
		if (root[u] == root[uu]) return cout << "NO", void();
	}

	cout << "YES" << el;
	
	vi ans;
	FOR(i, 1, m){
		int u = getID(i), uu = getID(-i);
		if (root[u] < root[uu]) ans.pb(u);
	}
	cout << (int) ans.size() << el;
	for(const int& v : ans) cout << v << " ";
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
		FOR(i, 1, n){
			int u, v; cin >> u >> v;
			g[getID(-u)].pb(getID(v));
			g[getID(-v)].pb(getID(u));
		}
		solve();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}