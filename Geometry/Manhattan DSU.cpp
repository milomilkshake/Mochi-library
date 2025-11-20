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

template <typename T>
vector<tuple<T, int, int>> manhattan_mst(vector<T> xs, vector<T> ys) {
	const int n = xs.size();
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0); // fill idx from 0, increasing by one each iteration
	vector<tuple<T, int, int>> ret;
	for (int s = 0; s < 2; s++) {
		for (int t = 0; t < 2; t++) {
			auto cmp = [&](int i, int j) { return xs[i] + ys[i] < xs[j] + ys[j]; };
			sort(idx.begin(), idx.end(), cmp);
			map<T, int> sweep;
			for (int i : idx) {
				for (auto it = sweep.lower_bound(-ys[i]); it != sweep.end(); it = sweep.erase(it)) {
					int j = it->second;
					if (xs[i] - xs[j] < ys[i] - ys[j]) break;
					ret.emplace_back(abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]), i, j);
				}
				sweep[-ys[i]] = i;
			}
			swap(xs, ys);
		}
		for (auto &x : xs) x = -x;
	}
	sort(ret.begin(), ret.end());
	return ret;
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
		
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}