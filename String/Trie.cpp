// Source : https://cses.fi/problemset/task/1731/
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

string s;
int n, k;

int trie[N][26], node = 1;
int cnt[N];

int dp[N]; // Numbers of way to create substring [i...n]

void add_string(string a){
	int pos = 1;
	for(char x : a){
		int c = x - 'a';
		if (trie[pos][c] == 0) trie[pos][c] = ++node;
		pos = trie[pos][c];
	}
	cnt[pos]++;
}
int search_substring(int x){
	int pos = 1, ans = 0;
	FOR(i, x, n){
		int c = s[i] - 'a';
		if (!trie[pos][c]) return ans;
		pos = trie[pos][c];

		ans = (ans + 1ll * cnt[pos] * dp[i + 1]) % MOD;
	}
	return ans;
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
		cin >> s >> k;
		n = s.size(); s = "#" + s;
		FOR(i, 1, k){
			string tmp; cin >> tmp;
			add_string(tmp);
		}

		dp[n + 1] = 1;
		FORD(x, n, 1) dp[x] = search_substring(x);
		cout << dp[1];
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}