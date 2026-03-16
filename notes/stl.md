
# STL in C++

## Overview
The Standard Template Library (STL) is a powerful library in C++ that provides generic programming tools including containers, algorithms, and iterators.

## Main Components

### Containers
- **Sequence Containers**: `vector`, `deque`, `list`
- **Associative Containers**: `set`, `map`, `multiset`, `multimap`
- **Unordered Containers**: `unordered_set`, `unordered_map`
- **Adapters**: `stack`, `queue`, `priority_queue`

#### `vector`
- when creating a vector, for memory reasons, it's best to create it with the size you already need.
- if you insert somethig further to the left, the API copies each os the numbers to the right and inserts the element. (Linear cost)
- `push_back()` has a constant cost.

#### `set`
- Search, insert, and delete in O(log n) time
- Does not allow duplicates.
- Elements are always sorted in ascending order by default
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
