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
 
 
int main()
{
    int n; cin>>n;
    int m; cin>>m;
    vector<int> values(n+1);
    vector<int> position(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>values[i];
        position[values[i]] = i;
    }
    int answer = 1;
    for(int i=1; i<n; i++)
        answer+= (position[i] > position[i+1]);
 
    int l, r;
    // set<pair<int, int>> st;
    while(m--)
    {
        set<pair<int, int>> st;
        cin>>l>>r;
        if(values[l] + 1 <= n)
            st.insert(make_pair(values[l], values[l]+1));
        if(values[l] - 1 >= 1)
            st.insert(make_pair(values[l]-1, values[l]));
        if(values[r] + 1 <= n)
            st.insert(make_pair(values[r], values[r] + 1));
        if(values[r] - 1 >= 1)
            st.insert(make_pair(values[r] - 1, values[r]));
        
        for(auto it:st)
        {
            answer -= (position[it.first] > position[it.second]);
        }
        swap(values[l], values[r]);
        position[values[l]] = l;
        position[values[r]] = r;
        for(auto it: st)
        {
            answer += (position[it.first] > position[it.second]);
        }
        cout<<answer<<endl;
        st.clear();
    }
    return 0;
}