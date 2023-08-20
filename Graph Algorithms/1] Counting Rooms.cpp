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

// Main Idea = This problem can be solved using depth-first search, breadth-first search or even floodfill.
// We take a two-dimensional boolean array to store all the elements that have been visited. We start at an element which is floor,
// and recursively using depth-first search find all the adjacent floor elements and mark them as visited. While iterating through the
//  map we increement the total count of room by 1, whenever there is a floor which is not visited.

// Time Complexity = O(n x m)
// Space Complexity = O(n x m)

void recur(vector<vector<bool>>& visited, vector<vector<char>>& vec, int i, int j, int n, int m)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    
    if(visited[i][j] == true)
        return;
 
    if(vec[i][j] == '#')
        return;
 
    if(vec[i][j] == '.' && visited[i][j] == false)
    {
        vec[i][j] = '1';
        visited[i][j] = true;
    }
    
    recur(visited, vec, i+1, j, n, m);
    recur(visited, vec, i-1, j, n, m);
    recur(visited, vec, i, j+1, n, m);
    recur(visited, vec, i, j-1, n, m);
}
 
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>> vec(n, vector<char>(m, ' '));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>vec[i][j];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            
            if(vec[i][j] == '.')
            {
                recur(visited, vec, i, j, n, m);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}