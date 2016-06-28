#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
const int cinf = 100000;

struct vertex{
  int idx;
  int key;
  vertex(int a = 0, int b = 0): idx(a), key(b) {}
};

struct cmp {
  bool operator()(vertex a, vertex b) {
    return a.key > b.key;
  }
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<int> dist(adj.size(), cinf);
  vector<int> prev(adj.size(), -1);
  dist[s] = 0;
  priority_queue<vertex, vector<vertex>, cmp> visiting;
  visiting.push(vertex(s, dist[s]));
  while (!visiting.empty())
  {
    vertex current = visiting.top();
    visiting.pop();
    int current_index = current.idx;
    for (int i = 0; i < adj[current_index].size(); i++)
    {
      int next_index = adj[current_index][i];
      if (dist[next_index] > dist[current_index] + cost[current_index][i])
      {
        dist[next_index] = dist[current_index] + cost[current_index][i];
        prev[next_index] = current_index;
        visiting.push(vertex(next_index, dist[next_index]));
      }
    }
  }
  if (prev[t] == -1)
  {
    return -1;
  }
  else
  {
    return dist[t];
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
