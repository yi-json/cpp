# Strings

## Empty Strings

To declare a `std::string` with nothing in it, just
default-construct it — no need to pass `""`:

```cpp
std::string s; // empty, preferred
```

Useful checks and operations:

```cpp
s.empty(); // true if length == 0 (prefer this over s.size() == 0 or s == "")
s.size();  // 0
s.clear(); // resets an existing string back to empty
```

## Number to String

Use `std::to_string` to convert any numeric type (int, long,
float, double, etc.) to a `std::string`:

```cpp
std::string a = std::to_string(42);   // "42"
std::string b = std::to_string(3.14); // "3.140000"
std::string c = std::to_string(-7L);  // "-7"
```

To go the other way (string to number), use `std::stoi`,
`std::stol`, `std::stod`, etc.:

```cpp
int x = std::stoi("42");      // 42
double y = std::stod("3.14"); // 3.14
```
