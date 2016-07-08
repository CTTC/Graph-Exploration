#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

struct vertex
{
	int parent;
	int rank;
	int x;
	int y;
	vertex(int a, int b, int c = -1, int d = 0)
	{
		x = a;
		y = b;
		parent = c;
		rank = d;
	}
};

struct edge
{
	int endOne;
	int endTwo;
	double weight;
	edge(int a, int b, double c)
	{
		endOne = a;
		endTwo = b;
		weight = c;
	}
};


bool cmp(edge a, edge b) {
	return a.weight < b.weight;
}


int getParent(int table, vector<vertex> &sets) {
	// find parent and compress path
	if (table != sets[table].parent)
	{
		sets[table].parent = getParent(sets[table].parent, sets);
	}
	return sets[table].parent;
}
void merge(int setOne, int setTwo, vector<vertex> &sets) {
	int oneRoot = getParent(setOne, sets);
	int twoRoot = getParent(setTwo, sets);
	if (oneRoot != twoRoot) {
		if (sets[oneRoot].rank > sets[twoRoot].rank)
		{
			sets[twoRoot].parent = oneRoot;
		}
		else
		{
			sets[oneRoot].parent = twoRoot;
			if (sets[oneRoot].rank == sets[twoRoot].rank)
			{
				sets[twoRoot].rank++;
			}
		}
		// merge two components
		// use union by rank heuristic
		// update max_table_size
	}
}

double minimum_distance(vector<int> x, vector<int> y) {
	double result = 0.;
	vector<vertex> vertices;
	vector<edge> edges;
	for (int i = 0; i < x.size(); i++)
	{
		vertices.push_back(vertex(x[i], y[i], i));
	}
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = i + 1; j < y.size(); j++)
		{
			double weight = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			edges.push_back(edge(i, j, weight));
		}
	}
	std::sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i].endOne;
		int v = edges[i].endTwo;
		if (getParent(u, vertices) != getParent(v, vertices))
		{
			result += edges[i].weight;
			merge(u, v, vertices);

		}
	}

	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
