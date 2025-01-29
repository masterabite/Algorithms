#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& g, int v, int c, int* col) {
    col[v] = c;
    
    for (int i = 0; i < int(g[v].size()); ++i) {
        if (col[g[v][i]] != -1) {
            if (col[g[v][i]] != ((c+1)%2)) {
                return false;
            }
        } else {
            if (!dfs(g, g[v][i], ((c+1)%2), col)) {
                return false;
            }
        }
    } 
    return true;
}

int main() {
    
    int n;
    cin >> n;
    
    vector<vector<int>> g = vector<vector<int>>();
    int* color = new int[n];
    
    //РёРЅРёС†РёР°Р»РёР·РёСЂСѓРµРј РіСЂР°С„
    for (int i = 0; i < n; ++i) {
        color[i] = -1;
        g.push_back(vector<int>());
    }
    
    //СЃС‡РёС‚С‹РІР°РµРј РіСЂР°С„
    for (int i = 0; i < n; ++i) {
        int temp;
        while (true) {
            cin >> temp;
            if (temp == 0) {
                break;
            }
            g[i].push_back(temp-1);
            g[temp-1].push_back(i); 
        }
    } 

    
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!dfs(g, i, 0, color)) {
                cout << -1;
                delete(color);
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << color[i];
    }

    delete(color);
    return 0;
}
