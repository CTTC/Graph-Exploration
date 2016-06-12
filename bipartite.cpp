#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  int nodeNum = adj.size();
  int bipartiteFlag = 1;
  vector<int> distance(nodeNum, nodeNum);   // initialize the distance vector, since the
                                                // maximum distance between any two nodes is the number of node minus one,
                                                // so here, I just use nodeNum to represent a large enough number (like infinite number)
  int s = 0;
  distance[s] = 0;
  queue<int> visiting;
  visiting.push(s);
  while(!visiting.empty() && bipartiteFlag)
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
      else if (distance[adjNode] == distance[node])
      {  // if two nodes connected by an edge are on the same layer,
       // then this graph cannot be bipartited.
        bipartiteFlag = 0;
        break;
      }
    }
  }
  return bipartiteFlag;
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
  std::cout << bipartite(adj);
}
