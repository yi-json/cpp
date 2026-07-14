# Sorting

## Standard Sorting

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 1, 3, 9, 2};
std::sort(v.begin(), v.end());                      // ascending
std::sort(v.begin(), v.end(), std::greater<int>()); // descending
```

## Custom Comparator

A lambda returning `true` if the first arg should come
before the second.

```cpp
std::sort(v.begin(), v.end, [](const auto &a, const auto &b) {
    return a.second < b.second; // sort by second val asc
});
```

## Sorting Pairs / Tuples

`std::pair` / `std::tuple` sort lexicographically by default
(first element, then second as tiebreaker). No comparator
needed for that order.

```cpp
std::vector<std::pair<int, int>> v = {{2, 1}, {1, 9}, {1, 3}};
std::sort(v.begin(), v.end());
```

## Sorting a Custom Struct

Pass a comparator

```cpp
struct Interval {
    int start, end;
};

std::sort(v.begin(), v.end(), [](const Interval &a, const Interval &b) {
    return a.start < b.start;
});
```

## Checking if Sorted

```cpp
std::is_sorted(v.begin(), v.end()); // true or false
```
