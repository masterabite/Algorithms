#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, set<int>> mono;

struct point {
    int x, y;
    
    point() {
        cin >> x >> y;
    }
    
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct line {
    point s, f;
    int len;
    
    line(point p1, point p2) {
        s = p1;
        f = p2;
        if (p1.x == p2.x) {
            len = p2.y-p1.y-1;
        } else {
            len = p2.x-p1.x-1;
        }
    }
};

bool cmp1(point p1, point p2) {
    if (p1.y < p2.y) {
        return true;
    } else if (p1.y == p2.y) {
        return (p1.x < p2.x);
    }
    return false;
}

bool cmp2(point p1, point p2) {
    if (p1.x < p2.x) {
        return true;
    } else if (p1.x == p2.x) {
        return (p1.y < p2.y);
    }
    return false;
}

int main() {
    
    vector<point> ps = vector<point>();
    int n, m, k, tx, ty;
    int answer = 0;
    cin >> m >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        ps.push_back(point(0, i));
        ps.push_back(point(m+1, i));
    }
    for (int i = 1; i <= m; ++i) {
        ps.push_back(point(i, 0));
        ps.push_back(point(i, n+1));
    }
    
    
    for (int i = 0; i < k; ++i) {
        ps.push_back(point());
    }
    
    k+=2*n+2*m;
    
    sort(ps.begin(), ps.end(), cmp1);
    for (int pi = 1; pi < k; ++pi) {
        while (pi < k && ps[pi].y == ps[pi-1].y) {
            while (pi < k && ps[pi].y == ps[pi-1].y && ps[pi-1].x == ps[pi].x+1) {
                ++pi;
            }
            if (pi < k && ps[pi].y == ps[pi-1].y) {
    
                line l = line(ps[pi-1], ps[pi]);
                if (l.len == 1) {
                    int 
                        lx = (l.s.x+l.f.x)/2,
                        ly = (l.s.y+l.f.y)/2;
                    
                    auto f = mono.find(lx);
                    if (f == mono.end()) {
                        mono.insert(make_pair(lx, set<int>()));  
                        f = mono.find(lx);
                    }
                    f->second.insert(ly);
                } else if (l.len > 1) {
                    ++answer;
                }
            }
            ++pi;
        }
    }

    sort(ps.begin(), ps.end(), cmp2);
    for (int pi = 1; pi < k; ++pi) {
        while (pi < k && ps[pi].x == ps[pi-1].x) {
            while (pi < k && ps[pi].x == ps[pi-1].x && ps[pi-1].y == ps[pi].y+1) {
                ++pi;
            }
            if (pi < k && ps[pi].x == ps[pi-1].x) {
    
                line l = line(ps[pi-1], ps[pi]);
                if (l.len == 1) {
                    int 
                        lx = (l.s.x+l.f.x)/2,
                        ly = (l.s.y+l.f.y)/2;
                        
                    auto f = mono.find(lx);
                    if (f == mono.end()) {
                        mono.insert(make_pair(lx, set<int>()));  
                        f = mono.find(lx);
                    }
                    auto ff = f->second.find(ly);
                    if (ff == f->second.end()) {
                        f->second.insert(ly);
                    } else {
                        if (lx != 0 && ly != 0) {
                            ++answer;
                        }
                    }
                } else if (l.len > 1) {
                    ++answer;
                }
            }
            ++pi;
        }
    }
    
    cout << answer;
    
    return 0;
}
