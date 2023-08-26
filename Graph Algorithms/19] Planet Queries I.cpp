#include <bits/stdc++.h>
using namespace std;
 
// Main idea = This uses the important concept of binary jumping. 
// parent[i][j] corresponds to i's (2 ^ j)th parent.
// We can answer each query based on the binary representation of the distance.
// Maximum depth of queries = ceil(log2(10 ^ 9)) = 30

// Time Complexity = O(q.log(k)), since for each query it requires log(k) time to find the final planet.
// Space Complexity = O(n*30), to store the parent array

const int MAXN = 2e5 + 5;
const int MAXD = 30;  
int n, q;

int parent[MAXN][MAXD];
 
int jump(int a, int d) {
	for (int i = 0; i < MAXD; i++)
		if (d & (1 << i)) a = parent[a][i];
	return a;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) { cin >> parent[i][0]; }
	// evaluate the parent matrix
	for (int d = 1; d < MAXD; d++)
		for (int i = 1; i <= n; i++) {
			parent[i][d] = parent[parent[i][d - 1]][d - 1];
		}
	// process queries
	while (q--) {
		int a, d;
		cin >> a >> d;
		cout << jump(a, d) << '\n';
	}
}