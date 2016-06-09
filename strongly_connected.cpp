#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void Explore(int vertex, int* clock, vector<int>& visited, vector<vector<int> > &adj, vector<pair<int, int> >& vertexAndPostOrder)
{
  visited[vertex] = 1;
  (*clock)++;  // This is for preorder number
  for (unsigned int i = 0; i < adj[vertex].size(); i++)
  {
    if (!visited[adj[vertex][i]])
    {
      Explore(adj[vertex][i], clock, visited, adj,vertexAndPostOrder);
    }
  }
  (*clock)++;
  pair<int, int> temp(vertex, *clock);
  vertexAndPostOrder.push_back(temp);
}

void Explore(int vertex, vector<int>& visited, vector<vector<int> > &adj)
{
  visited[vertex] = 1;
  for (unsigned int i = 0; i < adj[vertex].size(); i++)
  {
    if (!visited[adj[vertex][i]])
    {
      Explore(adj[vertex][i],visited, adj);
    }
  }
}


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int verticesNum = adj.size();
  vector<vector<int> > adjReverse(verticesNum,vector<int>());
  for (unsigned int i = 0; i < verticesNum; i++)
  {
    for (unsigned j = 0; j < adj[i].size(); j++)
    {
      adjReverse[adj[i][j]].push_back(i);
    }
  }
  int clock = 0;
  vector<int> visited(verticesNum,0);
  vector<pair<int, int> > vertexAndPostOrder;

  // Depth-First Search on the reverse graph
  for (int j = 0; j < verticesNum; j++)
  {
    if (!visited[j])
    {
      Explore(j, &clock, visited, adjReverse,vertexAndPostOrder);
    }
  }

  vector<int> reverseVisited(verticesNum,0);

  int sccNum = 0; // number of strongly connected number

  for (int t = 0; t < verticesNum; t++)
  {
    if (!reverseVisited[vertexAndPostOrder[verticesNum - 1 - t].first])
    {
      sccNum++;
      Explore(vertexAndPostOrder[verticesNum - 1 - t].first, reverseVisited, adj);
    }
  }
  return sccNum;
}



int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
