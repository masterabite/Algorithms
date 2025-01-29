#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const double Pi = 2 * acos(0.0), eps = 1e-9;

struct point {
    int number;
    long double x, y, angle;
    point(long double _x, long double _y, int n) {
        x = _x;
        y = _y;
        number = n;
        angle = 0;
    }
    
    long double length()const {
        return sqrt(x * x + y * y);
    }
    
    bool operator<(point* s) {
        return (x < s->x || (x == s->x && y < s->y));
    }
    
    void println() {
        cout << "(" << x << "; " << y << ")  L " << angle << '\n';
    }
};

long double pMult(point* p1, point* p2) {
    return p1->x*p2->x+p1->y*p2->y;
}

point* getVector(point* p1, point* p2) {
    return new point(p2->x-p1->x, p2->y-p1->y, p1->number);
}

long double getAngle(point* p1, point* p2) {
    
    long double answer = acos(pMult(p1, p2)/(p1->length()*p2->length()));

    if (p1->x < 0) {
        answer += Pi/2;
    }
    
    return answer;
}

bool cmp(point* p1, point* p2) {
    return (p1->angle > p2->angle);
}


int main() {
    int n, tx, ty;
    vector <point*> ps = vector<point*>();
    
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> tx >> ty;
        ps.push_back(new point(tx, ty, i+1));
        if (i > 0 && *ps[i] < ps[0]) {
            swap(ps[0], ps[i]);
        }
    }
    
    point* Oy = new point(0, 5, -1);
    
    for (int i = 1; i < n; ++i) {
        ps[i]->angle = getAngle(getVector(ps[0], ps[i]), Oy);
    }
    
    sort(ps.begin()+1, ps.end(), cmp);

    cout << ps[0]->number << ' ' << ps[n/2]->number;
    return 0;
}
