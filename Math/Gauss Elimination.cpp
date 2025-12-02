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

const int N = 100 + 5;
const int LG = 17;
const ll INF = 1e17 + 7;
const int inf = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-9;

int n, m;
double a[N][N];

int where[N];
double ans[N];

int gauss(){
    FOR(i, 1, m) where[i] = -1;

    for(int col = 1, row = 1; col <= m && row <= n; col++){
        int e = row;
        FOR(i, row + 1, n) if (abs(a[i][col]) > abs(a[e][col])) e = i; 
        // chọn phương trình e có abs(a[e][col]) lớn nhất

        if (abs(a[e][col]) < eps) continue;
        // tất cả các hệ số a[e][col] đều bằng 0
        // => ẩn x[col] là ẩn tự do
        // chuyển sang khử x[col + 1]
        
        swap(a[e], a[row]); // chuyển phương trình e lên đầu
        where[col] = row; // ẩn x[col] được khử bởi phương trình đang ở vị trí row

        /* chuyển hệ số a[row][col] về 1 */
        double tmp = a[row][col];
        FOR(i, 1, m + 1) a[row][i] /= tmp;

        /* khử hệ số a[i][col] ở toàn bộ n - 1 phương trình còn lại */
        FOR(i, 1, n) if (i != row){
            double c = a[i][col];
            FOR(j, col, m + 1) a[i][j] -= a[row][j] * c;
            // chỉ cần for từ col tại vì 
            // a[row][p] (p < col) đã bằng 0 
        }

        row++; // phương trình ở vị trí row đã được sử dụng
    }

    FOR(i, 1, m) ans[i] = 0; // gán tất cả các ẩn ban đầu 0
    FOR(i, 1, m) if (where[i] != -1) ans[i] = a[where[i]][m + 1]; 
    // nếu x[i] không phải ẩn tự do thì x[i] = b[where[i]]

    /* Thử lại */
    FOR(i, 1, n){
        double sum = 0;
        FOR(j, 1, m) sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m + 1]) > eps) return 0; // sum != b[i]
    }

    FOR(i, 1, m) if (where[i] == -1) return 2;
    // nếu có ít nhất 1 ẩn tự do thì hệ có vô số nghiệm
    return 1;
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
        FOR(i, 1, n) FOR(j, 1, m + 1) cin >> a[i][j];

        gauss();

        cout << setprecision(15) << fixed;
        FOR(j, 1, m) cout << ans[j] << el;
	}

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}