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
 
// Main Idea = This can be solved using concept of dfs and backtracking. 
// 1] We add the node to a vector named "path" if it is not visited.
// 2] While doing dfs if we encounter that a node has already been visited and the path size > 2, then we have found a round trip
// that begins in a city, goes through two or more other cities, and finally return to the starting city. Print the solution.
// 3] If while doing dfs we reach a node who has no neighbours other than its parent node and is not equal to the starting city, then a 
// round trip is not possible and hence remove this city from "path". (Backtracking).
// 4] Do not apply dfs to the cities that have already been visited.
// Continously iterate till we encounter 2]. If we have visited all the nodes and 2] does not satisfy, then no round trip exists and hence
// print "IMPOSSIBLE".

// Time Complexity = O(V + E), V = number of veritces, E = number of edges
// Space Complexity = O(V), array to store the round trip answer.

class RoundTrip{
public:
    bool found = false;
    void run()
    {
        takeinput();
        findcycle();
        if(!found)
            cout<<"IMPOSSIBLE"<<endl;
        // printoutput();
    }
    int n, m;
    vector<vector<int>> adj;
 
    void takeinput()
    {
        cin>>n>>m;
        adj = vector<vector<int>>(n+1);
        for(int i=0; i<m; i++)
        {
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
 
    vector<bool> visited;
    void findcycle()
    {
        visited.resize(n+1, false);
        for(int i=1; i<=n; i++)
        {
            if(visited[i] == true)
                continue;
            vector<int> path;
            dfs(i, -1, path);
        }
    }
 
    void dfs(int node, int parent, vector<int>& path)
    {
        if(found)
            return;
        if(visited[node])
        {
            if(path.size() > 2)
                printoutput(node, path);
            return;
        }
        visited[node] = true;
        path.push_back(node);
        for(auto it : adj[node])
        {
            if(it == parent)
                continue;
            
            dfs(it, node, path);
        }
        path.pop_back();
    }
 
    void printoutput(int node, vector<int> path)
    {
        found = true;
        int count = 1;
        vector<int> final;
        final.push_back(node);
        for(int i=path.size() - 1; i>=0; i--)
        {
            count++;
            final.push_back(path[i]);
            if(path[i] == node)
                break;
        }
        cout<<count<<endl;
        for(auto it:final)
            cout<<it<<" ";
    }
};
 
int main()
{
    RoundTrip rt;
    rt.run();
    return 0;
}
