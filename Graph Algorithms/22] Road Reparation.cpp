#include <bits/stdc++.h>
using namespace std;

// Main Idea = This uses the concept of minimum spanning tree which finds the minimum total weight to connect all the vertices in a 
// connected, edge-weighted, and undirected graph. To connect all the vertices the total edges must be (n - 1). If after running the 
// algorithm, we find that total_edges != (n - 1) it means there is an isolated vertex so we will print "IMPOSSIBLE".
// Store the minimum total weight in a variable and then print it at the end.

// Time Complexity = O(E.V + log(E)), in worst case each vertex V has E edges, and for inserting element into the set.
// Space Complexity = O(V), to store the elements in set.

long long prim(int n, const vector<vector<pair<long long, int>>> &adj) {
	long long weight = 0;
	vector<long long> dist(n, numeric_limits<long long>::max());
	dist[0] = 0;
	set<pair<long long, int>> q;
	// {cost, vertex}
	q.insert({0, 0});
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (q.empty()) { return -1; }
		int v = q.begin()->second;
		visited[v] = true;
		weight += q.begin()->first;
		q.erase(q.begin());
 
		for (auto &[cost, child] : adj[v]) {
			if (!visited[child] && cost < dist[child]) {
				q.erase({dist[child], child});
				dist[child] = cost;
				q.insert({cost, child});
			}
		}
	}
	return weight;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
 
	vector<vector<pair<long long, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
 
	long long ans = prim(n, adj);
	if (ans == -1) {
		cout << "IMPOSSIBLE";
	} else {
		cout << ans;
	}
	cout << endl;
}