#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
#define mod 1000000007
#include <algorithm>

// Main Idea = 
// dp[value] = 1 if we can reach value,
// dp[value] = 0 if we cannot reach value.
// When we update the dp from zero, it might happen that we are using the same coin more than one time to get dp[value].
// To prevent this from happening, we can update the dp starting from the last element.

// Time Complexity = O(n^2)
// Space Complexity = O(n)

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        sum = sum + x;
        arr[i] = x;
    }
    vector<int> reachable(sum+1, 0);
    reachable[0] = 1;
    for(int i=0; i<n; i++)
        for(int value = sum; value >= arr[i]; value--)
            reachable[value] = reachable[value] | reachable[value - arr[i]];
    
    int count = 0;
    for(int i=1; i<=sum; i++)
        if(reachable[i])
            count++;
    
    cout<<count<<endl;
    for(int i=1; i<=sum; i++)
        if(reachable[i])
            cout<<i<<" ";
    return 0;
}
