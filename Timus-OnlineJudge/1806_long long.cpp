#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#include <unordered_map>

using namespace std;

const int n = 10;
int tm[n]; //время(расстояние) по общему префиксу
vector<vector<pair<int, int>>> g; //граф

const long long pw[11] = {
    1, 10, 100, 1000, 10000, 100000, 
    1000000, 10000000, 100000000, 
    1000000000, 10000000000
};


long long getDigit(long long num, int pos) {
    return (num/pw[pos]) % 10; 
}

void shiftDigit(long long& num, int pos) {
    long long dig = getDigit(num, pos);
    if (dig != 9) {
        num += pw[pos];
    } else {
        num -= pw[pos]*9;
    }
}

void swapDigit(long long& num, int pos1, int pos2) {
    long long dig1 = getDigit(num, pos1);
    long long dig2 = getDigit(num, pos2);
    
    num -= pw[pos1]*dig1;
    num += pw[pos1]*dig2;
    
    num -= pw[pos2]*dig2;
    num += pw[pos2]*dig1;
}


/*
    если мы меняем одну цифру в номере NUM1, или меняем местами
    две любые РАЗНЫЕ цифры и получаем номер NUM2,
    то можно сказать, что в графе между NUM1 и NUM2 есть ребро с 
    весом tm[*длина общего префикса*]
*/
void changeNumber(int v, long long num, unordered_map<long long, int>& m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            
            shiftDigit(num, n-i-1);
            
            if (m.count(num) > 0) {
                g[v].push_back(make_pair(m[num], tm[i]));
            }
        }
        shiftDigit(num, n-i-1);
        
    }
    
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (getDigit(num, n-i-1) != getDigit(num, n-j-1)) {
                swapDigit(num, n-i-1, n-j-1);
                if (m.count(num) > 0) {
                    g[v].push_back(make_pair(m[num], tm[i]));
                }
                swapDigit(num, n-i-1, n-j-1);
            }
        }
    }
}


int main() {
    
    int m; cin >> m;
    unordered_map<long long, int> haveNumber; //привязка номера к индексу в массиве
    long long* v = new long long[m]; //массив номеров
    
    //считваем расстояния от префикса
    for (int i = 0; i < n; ++i) {
        cin >> tm[i];
    }

    //ввод номеров
    for (int i = 0; i < m; ++i) {
        g.push_back(vector<pair<int, int>>());
        cin >> v[i];
        haveNumber[v[i]] = i;
    }

    //заполняем граф
    for (int i = 0; i < m; ++i) {
        changeNumber(i, v[i], haveNumber);
    }
    


/*поиск кратчайшего пути*/
    int* p = new int[m];
    int* dist = new int[m];
    
    for (int i = 0; i < m; ++i) {
        dist[i] = INT_MAX;
        p[i] = -1;
    }
    dist[0] = 0;
    
    
    //алгоритм дейкстры с оптимизацией через set (с e-maxx.ru)
    set<pair<int, int>> q;
    q.insert(make_pair(0, 0));
    
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        
        for (auto j: g[v]) {
            int to = j.first, len = j.second;
            if (dist[v]+len < dist[to]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[v]+len;
                p[to] = v;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
    
    
    /*
        восстанавливаем ответ. 
        answer будет содержать 
        обратную последовательность 
        (от последней вершины к первой)
    */
    vector<int> answer = vector<int>();
    
    for (int cur = m-1; cur != -1; cur = p[cur]) {
        answer.push_back(cur);
    }
    
    //выводим ответ
    if (dist[m-1] == INT_MAX) {
        cout << -1;
    } else {
        cout << dist[m-1] << '\n' << answer.size() << '\n';
        for (int i = int(answer.size()-1); i >-1; --i) {//вывод с конца
            cout << answer[i]+1 << ' ';
        }
    }
    
    return 0;
}
