#include <bits/stdc++.h>
using namespace std; 
#define MAXN 202020

// Main Idea = The main idea here is to use DFS (Depth First Search). Start from a node and visit all its children and mark them as visited.
// If all the cities were interconnected to each other, then all of them would be marked as visited in one go.
// Else some cities will be left out, and these cities are the one for which a new road has to be made to connect them.

// Time complexity = O(n + m)
// Space complexity = O(1), to store the cities which are not connected.

int n, m;
vector<vector<int>>adj(MAXN);
vector<bool>visited(MAXN, false);
vector<int>bridges;
 
void DFS (int node) {
  visited[node] = true;
  for (auto child : adj[node]) {
    if (visited[child] == false) {
      DFS(child);
    }
  }
}
 
int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        bridges.push_back(i);
        DFS(i);
      }
    }
    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
      cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
    return 0;
}