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

// Main Idea = This uses Floyd Marshall algorithm which computes shortest path between every pair of verices in the graph.

// Time Complexity = O(V^3), V = number of vertices.
// Space Complexity = O(V^2), To store the adjacency matrix. V = number of vertices.

int main()
{
 
    int n, m; 
    int q;   
    cin>>n>>m; 
    cin>>q;
    vector<pair<int, int>> queries;
    vector<vector<ll>> matrix(n+1, vector<ll>(n+1, 1e18));
    for(int i=1; i<=m; i++)
    {
        ll a, b, length;
        cin>>a>>b>>length;
        matrix[a][b] = min(matrix[a][b], length);
        matrix[b][a] = min(matrix[b][a], length);
    }
    for(int i=1; i<=q; i++)
    {
        int q1, q2;
        cin>>q1>>q2;
        queries.push_back({q1, q2});
    }
    for(int i=1; i<=n; i++)
        matrix[i][i] = 0;
    
    for(int x = 1; x<=n; x++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][x] + matrix[x][j]);
                // cout<<matrix[i][j]<<" ";
            }
        }
    }
    for(int i=0; i<q; i++)
    {
 
        if(matrix[queries[i].first][queries[i].second] == 1e18)
            cout<<"-1"<<endl;
        else
            cout<<matrix[queries[i].first][queries[i].second]<<endl;
    }
    
   return 0;
}
