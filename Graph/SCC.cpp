// Source : https://oj.vnoi.info/problem/tjalg
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

const int N = 1e2 + 5;
const int N2 = 1e4 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m;
char a[N][N];
int val[N2];

inline int getID(const int& i, const int& j){
	return (i - 1) * m + j;
}
inline bool valid(const int& i, const int& j){
	if (a[i][j] == '#') return 0;
	return (1 <= i && i <= n && 1 <= j && j <= m);
}

vi g[N2], G[N2];

void input(){
	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m){
		cin >> a[i][j];
		val[getID(i, j)] = ('0' <= a[i][j] && a[i][j] <= '9') ? a[i][j] - '0' : 0;
	}
	FOR(i, 1, n) FOR(j, 1, m) if (valid(i, j)){
		if (valid(i + 1, j)) g[getID(i, j)].pb(getID(i + 1, j));
		if (valid(i, j + 1)) g[getID(i, j)].pb(getID(i, j + 1));

		if (a[i][j] == 'W' && valid(i, j - 1)) g[getID(i, j)].pb(getID(i, j - 1));
		if (a[i][j] == 'N' && valid(i - 1, j)) g[getID(i, j)].pb(getID(i - 1, j));
	}
}

int root[N2], low[N2], num[N2], total[N2];
bool del[N2];
int timeDfs = 0, scc = 0;
stack <int> st;

int dp[N2];

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
		++scc;

		while(1){
			int v = st.top(); st.pop();
			del[v] = 1; root[v] = scc;
			total[scc] += val[v];
			if (v == u) break;
		}
	}
}
int dfs2(int u){
	if (G[u].empty()) return total[u];
	if (dp[u] != -1) return dp[u];

	int& cur = dp[u]; cur = -inf; 
	for(const int& v : G[u]) maximize(cur, dfs2(v) + total[u]);
	return dp[u];
}
void solve(){
	FOR(i, 1, n) FOR(j, 1, m) if (valid(i, j) && !del[getID(i, j)])
		dfs(getID(i, j));

	FOR(i, 1, n) FOR(j, 1, m) if (valid(i, j)){
		int u = getID(i, j);
		for(const int& v : g[u]) if (root[u] != root[v])
			G[root[u]].pb(root[v]);
	} 

	memset(dp, -1, sizeof(dp));
	cout << dfs2(root[getID(1, 1)]);
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
		input(); solve();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}