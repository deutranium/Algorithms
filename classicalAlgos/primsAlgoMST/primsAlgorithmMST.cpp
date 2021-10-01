// Time Complexity : O(ElogV)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void init() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

class Graph {
	ll V;
	// Adjancency List
	vector<pair<ll, ll>> *l;
public:
	Graph(ll V) {
		this->V = V;
		l = new vector<pair<ll, ll>>[V];
	}

	void addEdge(ll u, ll v, ll wt) {
		l[u].push_back(make_pair(v, wt)); // vertex, weight
		l[v].push_back(make_pair(u, wt));
	}

	ll prim_mst() {
		// Min heap to get the min wt edge everytime
		// Init a priority queue
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

		// visited array denotes whether the vertex has been included in MST or not
		bool *visited = new bool[V] {0};

		ll min_wt = 0;
		// Push the src node in the queue
		Q.push({0, 0}); // weight,vertex

		while (!Q.empty()) {
			auto best = Q.top();
			Q.pop();

			ll vertex = best.second;
			ll wt = best.first;

			if (visited[vertex]) {
				// already included in MST, discard the edge;
				continue;
			}

			// take the current edge as it has minimum weight
			// mark it visited
			// Or include it in MST set
			visited[vertex] = 1;
			min_wt += wt;

			// put all the edges from that vertex int the priority queue
			for (auto edge : l[vertex]) {
				ll to = edge.first;
				ll w = edge.second;
				if (!visited[to]) {
					Q.push({w, to});
				}
			}
		}
		return min_wt;
	}
};

int main() {
	init();
	ll V, E;
	cin >> V >> E;
	Graph g(V);
	for (int i = 0; i < E; i++) {
		ll x, y, wt;
		cin >> x >> y >> wt;
		g.addEdge(x - 1, y - 1, wt);
	}

	cout << g.prim_mst() << endl;

	return 0;
}
