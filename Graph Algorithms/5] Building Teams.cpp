#include<bits/stdc++.h>
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
 
// Main Idea = This question is an example of Bipartite graph. We can do it by using either dfs or bfs. I have done using dfs.
// Mark the root starting node for traversal as 1. 
// If a node has color 1, then all its neighbours should have the color 2.
// If a node has color 2, then all its neighbours should have the color 1.
// While assigning the colors if a neighbour has already been colored and has the same color as the parent node, then graph cannot be Bipartite.
// If the neighbour has already been colored and has the color different than that of the parent node, continue, and keep on doing dfs.

// Time complexity = O(V + E), V = number of vertices, E = number of edges.
// Space complexity = O(V), to store the array for group of each vertex.

void setFastInputOutput() {
    cin.tie(nullptr)->sync_with_stdio(false);
}
 
class BuildingTeams {
public:
    void run() {
        readInput();
        dividePupilsIntoTwoGroups();
        printResult();
    }
 
    int n, m;
    vector<vector<int>> adj;
    void readInput() {
        cin >> n >> m;
        adj = vector<vector<int>>(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }   
 
    vector<int> group;
    bool isPossible = true;
    void dividePupilsIntoTwoGroups() {
        group = vector<int>(n+1);
        for (int i = 1; i < n + 1 && isPossible; i++)
            isPossible = dfs(i, 0);
    }
    bool dfs(int node, int prevGroup) {
        if (group[node] != 0)
            return group[node] != prevGroup;
 
        group[node] = prevGroup == 1 ? 2 : 1;
        for (auto child: adj[node])
            if (!dfs(child, group[node]))
                return false;
        return true;
    }
 
    void printResult() {
        if (!isPossible) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        for (int i = 1; i < n + 1; i++)
            cout << group[i] << " ";
    }
};
 
 
int main() {
    setFastInputOutput();
    BuildingTeams solver;
    solver.run();
    return 0;
}