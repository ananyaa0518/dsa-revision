# 05. Cycle Detection in Undirected Graph (BFS)

## Problem

Given an undirected graph, determine whether it contains a cycle.

---

## Key Idea

A visited neighbour **does not always mean a cycle**.

If the visited neighbour is the **parent**, ignore it.

If the visited neighbour is **not the parent**, a cycle exists.

---

## Trick

Instead of storing only the node, store:

- Current Node
- Parent Node

```cpp
queue<pair<int,int>> q;
```

Each pair stores:

```text
(node, parent)
```

Example:

```text
(2,1)

Current Node = 2
Parent = 1
```

---

## Pseudocode

```text
Create visited[]

For every vertex

    If not visited

        Push (start,-1)

        Mark visited

        While queue not empty

            Pop (node,parent)

            For every neighbour

                If neighbour not visited

                    Mark visited

                    Push(neighbour,node)

                Else if neighbour != parent

                    Return true

Return false
```

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

bool bfs(int start,
         vector<vector<int>>& adj,
         vector<bool>& visited) {

    queue<pair<int,int>> q;

    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node]) {

            if (!visited[it]) {
                visited[it] = true;
                q.push({it, node});
            }
            else if (it != parent) {
                return true;
            }
        }
    }

    return false;
}

bool hasCycle(vector<vector<int>>& adj) {

    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            if (bfs(i, adj, visited))
                return true;
        }
    }

    return false;
}

int main() {

    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    if (hasCycle(adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}
```

---

## Dry Run

Graph

```text
0 ----- 1
|       |
2 ----- 3
```

Queue

```text
(0,-1)
```

↓

Visit

```text
1
2
```

Queue

```text
(1,0)
(2,0)
```

↓

Pop

```text
(1,0)
```

Visit

```text
3
```

Queue

```text
(2,0)
(3,1)
```

↓

Pop

```text
(2,0)
```

Neighbour

```text
3
```

Already Visited?

✅ Yes

Is Parent?

❌ No

Cycle Found ✅

---

## Complexity

**Time**

```text
O(V + E)
```

**Space**

```text
O(V)
```

---

## Pattern

Normal BFS

```cpp
queue<int> q;
```

Cycle Detection BFS

```cpp
queue<pair<int,int>> q;
```

Extra Information Stored

```text
Parent Node
```

Condition

```cpp
if (!visited[neighbour]) {
    ...
}
else if (neighbour != parent) {
    return true;
}
```

---

## Interview Trick ⭐

Whenever you hear:

- Detect Cycle
- Undirected Graph
- BFS

Immediately think:

```text
Queue of (Node, Parent)
```

and remember:

```text
Visited Neighbour
        +
Neighbour is NOT Parent
        =
Cycle
```