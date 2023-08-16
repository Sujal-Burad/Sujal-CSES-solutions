#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>

// Main Idea = An empty cell with coordinates (x, y) can be reached either from the left or the top. 
// Create a 2D dp array, where dp[i][j] denotes the number of ways to reach the empty cell at (i, j).
// dp[i][j] = dp[i][j] + dp[i-1][j], reaching from top
// dp[i][j] = dp[i][j] + dp[i][j-1], reaching from left
// The final answer to be printed will be dp[n-1][n-1]

// Time Complexity = O(n^2), to go through every cell
// Space Complexity = O(n^2), to store the 2D dp array.

int main(){
    int n;
    cin>>n;
    vector<vector<long int>> dp(n, vector<long int>(n, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; i++)
    {
        string row;
        cin>>row;
        for(int j=0; j<n; j++)
        {
            if(row[j] == '.')
            {
                if(i>0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007;
                if(j>0)
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
            }
            else
                dp[i][j] = 0;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}
