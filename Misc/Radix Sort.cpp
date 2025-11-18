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

// Handle up to 2^31 - 1 intergers, doesnt handle negative number
void radix_sort(vi& arr) {
    const int FULL_MASK = MASK(16) - 1;
    auto get1 = [] (int x) { return x & FULL_MASK; };
    auto get2 = [] (int x) { return x >> 16; };

    vi cnt1(MASK(16), 0);  
    vi cnt2(MASK(16), 0);  
    for(const int& x : arr){
        cnt1[get1(x)]++;
        cnt2[get2(x)]++;
    }

    partial_sum(ALL(cnt1), cnt1.begin());
    partial_sum(ALL(cnt2), cnt2.begin());

    int n = arr.size();
    vi tmp(n);
    FORD(i, n - 1, 0) tmp[--cnt1[get1(arr[i])]] = arr[i];
    FORD(i, n - 1, 0) arr[--cnt2[get2(tmp[i])]] = tmp[i];
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
		int n; cin >> n;
		vi a(n);
		REP(i, n) cin >> a[i];
		
		radix_sort(a);
		REP(i, n) cout << a[i] << " ";
	} 

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}