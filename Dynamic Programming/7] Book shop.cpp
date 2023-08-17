#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
 
// Main Idea = This is a classical example of 0-1 knapsack problem. 
// dp[i][x] = maximum number of pages we get for price at most x, only buying among the first i books.
// We can either buy the current book if it falls under the price or do not buy it even if it falls under the price.
// Hence, dp[i][x] = max(dp[i-1][x], dp[i-1][x - price[i]] + pages[i])

// Time Complexity = O(n.p), n = number of books and p = maximum total price.
// Space Complexity = O(n.p), 2D dp array of dimension (n x p)

int main(){
    int n;
    cin>>n;
    int totalprice;
    cin>>totalprice;
    int prices[n];
    for(auto& it:prices)
        cin>>it;
    int pages[n];
    for(auto& it:pages)
        cin>>it;
    int dp[n+1][totalprice+1];
    // cout<<prices[3];
    for(int i=0; i<=n; i++)
    {
        for(int p = 0; p<=totalprice; p++)
        {
            if(i==0 || p == 0)
                dp[i][p] = 0;
            else
            {    dp[i][p] = dp[i-1][p];
                if(prices[i-1] <= p)
                    dp[i][p] = max(dp[i][p], dp[i-1][p-prices[i-1]] + pages[i-1]);
            }
        }
    }
    cout<<dp[n][totalprice]<<endl;
    return 0;
}