# Hashsets

## Common Operations

```cpp
#include <unordered_set>
std::unordered_set<int> hs;

hs.insert(5); // add element
hs.erase(5);  // remove an element (by value)
hs.find(5);   // returns iterator, or hs.end() if nil
hs.empty();   // true of size == 0
hs.size();    // # of elements
hs.clear();   // remove everything

// membership check; prefer over find() when iterator is not needed
if (hs.count(5)) {...}

// C++20: contains() is clearer than count() for a boolean check
hs.contains(5);

// iteration
for (int x : hs) { ... }
```
