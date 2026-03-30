
# STL in C++

## Overview
The Standard Template Library (STL) is a powerful library in C++ that provides generic programming tools including containers, algorithms, and iterators.

## Main Components

### Containers
- **Sequence Containers**: `vector`, `deque`, `list`
- **Associative Containers**: `set`, `map`, `multiset`, `multimap`
- **Unordered Containers**: `unordered_set`, `unordered_map`
- **Adapters**: `stack`, `queue`, `priority_queue`

#### `vector` -> dinamic array
- stores elements in a contiguos block of memory (side-by-side)
- uses two main internal variables: 
    - `size` -> how many elements it currently holds
    - `capacity` -> how much space is currently allocated in memory 
- when the size reach the capacity and you add a new element, the vector double his capacity, so, when creating a vector, for memory reasons, it's best to create it with the size you already need.
- operations:
    - random access -> `v[i]`, `front()`, `back()` -> O(1)
    - insert/delete at the end -> `push_back()`, `emplace_back()`, `pop_back()` -> amortized O(1)
    - insert/delete in the middle or front -> `insert()`, `erase()` -> O(n) -> requires shifting
    - size and capacity check -> `size()`, `capacity()` -> O(1)
- advantages -> random access instantly
    - It should be your default choice for 99% of competitive programming problems.
- disadvantages -> slow insertions and deletions at the front or middle, because it has to shift everything else (if you need to insert/delete at the front frequently, use `deque`)

- if you insert somethig further to the left, the API copies each os the numbers to the right and inserts the element. (Linear cost)
- `push_back()` has a constant cost.

#### `list` -> doubly linked list
- stores each element in a isolated node em some random memory location. 
- loads three things:
    - the value
    - a pointer pointing to the next value
    - a pointer pointing to the previous value
- operations: 
    - access in the ends -> `front()`, `back()` -> O(1)
    - access in the middle -> does not exist
    - insert/delete in the ends -> `push_back()`, `push_front()`, `pop_back()` and `pop_front()` -> O(1)
    - insert/delete in the middle -> `insert()` and `erase()` -> O(1)*
    - `size()` -> O(1)
- when to use - advantages -> insert and delete elements from the middle without need to shift the others.
    - only use when the problem evolves many inserts and delections in the middle
- disadvantages -> no random access (list[n] does not exist).

#### `deque`-> double ended queue
- allows incredibly fast insertion and deletion at both its beginning and its end
- unlike a vector, it does not store all elements in a single contiguous memory block, it uses a sequence of individually allocated fixed-size arrays (chunks) and keeps a central array of pointers (a "map") to track them. when it runs out of space at the front or back, it simply allocates a new chunk and updates the pointer map.
- operations:
    - random access -> `dq[i]`, `front()`, `back()` -> O(1)
    - insert/delete at BOTH ends -> `push_front()`, `push_back()`, `pop_front()`, `pop_back()` -> O(1)
    - insert/delete in the middle -> `insert()`, `erase()` -> O(N) (requires shifting elements, similar to a vector).
    - size and empty check -> `size()`, `empty()` -> O(1)
- advantages:
    - the Best of Both Worlds: It gives you the O(1) random access of a vector AND the O(1) front insertion/deletion of a list.
    - it is the absolute standard choice for Sliding Window Maximum/Minimum algorithms and 0-1 BFS
- disadvantages:
    - slightly slower than a vector for purely sequential iteration because the CPU cache has to jump between different memory chunks.
    - memory overhead: It consumes more memory than a vector due to the complex internal pointer structure.
    - since memory is not strictly contiguous, you cannot use C-style pointer arithmetic (&dq[0] + i) safely
- if the problem does not require insertions or deletions at the front, always use `vector`.

#### `set` -> Ordered Collection of Unique Elements
- Does not allow duplicates.
- Elements are always sorted in ascending order by default
- under the hood -> its usually implemented as a self-balancing binary search tree.
- every time you insert a number, the tree navigates left or right and re-balances itself
- operations:
    - search -> `find()`, `count()` -> O(log n)
    - insert -> `insert()`, `emplace()` -> O(log n)
    - remove -> `erase()` -> O(log n)
    - size and empty check -> `size()`, `empty()` -> O(1)
- advantages:
    - Native de-duplication
    - always sorted -> you can iterate through a set from `begin()`to `end()` and the elements will come out in perfect sorted sorder.
- disadvantages:
    - no random access
    - high memory overhead -> each element store pointers to its parent, left child and right child
```python
#include <iostream>
#include <set>
using namespace std;

int main() {

    // Creating an empty set
    set<int> s1;

    // Initialize set with list 
    set<int> s2 = {1, 2, 3, 2, 1}; 

    // Traversing the set
    for (auto& x : s2)
        cout << x << " ";
    cout << endl;

    return 0;
}
```

#### `map` -> Ordered Key-Value Dictionary
- represents a collection of key-value pairs (like a dictionary), automatically sorted by the unique keys.
- very similar to the set, but stores a `pair<const Key, Value>` and the tree is balanced strictly based on the key.
- operations:
    - access/insert a value by its key -> `m[key]` -> O(log n)
    - search for a key -> `find()`, `count()` -> O(log n)
    - remove a pair -> `erase()` -> O(log n)
- advantages -> extremaly powerful counting (e.g. counting how many times a string appears) or mapping complex data types (like mapping a string name to an ind ID)
- disadvantages -> memory overhead and O(log n) operational cost. 

#### `unordered_set` -> Unsorted Collection of Unique Elements
- Operations:
    - Search for an element -> `find()`, `count()` -> Average O(1), Worst case O(N)
    - Insert an element -> `insert()`, `emplace()` -> Average O(1), Worst case O(N)
    - remove an element -> `erase()` -> Average O(1), Worst case O(N)
- advantages -> Incredibly fast for checking if an element exists. (O(1))
- disadvantages -> no order

#### `unordered_map` -> Unsorted Key-Value Dictionary
- Operations:
    - access/insert a value by its key -> `m[key]` -> Average O(1), Worst case O(N)
    - search for a key -> `find()`, `count()` -> Average O(1), Worst case O(N)
    - remove a pair -> `erase()` -> Average O(1), Worst case O(N)
- advantages -> The absolute fastest way to map a key to a value or count frequencies of elements, assuming a good hash function.
- disadvantages -> consumes more memory because it needs to maintain the array of buckets even if they are empty.

#### `queue` -> First-In First-Out
- operations:
    - access the front element -> `front()` -> O(1)
    - access the back element -> `back()` -> O(1)
    - insert at the end -> `push()`, `emplace()` -> O(1)
    - remove from the front -> `pop()`-> O(1) 
        - does not return the element, only removes it
        - to know the element, you must call `front()` before `pop()`
    - size and empty check ->  `śize()`, `empty()` -> O(1)
- advantages -> extremely fast, enforces strict logical rules and essential for BFS (Breadth-First Search) algorithms.
- disadvantages -> no random access and no iterators (the only way to read all elements is by popping them out one by one until the queue is empty)

####  `stack` -> Last-In First-Out
- operations:
    - access the top element -> `top()` -> O(1)
    - insert at the top -> `push()`, `emplace()` -> O(1)
    - remove from the top -> `pop()` -> O(1)
    - size and empty check -> `size()`, `empty()` -> O(1)
- advantages -> DFS (Depth-First Search), parsing/matching problems and powerful monotonic stack technique.
- disadvantages -> no random access and no iterators (same as the queue).

#### `priority_queue` -> max-heap
- represents a queue where elements are strictly ordered by their "priority" (by default in c++, the largest element is always at the front/top)
- it uses heap algorithms (`push_heap`, `pop_heap`) to organize the vector as a Binary Tree mapped inside an array, this guarantees the maximum element is always at the root.
- operations:
    - access the top (largest) element -> `top()` -> O(1)
    - insert an element -> `push()`, `emplace()` -> O(log N)
    - remove the top element -> `pop()` -> O(log N)
    - size and empty check -> `size()`, `empty()` -> O(1)
- advantages:
    - dynamically maintains the maximum (or minimum) element as you constantly add and remove items.
    - dijkstra's algorithm (shortest path - min heap), prim's algorithm (minimum spanning tree) and complex greedy algorithms
    ```cpp
    // Creates a Min-Heap (smallest element on top)
    priority_queue<int, vector<int>, greater<int>> pq;
    ```
- disadvantages:
    - no random access, no iterators and logarithmic overhead (it rearranges the internal tree on every insertion/deletion - O(log n))

### Iterators
- Input, output, forward, bidirectional, and random-access iterators
- Enable traversal and manipulation of container elements

### Algorithms
- Sorting: `sort()`, `stable_sort()`
- Searching: `find()`, `binary_search()`
- Manipulation: `copy()`, `transform()`, `reverse()`
- Numeric: `accumulate()`, `inner_product()`, `min()`, `max()`, `lower_bound()`, `upper_bound()`

#### `sort()`
- it already has an efficient implementation, using the best algorithm based on the list to be sorted.
#### `binary_search()` 
- efficiently check whether a specific value exists in a sorted range.
- take the middle value, if it's not the number, analyze if it's smaller ou larger.
```python
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {1, 3, 6, 8, 9};
    int k = 8;

    if (binary_search(v.begin(), v.end(), k))
        cout << k << " is Present";
    else
        cout << k << " is NOT Present";

    return 0;
}
```

#### `lower_bound()`
```python
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = lower_bound(v.begin(), v.end(), 30);

    cout << *it;
    return 0;
}

# Output 
# 30
```
- searches for the first element ≥ 30
- Since 30 exists, it returns an iterator pointing to 30

#### `upper_bound()`
```python
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Finding upper bound for value 30 in vector v
    cout << *upper_bound(v.begin(), v.end(), 30);

    return 0;
}

# Output
# 40
```
- The vector is already sorted
- upper_bound(30) skips 10, 20, 30
- Returns iterator pointing to 40
- Dereferencing the iterator prints 40

### Functors & Lambda Functions
- Function objects for custom behavior
- Lambda expressions for inline operations

## Key Features
- **Generic Programming**: Templates enable type-safe, reusable code
- **Performance**: Highly optimized implementations
- **Compatibility**: Works across standard C++ platforms
