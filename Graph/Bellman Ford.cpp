// Source : https://cses.fi/problemset/task/1197
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

const int N = 5e3 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m;
struct edge{
	int u, v, w;
	edge(int _u = 0, int _v = 0, int _w = 0): u(_u), v(_v), w(_w) {}
} e[N];

int trace[N];
ll d[N];

void process(){
	memset(d, 0x3f, sizeof(d)); d[1] = 0;
	memset(trace, -1, sizeof(trace));
	
	int negstart = -1;
	FOR(T, 1, n) FOR(i, 1, m){
		auto [u, v, w] = e[i];
		if (minimize(d[v], d[u] + w)){
			trace[v] = u;
			if (T == n) negstart = v;
		}
	}
	
	if (negstart == -1){
		cout << "NO"; return;
	} 
	
	cout << "YES" << el;

	int u = negstart;
	vi cycle;
	FOR(T, 1, n) u = trace[u];
	for(int v = u; ; v = trace[v]){
		cycle.pb(v);
		if (v == u && (int) cycle.size() > 1) break;
	}
	
	reverse(ALL(cycle));
	for(const int& v : cycle) cout << v << " ";
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
		FOR(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;

		process();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}