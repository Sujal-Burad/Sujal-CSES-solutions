#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
 
// Main Idea = To generate all the strings we will use recursion and store the generated strings in a set so that there
// are no duplicates.
// We will call recursion everytime we swap a character at a position with all the characters present at an index
// with value >= the position of character to be swapped.
// This will continue till the index < string size, and at the end we will store the string formed by swapping in the set

// Time Complexity = O(n!)
// Space Complexity = depends on the string given and number of unique characters in the string. 

void recur(int l, int r, string a, set<string>& st)
{
    if(l==r)
        st.insert(a);
    else
    {
        for(int i=l; i<=r; i++)
        {
            swap(a[l], a[i]);
            recur(l+1, r, a, st);
        }
    }
}
int main(){
    string s;
    cin>>s;
    set<string> st;
    recur(0, s.length()-1, s, st);
    cout<<st.size()<<endl;
    for(auto it : st)
        cout<<it<<endl;
  return 0;
}