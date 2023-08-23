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
// #define 1e10 10000000000

// Main idea = This can be solved using Bellman Ford which uses Dijkstra's algorithm's Greedy approach to find shortest path between a given node and
// all other nodes in a graph by traversing all the edges for a node. Using the set method the time needed to complete is further reduced.

// Time Complexity = O(V * E), E = number of edges, V = number of nodes.
// Space Complexity = O(V), V = number of nodes

int main()
{
    // cout<<1e9<<endl;
    ll n, m;   
    cin>>n>>m;
    vector<vector<pair<ll, ll>>> connections(n+1);
    // ll a, b, length;
    for(ll i=1; i<=m; i++)
    {
        ll a, b, length;
        cin>>a>>b>>length;
        connections[a].push_back({b, length});
    }
    ll adjnode, weight;
 
    set<pair<ll, ll>> st;
    vector<ll> dist(n+1, 1e18);
    st.insert({0, 1});
    dist[1] = 0;
    while(!st.empty())
    {
        auto it = *(st.begin());
        ll node = it.second;
        ll dis = it.first;
        st.erase(it);
        for(ll i = 0; i<connections[node].size(); i++)
        {
            adjnode = connections[node][i].first;
            weight = connections[node][i].second;
            if(dis + weight < dist[adjnode])
            {
                if(dist[adjnode] != 1e9)
                    st.erase({dist[adjnode], adjnode});
                
                dist[adjnode] = dis + weight;
                st.insert({dist[adjnode], adjnode});
            }
        }
    }
    for(ll i=1; i<=n; i++)
        cout<<dist[i]<<" ";
    
   return 0;
}