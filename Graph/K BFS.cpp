// Source : 
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
const int max_w = 30;

int n, m;
vector<pii> g[N];

int d[N];
bool dd[N];

queue <int> q[max_w + 5];

void process(){
	memset(d, 0x3f, sizeof(d));
	memset(dd, 0, sizeof(dd));
	q[0].push(1); d[1] = 0;

	int pos = 0, num = 1;
	while(num > 0){
		while(q[pos % (max_w + 1)].empty()) ++pos;

		int u = q[pos % (max_w + 1)].front();
		q[pos % (max_w + 1)].pop();
		--num;

		if (dd[u]) continue;
		dd[u] = 1;

		for(const pii& nxt : g[u]){
			int v = nxt.fi, w = nxt.se;
			if (minimize(d[v], d[u] + w)){
				q[d[v] % (max_w + 1)].push(v);
				++num;
			}
		}
	}

	cout << d[n];
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
			int u, v, w; cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
		}

		process();
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}