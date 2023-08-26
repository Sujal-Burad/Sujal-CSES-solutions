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
 
// Main idea = The fundamental concept involved here is of Dijstras, but we will modify it to get the answers to all the 4 questions.
// If the proposed cost to reach adjacent_node from the parent_node is equal to the current_cost to reach adjacent_node, then 
// we will update the least and most number of flights required to reach adjacent_node, if possible.
// If the proposed cost to reach adjacent_node from the parent_node is less than the current_cost to reach adjacent_node, then it means
// we found a new optimal route. In this case, we will have to update the cost, least and most number of flights required to reach
// adjacent_node and push this cost into the priority queue of Dijkstra.

// E = number of edges, V = number of vertices.
// Time Complexity = O(E.log(V))
// Space Complexity = O(4 * V), to store minimum price, count of minimum-price routes, minimum and maximum number of flights in a 
// minimum-price route.

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, ll>>> adjmatrix(n+1);
    for(int i=0; i<m; i++)
    {
        int a, b; ll c;
        cin>>a>>b>>c;
        adjmatrix[a].push_back({b, c});
    }
    vector<ll> cost(n+1, 1e15);
    cost[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    
    vector<int> min_price_routes(n+1);
    vector<int> min_num_flights(n+1);
    vector<int> max_num_flights(n+1);
    min_price_routes[1] = 1;
    while(!pq.empty())
    {
        int node = pq.top().second;
        ll price = pq.top().first;
        pq.pop();
 
        if(price > cost[node])  continue;
 
        for(auto it : adjmatrix[node])
        {
            ll weight = it.second;
            int adjnode = it.first;
            if(weight + price > cost[adjnode])  continue;
 
            if(weight + price == cost[adjnode])
            {
                min_num_flights[adjnode] = min(min_num_flights[node] + 1, min_num_flights[adjnode]);
                max_num_flights[adjnode] = max(max_num_flights[node] + 1, max_num_flights[adjnode]);
                min_price_routes[adjnode] = min_price_routes[adjnode] + min_price_routes[node];
                min_price_routes[adjnode] = min_price_routes[adjnode] % mod;
            }
 
            if(weight + price < cost[adjnode])
            {
                min_price_routes[adjnode] = min_price_routes[node];
                min_num_flights[adjnode] = min_num_flights[node] + 1;
                max_num_flights[adjnode] = max_num_flights[node] + 1; 
                cost[adjnode] = weight + price;
                pq.push({cost[adjnode], adjnode});
            }
        }
    }
    cout<<cost[n]<<" "<<min_price_routes[n]<<" "<<min_num_flights[n]<<" "<<max_num_flights[n];
    return 0;
}   
