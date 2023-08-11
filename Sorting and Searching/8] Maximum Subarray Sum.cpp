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
 
// Main Idea = If all the elements of array are negative, print the greatest negative element.
// Update maximum sum till now in maxi, and start from positive number.

// Time Complexity = O(n)
// Space Complexity = O(1)

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    ll maxi = INT_MIN;
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
        if(sum > maxi)
            maxi = sum;
        
        if(sum < 0)
            sum = 0;
    }
    cout<<maxi<<endl;
    return 0;
}