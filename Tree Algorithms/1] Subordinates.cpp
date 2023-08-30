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
 
// Main Idea = It uses the concept of recursion and DFS to find the number of subordinates of a particular employee.

// V = number of vertices, E = number of Edges
// Time Complexity = O(V + E)
// Space Complexity = O(V), to store the final answer in an array.

int recur(int node, vector<int>& final, vector<vector<int>>& adjmatrix)
{
    if(adjmatrix[node].size() == 0)
    {
        return 1;
    }
    else 
    {
        for(int i=0; i<adjmatrix[node].size(); i++)
        {
            final[node] += recur(adjmatrix[node][i], final, adjmatrix);
        }
    }
    return final[node] + 1;
}
int main()
{
    int n;
    cin>>n;
    vector<int> final(n+1);
    vector<vector<int>> adjmatrix(n+1);
    for(int i=2; i<=n; i++)
    {
        int boss; cin>>boss;
        adjmatrix[boss].push_back(i);
    } 
    int ans = recur(1, final, adjmatrix);   
    for(int i=1; i<final.size(); i++)
        cout<<final[i]<<" ";
    return 0;
}