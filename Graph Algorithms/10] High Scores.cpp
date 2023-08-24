#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
// Main idea = This is a single source longest path problem which can be converted to single source shortest path problem by
// taking the negative of all the weights given.
// We will now perform the Bellman Ford algorithm, which returns the single source shortest path in (V x E) time (V = number of vertices
// , E = number of Edges). This is valid only when there is/are no negative cycles, and we will then print the final answer.
// In case of negative cycle, the Bellman Ford algorithm will resolve it in (2 x V x E) time and recognise the nodes that will be affected
// by this negative cycle.

// Time Complexity = O(V x E)
// Space Complexity = O(V x E + V), to store the adjacency list and distance vector

const int INF = 1e17;
const int NINF = INF*(-1);
 
struct triplet{
	int first;
	int second;
	int third;
};
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
 
void bellman_ford()
{
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} // n - 1 relaxations
 
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
			{
				dist[v] = NINF;
			}
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	edges.resize(m);
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		inp.third *= -1; 
		edges[i] = inp;
	}
 
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}
 
	bellman_ford();
	if(dist[n] == NINF || dist[n] == 0)
	{
		cout << -1 << endl;
		return 0;
	} 
	cout << dist[n] * (-1) << endl;
}