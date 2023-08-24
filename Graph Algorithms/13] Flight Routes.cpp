#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
 
// Main Idea = Use combination of Dijkstra's algorithm and sorting technique. If the distance in Dijsktra is better than the kth
// cheapest route, update the distance array's corresponding kth element and sort it, so that kth element will still be the worst
// cheapest route.

// Time Complexity = O(E.log(V).log(k)), E = number of edges, V = number of Vertices.
// Space Complexity = O(n.k), to store the final answer.

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>> adjmatrix(n+1);
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adjmatrix[a].push_back({b, c});
    }
    vector<vector<ll>> distance(n+1, vector<ll>(k, 1e17));
    priority_queue<pair<ll, int>, 
    vector<pair<ll, int>>, 
    greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    distance[1][0] = 0;
 
    while(!pq.empty())
    {
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        if(distance[node][k-1] < d) continue;
  
        for(auto it : adjmatrix[node])
        {
            int adjnode = it.first;
            ll edgeweight = it.second;
            if(distance[adjnode][k-1] > edgeweight + d)
            {
                distance[adjnode][k-1] = edgeweight + d;
                pq.push({distance[adjnode][k-1], adjnode});
                sort(distance[adjnode].begin(), distance[adjnode].end());
            }
        }
    }
    for(int i=0; i<k; i++)
        cout<<distance[n][i]<<" ";
    return 0;
}   