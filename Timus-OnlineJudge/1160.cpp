#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int col[1001];

struct edge {
    int from, to, weight;
    edge(int f, int t, int w) {
        from = f;to = t;weight = w;
    }
};

bool cmp(edge* e1, edge* e2) {
    return (e1->weight < e2->weight);
}

int main() {
    int s, f, w, n, m;
    vector<edge*> edges = vector<edge*>();
    vector<edge*> answer = vector<edge*>();
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        col[i] = i;
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> f >> s >> w;
        edges.push_back(new edge(f, s, w));
    }
    
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < m; ++i) {
        int col1 = col[edges[i]->from];
        int col2 = col[edges[i]->to];
        if (col1 != col2) {
            answer.push_back(edges[i]);
            for (int j = 1; j <= n; ++j) {
                if (col[j] == col1) {
                    col[j] = col2;
                }
            }
        }
    }
    
    cout << answer[answer.size()-1]->weight << '\n' << answer.size() << '\n';
    for (edge* e: answer) {
        cout << e->from << ' ' << e->to << '\n';
    }

    return 0;
}
