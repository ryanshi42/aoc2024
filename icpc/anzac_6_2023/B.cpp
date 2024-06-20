#include <bits/stdc++.h>
using namespace std;



#define INF 999999;

void floyd_warshall(int dist[][], int nv) {
    
}

int main() {
    // input
    nv, ns << cin;
    int graph[nv][nv] = {INF};
    // Hashmap to list of symbols
    int symbols[ns];


    std::map<int, std::list<int> > my_map;

    

    for (int i = 0; i < nv; i++) {        
        int s, t;
        cin >> s >> t;

        my_map[s].push_back(nv);
        my_map[t].push_back(nv);
    }
    
    
    
    
    for (int i = 0; i < nv; i++) {
        graph[i][i] = 0;
    }
    floyd_warshall(graph);

    for 
}