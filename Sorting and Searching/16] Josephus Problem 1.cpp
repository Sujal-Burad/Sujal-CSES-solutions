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

// Main Idea = Every time we iterate through the circle, the child sitting at odd index position (zero-based indexing) are removed.
// If the total number of children are odd, we push the last child to the first position and remove the children as mentioned above.
// If the total number of children are even, the last child is not pushed to the first position.
// We keep on iterating till no child remains.

// Time complexity = O(n), to remove the n children.
// Space Complexity = O(n), to store the n children.

int main()
{
    int n; cin>>n;
    vector<int> children(n);
    for(int i=0; i<n; i++)
        children[i] = i+1;
    
    while(children.size() > 1)
    {
        vector<int> survivor;
        for(int i=0; i<children.size(); i++)
        {
            if(i%2 == 1)
                cout<<children[i]<<" ";
            else
                survivor.push_back(children[i]);
        }
        if(children.size() % 2 == 0)
            children = survivor;
        else
        {
            int last = survivor.back();
            survivor.pop_back();
            children.clear();
            children.push_back(last);
            for(int i=0; i<survivor.size(); i++)
                children.push_back(survivor[i]);
        }
    }
    cout<<children[0];
    return 0;
}