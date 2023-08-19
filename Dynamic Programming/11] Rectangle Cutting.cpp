#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
#define mod 1000000007
#include <algorithm>
 
// Main Idea =
// dp[i][j] = Minimum number of cuts needed to cut a (i x j) piece into square.
// If (i == j), then it's already a square and hence no cut will be required.
// A horizontal cut can be made at 1, 2, ... i - 1. A vertical cut can be made at 1, 2, ..., j - 1.
// If we make a horizontal cut at row, then we are left with two pieces of size (row x j) and ((i - row) x j).
// We can look up the number of moves to reduce these to squares in the dp array. 
// We loop over all possibilities row and take the best one. Similarly for vertical cuts.

// Time Complexity = O(a^2.b + a.b^2)
// Space Complexity = O(a.b), for storing dp array.

int main(){
    int a, b;
    cin>>a>>b;
    int dp[a+1][b+1];
    for(int row = 1; row<=a; row++)
    {
        for(int col = 1; col<=b; col++)
        {
            if(row == col)
                dp[row][col] = 0;
            else
            {
                int ans = INT_MAX;
                for(int i=1; i<row; i++)
                    ans = min(ans, 1 + dp[i][col] + dp[row-i][col]);
                for(int j=1; j<col; j++)
                    ans = min(ans, 1 + dp[row][j] + dp[row][col-j]);
                
                dp[row][col] = ans;
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}