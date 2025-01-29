#include <iostream>

using namespace std;

int main()
{
    int m, n, k;
    cin >> m;
    for (int t = 0; t < m; ++t) {
        cin >> n >> k;
        int d = n/k, ans = 0;
        
        int* team = new int[n];
        for (int i = 0; i < k; ++i) {
            team[i] = d;
            if (i < n%k) {
                ++team[i];
            }
        }
        
        for (int i = 0; i < k-1; ++i) {
            for (int j = i+1; j < k; ++j) {
                ans += team[i]*team[j];
            }
        }
        cout << ans << '\n';
        delete(team);
    }

    return 0;
}
