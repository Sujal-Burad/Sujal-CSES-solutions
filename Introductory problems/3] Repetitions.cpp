#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map>

// Main Idea = Traverse through the complete array, and keep updating the maximum-length substring 
// found so far containing only one type of character in a variable 'ans'.

// Time Complexity = O(n)
// Space Complexity = O(1) i.e constant space is required

int main(){
    string s;
    cin>>s;
    int ans=1, maxi=1;
    for(unsigned i=1; i<s.length(); i++)
    {
        if(s[i] == s[i-1])
            maxi++;
        else
        {
            ans = max(maxi, ans);
            maxi = 1;
        }
    }
    ans = max(maxi, ans);
    cout<<ans<<" ";
    return 0;
}