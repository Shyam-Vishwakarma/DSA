#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // Infinity value

// Pair: {distance, node}
typedef pair<int, int> pii;

void dijkstra(int src, int n, vector<vector<pii>>& adj) {
    vector<int> dist(n, INF); // Distance from source to each node
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if already found a shorter path
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances from source
    for (int i = 0; i < n; ++i) {
        cout << "Distance from node " << src << " to node " << i << " is ";
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pii>> adj(n); // Adjacency list

    // Example graph: undirected with weighted edges
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    // If undirected, also add reverse edges:
    adj[1].push_back({0, 4});
    adj[2].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[3].push_back({1, 1});
    adj[3].push_back({2, 5});
    adj[4].push_back({3, 3});

    int source = 0;
    dijkstra(source, n, adj);

    return 0;
}
// This code implements Dijkstra's algorithm to find the shortest paths from a source node
// to all other nodes in a weighted graph represented as an adjacency list.
// It uses a priority queue to efficiently get the next node with the smallest distance.
// The graph is undirected, and edges can be added in both directions.
// The output shows the shortest distance from the source node to each node in the graph.
// The algorithm runs in O((V + E) log V) time, where V is the number of vertices and E is the number of edges.