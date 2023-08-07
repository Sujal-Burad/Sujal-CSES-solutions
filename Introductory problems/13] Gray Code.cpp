#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map>
#include<unordered_map>
 
// Main Idea = We can use recursion to generate the gray code for given length 'n' using the gray code of length '(n-1)'.
// The base cases would be {"0"} for n <= 0 and {"0", "1"} for n == 1
// For generating gray code of length 'n' append the following two lists:
// a] Add "0" as the prefix to every element of list of gray code of length "(n-1)".
// b] Reverse the list of gray code of length "(n-1)" and add "1" as the prefix to every element of the list
// By doing this we can generate the gray code of length "n".

// Time and Space Complexity = O(2^n), since we have to generate every possible string and store it in a list.

vector<string> recur(int n)
{
    if(n<=0)
        return {"0"};
    
    if(n == 1)
        return {"0", "1"};
    
    vector<string> recurans = recur(n-1);
    vector<string> mainans;
    int recurans_size = recurans.size();
    for(int i=0; i<recurans_size; i++)
        mainans.push_back("0" + recurans[i]);
    
    for(int i=recurans_size-1; i>=0; i--)
        mainans.push_back("1" + recurans[i]);
    
    return mainans;
}
 
int main(){
  int n;
  cin>>n;
    vector<string> final = recur(n);
    int final_size = final.size();
    for(int i=0; i<final_size; i++)
        cout<<final[i]<<endl;
  return 0;
}