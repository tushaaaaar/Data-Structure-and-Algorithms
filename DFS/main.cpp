#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void BFS (vector <vector <int>>& adj, int start, int nodes) {
    vector <int> visited(nodes, false);
    stack <int> st;
    st.push(start);
    visited[start] = true;

    while(!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";
        for (int v: adj[u]) {
            if (!visited[v]) {
                st.push(v);
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
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    cout << "BFS traversal in above graph: " << endl;
    BFS (adj, source, nodes);
}