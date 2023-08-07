#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
 
// Main Idea = We will solve this by recursion to find the minimum difference.
// At every stage we can either put the apple in group 1 or keep it in group 2.
// Depending on where we put it, resepectively increment or decrement the sum of weight of that group.

// Time Complexity = O(2^n), since every apple has two choices
// Space complexity = O(1), one variable to store the final minimum differnce.

long int recur(int n, int curr, long int arr[], long int sum1, long int sum2)
{
    if(curr == n - 1)
        return abs(sum1 - sum2);
    
    return min(recur(n, curr+1, arr, sum1 + arr[curr], sum2 - arr[curr]), recur(n, curr+1, arr, sum1, sum2));
}
int main(){
    int n;
    cin>>n;
    long int arr[n];
    long int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum = sum + arr[i];
    }
    long int ans;
    ans = recur(n, 0, arr, 0, sum);
    cout<<ans<<endl;
    return 0;
}