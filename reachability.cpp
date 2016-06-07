#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int Explore(int vertex,int target, vector<int>& visited,vector<vector<int> > &adj)
{
	visited[vertex] = 1;
	int findFlag = 0;
	for (unsigned int i = 0; i < adj[vertex].size(); i++)
	{
		if (!visited[adj[vertex][i]])
		{
			if (adj[vertex][i] == target)
			{
				findFlag = 1;
				break;
			}
			else
			{
				findFlag = Explore(adj[vertex][i],target, visited, adj);
				if (findFlag)
				{
					break;
				}
			}

		}
	}
	return findFlag;
}

int reach(vector<vector<int> > &adj, int x, int y)
{
	vector<int> visited(adj.size(),0);
	return Explore(x,y, visited, adj);
}

int main()
{
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++)
	{
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, x - 1, y - 1);
}
