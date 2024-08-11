#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<vector<pair<int,int>>>& graph, vector<int>& dist, int source) {
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it: graph[x.second]) {
            if (dist[it.first] > dist[x.second] + it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
}

void display(int source, vector<int>& dist, int n) {
    for (int i = 1; i <= n; i++) {
        if (dist[i] < INT_MAX)
            cout << "Distance from " << source << " to " << i << ": " << dist[i] << endl;
        else
            cout << -1 << " ";
    }
    cout << endl;
}

int main () {
    int n, e, source;
    cout << "enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<pair<int, int>>> graph(n+1);
    vector<int> dist(n+1, INT_MAX);
    for (int i = 0; i < e; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << "Enter source node: ";
    cin >> source;
    dijkstra(graph, dist, source);
    display (source, dist, n);
}