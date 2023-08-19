#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>

// Main Idea = This can be solved using the concept of lower_bound. Store the increasing subsequence in vector named "dp" which will be continuously
// updated.
// While traversing through the array, if we find lower_bound of current element present in dp, then replace that position in dp with the 
// current element.
// And, if we don't find the lower_bound of current element present in dp, then add the current element in the dp vector.
// At the end, we will have the vector containing the longest increasing subsequence 

// Time complexity = O(n.logn), logn = for lower_bound
// Space complexity = O(n)

int main() {
    int n; cin>>n;
    long int arr[n];
    for(int i=0; i<n; i++)
    {
        long int x; cin>>x;
        arr[i] = x;
    }
    vector<long int> dp;
    for(int i=0; i<n; i++)
    {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if(pos == dp.size())
            dp.push_back(arr[i]);
        
        else
            dp[pos] = arr[i];
    }
    cout<<dp.size()<<endl;
   return 0;
}