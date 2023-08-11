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
 
// Main Idea = It uses the concept of median which occupies the centre position when the elements are arranged in ascending or 
// descending order. 
// For even number of elements use the element at n/2;
// For odd number of elements it can either be at (n/2 - 1) or (n/2 + 1);

// Time Complexity = O(n)
// Space Complexity = O(1)
int main()
{
    int n; cin>>n;
    int length[n];
    for(int i=0; i<n; i++)
        cin>>length[i];
    
    sort(length, length + n);
    if(n%2 == 1)
    {
        ll total = 0;
        int tar = length[n/2];
        for(int i=0; i<n; i++)
            total = total + abs(tar - length[i]);
        cout<<total<<endl;
    }
    else
    {
        ll tot1 = 0;
        ll tot2 = 0;
        int tar1 = length[n/2];
        int tar2 = length[n/2 - 1];
        for(int i=0; i<n; i++)
            tot1 = tot1 + abs(tar1 - length[i]);
        for(int i=0; i<n; i++)
            tot2 = tot2 + abs(tar2 - length[i]);
        
        cout<<min(tot1, tot2)<<endl;
    }
    return 0;
}