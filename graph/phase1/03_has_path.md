# Check if a Path Exists in an Undirected Graph (BFS)

## Problem
Given an undirected graph represented as an adjacency list, determine whether there is a path between two vertices.

---

## Approach (Breadth-First Search)

We use **BFS (Breadth-First Search)** to explore the graph level by level.

### Steps
1. If `src == dest`, return `true`.
2. Create a `visited` array to avoid revisiting nodes.
3. Push the source node into a queue.
4. While the queue is not empty:
   - Pop the front node.
   - Traverse all its neighbors.
   - If a neighbor has not been visited:
     - Mark it as visited.
     - If it is the destination, return `true`.
     - Otherwise, push it into the queue.
5. If BFS finishes without finding the destination, return `false`.

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

bool hasPath(int src, int dest, vector<vector<int>>& adj) {
    if (src == dest)
        return true;

    int n = adj.size();
    vector<bool> v(n, false);
    queue<int> q;

    q.push(src);
    v[src] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
          if (node == dest)
            return true;
        for (auto it : adj[node]) {
            if (!v[it]) {
                v[it] = true;
                q.push(it);
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0},
        {1},
        {}
    };

    cout << hasPath(0, 3, adj) << endl; // 1
    cout << hasPath(2, 3, adj) << endl; // 1
    cout << hasPath(4, 0, adj) << endl; // 0
}
```

---

## Dry Run

### Graph

```
0 ---- 1 ---- 3
|
2

4 (isolated)
```

### Example 1

```cpp
hasPath(0, 3)
```

| Queue | Visited | Action |
|------|---------|--------|
| 0 | {0} | Start BFS |
| 1,2 | {0,1,2} | Visit neighbors of 0 |
| 2,3 | {0,1,2,3} | Found destination |

**Answer:** `true`

---

### Example 2

```cpp
hasPath(2, 3)
```

Traversal:

```
2 → 0 → 1 → 3
```

Destination found.

**Answer:** `true`

---

### Example 3

```cpp
hasPath(4, 0)
```

Node `4` has no neighbors.

Traversal:

```
4
```

Queue becomes empty.

**Answer:** `false`

---

## Time Complexity

- **BFS Traversal:** `O(V + E)`

where:
- `V` = Number of vertices
- `E` = Number of edges

---

## Space Complexity

- Visited array: `O(V)`
- Queue: `O(V)`

**Overall:** `O(V)`

---

## Key Points

- BFS guarantees that every reachable vertex is visited exactly once.
- The `visited` array prevents infinite loops in cyclic graphs.
- Returning immediately when the destination is found avoids unnecessary traversal.
- Works for both connected and disconnected graphs.