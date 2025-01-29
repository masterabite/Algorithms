#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct sign {
    int num;
    int amo;
    sign(int n, int a) {
        num = n;
        amo = a;
    }
};

bool cmp(sign s1, sign s2) {
    return(s1.amo > s2.amo);
}

void putSign(vector<sign>& v, int pos) {
    if (!v.empty()) {
        cout << v[pos].num << ' ';
        v[pos].amo--;
        if (v[pos].amo == 0) {
            v.erase(v.begin() + pos);
        }
    }
}

int main()
{
    int n, temp;
    cin >> n;
    vector <sign> v = vector<sign>();
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(sign(i+1, temp));    
    }
    
    sort(v.begin(), v.end(), cmp);

    while (!v.empty()) {
        putSign(v, 0);
        putSign(v, int(v.size())-1);
        sort(v.begin(), v.end(), cmp);
    }
    
    return 0;
}
