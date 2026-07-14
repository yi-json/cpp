# Hashmaps

## Cool Tricks

When iterating a hashmap, we should do a lookup once by declaring an iterator.

```cpp
auto it = hs.find(...);
if (it != hs.end()) {
    return {i, i->second};
}
```
