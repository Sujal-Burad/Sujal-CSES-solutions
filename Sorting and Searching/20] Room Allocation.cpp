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

// Main Idea = Sort the customers in ascending order according to their arrival time. Maintain a priority queue to store the 
// departure time of the customers already processed, and also their room number.
// For each customer find the element in priority queue with the least departure time that is less than the present customer's arrival
// time. If such an element is found, then assign the current customer that room and update the element in priority queue.

// If no such element is found, it means all the rooms are full and we will need to allocate another room to the current customer.
// ALso, push this new room no. and the departure time into the priority queue.

// Time Complexity = O(n.logn), sorting and to insert elements into the priority queue.
// Space Complexity = O(n), to store the room id of each customer.

int main()
{
    int n; cin>>n;
    vector<pair<pair<int, int>, int>> vec;
    for(int i=0; i<n; i++)
    {
        int a, b; cin>>a>>b;
        vec.push_back({{a, b}, i});
    }
    sort(vec.begin(), vec.end());
    vector<int> room(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int roomid = 1;
    for(int i=0; i<n; i++)
    {
        if(pq.size() == 0)
        {
            room[vec[i].second] = roomid++;
            pq.push({vec[i].first.second, roomid-1});
        }
        else
        {
             if(vec[i].first.first > pq.top().first)
            {
                room[vec[i].second] = pq.top().second;
                pair<int, int> t = pq.top();
                pq.pop();
                pq.push({vec[i].first.second, t.second});
            }
            else
            {
                room[vec[i].second] = roomid++;
                pq.push({vec[i].first.second, roomid-1});
            }
        }
    }
    cout<<roomid-1<<endl;
    for(int i=0; i<n; i++)
        cout<<room[i]<<" ";
    return 0;
}