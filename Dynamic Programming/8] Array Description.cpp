#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

// Main Idea : 
// dp[i][x] = number of ways to fill the array up to index i, if v[i] = x
// dp[0][x] = 1 for every value of x, including x = 0, since x = 0 can take any value and x = v implies that only 1 value is allowed.
// For other indices, i > 0. If v[i] = 0, we can replace it by any value. But it can take a particular value x only if its previous
// value is either x - 1, x, or x + 1. Thus, the number of ways to fill the array up to i, is the sum of the previous values being
// x - 1, x, or x + 1. 
// If v[i] = x, then only dp[i][x] is allowed.
// Still, dp[i][x] = dp[i][x - 1] + dp[i][x] + dp[i][x + 1].
// The final answer is the summation of dp[n][x], for all x upto m.

// Time Complexity = O(n.m)
// Space Complexity = O(n.m)

int solve(int n, int m, vector<int>& v)
{
    int dp[n+2][m+2];
    memset(dp, 0, sizeof dp);
 
    for(int i = 1; i <= n; i++)
    {
        for(int x = 1; x <= m; x++)
        {
            if(i == 1)
            {
                if(v[i] == 0 || v[i] == x)
                    dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else
            {
                if(v[i] == 0 || v[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod;
                }
                else dp[i][x] = 0;
            }
        }
    }
 
    int ans = 0;
    for(int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % mod;
    return ans;
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        int n,m;
        cin >> n >> m;
        vector<int> v(n+1);
        fr(1,n+1)
            cin >> v[i];
        cout << solve(n,m,v);
   }
   return 0;
}