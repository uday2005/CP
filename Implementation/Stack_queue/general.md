## C++ STL: Stack and Queue

### Stack

- **Header:** `#include <stack>`
- **Type:** LIFO (Last In, First Out)
- **Common Methods:**
  - `push(x)`: Add element to top
  - `pop()`: Remove top element
  - `top()`: Access top element
  - `empty()`: Check if stack is empty
  - `size()`: Number of elements

**Example:**
```cpp
#include <stack>
using namespace std;

stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.pop();         // Removes 30
int x = st.top(); // x = 20
bool isEmpty = st.empty();
```

---

### Queue

- **Header:** `#include <queue>`
- **Type:** FIFO (First In, First Out)
- **Common Methods:**
  - `push(x)`: Add element to back
  - `pop()`: Remove front element
  - `front()`: Access front element
  - `back()`: Access last element
  - `empty()`: Check if queue is empty
  - `size()`: Number of elements

**Example:**
```cpp
#include <queue>
using namespace std;

queue<int> q;
q.push(10);
q.push(20);
q.push(30);
q.pop();           // Removes 10
int y = q.front(); // y = 20
int z = q.back();  // z = 30
bool isEmpty = q.empty();
```

---

**Summary Table**

| Container | Access Order | Fastest Operations | Typical Use      |
|-----------|--------------|--------------------|------------------|
| stack     | LIFO         | push, pop, top     | DFS, undo, etc.  |
| queue     | FIFO         | push, pop, front   | BFS, scheduling  |