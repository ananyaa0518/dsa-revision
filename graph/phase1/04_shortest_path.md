# 04. Shortest Path in an Unweighted Graph (BFS)

## Problem

Given an **unweighted graph** and a source node `src`, find the **shortest distance** from the source to every other node.

---

## Example

### Graph

```text
0 ---- 1
|      |
2      3
 \    /
   4
```

### Adjacency List

```cpp
0 -> {1,2}
1 -> {0,3}
2 -> {0,4}
3 -> {1,4}
4 -> {2,3}
```

### Input

```cpp
src = 0
```

### Output

```text
Node : Distance

0 : 0
1 : 1
2 : 1
3 : 2
4 : 2
```

---

# Approach

Since every edge has the **same weight (1)**, BFS always reaches a node using the shortest path.

We maintain:

- `queue` → for BFS traversal
- `visited[]` → to avoid revisiting nodes
- `dist[]` → stores the shortest distance from the source

Initially,

- Distance of the source is `0`
- Distance of every other node is `-1`

Whenever we visit an unvisited neighbor,

```cpp
dist[neighbor] = dist[current] + 1;
```

---

# Algorithm

1. Create a `visited` array initialized to `false`.
2. Create a `distance` array initialized to `-1`.
3. Push the source node into the queue.
4. Mark the source as visited.
5. Set `distance[source] = 0`.
6. While the queue is not empty:
   - Pop the front node.
   - Traverse all its neighbors.
   - If a neighbor is unvisited:
     - Mark it visited.
     - Set its distance as `distance[current] + 1`.
     - Push it into the queue.
7. Return the distance array.

---

# Code

```cpp
vector<int> shortestPath(int src, vector<vector<int>>& adj) {
    int n = adj.size();

    vector<bool> visited(n, false);
    vector<int> dist(n, -1);

    queue<int> q;

    q.push(src);
    visited[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist;
}
```

---

# Dry Run

### Initial State

```text
Queue = [0]

Visited = [T, F, F, F, F]

Distance = [0, -1, -1, -1, -1]
```

---

### Pop 0

Neighbors: **1, 2**

```text
Queue = [1, 2]

Visited = [T, T, T, F, F]

Distance = [0, 1, 1, -1, -1]
```

---

### Pop 1

Neighbor: **3**

```text
Queue = [2, 3]

Visited = [T, T, T, T, F]

Distance = [0, 1, 1, 2, -1]
```

---

### Pop 2

Neighbor: **4**

```text
Queue = [3, 4]

Visited = [T, T, T, T, T]

Distance = [0, 1, 1, 2, 2]
```

---

### Pop 3

No new node.

---

### Pop 4

No new node.

Queue becomes empty.

Final distance array:

```text
[0, 1, 1, 2, 2]
```

---

# Complexity Analysis

### Time Complexity

```text
O(V + E)
```

Every vertex is visited once, and every edge is processed once.

### Space Complexity

```text
O(V)
```

For:

- Visited array
- Distance array
- Queue

---

# Key Learning

- Use **BFS** to find the shortest path in an **unweighted graph**.
- The first time BFS reaches a node is always through the shortest path.
- Store the distance using:

```cpp
dist[neighbor] = dist[current] + 1;
```

---

# Pattern to Remember

```text
Queue
    ↓
Push source
    ↓
visited[source] = true
    ↓
distance[source] = 0
    ↓
While queue is not empty
    ↓
Pop node
    ↓
Visit all neighbors
    ↓
If neighbor is unvisited
    ↓
visited[neighbor] = true
distance[neighbor] = distance[node] + 1
Push neighbor
```