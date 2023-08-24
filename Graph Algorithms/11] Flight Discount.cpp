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
 
// Main Idea = Use Dijkstra and make two distance arrays to track whether discount has been used or not.
// with_discount[i] = represents shortest distance from start node to node i, after using the discount.
// without_discount[i] = represents shortest distance form start node to node i, without using the distance.

// Time Complexity = O(E.log(V)), E = number of edges, V = number of vertices
// Space Complexity = O(2*V), to store the two distance arrays.

int main()
{
    ll n, m;
    cin>>n>>m;
    // a->b, price of flight
    vector<vector<pair<int, int>>> flight(n+1);
    for(ll i=0; i<m; i++)
    {
        ll a, b, price;
        cin>>a>>b>>price;
        flight[a].push_back({b, price});
    }
    vector<ll> with_discount(n+1, 1e17);
    vector<ll> without_discount(n+1, 1e17);;
    
    with_discount[1] = 0;
    without_discount[1] = 0;
    // bool coupon_used = false;
    
    // {cost, {layover stop, coupon_used}};
    priority_queue<pair<ll, pair<ll, bool>>, vector<pair<ll, pair<ll, bool>>>, greater<pair<ll, pair<ll, bool>>>> pq;
 
    pq.push({0, {1, false}});
 
    while(!pq.empty())
    {
        ll cost = pq.top().first;
        ll layover = pq.top().second.first;
        bool coupon_used = pq.top().second.second;
        pq.pop();
 
        if(coupon_used == true)
            if(with_discount[layover] < cost)
                continue;
        if(coupon_used == false)
            if(without_discount[layover] < cost)
                continue;
        
        for(auto e : flight[layover])
        {
            ll vertex = e.first;
            ll price = e.second;
            if(coupon_used == false)
            {
                if(without_discount[vertex] > price + cost)
                {
                    without_discount[vertex] = price + cost;
                    pq.push({without_discount[vertex], {vertex, false}});
                }
                if(with_discount[vertex] > price/2 + cost)
                {
                    with_discount[vertex] = price/2 + cost;
                    pq.push({with_discount[vertex], {vertex, true}});
                }
            }
            else
            {
                if(with_discount[vertex] > price + cost)
                {
                    with_discount[vertex] = price + cost;
                    pq.push({with_discount[vertex], {vertex, true}});
                }
            }
        }
    }
    cout<<with_discount[n]<<endl;
    return 0;
}   