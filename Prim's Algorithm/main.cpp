#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Edge {
public:
    int dest;
    int weight;
};

void primMST(int n, vector<vector<Edge>>& adj) {
    vector<bool> visited(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (auto& edge : adj[u]) {
            int v = edge.dest;
            int w = edge.weight;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<Edge>> adj(n);

    cout << "Enter the edges (u v w):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    primMST(n, adj);
}
