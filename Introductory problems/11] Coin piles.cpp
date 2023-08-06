#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
 
// Main Idea = The only ways in which the piles cannot be emptied is when, 
// a] The maximum of the two > 2 * the minimum of the two,
// b] (a + b) modulo 3 is != 0

// Time and Space Complexity = constant O(1)

int main(){
  int n;
  cin>>n;
  for(int tt=1; tt<=n; tt++)
  {
    long long a, b;
    cin>>a>>b;
    if(max(a, b) > 2 * min(a, b) || (a+b)%3 != 0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
  }
  return 0;
}