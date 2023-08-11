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

// Main Idea = Sort the array. When an array element is greater than the smallest sum found so far, print that element.
// Else update the smallest sum found so far.

// Time Complexity = O(n.logn + n), sorting + traversing
// Space Complexity = O(1), to store the answer.

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr+n);
    ll sum = 1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > sum)
            break;
        else
        {
            sum = sum + arr[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}