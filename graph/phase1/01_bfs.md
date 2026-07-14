### BFS (Breadth First Search)

* BFS **level by level** traversal karta hai.
* Isme **Queue** use hoti hai.
* Pehle current level ke saare nodes visit hote hain, phir next level ke.

### Steps

1. `visited` array banao aur sabko `false` se initialize karo.
2. Ek `queue` banao.
3. Start node ko queue me daal do.
4. Start node ko `visited = true` mark kar do.
5. Jab tak queue empty na ho:

   * Front node nikalo.
   * Uske saare adjacent nodes check karo.
   * Agar koi node visited nahi hai:

     * Usko `visited = true` mark karo.
     * Queue me push kar do.

```cpp
#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
```

## Dry Run

Graph:

```text
0 ---- 1
|      |
2 ---- 3
```

Start = `0`

Initial:

```text
Queue = [0]
Visited = [T, F, F, F]
```

### Iteration 1

* Pop `0`
* Print `0`
* Adjacent = `1, 2`

```text
Queue = [1, 2]
Visited = [T, T, T, F]
```

### Iteration 2

* Pop `1`
* Print `1`
* Adjacent = `0, 3`
* `0` already visited
* Push `3`

```text
Queue = [2, 3]
Visited = [T, T, T, T]
```

### Iteration 3

* Pop `2`
* Print `2`
* Adjacent = `0, 3`
* Dono already visited

```text
Queue = [3]
```

### Iteration 4

* Pop `3`
* Print `3`

```text
Queue = []
```

Output:

```text
0 1 2 3
```

## Time Complexity

* **O(V + E)**

`V` = Number of Vertices

`E` = Number of Edges

## Space Complexity

* **O(V)**

Queue + Visited array

## Yaad Rakhna

* Queue ⇒ **FIFO**
* BFS ⇒ **Level by Level**
* Node ko **push karte hi visited = true** mark karo.
* Agar graph disconnected ho to har unvisited node se BFS call karni padegi.
