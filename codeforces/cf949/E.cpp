
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>


using namespace std;

// Swap consecutive inversion elements one at a time.
// Because let's say that the element is out of order, and the second element is actually in the last spot.
// Then we have a situation where we need to swap to get there... 4312 <=> 2310, which swaps consecutive first, and in preferential order of index.

const int MAX_N = 1e5 + 10;

typedef long long ll;
typedef tuple<int,int,int> iii;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

const ll MOD = 1e9 + 7;
inline ll mod(ll x, ll m = MOD) {
    return ((x % m) + m) % m;
}

typedef pair<int,int> pii;
 
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, int E, int edges[][3])
{   
    // Create an adjacency list representation of the graph
    vector<vector<int>> adj[V];
     
    // Fill the adjacency list with edges and their weights
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
     
    // Create a priority queue to store edges with their weights
    priority_queue<pii, vector<pii>, greater<pii>> pq;
     
    // Create a visited array to keep track of visited vertices
    vector<bool> visited(V, false);
     
    // Variable to store the result (sum of edge weights)
    int res = 0;
     
    // Start with vertex 0
    pq.push({0, 0});
     
    // Perform Prim's algorithm to find the Minimum Spanning Tree
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
         
        int wt = p.first;  // Weight of the edge
        int u = p.second;  // Vertex connected to the edge
         
        if(visited[u] == true){
            continue;  // Skip if the vertex is already visited
        }
         
        res += wt;  // Add the edge weight to the result
        visited[u] = true;  // Mark the vertex as visited
         
        // Explore the adjacent vertices
        for(auto v : adj[u]){
            // v[0] represents the vertex and v[1] represents the edge weight
            if(visited[v[0]] == false){
                pq.push({v[1], v[0]});  // Add the adjacent edge to the priority queue
            }
        }
    }

    for (auto v : visited) {
        if (!v) return -1;
    }

    return res;  // Return the sum of edge weights of the Minimum Spanning Tree
}

int ch[MAX_N];

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    ll t;
    cin >> t;

    while (t--) {
        int n = 0;
        cin >> n;

        int graph[][3] = {};

        int edges = 0;

        // too slow, need optimisation
 
        // Function call
        cout << spanningTree(n, edges, graph) << '\n';

    } 

}