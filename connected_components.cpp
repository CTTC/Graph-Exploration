#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void Explore(int vertex, vector<int>& visited,vector<vector<int> > &adj)
{
  visited[vertex] = 1;
  for (unsigned int i = 0; i < adj[vertex].size(); i++)
  {
    if (!visited[adj[vertex][i]])
    {
      Explore(adj[vertex][i], visited, adj);
    }
  }
}
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<int> visited(adj.size(),0);
  for (unsigned int i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
    {
      Explore(i, visited, adj);
      res++;
    }
  }

  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
