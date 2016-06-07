# Graph-Exploration

---
### `connected_components.cpp`
* Function: find the number of connected components in a graph
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
* Function: find if two vertices are reachable from each other
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
