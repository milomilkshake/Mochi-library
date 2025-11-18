// Source : https://oj.vnoi.info/problem/floyd
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
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, q;
ve <pii> g[N];

int d[N], trace[N];

void go(const int& st){
	FOR(i, 1, n) d[i] = inf, trace[i] = -1;
	d[st] = 0; trace[st] = 0;

	priority_queue <pii> pq;
	pq.push(mp(0, st));

	while(!pq.empty()){
		pii cur = pq.top(); pq.pop();
		int u = cur.se; if (-cur.fi > d[u]) continue;
		for(const pair<int,int>& nxt : g[u]){
			int v = nxt.fi, w = nxt.se;
			if (minimize(d[v], d[u] + w)){
				trace[v] = u;
				pq.push(mp(-d[v], v));
			}
		}
	}
}
void query0(int u, int v){
	go(u); cout << d[v] << '\n';
}
void query1(int u, int v){
	go(u); 

	vector <int> path;
	for(; v > 0; v = trace[v]) path.push_back(v);
	reverse(path.begin(), path.end());

	cout << (int) path.size() << " ";
	for(const int& u : path) cout << u << " ";
	cout << '\n';
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
		cin >> n >> m >> q;
		FOR(i, 1, m){
			int u, v, w; cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
		}

		while(q--){
			int t, u, v; cin >> t >> u >> v;

			if (t == 0) query0(u, v);
			else query1(u, v);
		}
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}