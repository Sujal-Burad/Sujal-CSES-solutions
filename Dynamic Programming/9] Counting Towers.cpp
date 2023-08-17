#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
#define mod 1000000007

// Main Idea = 
// dp[i][0] = Number of ways to build the tower till ith layer, if the ith layer consists of two tiles of width 1.
// dp[i][0] = dp[i-1][0] + dp[i-1][1] (do not extend the previous layer) + dp[i-1][0] (extend both the tiles of previous layer) +
//            2 * dp[i-1][0] (extend one of the tiles of previous layer and make a new tile for the other layer)
// Therfore, dp[i][0] =  4 * dp[i-1][0] + dp[i-1][1]

// dp[i][1] = Number of ways to build the tower till ith layer, if the ith layer consists of one single tile of width 2.
// dp[i][1] = dp[i-1][0] + dp[i-1][1] (Do not extend the previous layer) + dp[i-1][1] (Extend both the tiles of previous layer)
// Therfore, dp[i][1] = 2 * dp[i-1][1] + dp[i-1][0]

// The final answer is dp[n][0] + dp[n][1], where the last layer can either be 1 tile of width 2 or 2 tiles of width 1.


// Time complexity = O(n)
// Space Complexity = O(n)
int main(){
    fio;
    int test;
    cin>>test;
    while(test--)
    {
       int n; cin>>n;
       ll dp[n+1][2];
       dp[1][0] = 1;
       dp[1][1] = 1;
       for(int i=2; i<=n; i++)
       {
            dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
            dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%mod;
       }
       cout<<(dp[n][0] + dp[n][1])%mod<<endl;
    }
    return 0;
}