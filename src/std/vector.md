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

### Iterating a Vector

**Read-Only (making copies)**

If you only need to read values and the elements are cheap to copy (like integers),
you can copy each value into the loop variable

```cpp
std::vector<int> vec = {10, 20, 30};

for (auto x : vec) {
    std::cout << x << " "; // Prints: 10 20 30
}
```

**Read-Only (By `const` Reference)**

If your vector contains heavy objects (like `std::string` or custom classes), 
use `const auto&` to avoid expensive copies while ensuring the vector data cannot be modified.

```cpp
std::vector<std::string> words = {"apple", "banana", "cherry"};

for (const auto& word : words) {
    std::cout << word << " ";
}
```

**Modifying Elements (By Reference)**

If you need to change the actual values inside the vector, use a non-const reference (`auto&`).

```cpp
std::vector<int> vec = {1, 2, 3};

for (auto& x : vec) {
    x *= 2; // Doubles each element in the original vector
}
// vec is now {2, 4, 6}
```

**Traditional Iterator-Based**

If you need direct access to the pointer-like iterator to erase elements, use standard algorithms, or need the index positioning, you can use `auto` to replace the verbose iterator declaration.

```cpp
std::vector<int> vec = {10, 20, 30};

// 'it' is automatically deduced as std::vector<int>::iterator
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " "; // Dereference the iterator to get the value
}
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
