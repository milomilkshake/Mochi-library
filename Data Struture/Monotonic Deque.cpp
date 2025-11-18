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

template <class T> struct Deque{
    T a[2 * N + 5];
    int fr = N + 1, ba = N;
    void push_back(T u){ a[++ba] = u; }
    void pop_back(){ ba--; }
    void push_front(T u){ a[--fr] = u; }
    void pop_front(){ fr++; }
    T front(){ return a[fr]; }
    T back(){ return a[ba]; }
    int size(){ return ba - fr + 1; }
    bool empty(){ return size() == 0; }
    void clear(){ fr = N + 1; ba = N; }
};

int n, k, a[N];

vi minInRange(const int& k){
	vi ans(n - k + 2, inf);

	Deque <int> dq;
	FOR(i, 1, n){
		while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push_back(i);

		while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
		if (i >= k) ans[i - k + 1] = a[dq.front()];
	}	

	return ans;
}	

vector<pii> RangeOfMin(){
	vector <pii> ans(n + 1, {0, 0});

	stack <int> st;
	FOR(i, 1, n){
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		ans[i].fi = 1 + (st.empty() ? 0 : st.top());  
		st.push(i);
	}

	while(!st.empty()) st.pop();
	FORD(i, n, 1){
		while(!st.empty() && a[st.top()] >= a[i]) st.pop();
		ans[i].se = (st.empty() ? n + 1 : st.top()) - 1;
		st.push(i);
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
		cin >> n >> k;
		FOR(i, 1, n) cin >> a[i];

		// vi tmp = minInRange(k);
		// FOR(i, 1, n - k + 1) cout << tmp[i] << " ";

		vector<pii> tmp = RangeOfMin();
		FOR(i, 1, n) cout << tmp[i].fi << " " << tmp[i].se << el;
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}