#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
 
// Main Idea = Use backtracking.
// A queen can be placed at a free square only if there is no queen placed in the same left and right diagonal
// and the same row
// Left diagonal goes from top left to bottom right,  
// Right diagonal goes from bottom right to top left
// Store the final answer in an integer

// Time Complexity = O(8^N), exponential since its backtracking
// Space Complexity = O(1), to store the answer

char chess[8][8];
int c=0;
bool ld[15], rd[15], row[7];
void rec(int j){
	if (j==8) {
        c++; 
        return;}
    for(int i = 0; i < 8; i++)
    {
        if(chess[i][j] == '.' && ld[i - j + 7] == 0 && rd[i + j] == 0 && row[i] == 0)
        {
            ld[i - j + 7] = 1;
            rd[i + j] = 1;
            row[i] = 1;
            rec(j + 1);
            ld[i - j + 7] = 0;
            rd[i + j] = 0;
            row[i] = 0;
        }
    }
}
int main(){
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0; j < 8; j ++ )
            cin>>chess[i][j];
    }
	rec(0);
	cout<<c;
}