#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
#define mod 1000000007
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
 
// Main Idea = Here we will apply Topo sort. Two topo sorts will be needed, first to prune the graph so that only 1 remains as the
// starting node, and the second one to get the number of ways to reach from 1 to n.
// The variable count defined below, is used to store the number of ways to reach a particular vertex.

// V = number of vertices, E = number of edges
// Time Complexity = O(2 * (V + E))
// Space Complexity = O(V), for the count vector.

// TOPO sort
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> indegree(n+1, 0);
    vector<vector<int>> adjmatrix(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        indegree[b]++;
        adjmatrix[a].push_back(b);
    }
    queue<int> q;
    for(int i=2; i<=n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adjmatrix[node])
        {
            if(it != 1)
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
            else
            {
                indegree[it]--;
            }
        }
    }
    
    q.push(1);
    vector<int> count(n+1, 0);
    count[1] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adjmatrix[node])
        {
            indegree[it]--;
            count[it] = count[it] + count[node];
            count[it] = count[it]%mod;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    cout<<count[n]<<endl;
    return 0;
}   