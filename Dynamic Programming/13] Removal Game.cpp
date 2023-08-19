#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
#define mod 1000000007
#include <algorithm>

// Main Idea = 
// dp[i][j] = Stores the maximum possible score for the first player in the index range [i, j]
// After the move of first player, since both of them are playing optimally, the next move of the first player i.e just after the second 
// player's move will include getting the maximum score from the remaining array which will be minimised.
// At each move a player can either choose a card from the beginning or the end, and hence optimally trying to get the maximum score for
// himself and leaving the other player with minimised array.

long long dp[5000][5000];
long long solve(long long arr[], int i, int j)
{
    if(i>j)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    long long x = arr[i] + min(solve(arr, i+2, j), solve(arr, i+1, j-1));
    long long y = arr[j] + min(solve(arr, i, j-2), solve(arr, i+1, j-1));
    
    return dp[i][j] = max(x, y);
}
int main(){
    // Your code here
    int n; cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        long long x; cin>>x;
        arr[i] = x;
    }
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    long long ans  = solve(arr, 0, n-1);
    cout<<ans<<endl;
    return 0;
}