#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const double Pi = 2 * acos(0.0);

struct point {
    int number;
    long double x, y, angle;
    point(long double _x, long double _y, int n) {
        x = _x;
        y = _y;
        number = n;
        angle = atan2(y, x);
        if (angle < 0) {
            angle += 2*Pi;
        }
    }
    
    long double length() {
        return sqrt(x * x + y * y);
    }
};


bool cmp(point* p1, point* p2) {
    return (
        p1->angle < p2->angle || 
        p1->angle == p2->angle && p1->length() < p2->length()
    
    );
}


int main() {
    int n, tx, ty, sx, sy;
    cin >> n >> sx >> sy;
    cout << n-- << "\n1\n";
    
    vector<point*> ps = vector<point*>();

    for (int i = 1; i <= n; ++i) {
        cin >> tx >> ty;
        ps.push_back(new point(tx-sx, ty-sy, i+1));
    }
    
    sort(ps.begin(), ps.end(), cmp);
    
    int shift = 0;
    double mAngle = ps[0]->angle-(ps[n-1]->angle-2*Pi);
    for (int i = 0; i < n-1; ++i) {
        if (ps[i+1]->angle-ps[i]->angle > mAngle) {
            mAngle = ps[i+1]->angle-ps[i]->angle;
            shift = i+1;
        }
    }
        
    for (int i = 0; i < n; ++i) {
        cout << ps[(i+shift)%n]->number << '\n';
    }
    
    return 0;
}
