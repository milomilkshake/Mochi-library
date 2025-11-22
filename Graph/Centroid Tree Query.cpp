// Source : https://www.spoj.com/problems/QTREE5/
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

int n, q, col[N];
vi g[N];

pii rmq[2 * N][LG + 1];
int lg[2 * N];
int st[N], h[N];

int par[N], sz[N];
bool del[N];

multiset<int> s[N];

int timedfs = 0;
void dfs(int u = 1, int p = 0){
    rmq[++timedfs][0] = make_pair(h[u], u);
    st[u] = timedfs;

    for(const int& v : g[u]) if (v != p){
        h[v] = h[u] + 1;
        dfs(v, u);
    } 

    if (p != 0) rmq[++timedfs][0] = make_pair(h[p], p);
}
void build_rmq(){
    FOR(i, 2, 2 * n - 1) lg[i] = lg[i / 2] + 1;
    FOR(j, 1, LG) FOR(i, 1, 2 * n - MASK(j))
        rmq[i][j] = min(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);
}
int dist(int u, int v){
    int l = st[u], r = st[v];
    if (l > r) swap(l, r);

    int k = lg[r - l + 1];
    int lca = min(rmq[l][k], rmq[r - (1 << k) + 1][k]).second;

    return h[u] + h[v] - 2 * h[lca];
}

int calcsz(int u, int p) {
    sz[u] = 1;
    for(const int& v : g[u]) if(v != p && !del[v])
        sz[u] += calcsz(v, u);
    return sz[u];
}
int centroid(int u, int p, int SZ) {
    for(const int& v : g[u]) if(v != p && !del[v])
        if (sz[v] > SZ / 2) return centroid(v, u, SZ);
    return u;
}
int build(int u = 1){
    int SZ = calcsz(u, 0);
    u = centroid(u, 0, SZ);

    del[u] = 1;
    for(const int& v : g[u]) if (!del[v]){
        int x = build(v);
        par[x] = u;
    }
    return u;
}

void solve(){
	dfs(); build_rmq();

	build();

	cin >> q;
	FOR(i, 1, n) col[i] = 1;
	while(q--){
		int t, u; cin >> t >> u;
		if (t == 0){
			int p = u; col[u] ^= 1;
			if (col[u]){
                while(p){
                    s[p].erase(s[p].lower_bound(dist(u, p)));
                    p = par[p];
                }
            } else{
                while(p){
                    s[p].insert(dist(u, p));
                    p = par[p];
                }
            }
		} else{
			int ans = inf, p = u;
            while(p){
                if (s[p].size()) ans = min(ans, dist(u, p) + *s[p].begin());
                p = par[p];
            }
            if (ans >= inf) cout << -1 << el;
            else cout << ans << el;
		}
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
		cin >> n;
		FOR(i, 1, n - 1){
			int u, v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		} 
		solve();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}