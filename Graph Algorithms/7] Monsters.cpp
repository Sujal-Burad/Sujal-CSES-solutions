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

// Main idea = This problem involves using BFS.
// 1] Using BFS find the minimum number of steps taken by the monster to reach a particular floor in the map.
// 2] To reach the boundary cell one has to taken total steps < minimum number of steps taken by the monsters to reach that particular boundary
// cell. So, we will again use BFS to find the minimum number of steps taken to reach the boundary cell.
// 3] Also, store the directions for a particular cell.

int main()
{              //L, R, U, D
    int dx[4] = {0, 0, -1, +1};
    int dy[4] = {-1, +1, 0, 0};
    int n, m;
    cin>>n>>m;
    vector<vector<char>> labyrinth(n+1, vector<char>(m+1, ' '));
    vector<pair<int, int>> startA;
    vector<pair<int, int>> startmonster;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>labyrinth[i][j];
            if(labyrinth[i][j] == 'A')
            {
                startA.push_back({i, j});
            }
            if(labyrinth[i][j] == 'M')
            {
                startmonster.push_back({i, j});
            }
        }
    }
    queue<vector<int>> q;
    for(int i=0; i<startmonster.size(); i++)
        q.push({startmonster[i].first, startmonster[i].second, 0});
    
    vector<vector<int>> monstdist(n+1, vector<int>(m+1, -1));
 
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr[0];
        int y = curr[1];
        int steps = curr[2];
        if(x<0 || y<0 || x>=n || y>=m || labyrinth[x][y] == '#' || monstdist[x][y] != -1)   continue;
 
        monstdist[x][y] = steps;
        for(int i=0; i<4; i++)
            q.push({x+dx[i], y+dy[i], steps + 1});
    }
 
    string ans;
    while(!q.empty()) q.pop();
 
    q.push({startA[0].first, startA[0].second, 0, 0});
    vector<vector<int>> Adist(n+1, vector<int>(m+1, -1));
    vector<vector<int>> path(n+1, (vector<int>(m+1, 0)));
    bool condition = false;
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr[0];
        int y = curr[1];
        int steps = curr[2];
        int dir = curr[3];
        if(x<0 || y<0 || x>=n || y>=m || labyrinth[x][y] == '#' || Adist[x][y] != -1 || (monstdist[x][y] >=0  && monstdist[x][y] <= steps)) continue;
 
        if(x==n-1 || x==0 || y==m-1 || y==0)
        {
            path[x][y] = dir;
            while(x!= startA[0].first || y!=startA[0].second)
            {
                if(path[x][y] == 0) ans+='L', y++;
                if(path[x][y] == 1) ans+='R', y--;
                if(path[x][y] == 2) ans+='U', x++;
                if(path[x][y] == 3) ans+='D', x--;
            }
            reverse(ans.begin(), ans.end());
            condition = true;
            break;
        }
        if(condition == true)
            break;
        
        path[x][y] = dir;
        Adist[x][y] = steps;
        for(int i=0; i<4; i++)
        {
            q.push({x+dx[i], y+dy[i], steps+1, i});
        }
    }
    if(condition)
    {
        cout<<"YES"<<endl<<ans.size()<<endl<<ans<<endl;
    }
    else
        cout<<"NO"<<endl;
 
   return 0;
}