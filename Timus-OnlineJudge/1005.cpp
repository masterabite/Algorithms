#include <iostream>

using namespace std;

void rec(int* a, int& n, int pos, int s1, int s2, int& ans) {
    if (pos >= n) {
        return;
    }
    
    if (abs(s2-s1) < ans) {
        ans = abs(s2-s1);
    }
    
    rec(a, n, pos + 1, s1 + a[pos], s2 - a[pos], ans);
    rec(a, n, pos + 1, s1, s2, ans);
}

int main()
{
    int n, s = 0, ans = 0;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    ans = s;
    rec (a, n, 0, 0, s, ans);
    cout << ans;
    return 0;
}
