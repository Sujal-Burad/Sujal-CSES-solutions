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

// Main Idea = Every time we go from left to right, if for a current element the just smaller element has been already visited, then do not increase
// the count. Else, increase the count, since it is now the smallest element in the array which has not been visited. 
// A map can be used for this purpose.

// Time Complexity = O(n), worst case
// Space Complexity = O(1)

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> mpp;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        mpp[v[i]] = 0;
    }
    mpp[0] = 1;
    int count = 1;
    for(int i=0; i<n; i++)
    {
        if(mpp[v[i] - 1] == 0)
        {
            mpp[v[i]] = 1;
            count++;
        }
        else
        {
            mpp[v[i]] = 1;
        }
    }
    cout<<count<<endl;
    return 0;
}