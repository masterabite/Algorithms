#include <iostream>
#include <algorithm>

using namespace std;

int strNum[100000];

char* decrypt(int k, string str) {
    
    int n = int(str.size());
    string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
    
    int p = 0;
    for (char& c: symbols) {
        for (int i = 0; i < n; ++i) {
            if (str[i] == c) {
                strNum[i] = p++; 
            }    
        }
    }
    
    char* answer = new char[n];
    
    for (int i = 0, cur = k; i < n; ++i) {
        answer[n-i-1] = str[cur];
        cur = strNum[cur]; 
    }
    return answer;
}

int main() {
    
    int k;
    string str;
    
    cin >> k >> str;
    char* ans = decrypt(--k, str);
    for (int i = 0; i < int(str.size()); ++i) {
        cout << ans[i];
    }
    return 0;
}
