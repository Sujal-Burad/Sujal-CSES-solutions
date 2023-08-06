#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea = Trailing zeros are only formed when there is a factor of '5' in the number given. To calculate
// the answer we can simply calculate the total number of times '5' or its multiples occur in the factorial.

// Time Complexity = O(n)
// Space Complexity = O(1), since only one variable is required to store the final answer.

int main(){
  int n;
  cin>>n;
  long ans = 0;
  while(n>=5)
  {
    ans = ans + n/5;
    n=n/5;
  }
  cout<<ans;
  return 0;
}