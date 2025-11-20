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

const long double eps = 1e-9;
int sign(long double x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}

struct Point{ // Can be used as vector
    long double x, y;

    Point(long double x = 0, long double y = 0): x(x), y(y) {};
    
    friend istream &operator >> (istream &in, Point &A) {
		return in >> A.x >> A.y;
	}

    long double dot(const Point& other)const{
        return x * other.x + y * other.y;
    }

    long double cross(const Point& other)const{
        return x * other.y - other.x * y;
    }

    Point operator+ (const Point &a)const{
        return Point(x + a.x, y + a.y);
    }

    Point operator- (const Point &a)const{
        return Point(x - a.x, y - a.y);
    }

    Point operator* (const Point &a)const{
        return Point(x * a.x, y * a.y);
    }

    Point operator/ (const Point &a)const{
        if(a.x == 0.0 or a.y == 0.0) throw invalid_argument("Mau so bang 0");
        return Point(x / a.x, y / a.y);
    }

    long double length()const{
        return sqrtl(x * x + y * y);
    }

    bool operator< (const Point& a)const{
        if(abs(x - a.x) < eps) return y < a.y;
        return x < a.x;
    }

    bool operator> (const Point& a)const{
        if(abs(x - a.x) < eps) return y > a.y;
        return x > a.x;
    }

    bool operator== (const Point& a)const{
        return abs(x - a.x) < eps && abs(y - a.y) < eps;
    }
};

long double ccw(const Point &A, const Point &B, const Point &C) {
    return (long double) (B - A).cross(C - A);
}

struct Line {
    long double a, b, c; // ax + by + c = 0
    void normalize(){
    	if(a < 0) a = -a, b = -b, c = -c;
    	else if(a == 0 && b < 0) b = -b, c = -c;
    }
    Line (long double _a = 0, long double _b = 0, long double _c = 0) : a(_a), b(_b), c(_c) {
    	normalize();
    }
	Line (const Point &A, const Point &B) : a(B.y - A.y), b(A.x - B.x), c(B.x * A.y - A.x * B.y) {
		normalize();
	}
	bool operator< (const Line& o)const{
		if(abs(a - o.a) < eps){
			if(abs(b - o.b) < eps) return c < o.c;
			return b < o.b;
		}
		return a < o.a;
	}
};

Line make_right (const Point &M, const Line &d) {
    return Line(d.b, -d.a, d.a * M.y - d.b * M.x);
}

Line make_paral (const Point &M, const Line &d) {
    return Line(d.a, d.b, -d.b * M.y - d.a * M.x);
}

long double distance (const Point &A, const Point &B) {
	return sqrtl(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

long double distance (const Point &M, const Line &d) {
    return abs(d.a * M.x + d.b * M.y + d.c) / sqrtl(pow(d.a, 2) + pow(d.b, 2));
}
long double distance (const Point &A, const Point &B, const Point &M){ // Distance between point M and segment AB
	long double dist = distance(M, Line(A, B));
	if((A - B).dot(M - B) < 0) return distance(M, B);
	if((B - A).dot(M - A) < 0) return distance(M, A);
	return dist;	
}

long double distance (const Line &d1, const Line &d2) {
    if (d1.b == 0 || d2.b == 0) return abs(1.0 * d1.c / d1.a - 1.0 * d2.c / d2.a);
    long double x = 0;
    long double y = (-1.0 * d1.c - 1.0 * x * d1.a) / d1.b;
    return distance(Point(x, y), d2);
}

Point projection(Line L, Point x){ // hinh chieu
    long double k = (L.a * x.x + L.b * x.y + L.c) / (L.a * L.a + L.b * L.b);
    return Point(x.x - L.a * k, x.y - L.b * k);
}

Point intersect (const Line &d1, const Line &d2) {
    long double D = 1.0 * d1.a * d2.b - 1.0 * d2.a * d1.b;
    long double Dx = 1.0 * d1.b * d2.c - 1.0 * d2.b * d1.c;
    long double Dy = 1.0 * d1.c * d2.a - 1.0 * d2.c * d1.a;
    return Point((long double) Dx / D, (long double) Dy / D);
}

bool intersect (Point A, Point B, Point C, Point D) { // check if AB intersects CD
    int ABxAC = sign((B - A).cross(C - A));
    int ABxAD = sign((B - A).cross(D - A));
    int CDxCA = sign((D - C).cross(A - C));
    int CDxCB = sign((D - C).cross(B - C));
    if (ABxAC == 0 || ABxAD == 0 || CDxCA == 0 || CDxCB == 0) {
		if (ABxAC == 0 && sign((A - C).dot(B - C)) <= 0) return true;
		if (ABxAD == 0 && sign((A - D).dot(B - D)) <= 0) return true;
		if (CDxCA == 0 && sign((C - A).dot(D - A)) <= 0) return true;
		if (CDxCB == 0 && sign((C - B).dot(D - B)) <= 0) return true;
        return false;
    }
    return (ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0);
}

bool perpendicular(const Line &d1, const Line &d2){
    Point v1 = d1.b - d1.a;
    Point v2 = d2.b - d2.a;
    return v1.dot(v2) == 0;
}

Point Rotations(Point A, Point C, long double rad) { // rotate A around C by an angle rad
    Point A2 = A - C;
    Point B2 = Point(A2.x * cos(rad) - A2.y * sin(rad), A2.x * sin(rad) + A2.y * cos(rad));
    Point B = B2 + C;
    return B;
}

void ConvexSort(vector <Point>& p){
	if(p.size() < 3) throw invalid_argument("Size of vector point < 3");

    sort(p.begin(), p.end(), [&](const Point &A, const Point &B) {
		if(abs(A.y - B.y) < eps) return A.x < B.x;
    	return A.y < B.y;
    });

    sort(p.begin() + 1, p.end(), [&](const Point &A, const Point &B) {
    	if(abs(ccw(p[0], A, B)) < eps) return distance(p[0], A) < distance(p[0], B);
    	return ccw(p[0], A, B) > 0;
    });
}

vector <Point> buildConvexHull (vector <Point> p) {
	ConvexSort(p);
	int n = p.size();
    
    vector <Point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    
    p.push_back(p[0]);
    for (int i(2); i <= n; ++i) {
        while ((int)hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i]) <= 0) { // < 0: lay cac diem thang hang
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    
    hull.pop_back();
    
    return hull;
}

// remember to use ConvexSort(p) before calling these:
long double PolygonArea(const vector <Point> &p) {
	long double res = 0;
	for(int i(0); i < (int) p.size(); i++){
		int j = (i + 1) % int(p.size());
		res += (long double) (p[j].x + p[i].x) * (p[j].y - p[i].y);
	}
	return res / 2.0;
}

long double distance(const Point &A, const vector <Point> &p) {
	long double res = 1e18;
	for(int i(0); i < (int) p.size(); i++){
		int j = (i + 1) % int(p.size());
		res = min(res, distance(p[i], p[j], A));
	}
	return res;
}

bool PointInPolygon(const vector <Point> &p, const Point &A){
	int cnt = 0;
	for(int i(0); i < (int) p.size(); i++){
		int j = (i + 1) % int(p.size());
		if(abs(ccw(p[i],A,p[j])) < eps) return 1; // check constraints on problem's statement if it allows point on segments
		if(p[i].x <= A.x && A.x < p[j].x && ccw(A,p[i],p[j]) < 0) cnt++;
        else if(p[j].x <= A.x && A.x < p[i].x && ccw(A,p[j],p[i]) < 0) cnt++;
	}
	return cnt & 1;
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