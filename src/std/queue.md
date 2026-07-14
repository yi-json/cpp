# Queue

## Common Operations

```cpp
#include <queue>
std::queue<int> q;

q.push(5); // add to back
q.pop();   // remove from FRONT
q.front(); // ref to front elt
q.back();  // ref to back elt
q.empty(); // true if size == 0
q.size();  // # of elts
```

## Usage

To assign the front value of a queue to a variable and pop
it:

```cpp
int x = q.front();
q.pop();
```
