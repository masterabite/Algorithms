#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = vector<int>();
 
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        v.push_back(i+1);
    }
    
    for (int i = 0, pos = 0; i < n; ++i) {
        pos = (pos+k-1) % int(v.size());
        cout << v[pos] << ' ';
        v.erase(v.begin() + pos);
    }
    
    return 0;
}
