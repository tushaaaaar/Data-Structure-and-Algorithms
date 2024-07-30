#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS (vector <vector <int>>& adj, int start, int nodes) {
    vector <int> visited(nodes, false);
    queue <int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v: adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

int main () {
    int source, nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter start node: ";
    cin >> source;

    vector <vector <int>> adj(nodes);
    
    cout << "Enter adjacency list: " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "BFS traversal in above graph: " << endl;
    BFS (adj, source, nodes);
}