#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int from, to, weight;
    edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
    void print() {
        cout <<  ":(" << from+1 << "->" << to+1 << ")=" << weight << ' ';
    }
};

int main() {
    int n, m, tf, tt, tw, s, f;
    cin >> n >> m;
    
    vector <edge*> edges = vector<edge*>();
    
    for (int i = 0; i < m; ++i) {
        cin >> tf >> tt >> tw;
        --tf; --tt;
        edges.push_back(new edge(tf, tt, tw));
    }
    
    cin >> s >> f;
    --s; --f;
    
    int dist[500];
    for (int i = 0; i < n; ++i) {
       dist[i] = -1; 
    }
    dist[s] = 0;
    
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[edges[j]->from] > -1) {
                dist[edges[j]->to] = max(dist[edges[j]->to], dist[edges[j]->from] + edges[j]->weight);
            }
        }
    }
    if (dist[f] != -1) {
        cout << dist[f];
    } else {
        cout << "No solution";
    }
    return 0;
}
