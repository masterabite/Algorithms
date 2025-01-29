#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    
    long long answer = 0, ways = n;
    ways *= (n-1);
    
    int* ax = new int[n]; 
    int* ay = new int[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> ax[i] >> ay[i];
    }
    
    sort(ax, ax + n);
    sort(ay, ay + n);
    
    for (int i = 1; i < n; ++i) {
        long long d = (ax[i]-ax[i-1] + ay[i]-ay[i-1]);
        d *= i;
        d *= (n-i) * 2;
        answer += d;
    }
    
    cout << answer/ways << '\n';
    
    return 0;
}
