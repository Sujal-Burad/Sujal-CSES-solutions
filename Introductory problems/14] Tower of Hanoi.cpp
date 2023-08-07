#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 
#include<unordered_map>
 
// Main Idea = This problem can be solved using recursion. 
// First shift '(n-1)' disks from left stack to middle stack using the right stack. 
// Then, shift the last disk from left stack to the right stack. 
// And, lastly shift the remaining '(n-1)' disks from middle stack to the right stack using the left stack.

// Total no. of moves in Hanoi problem = 2^n - 1, n = number of disks.

// Time Complexity = O(2^n), since there are two possibilities for every disk. Thus, 2*2*..*2 (n times) = 2^n
// Space Complexity = O(1), only one variable is used to store the total number of moves

void recur(int n, int from, int to, int middle)
{
    if(n==0)
        return;
    
    recur(n-1, from, middle, to);
    cout<<from<<" "<<to<<endl;
    recur(n-1, middle, to, from);
}
int main(){
  int n;
  cin>>n;
  long long x = 1<<n;
  cout<<x-1<<endl;
 
  recur(n, 1, 3, 2);
  return 0;
}