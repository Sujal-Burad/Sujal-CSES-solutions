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

// Main Idea = This can be solved using the concept of monotonic stack. The stack stores the element and its index position in increasing order.
// That is to say, the top of the stack will contain the largest value and its index, and the bottom of the stack will contain the 
// smallest value and its index. 
// While going through the array we will keep popping the top element of the stack till we find an element with value less than the current
// element. If we find such value, then we will print the position of the value.
// If we don't find such value and the stack is empty, then we will print '0'.
// We will always push the current element into the stack, everytime.

// Time Complexity = O(n^2), at max we will have to pop all the elements of the stack. This happens when the array is in non-increasing order
// Space Complexity = O(n), to store the elements into the stack.


int main()
{
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
 
    stack<pair<int, int>> st;
    for(int i=0; i<n; i++)
    {
        while(st.size() > 0 && st.top().first >= vec[i])
            st.pop();
        
        if(st.size() > 0)
            cout<<st.top().second<<" ";
        else    
            cout<<"0"<<" ";
        st.push({vec[i], i+1});
    }    
    return 0;
}
