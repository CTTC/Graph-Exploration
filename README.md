# Graph-Exploration

---
### `connected_components.cpp`
* Function: find the number of **connected components** in a graph
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge.
* Output Format: Output the number of connected components.

####Example:

#####Input:
```
4 2 
1 2 
3 2
```
#####Output:
```
2
```
Note: The input means there are 4 vertices and 2 edges. The two edges are connected by vertex 1 and vertex 2, vertex 3 and vertex 2.

Graph:
```

(4)    (3)
        |
(1) —— (2)
```

---
###`reachability.cpp`
* Function: find if two vertices are **reachable from each other**
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge.
   * The last line is the two vertices (u,v) that are used to explore reachability.
* Output Format: Output 1 if there is a path between u and v and 0 otherwise.

####Example:

#####Input:
```
4 4
1 2
3 2
4 3
1 4
1 4

```
#####Output:
```
1
```
Note: The input means there are 4 vertices and 4 edges. The two edges are connected by vertex 1 and vertex 2, vertex 3 and vertex 2, vertex 4 and vertex 3, vertex 1 and vertex 4.

Graph:
```

(4) —— (3)
 |      |
(1) —— (2)
```

---
###`acyclicity.cpp`
* Function: check if the **graph contains a cycle**
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v.
* Output Format: Output 1 if there is a cycle in the graph and 0 otherwise.

####Example:

#####Input:
```
4 4
1 2
4 1
2 3
3 1

```
#####Output:
```
1
```
Note: This graph contains a cycle: 3 → 1 → 2 → 3.

---
###`toposort.cpp`
* Function: Compute **a topological ordering** of a given **directed acyclic graph (DAG)** with n vertices and m edges
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v.
* Output Format: Output any topological ordering of its vertices.

####Example:

#####Input:
```
4 3
1 2
4 1
3 1

```
#####Output:
```
4 3 1 2
```

---
###`strongly_connected.cpp`
* Function: Compute the number of **strongly connected components** of a given directed graph with n vertices and m edges.
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v.
* Output Format: Output the number of strongly connected components.

####Example:

#####Input:
```
4 4
1 2
4 1
2 3
3 1

```
#####Output:
```
2
```

---
###`bfs.cpp`
* Function: Given an undirected graph with n vertices and m edges and two vertices u and v, compute the length
of a shortest path between u and v (that is, the minimum number of edges in a path from u to v). It is computed based on **breadth-first search** algorithm.
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v.
* Output Format: Output the minimum number of edges in a path from u to v, or 􀀀1 if there is no path.

####Example:

#####Input:
```
4 4
1 2
4 1
2 3
3 1
2 4

```
#####Output:
```
2
```
---
###`bipartite.cpp`

* Function: Given an undirected graph with n vertices and m edges and two vertices u and v, check whether it
is bipartite. It is checked based on **breadth-first search** algorithm.Definition for bipartite: a graph is bipartite if its vertices can be colored with two colors (say, black and white) such that the endpoints of each edge have dierent colors.
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v.
* Output Format: Output 1 if the graph is bipartite and 0 otherwise.

####Example:

#####Input:
```
4 4
1 2
4 1
2 3
3 1
2 4

```
#####Output:
```
0
```

---
###`dijkstra.cpp`

* Function: Given an directed graph with positive edge weights and with n vertices and m edges as well as two vertices u and v, compute the weight of a shortest path between u and v (that is, the minimum total weight of a path from u to v). This file utilized the **Dijkstra Algorithm**.
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v. The third number in the line is the weight of the edge.
   * The last line is starting vertex and ending vertex.
* Output Format: Output the minimum weight of a path from u to v, or 􀀀1 if there is no path.

####Example:

#####Input:
```
4 4
1 2 1
4 1 2
2 3 2
1 3 5
1 3

```
#####Output:
```
3
```

---
###`negative_cycle.cpp`

* Function: Given an directed graph with possibly negative edge weights and with n vertices and m edges, check whether it contains **a cycle of negative weight**.
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v. The third number in the line is the weight of the edge.
* Output Format: Output 1 if the graph contains a cycle of negative weight and 0 otherwise.

####Example:

#####Input:
```
4 4
1 2 -5
4 1 2
2 3 2
3 1 1

```
#####Output:
```
1
```

---
###`shortest_paths.cpp`

* Function: Given a directed graph with possibly negative edge weights and with n vertices and m edges as well as its vertex s, compute the length of shortest paths from s to all other vertices of the graph.
* Input Format:
   * The first line contains non-negative integers n and m — the number of vertices and the number of edges respectively. 
   * The vertices are always numbered from 1 to n. 
   * Each of the following m lines defines an directed edge in the format u v where 1 ≤ u, v ≤ n are endpoints of the edge. And the edge is from u to v. The third number in the line is the weight of the edge.
   * The last line is starting vertex.
* Output Format: For all vertices i from 1 to n output the following on a separate line:
   * "*", if there is no path from s to u;
   * "-", if there is a path from s to u, but there is no shortest path from s to u (that is, the distance from s to u is 􀀀1);
   * the length of a shortest path otherwise.

####Example:

#####Input:
```
6 7
1 2 10
2 3 5
1 3 100
3 5 7
5 4 10
4 3 -18
6 1 -1
1

```
#####Output:
```
0
10
-
-
-
*
```


---
###`connecting_points.cpp`

* Function: Given n points on a plane, connect them with segments of minimum total length such that there is a path between any two points.This file is based on **Kruskal’s algorithm for Minimum Spanning Tree**.
* Input Format:
   * The first line contains the number n of points. Each of the following n lines defines a point (xi, yi)
* Output Format: Output the minimum total length of segments

####Example:

#####Input:
```
5
0 0
0 2
1 1
3 0
3 2

```
#####Output:
```
7.064495102
```

---
###`clustering.cpp`

* Function: Given n points on a plane and an integer k, compute the largest possible value of d such that the given points can be partitioned into k non-empty subsets in such a way that the distance between any two points from different subsets is at least d.This file is based on **Kruskal’s algorithm for clustering**.
* Input Format:
   * The first line contains the number n of points. Each of the following n lines defines a point (xi, yi). 
   * The last line contains the number k of clusters.
* Output Format: Output the largest value of d.

####Example:

#####Input:
```
12
7 6
4 3
5 1
1 7
2 7
5 7
3 3
7 8
2 8
4 4
6 7
2 6
3

```
#####Output:
```
2.828427124746
```
