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
 
// Main idea = Since we have to find minimum number of computers on valid route, we can use BFS.
// Initially, let the parent of every node be "-1". For printing the route we will need to update the parent of current node. 
// If the parent[n] = -1, then it is IMPOSSIBLE to reach given computer.
// Else start from n and push the parent of every nodes into a stack, and then print st.top() and pop the topmost element, keep repeating
// this till the stack is empty.

// Time Complexity = O(V + E), V = number of vertices, E = number of edges
// Space Complexity = O(V), we will have to go through every vertex in the worst case.

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    // int adj[n+1][n+1] = {0};
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1, -1);
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty())
    {
        int frnt = q.front();
        q.pop();
        for(auto it : adj[frnt])
        {
            if(!visited[it])
            {
                visited[it] = true;
                parent[it] = frnt;
                q.push(it);
            }
        }
    }
 
    if(parent[n] == -1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    else
    {
        int ans = n;
        stack<int> st;
        while(ans != -1)
        {
            st.push(ans);
            ans = parent[ans];
        }
        cout<<st.size()<<endl;
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    return 0;
}