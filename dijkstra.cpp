/*
Dijkstra's Shortest Path Algorithm (C++)

Original source:
GeeksforGeeks - https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

Adapted and annotated by:
Daniel Green

Modifications:
- Renamed variables for clarity (u, v, d)
- Added detailed beginner-friendly comments explaining each step
- Reformatted for educational readability

Purpose:
Personal study implementation to understand Dijkstra's algorithm using a priority queue.
*/

#include <bits/stdc++.h>

using namespace std;

// returns shortest path as a vector. Uses min/heap
vector<int> dijkstra(vector<vector<pair<int,int>>> &adj_list, int src) {
    // vector< vector< pair<int,int> > >
    // pair <Neighbor, Edge_Weight>
    
    // adj[0] = {{1,4}, {2,8}};
    // 1 and 2 are neighbors of 0
    
    int V = adj_list.size();    // number of vertices
    
    // 3 arguments of priority_queue<>:
    
    // 1. Type (using pairs)
    // 2. Container to store elements (in this case using vector of pairs)
    // 3. Compare - determines if max heap (less<...>) or min heap (great<...>)

    // pair : (distance, vertex)
    // EX: pq.emplace(7, 3) means "path from src to vertex 3 with distance of 7"
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> dist(V, INT_MAX);
    
    // distance from source to itself is 0
    dist[src] = 0;
    
    pq.emplace(0, src);
    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();   // pop is void, must use 2 step process
        
        int curr_dist = top.first;  // current distance from source
        int curr_vert = top.second; // current vertex or node
        
        // ignore "outdated" queries
        if (curr_dist > dist[curr_vert])
            continue;
        
        // use reference (&) to update pair, otherwise its a copy
        for (auto &p : adj_list[curr_vert]) {
            int neighbor = p.first;
            int weight = p.second;
            
            // if we find a shorter path to neighbor, update path
            if (dist[curr_vert] + weight < dist[neighbor]) {
                dist[neighbor] = dist[curr_vert] + weight;
                pq.emplace(dist[neighbor],neighbor);
            }
        }
    }
    return dist;
}

int main()
{
    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    vector<int> result = dijkstra(adj, src);

    for (int d : result)
        cout << d << " ";
    cout << "\n";

    return 0;
}
