# Heaps / Priority Queues

## Common Operations

```cpp
#include <queue>
std::priority_queue<int> pq; // max-heap default

// to heapify a given vec -- O(n)
std::vector<int> v = {1, 2, 3};
std::priority_queue<int> pq(v.begin(), v.end());
pq.top(); // 3

pq.push(5); // O(log n)
pq.pop();   // remove the top (largest) - no return val
pq.top();
pq.empty(); // true if size == 0
pq.size();
```

## Min-Heap

Priority Queues in C++ are max-heaps by default. To use a
min-heap:

### Template Parameters

```cpp
#include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

// heapify -- O(n)
std::vector<int> v = {1, 2, 3};
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(v.begin(), v.end());

minHeap.push(5);
minHeap.push(1);
minHeap.push(3);
minHeap.top(); // 1 (smallest)
```

### Negating Values

```cpp
std::priority_queue<int> pq; // max heap
pq.push(-5);
pq.push(-1);
pq.push(-3);
int smallest = -pq.top(); // 1

```
