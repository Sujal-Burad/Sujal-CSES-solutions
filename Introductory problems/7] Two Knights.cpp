#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea : First, count the total number of ways that are possible to keep two knights and then
// subtract the ways in which they can attack each other.
// One attack occupies a block of dimension (2x3), so we have  2 * (tt-1)*(tt-2) ways of selecting a (2x3)
// block on the board.(once we select horizontally and the second time we select vertically.)
// We then multiply this number by 2, since there are two distinct ways two kinghts can be placed in a (2x3) block
// so that they can attack each other.
// Final number to be subtracted = 4*(tt-1)*(tt-2).

// Time complexity = O(n), since its O(1) for each test case
// Space complexity = O(1), constant space is required.

int main(){
   int test;
   cin>>test;
//    int row[4] = {-1, +1, -2, +2};
//    int col[4] = {+2, -2, +1, -1};
   for(int tt=1; tt<=test; tt++)
   {
        long long total = tt*tt;
        total = total*(total-1)/2;
        if(tt>2) total = total - 4*(tt-1)*(tt-2);
        cout<<total<<endl;
   }
   return 0;
}