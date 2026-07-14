# Vectors

## Common Operations

```cpp
#include <vector>

v.push_back(5);    // add to end
v.pop_back();      // remove from end (no return value)
v.emplace_back(5); // construct in place at end (no copy/move for obj)
```

### `push_back` vs `emplace_back`

For simple types like `int`, use either.

For pairs/structs/objects with real constructors,
`emplace_back` is generally preferred since it avoids the
extra copy.

```cpp
v.push_back(std::make_pair(1, 2));
v.emplace_back(1, 2); // constructs the pair(1,2) inside
                      // vector's storage -- no
                      // extra copy/move

// custom class
v.push_back(Interval(1, 5)); // builds temp Interval, copies it in
v.emplace_back(1, 5);        // builds the Interval directly in vector, no temp
```

## 2D Vectors

### Initialization

```cpp
// basic delcaration
std::vector<std::vector<int>> grid;

// MxN grid, all filled with default val
int m = 3, n = 4;
std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
```
