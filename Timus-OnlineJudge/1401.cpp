#include <iostream>

using namespace std;

int a[513][513];
int cur = 1;

struct point {
    int x, y;

    point() {
        x = 1;
        y = 1;
    }
    
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct square {
  point p1, p2, p3, p4;  
  int size;
  
  square(point _p1, point _p4) {
      p1 = _p1;
      p4 = _p4;
      p2 = point(p1.x, p4.y);
      p3 = point(_p4.x, p1.y);
      size = p4.x-p1.x+1;
  }
  
  bool havePoint(point p) {
      return (p.x >= p1.x && p.x <= p4.x && p.y >= p1.y && p.y <= p4.y);
  }
 
};

void rec(square s, point p0) {
    int size = s.size;

    square lu = square(s.p1, point(s.p1.x+size/2-1,s.p1.y+size/2-1));
    square ru = square(point(s.p1.x, s.p1.y+size/2), point(s.p1.x+size/2-1, s.p1.y+size-1));
    square ld = square(point(s.p1.x+size/2, s.p1.y), point(s.p1.x+size-1, s.p1.y+size/2-1));
    square rd = square(point(s.p1.x+size/2, s.p1.y+size/2), point(s.p1.x+size-1, s.p1.y+size-1));
    
    if (size == 1) {
        a[s.p1.x][s.p1.y] = cur;
    } else {
        
        (lu.havePoint(p0)?rec(lu, p0):rec(lu, lu.p4)); 
        (ru.havePoint(p0)?rec(ru, p0):rec(ru, ru.p3)); 
        (ld.havePoint(p0)?rec(ld, p0):rec(ld, ld.p2)); 
        (rd.havePoint(p0)?rec(rd, p0):rec(rd, rd.p1)); 
            
        if (!lu.havePoint(p0)) a[lu.p4.x][lu.p4.y] = cur;
        if (!ru.havePoint(p0)) a[ru.p3.x][ru.p3.y] = cur;
        if (!ld.havePoint(p0)) a[ld.p2.x][ld.p2.y] = cur;
        if (!rd.havePoint(p0)) a[rd.p1.x][rd.p1.y] = cur;
        ++cur;
    }
}

int main() {
    int n;
    long long f = 1;
    point p;
    cin >> n >> p.x >> p.y;
    for (int i = 0; i < n; ++i) {
        f *= 2;
    }
    
    square s = square(point(1, 1), point(f, f));
    rec(s, p);
    a[p.x][p.y] = 0;
    
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= f; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
