#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea = The total number of possible bit strings is simply 2^(n). Please make sure to take mod every 
// single time when multipltying by two, as shown in the code, as we have to print result modulo 1000000007.

// Time Complexity = O(n)
// Space Complexity = O(1), since we are only using one variable to print the final answer.

int main(){
  int n;
  cin>>n;
  long long ans = 1;   
  for(int i=1; i<=n; i++)
    ans = (ans * 2)%(1000000007);
 
    cout<<ans;
  return 0;
}