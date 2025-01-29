#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];

int main() {
    int n, temp, cur = 0;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> temp;

        a[temp] = (a[temp-1]==0?temp-1:a[temp-1]);
        if (temp > cur) {
            cur = temp;
        } else {
            int top = cur;
            while (a[a[cur]] != 0) {
                cur = a[cur];
            }
            a[top] = a[cur]; 
            if (a[cur] > temp) {
                cout << "Cheater";
                return 0;
            }
        }
    }
    cout << "Not a proof";
    return 0;
}
