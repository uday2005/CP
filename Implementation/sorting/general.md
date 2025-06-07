### Common C++ STL Algorithms for Searching & Sorting

- **sort(v.begin(), v.end())**: Sorts a container or array in increasing order.
- **reverse(v.begin(), v.end())**: Reverses a container or array.
- **lower_bound(v.begin(), v.end(), x)**: Returns iterator to the first element **not less than** (≥) `x` in a sorted range.
- **upper_bound(v.begin(), v.end(), x)**: Returns iterator to the first element **greater than** (>) `x` in a sorted range.
- **equal_range(v.begin(), v.end(), x)**: Returns a pair of iterators for the range of elements **equal to** `x` in a sorted range.
- **binary_search(v.begin(), v.end(), x)**: Returns `true` if `x` exists in a sorted range, else `false`.
- **find(v.begin(), v.end(), x)**: Returns iterator to the first occurrence of `x` in a range (not necessarily sorted).
- **count(v.begin(), v.end(), x)**: Counts the number of occurrences of `x` in a range.
- **min_element(v.begin(), v.end())**: Returns iterator to the **minimum** element in a range.
- **max_element(v.begin(), v.end())**: Returns iterator to the **maximum** element in a range.
- **next_permutation(v.begin(), v.end())**: Rearranges to the **next lexicographical permutation**. Returns `true` if such permutation exists.
- **prev_permutation(v.begin(), v.end())**: Rearranges to the **previous lexicographical permutation**.
- **partition(v.begin(), v.end(), pred)**: Partitions a range based on a predicate `pred`.
- **nth_element(v.begin(), v.begin() + n, v.end())**: Rearranges so that the nth element is the one that would be in that position in a sorted array (elements before are less, after are greater).

---

#### **How to use each method:**
Use lower_bound, upper_bound, equal_range, and binary_search only on sorted data.
The rest can be used on any container or array.

```cpp
// sort
sort(v.begin(), v.end());

// reverse
reverse(v.begin(), v.end());

// lower_bound
auto it = lower_bound(v.begin(), v.end(), x);

// upper_bound
auto it = upper_bound(v.begin(), v.end(), x);

// equal_range
auto p = equal_range(v.begin(), v.end(), x); // p.first, p.second

// binary_search
bool exists = binary_search(v.begin(), v.end(), x);

// find
auto it = find(v.begin(), v.end(), x);

// count
int cnt = count(v.begin(), v.end(), x);

// min_element
auto it = min_element(v.begin(), v.end());

// max_element
auto it = max_element(v.begin(), v.end());

// next_permutation
bool has_next = next_permutation(v.begin(), v.end());

// prev_permutation
bool has_prev = prev_permutation(v.begin(), v.end());

// partition
partition(v.begin(), v.end(), pred); // pred is a function or lambda

// nth_element
nth_element(v.begin(), v.begin() + n, v.end());
```

## Sorting in C++ — Notes

---

### Basic Usage

**Sorting a vector in increasing order:**
```cpp
vector<int> v = {4,2,5,3,5,8,3};
sort(v.begin(), v.end()); // v becomes [2,3,3,4,5,5,8]
```

**Sorting a vector in decreasing order:**
```cpp
sort(v.rbegin(), v.rend());
```

**Sorting an array:**
```cpp
int n = 7;
int a[] = {4,2,5,3,5,8,3};
sort(a, a + n);
```

**Sorting a string:**
```cpp
string s = "monkey";
sort(s.begin(), s.end()); // s becomes "ekmnoy"
```

---

### Comparison Operators

- `sort` uses the `<` operator by default.
- Built-in types (int, string, etc.) have this operator defined.
- For `pair`, sorting is by `.first`, then `.second`.
- For `tuple`, sorting is by the first element, then second, etc.

**Example: Sorting pairs**
```cpp
vector<pair<int,int>> v = {{1,5}, {2,3}, {1,2}};
sort(v.begin(), v.end()); // Result: (1,2), (1,5), (2,3)
```

**Example: Sorting tuples**
```cpp
vector<tuple<int,int,int>> v = {{2,1,4}, {1,5,3}, {2,1,3}};
sort(v.begin(), v.end()); // Result: (1,5,3), (2,1,3), (2,1,4)
```

---

### User-defined Structs

- You must define `operator<` for custom structs to use `sort`.

**Example:**
```cpp
struct P {
    int x, y;
    bool operator<(const P &p) const {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};
```

---

### Custom Comparison Functions

- You can pass a custom comparator to `sort`.

**Example: Sort strings by length, then alphabetically**
```cpp
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
sort(v.begin(), v.end(), comp);
```

---

### Summary Table

| Data Type         | Default Sort Order         | Custom Sort Possible? |
|-------------------|---------------------------|----------------------|
| int, string       | Yes (by value)            | Yes                 |
| pair, tuple       | Yes (lexicographical)     | Yes                 |
| struct/class      | No (unless operator<)     | Yes                 |

---

## C++ Binary Search Functions and Advanced Patterns — Notes

### Standard Library Binary Search Functions

- **`lower_bound`**: Returns a pointer/iterator to the first element **not less than** `x` (i.e., `>= x`). Atlest x 
- **`upper_bound`**: Returns a pointer/iterator to the first element **greater than** `x` (i.e., `> x`).
- **`equal_range`**: Returns a pair of iterators/pointers: the range of elements equal to `x` (i.e., `[lower_bound, upper_bound)`).

**All require the array or container to be sorted!**

---

#### Example: Check if an element exists in an array

```cpp
auto k = lower_bound(array, array + n, x) - array;
if (k < n && array[k] == x) {
    // x found at index k
}
```

---

#### Example: Count occurrences of `x` in an array

```cpp
auto a = lower_bound(array, array + n, x);
auto b = upper_bound(array, array + n, x);
cout << b - a << "\n"; // Number of elements equal to x
```

**Using `equal_range`:**
```cpp
auto r = equal_range(array, array + n, x);
cout << r.second - r.first << "\n";
```

---

### Finding the Smallest Solution (Binary Search on Answer)

- Often used to find the **smallest value `k`** for which a function `ok(x)` becomes true.
- `ok(x)` is **false** for all `x < k` and **true** for all `x >= k`.

**Pattern:**
```cpp
int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (!ok(x + b)) x += b;
}
int k = x + 1; // Smallest k such that ok(k) is true
```
- Start with a jump length `z` large enough that `ok(z)` is true.
- The loop finds the largest `x` for which `ok(x)` is false, so `k = x + 1` is the answer.

**Time Complexity:**  
- Calls `ok` O(log z) times.  
- If `ok` is O(n), total is O(n log z).

---

### Finding the Maximum Value (Peak in Unimodal Function)

- Used when a function `f(x)` is **first increasing, then decreasing** (unimodal).
- Goal: Find `k` such that:
  - `f(x) < f(x+1)` when `x < k`
  - `f(x) > f(x+1)` when `x >= k`

**Pattern:**
```cpp
int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (f(x + b) < f(x + b + 1)) x += b;
}
int k = x + 1; // Position of the peak
```
- This finds the largest `x` where `f(x) < f(x+1)`, so the peak is at `k = x + 1`.

**Note:**  
- If `f(x)` can have equal consecutive values, this method may not work (ambiguous direction).

---

### Summary Table

| Function/Pattern         | Purpose                                 | Usage Example                |
|--------------------------|-----------------------------------------|------------------------------|
| `lower_bound`            | First element `>= x`                    | Find/insert/search           |
| `upper_bound`            | First element `> x`                     | Count occurrences            |
| `equal_range`            | Range of elements equal to `x`          | Count/erase all occurrences  |
| Binary search on answer  | Find smallest `k` where `ok(k)` is true | Parametric search problems   |
| Peak finding             | Find max in unimodal function           | Bitonic/peak element search  |

---

**Tip:**  
- Use these patterns for efficient searching and optimization in sorted data or monotonic/unimodal functions!