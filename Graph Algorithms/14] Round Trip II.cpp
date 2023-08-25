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
 
// Main Idea = This uses the concept of DFS and stacks. DFS is used to find the round trip, if it exists, and stack is used to store
// the order in which they are travelled.
// In DFS, if we reach the city that is already in the stack then a round trip is possible. Now print the order.

// DFS does not travel through the same city which has already been visited and not present in the stack.
// If we reach the end node for a particular DFS, and that element is not present in the stack, then keep on popping the elements of
// stack till we do a different DFS traversal.
// If at the end we do not find a round trip, then print "IMPOSSIBLE".

// V = number of vertices, and E = number of Edges.
// Time Complexity = O((V + E) + V), DFS + printing the elements of stack.
// Space Complexity = O(V), to store the round trip cities.

stack<int> st;
vector<bool> visited;
vector<bool> instack;
 
bool dfs(vector<vector<int>>& adjmatrix, int node)
{
    visited[node] = true;
    instack[node] = true;
    st.push(node);
    for(auto adjacent : adjmatrix[node])
    {
        if(!visited[adjacent])
        {
            if(dfs(adjmatrix, adjacent))
                return true;
        }
        else if(instack[adjacent])
        {
            st.push(adjacent);
            return true;
        }
    }
    instack[node] = false;
    st.pop();
    return false;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjmatrix(n+1);
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        adjmatrix[a].push_back(b);
    }
    visited.resize(n+1, false);
    instack.resize(n+1, false);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(dfs(adjmatrix, i))
            {
               vector<int> ans;
               int temp = st.top();
               while(!st.empty())
               {
                    ans.push_back(st.top());
                    st.pop();
                    if(ans.back() == temp && ans.size() != 1)
                        break;
               }
               reverse(ans.begin(), ans.end());
               cout<<ans.size()<<endl;
                for(auto it: ans)
                    cout<<it<<" ";
 
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}   