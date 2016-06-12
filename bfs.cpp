#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

// Breadth-First Search
vector<int> BFS(vector<vector<int> > &adj, int s)
{
	int nodeNum = adj.size();
	vector<int> distance(nodeNum, nodeNum);   // initialize the distance vector, since the
	                                              // maximum distance between any two nodes is the number of node minus one,
	                                              // so here, I just use nodeNum to represent a large enough number (like infinite number)
	distance[s] = 0;
	queue<int> visiting;
	visiting.push(s);
	while(!visiting.empty())
	{
		int node = visiting.front();
		visiting.pop();
		for (int i = 0; i < adj[node].size(); i++)
		{
			int adjNode = adj[node][i];
			if (distance[adjNode] == nodeNum)  // is the node is unvisited
			{
				visiting.push(adjNode);
				distance[adjNode] = distance[node] + 1;
			}
		}
	}
	return distance;
}
int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int> distance = BFS(adj, s);
  return distance[t] == adj.size() ? -1 : distance[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
