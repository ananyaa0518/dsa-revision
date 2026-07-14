### Count Connected Components using BFS

Agar graph **disconnected** hai, to ek baar BFS chalane se saare nodes visit nahi honge.

**Trick:**

* Har node par jao.
* Agar node **visited nahi hai**, matlab ek **naya component** mila.
* Us node se BFS chala do.
* Jitne nodes us component ke hain sab visited ho jayenge.
* `count++`

Har baar jab nayi BFS start hoti hai, ek **connected component** milta hai.

---

### Code

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

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

int countComponents(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<bool> visited(n, false);

    int count = 0;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            bfs(i, adj, visited);

            count++;
        }
    }

    return count;
}

int main() {

    vector<vector<int>> adj = {
        {1},
        {0},
        {3},
        {2},
        {}
    };

    cout << countComponents(adj);

    return 0;
}
```

---

### Dry Run

Graph:

```text
0 ----- 1

2 ----- 3

4
```

Adjacency List

```cpp
0 -> 1
1 -> 0
2 -> 3
3 -> 2
4 -> {}
```

Initially

```text
visited = [F, F, F, F, F]
count = 0
```

---

## i = 0

Node 0 visited nahi hai.

➡️ BFS start from 0.

Visit sequence:

```text
0 -> 1
```

Ab

```text
visited = [T, T, F, F, F]
count = 1
```

---

## i = 1

Already visited.

Skip.

---

## i = 2

Visited nahi hai.

➡️ BFS start from 2.

Visit sequence

```text
2 -> 3
```

Ab

```text
visited = [T, T, T, T, F]
count = 2
```

---

## i = 3

Already visited.

Skip.

---

## i = 4

Visited nahi hai.

BFS start from 4.

Sirf ek node hai.

```text
visited = [T, T, T, T, T]
count = 3
```

Loop khatam.

Return

```text
3
```

---

# Visualization

```text
Component 1

0 ----- 1

Component 2

2 ----- 3

Component 3

4
```

Total Components = **3**

---

### Trick 

**Connected Component = Ek baar BFS/DFS chalane se jitne nodes visit ho jaye.**

Isliye:

```cpp
for every node

    agar visited nahi hai

        BFS chalao

        count++
```

### Easy way yaad rakhna

* **Unvisited node mila?** ➜ Matlab naya component start hua.
* **BFS/DFS chala do** ➜ Pura component cover ho jayega.
* **Ek hi baar count badhao.**

---

# Time Complexity

```text
O(V + E)
```

Har node aur har edge sirf ek hi baar visit hoti hai.

# Space Complexity

```text
O(V)
```

* Visited array
* Queue
