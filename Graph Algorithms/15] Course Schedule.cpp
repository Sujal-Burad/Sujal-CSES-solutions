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
 
// Main Idea = This questions is a classical example of Topological sort and finding cycle in the graph.
// The topo sort is used to find the order in which to complete the courses. 
// This will fail in the case of presence of cycle in the graph, where the two tasks are interdependent on each other.

// V = number of vertices, E = number of edges
// Time Complexity = O((V + E) + V), Topo sort + printing the order of courses 
// Space Complexity = O(V), to store the courses' order.

stack<int> st;
vector<bool> visited;
vector<bool> instack;
 
int flag = 0;
void topo(vector<int> adjmatrix[], stack<int>& st, vector<bool>& visited, int node, vector<bool>& instack)
{
    visited[node] = true;
    // instack[node] = true;
    for(auto it : adjmatrix[node])
    {
        if(!visited[it])
            topo(adjmatrix, st, visited, it, instack);
        
        else if(visited[it] && instack[it] == false)
        {
            flag = 1;
            return;
        }
    }   
    instack[node] = true;
    st.push(node);
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adjmatrix[n+1];
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        adjmatrix[a].push_back(b);
    }
    stack<int> st;
    vector<bool> visited(n+1, false);
    vector<bool> instack(n+1, false);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
            topo(adjmatrix, st, visited, i, instack);
    }
    if(st.empty() == true || flag == 1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}