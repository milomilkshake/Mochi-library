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

namespace Standard_GCD{

	const int N = 5000;
	int savedGCD[N + 5][N + 5];

	void build(){
		FOR(i, 0, N) savedGCD[i][0] = i;
		FOR(i, 1, N)
			for(int j = i; j <= N; j += i) 
			for(int k = i; k <= j; k += i)
				savedGCD[j][k] = i;
	}

	int gcd(int a, int b){
	    while(1){
	    	if (a == 0 || b == 0 || a == b)
	    		return a | b;
	    	if (a <= N && b <= N)
	    		return savedGCD[max(a, b)][min(a, b)];
	    	if (a > b) a %= b; else b %= a;
	    }
	}
}

namespace Extended_Euclid{
	// Tìm 1 cặp nghiệm (x, y) của phương trình ax + by = gcd(a, b)
	// Giả sử kết quả trả về là (x0, y0), họ nghiệm của phương trình sẽ là (x_0+kb/d,y_0-ka/d) với k∈Z.
	// Phương trình tổng quát ax + by = d chỉ có nghiệm khi d chia hết cho gcd(a, b).
	pii euclid(int a, int b){
        if (!b) return make_pair(1, 0);
        pii r = euclid(b, a % b);
        return mp(r.se, r.fi - a / b * r.se);
    }
    void solve(int n, int a, int b){ // ax + by = n
		auto [x, y] = euclid(a, b);
		int g = ax + by;
		assert(n % g != 0); // VÔ NGHIỆM

		a /= g; b /= g; n /= g;
		x = x * n; y = y * n;
		
		// Non-negative x and y
		if(x < 0){
			int k = (-x + b - 1)/b;
			x += k * b;
			y -= k * a;
		}
		if(y < 0){
			int k = (y - a + 1) / a;
			x += k * b;
			y -= k * a;
		}

		assert(x < 0 || y < 0); //VÔ NGHIỆM
		
		// Smallest x + y
		int x1 = x % b;
		int y1 = y + x/b * a;
		int y2 = y % a;
		int x2 = x + y/a * b;

		if (x1 + y1 < x2 + y2){
			// x1 + y1 is smaller
		}
		else{
			// x2 + y2 is smaller
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
		
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}