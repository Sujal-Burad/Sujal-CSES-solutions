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
 
// Main Idea = It can simply be solved using the concept of hash maps. Store the element and its index in a hash map.
// If we find the pair {value, target - value} while traversing through the map, then
// store the positions of these two elements and at the end print these positions.
// If while traversing through the complete map, we don't find any such pair, then print "IMPOSSIBLE".

// Time Complexity = O(n), worst case for finding a value in map
// Space Complexity = O(n), to map the elements of array.

int main()
{
    int n, target;
    cin>>n>>target;
    map<int, int> mpp;
    int flag = 0;
    int a, b;
    for(int i=1; i<=n; i++)
    {
        int val; cin>>val;
        if(flag == 0 && mpp.count(target - val) > 0)
        {
            flag = 1;
            a = i; b = mpp[target - val];
        }
        else
        {
            mpp[val] = i;
        }
    }
    if(flag == 1)
        cout<<a<<" "<<b;
    else
        cout<<"IMPOSSIBLE";
 
    return 0;
}