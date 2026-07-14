# Object Oriented Programming

## Constructor

A method with the same name as the class, no return type

```cpp
class Point {
private:
    int x, y;
public:
    // constructor
    Point(int x, int y) : x(x), y(y) {}

    // getters and setters
    int getX() const { return x; }
    int setX(int new X) { x = newX; }
};

// Usage
Point p1(3, 4); // calls constructor
Point p2{3, 4}; // brace-init, also calls it
```

The `private` keyword is optional -- it's `private` by
default.

## Member Access: `.` vs `->`

`->` when the left side is a pointer, `.` when it isn't.

Suppose we have the following class:

```cpp
class Interval {
public:
    int start, end;
    Interval(int start, int end) : start(start), end(end) {}
}

Interval i(1, 5);   // direct object
i.start;            // dot -- i is not a pointer

Interval *ptr = &i;
ptr->start;         // arrow -- ptr is a pointer
(*ptr).start;       // equivalent to ptr->start

Interval &ref = i;
ref.start;          // dot - references act like the obj 
                    //       itself, not a pointer
```

How to quickly check: look at the variable's declared type
-- does it have a `*` in it? If so, use `->` else `.`
