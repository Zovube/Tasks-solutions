#include<bits/stdc++.h>
using namespace std;

using ld = long double;

struct point {
    ld x, y;

    point() {}

    point(ld a, ld b) : x(a), y(b) {}
};

struct line {
    ld A, B, C;

    line() {}

    line(point a, point b) {
        this->A = (b.y - a.y);
        this->B = -(b.x - a.x);
        this->C = -(this->A * a.x + this->B * a.y);
    }

    point get_per(point a) {
        ld norm_dist = (A * a.x + B * a.y + C) / (A * A + B * B);
		return point(a.x - norm_dist * A, a.y - norm_dist * B);
    }

};

ld dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool ok(point a, point b, point c) {
	return a.x >= min(b.x, c.x) && a.x <= max(b.x, c.x) && a.y >= min(b.y, c.y) && a.y <= max(b.y, c.y);
}

int main() {
    point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    ld L;
    cin >> L;

    line l(A, B);
    
    ld dist_A_C = dist(A, C) - L;
    ld dist_B_C = dist(B, C) - L;

    ld dist_l_C = dist(l.get_per(C), C) - L;
	if(!ok(l.get_per(C), A, B)) 
		dist_l_C = dist_A_C;    

	cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);
	
	point X = l.get_per(C);

	//cout << X.x << ' ' << X.y << endl;
	//cout << l.A << ' ' << l.B << ' ' << l.C << endl;
	//cout << dist_A_C << ' ' << dist_B_C << ' ' << dist_l_C << endl;

    cout << max((ld)0, min(min(dist_A_C, dist_B_C), dist_l_C)) << endl;
    cout << max((ld)0, max(max(dist_A_C, dist_B_C), dist_l_C)) << endl;
    
    return 0;
}
