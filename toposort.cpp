#include <iostream>
#include <algorithm>
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
			Explore(adj[vertex][i], clock, visited, adj, vertexAndPostOrder);
		}
	}
	(*clock)++;
	pair<int, int> temp(vertex, *clock);
	vertexAndPostOrder.push_back(temp);
}

vector<int> toposort(vector<vector<int> > adj) {
	int verticesNum = adj.size();
	vector<int> visited(verticesNum, 0);
	vector<int> order(verticesNum, 0);

	int clock = 0;
	vector<pair<int, int> > vertexAndPostOrder;

	for (int j = 0; j < verticesNum; j++)
	{
		if (!visited[j])
		{
			Explore(j, &clock, visited, adj, vertexAndPostOrder);
		}
	}

	for (int i =0; i < verticesNum; i++)
	{
		order[i] = vertexAndPostOrder[verticesNum - 1 - i].first;
	}

	return order;
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
	vector<int> order = toposort(adj);
	for (size_t i = 0; i < order.size(); i++) {
		std::cout << order[i] + 1 << " ";
	}
}
