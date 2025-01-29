#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, sum = 0, ans = 0;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (sum < 0) {
            sum = 0;
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}
