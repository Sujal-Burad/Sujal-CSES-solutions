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
 
// Main Idea = Since we have to find the shortest path from A to B, we can use the concept of BFS(Breadth first search).
// We also have to print the path, so we will have to store the directions taken at every point.
// We will use a 2D array to store the path. Let's say we are currently at (a, b) and if (a, b - 1) is valid then path[a][b - 1] = 'L'.
// Similarly, we can do it for 'R', 'U' and 'D'.
// When we reach 'B', we should traverse back in the reverse order to reach and push the corresponding direction in final answer i.e if
// path[a][b] = 'L' then we should move to [a][b + 1], and so on till we reach 'A'.

// Time Complexity = O(n x m)
// Space Complexity = O(n x m)

int n, m;
char labyrinth[1001][1001];
bool visited[1001][1001];
char path[1001][1001];
vector<char> final;
int flag = 0;

bool isvalid(int a, int b)
{
    if(a<0 || b<0 || a>=n || b>=m || visited[a][b] == true
        || labyrinth[a][b] == '#')
        return false;
    
    return true;
}
int main()
{
    cin>>n>>m;
    int startx, starty;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>labyrinth[i][j];
            if(labyrinth[i][j] == 'A')
            {
                startx = i;
                starty = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({startx, starty});
    visited[startx][starty] = true;
    while(!q.empty())
    {
        int size = q.size();
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(labyrinth[a][b] == 'B')
        {
            while(1)
            {
                final.push_back(path[a][b]);
                if(final.back() == 'L')  b++;
                if(final.back() == 'R')  b--;
                if(final.back() == 'U')  a++;
                if(final.back() == 'D')  a--;
 
                if(a == startx && b== starty)
                    break;
            }
            flag = 1;
            break;
        }
        if(flag == 1)
            break;
        if(isvalid(a, b-1))
        {
            q.push({a, b-1});
            visited[a][b-1] = true;
            path[a][b-1] = 'L';
        }
        if(isvalid(a, b+1))
        {
            q.push({a, b+1});
            visited[a][b+1] = true;
            path[a][b+1] = 'R';
        }
        if(isvalid(a+1, b))
        {
            q.push({a+1, b});
            visited[a+1][b] = true;
            path[a+1][b] = 'D';
        }
        if(isvalid(a-1, b))
        {
            q.push({a-1, b});
            visited[a-1][b] = true;
            path[a-1][b] = 'U';
        }
    }
 
    if(flag == 0)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<final.size()<<endl;
        while(!final.empty())
        {
            cout<<final.back();
            final.pop_back();
        }
    }
   return 0;
}