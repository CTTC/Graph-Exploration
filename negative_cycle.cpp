
#include <iostream>
#include <vector>

using std::vector;
const int cinf = 10000000;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost)
{
	vector<int> dist(adj.size(), cinf);
	vector<int> prev(adj.size(), -1);
	vector<int> visited(adj.size(), 0);
	for (int w = 0; w < adj.size(); w++)
	{
		if (visited[w] == 0)
		{
			for (int i = 0; i < adj.size(); i++)
			{
				for (int j = 0; j < adj.size(); j++)
				{
					int current_index = j;
					visited[current_index] = 1;
					for (int k = 0; k < adj[j].size(); k++)
					{
						int next_index = adj[j][k];
						visited[next_index] = 1;
						if (dist[next_index]
								> dist[current_index] + cost[current_index][k])
						{
							if (i == adj.size() - 1)
							{
								return 1; // the graph contains a cycle with negative weight
							}
							dist[next_index] = dist[current_index]
									+ cost[current_index][k];
							prev[next_index] = current_index;
						}

					}
				}
			}
		}
	}

	return 0;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cout << negative_cycle(adj, cost);
}
