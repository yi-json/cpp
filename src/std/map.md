# Hashmaps

## Common Operations

```cpp
#include <unordered_map>

std::unordered_map<std::string, int> m;

m["apple"] = 3;            // insert or overwrite
m.insert({"pear", 2});     // insert only if key doesn't exist
m.emplace("kiwi", 1);      // construct in place, also no overwrite
m.erase("apple");          // remove by key (returns # removed: 0 or 1)
m.size();
m.empty();
```

### Lookup

```cpp
m.count("apple");     // 1 if exists, 0 if not
m.contains("apple");  // C++20, returns bool
m.at("apple");        // throws std::out_of_range if missing

auto it = m.find("apple");
if (it != m.end()) {
    int val = it->second; // it->first is the key
}
```

### `[]` gotcha

`m[key]` **inserts** a default value (0 for int, "" for string)
if the key doesn't exist. Don't use it just to check whether a key exists.

```cpp
if (m["banana"] > 0) {} // banana now exists in m with value 0
if (m.count("banana")) {} // safe, no insert
```

That same behavior is why frequency counting works:

```cpp
std::unordered_map<int, int> freq;
for (int x : nums) {
    freq[x]++; // missing key starts at 0, then ++
}
```

## Iteration

```cpp
// C++17 structured bindings
for (const auto& [key, val] : m) {
    std::cout << key << ": " << val << "\n";
}

// older style
for (const auto& p : m) {
    p.first; p.second;
}
```

Order is **not** guaranteed in `unordered_map`.

## `unordered_map` vs `map`

|            | `unordered_map`       | `map`                      |
|------------|-----------------------|----------------------------|
| Under hood | hash table            | red-black tree             |
| Lookup     | O(1) avg, O(n) worst  | O(log n)                   |
| Ordered?   | no                    | yes, sorted by key         |
| Header     | `<unordered_map>`     | `<map>`                    |

Default to `unordered_map`. Use `map` when you need sorted keys
or `lower_bound` / `upper_bound`.

## Pair / Custom Keys

`unordered_map` has no built-in hash for `std::pair`. Options:

```cpp
// 1. just use map (pair has operator<)
std::map<std::pair<int, int>, int> m;

// 2. custom hash
struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};
std::unordered_map<std::pair<int, int>, int, PairHash> m;

// 3. encode as a single key (grid problems)
int key = r * n + c;
```

## Hash Sets

Same idea, keys only.

```cpp
#include <unordered_set>

std::unordered_set<int> s;
s.insert(5);
s.count(5);   // 1 or 0
s.erase(5);
```