#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
// Main Idea = Applying Bellman ford takes (N - 1) iterations to take minmize all the distance. It is possible to detect the negative cycle
// in the Nth iteration if the distance gets further reduced . Also, store the relaxants of every node during the iteration.
// If the negative cycle is found, then iterate through the relaxants and every time make current_node = relaxant[current_node]. If
// at the end we again reach the starting node of cycle with cycle.size() > 1, then we have found the cycle.
// Now, print the cycle.

// Time Complexity = O(V * E), V = number of vertices, E = number of edges.
// Space Complexity = O(V), to store the relaxant array.

class triplet{
public:
	int first;
	int second;
	int third;
 
};
 
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
vector<int> relaxant;
 
void bellman_ford()
{	
	int x;
	for(int i = 1; i <= n; ++i)
	{
		x = -1;
		for(auto e: edges)
		{
 
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u]+d < dist[v])
			{
				dist[v] = d+dist[u];
				relaxant[v] = u;
				x = v;
			}
		}
	} // n relaxations
 
	if(x == -1)
		cout << "NO" << endl;
 
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			x = relaxant[x];
		}
 
		vector<int> cycle;
 
		for(int v = x; ; v = relaxant[v])
		{
			cycle.push_back(v);
			if(v == x and cycle.size() > 1)
				break;
		}
 
		reverse(cycle.begin(), cycle.end());
 
		cout << "YES" << endl;
		for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
	}
 
 
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	relaxant.resize(n+1);
	edges.resize(m);
 
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		edges[i] = inp;
	}
 
	for(int i = 1; i <= n; ++i)
	{
		relaxant[i] = -1;
	}
	bellman_ford();	
}