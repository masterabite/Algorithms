#include <iostream>
#include <vector>

using namespace std;

//структура обмена валюты (курс, комиссия)
struct ex{
    double r, c;
    
    ex() {
        r = 0;
        c = 0;
    }
    
    void scan() {
        cin >> r >> c;
    }
    
    //функция обмена (меняем a ед. первой валюты)
    double change(double a) {
        //возвращает единицы во второй валюте
        return (a-c)*r;
    }
};

//структура ребра
struct edge {
    int from, to;
    ex weight;
    
    edge(int f, int t, ex w) {
        from = f;
        to = t;
        weight = w;
    }
};



int main() {
    int n, m, s;
    double money;
    cin >> n >> m >> s >> money;

    vector <edge*> edges = vector<edge*>(); //массив всех ребер
    
    int vf, vt;
    ex e1, e2;
    for (int i = 0; i < m; ++i) {
        cin >> vf >> vt;
        e1.scan();e2.scan();
        edges.push_back(new edge(vf-1, vt-1, e1));
        edges.push_back(new edge(vt-1, vf-1, e2));
    }

    double dist[100];
    for (int i = 0; i < n; ++i) {
       dist[i] = -1; 
    }
    dist[s-1] = money;
    
    for (int i = 0; i < n; ++i) {
        for (edge* e: edges) {
            if (dist[e->from] > 0) {
                if (dist[e->to] < e->weight.change(dist[e->from])) {
                    /*
                    если на n-ой итерации изменяются веса, то 
                    есть положительный цикл, следовательно, ответ на задачу- ДА
                    */
                    if (i == n-1 && dist[e->to] != -1) {
                        cout << "YES";
                        return 0;
                    } else {
                       dist[e->to] = e->weight.change(dist[e->from]);
                    }
                }
            }
        }
    }

    //если полож. цикл не найден
    cout << "NO";
    return 0;
}
