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
#include <iterator>
 
// Main Idea = This problem can be considered as an extension of sum of two values, where we had to find two values at distinct position
// in the array with sum = target value. This can be solved using two pointer method.
// First, we will have to sort the array. Then, we will iterate 'i' from '0' to 'n-1'. Now, we apply the two pointer method where none 
// of the pointer should be equal to i and sum of element at the two pointers = target - value of element at 'i'th position.
// If the sum of value of the elements at the two pointers < target, then increement the left pointer.
// If the sum of value of the elements at the two pointers > target, then decreement the right pointer.

// Time Complexity = O(n.logn + n^2), to sort the array and apply the above technique.
// Space Complexity = O(1), to store the final answer.

int main()
{
    int n; cin>>n;
    int tar; cin>>tar;
    vector<pair<int, int>> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i].first;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<n; i++)
    {
        int l = 0;
        int r = n-1;
        while(l<r)
        {
            if(l!=i && r!=i && vec[l].first + vec[r].first == tar - vec[i].first)
            {
                cout<<vec[i].second+1<<" "<<vec[l].second+1<<" "<<vec[r].second+1<<endl;
                return 0;
            }
            if(vec[l].first + vec[r].first < tar - vec[i].first)
                l++;
            else
                r--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}