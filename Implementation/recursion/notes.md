# Notes on Recursion Functions (`subset.cpp`)

## 1. skip(p, up)

**Purpose:**  
Skips all occurrences of the character `'a'` in the string `up` and prints all possible results.

**Recursion Tree Example:**  
For `p = ""`, `up = "baacde"`:

```
skip("", "baacde")
├── skip("b", "aacde")
│   ├── skip("b", "acde")
│   │   ├── skip("b", "cde")
│   │   │   ├── skip("bc", "de")
│   │   │   │   ├── skip("bcd", "e")
│   │   │   │   │   ├── skip("bcde", "")
│   │   │   │   │   └── skip("bcd", "")
│   │   │   │   └── skip("bc", "e")
│   │   │   └── skip("b", "de")
│   │   └── skip("b", "cde")
│   └── skip("b", "acde")
└── skip("", "aacde")
```

---

## 2. skip2(up)

**Purpose:**  
Returns a new string with all `'a'` characters removed from `up`.

**Recursion Tree Example:**  
For `up = "baacde"`:

```
skip2("baacde")
├── 'b' + skip2("aacde")
    ├── skip2("acde")
        ├── skip2("cde")
            ├── 'c' + skip2("de")
                ├── 'd' + skip2("e")
                    ├── 'e' + skip2("")
                        └── ""
```

Result: `"bcde"`

---

## 3. skip3(up, given)

**Purpose:**  
Skips all occurrences of the substring `given` in `up`.

**Recursion Tree Example:**  
For `up = "bascappleappfd"`, `given = "apple"`:

```
skip3("bascappleappfd", "apple")
├── 'b' + skip3("ascappleappfd", "apple")
    ├── 'a' + skip3("scappleappfd", "apple")
        ├── 's' + skip3("cappleappfd", "apple")
            ├── 'c' + skip3("appleappfd", "apple")
                ├── skip3("appfd", "apple")
                    ├── 'a' + skip3("ppfd", "apple")
                        ├── 'p' + skip3("pfd", "apple")
                            ├── 'p' + skip3("fd", "apple")
                                ├── 'f' + skip3("d", "apple")
                                    ├── 'd' + skip3("", "apple")
                                        └── ""
```

Result: `"bascappfd"`

---

## 4. skip4(up, given, not_removed)

**Purpose:**  
Skips all occurrences of `given` **unless** they are part of `not_removed`.

**Recursion Tree Example:**  
For `up = "bascappleappfd"`, `given = "app"`, `not_removed = "apple"`:

```
skip4("bascappleappfd", "app", "apple")
├── 'b' + skip4("ascappleappfd", ...)
    ├── 'a' + skip4("scappleappfd", ...)
        ├── 's' + skip4("cappleappfd", ...)
            ├── 'c' + skip4("appleappfd", ...)
                ├── 'a' + skip4("ppleappfd", ...)
                    ├── 'p' + skip4("pleappfd", ...)
                        ├── 'p' + skip4("leappfd", ...)
                            ├── 'l' + skip4("eappfd", ...)
                                ├── 'e' + skip4("appfd", ...)
                                    ├── skip4("fd", ...)
                                        ├── 'f' + skip4("d", ...)
                                            ├── 'd' + skip4("", ...)
                                                └── ""
```

Result: `"bascapplefd"`

---

## 5. subser(p, up)

**Purpose:**  
Prints all subsequences of `up` (including the empty string).

**Recursion Tree Example:**  
For `p = ""`, `up = "ab"`:

```
subser("", "ab")
├── subser("a", "b")
│   ├── subser("ab", "")
│   └── subser("a", "")
└── subser("", "b")
    ├── subser("b", "")
    └── subser("", "")
```

Printed: `ab`, `a`, `b`, `` (empty string)

---

## 6. subser1(p, up, arr)

**Purpose:**  
Stores all non-empty subsequences of `up` in `arr`.

```
subser("", "abc")
├─ Option 1: Include 'a' (p="a", up="bc")
│   ├─ Option 1: Include 'b' (p="ab", up="c")
│   │   ├─ Option 1: Include 'c' (p="abc", up="")
│   │   │   └─ Print "abc"
│   │   ├─ Option 2: Include ASCII 'c' (p="ab99", up="")
│   │   │   └─ Print "ab99"
│   │   └─ Option 3: Exclude 'c' (p="ab", up="")
│   │       └─ Print "ab"
│   ├─ Option 2: Include ASCII 'b' (p="a98", up="c")
│   │   ├─ Option 1: Include 'c' (p="a98c", up="")
│   │   │   └─ Print "a98c"
│   │   ├─ Option 2: Include ASCII 'c' (p="a9899", up="")
│   │   │   └─ Print "a9899"
│   │   └─ Option 3: Exclude 'c' (p="a98", up="")
│   │       └─ Print "a98"
│   └─ Option 3: Exclude 'b' (p="a", up="c")
│       ├─ Option 1: Include 'c' (p="ac", up="")
│       │   └─ Print "ac"
│       ├─ Option 2: Include ASCII 'c' (p="a99", up="")
│       │   └─ Print "a99"
│       └─ Option 3: Exclude 'c' (p="a", up="")
│           └─ Print "a"
├─ Option 2: Include ASCII 'a' (p="97", up="bc")
│   ├─ Option 1: Include 'b' (p="97b", up="c")
│   │   ├─ Option 1: Include 'c' (p="97bc", up="")
│   │   │   └─ Print "97bc"
│   │   ├─ Option 2: Include ASCII 'c' (p="97b99", up="")
│   │   │   └─ Print "97b99"
│   │   └─ Option 3: Exclude 'c' (p="97b", up="")
│   │       └─ Print "97b"
│   ├─ Option 2: Include ASCII 'b' (p="9798", up="c")
│   │   ├─ Option 1: Include 'c' (p="9798c", up="")
│   │   │   └─ Print "9798c"
│   │   ├─ Option 2: Include ASCII 'c' (p="979899", up="")
│   │   │   └─ Print "979899"
│   │   └─ Option 3: Exclude 'c' (p="9798", up="")
│   │       └─ Print "9798"
│   └─ Option 3: Exclude 'b' (p="97", up="c")
│       ├─ Option 1: Include 'c' (p="97c", up="")
│       │   └─ Print "97c"
│       ├─ Option 2: Include ASCII 'c' (p="9799", up="")
│       │   └─ Print "9799"
│       └─ Option 3: Exclude 'c' (p="97", up="")
│           └─ Print "97"
└─ Option 3: Exclude 'a' (p="", up="bc")
    ├─ Option 1: Include 'b' (p="b", up="c")
    │   ├─ Option 1: Include 'c' (p="bc", up="")
    │   │   └─ Print "bc"
    │   ├─ Option 2: Include ASCII 'c' (p="b99", up="")
    │   │   └─ Print "b99"
    │   └─ Option 3: Exclude 'c' (p="b", up="")
    │       └─ Print "b"
    ├─ Option 2: Include ASCII 'b' (p="98", up="c")
    │   ├─ Option 1: Include 'c' (p="98c", up="")
    │   │   └─ Print "98c"
    │   ├─ Option 2: Include ASCII 'c' (p="9899", up="")
    │   │   └─ Print "9899"
    │   └─ Option 3: Exclude 'c' (p="98", up="")
    │       └─ Print "98"
    └─ Option 3: Exclude 'b' (p="", up="c")
        ├─ Option 1: Include 'c' (p="c", up="")
        │   └─ Print "c"
        ├─ Option 2: Include ASCII 'c' (p="99", up="")
        │   └─ Print "99"
        └─ Option 3: Exclude 'c' (p="", up="")
            └─ Print ""

```

**Recursion Tree:**  
Same as `subser`, but only non-empty results are stored.

---

## 7. subser2(p, up)

**Purpose:**  
Returns a vector of all non-empty subsequences of `up`.

**Recursion Tree:**  
Same as `subser1`, but returns a vector instead of printing or storing by reference.

```
subser2("", "abc")
├─ include 'a' (p="a", up="bc")
│   ├─ include 'b' (p="ab", up="c")
│   │   ├─ include 'c' (p="abc", up="") → return ["abc"]
│   │   └─ exclude 'c' (p="ab", up="")  → return ["ab"]
│   │      (parent combines ["abc"] and ["ab"] into ["abc", "ab"])
│   └─ exclude 'b' (p="a", up="c")
│       ├─ include 'c' (p="ac", up="")  → return ["ac"]
│       └─ exclude 'c' (p="a", up="")   → return ["a"]
│          (parent combines ["ac"] and ["a"] into ["ac", "a"])
│   (grandparent combines ["abc", "ab"] and ["ac", "a"] into ["abc", "ab", "ac", "a"])
└─ exclude 'a' (p="", up="bc")
    ├─ include 'b' (p="b", up="c")
    │   ├─ include 'c' (p="bc", up="")  → return ["bc"]
    │   └─ exclude 'c' (p="b", up="")   → return ["b"]
    │      (parent combines ["bc"] and ["b"] into ["bc", "b"])
    └─ exclude 'b' (p="", up="c")
        ├─ include 'c' (p="c", up="")   → return ["c"]
        └─ exclude 'c' (p="", up="")    → return []
           (parent combines ["c"] and [] into ["c"])
    (grandparent combines ["bc", "b"] and ["c"] into ["bc", "b", "c"])
(root combines ["abc", "ab", "ac", "a"] and ["bc", "b", "c"] into ["abc", "ab", "ac", "a", "bc", "b", "c"])

So the thing is that first at the last index or  
when the given string is empty so what we did   
first returns the index from base at each node level  
and after that what we did is we create a new variable of string   vector
which will be combining the include and exclude side  
and returns each time combined value of each node and   
goes upward from tjat position and at last returns  
all combined value.

```

---

## 8. print_sub_iter(string s)

**Purpose:**  
Prints all subsets (subsequences) of the string `s` using **bit masking** (iterative method).

**How it works:**  

- For a string of length `n`, there are `2^n` possible subsets.
- Each subset is represented by a number from `0` to `2^n - 1`.
- For each bit in the number, if the bit is set, include the corresponding character.

**Example for `s = "abc"`:**  

```
n = 3
Subsets (b in binary):

000 -> ""
001 -> "a"
010 -> "b"
011 -> "ab"
100 -> "c"
101 -> "ac"
110 -> "bc"
111 -> "abc"
```

So, output will be:

```
(empty line)
a
b
ab
c
ac
bc
abc
```

---

## 9. print_sub_iter(vector<int> arr)

**Purpose:**  
Prints all subsets of the integer array `arr` using **bit masking** (iterative method).

**How it works:**  

- For an array of size `n`, there are `2^n` possible subsets.
- Each subset is represented by a number from `0` to `2^n - 1`.
- For each bit in the number, if the bit is set, include the corresponding element.

**Example for `arr = {1, 2, 3}`:**  

```text
n = 3
Subsets (b in binary):

000 -> (empty)
001 -> 1
010 -> 2
011 -> 1 2
100 -> 3
101 -> 1 3
110 -> 2 3
111 -> 1 2 3
```

So, output will be:

```text
(empty line)
1
2
1 2
3
1 3
2 3
1 2 3
```

---

## 10. subsets (int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result)

**Purpose:**  
Generates all possible subsets (the power set) of the array `nums` using recursion and backtracking.

**How it works:**  

- At each index, you have two choices:  
  1. Exclude the current element and move to the next index.  
  2. Include the current element in the current subset and move to the next index.
- When the index reaches the end of the array, the current subset is added to the result.

**Recursion Tree Example for nums = [1, 2]:**

```
subsets(0, [1,2], [], result)
├── Exclude 1: subsets(1, [1,2], [], result)
│   ├── Exclude 2: subsets(2, [1,2], [], result)   // []
│   └── Include 2: subsets(2, [1,2], [2], result) // [2]
└── Include 1: subsets(1, [1,2], [1], result)
    ├── Exclude 2: subsets(2, [1,2], [1], result)  // [1]
    └── Include 2: subsets(2, [1,2], [1,2], result)// [1,2]
```

**Result:** `[[], [2], [1], [1,2]]`

---

## 11. subsets2 (int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result)

**Purpose:**  
Generates all subsets, but adds the current subset to the result at every step (not just at the leaves).

**How it works:**  

- At each call, the current subset is added to the result.
- Then, for each element from `index` to end, include it and recurse, then backtrack.

**Recursion Tree Example for nums = [1, 2]:**

```
subsets2(0, [1,2], [], result)
├── Add [] to result
├── i=0: current=[1]
│   ├── Add [1] to result
│   ├── i=1: current=[1,2]
│   │   ├── Add [1,2] to result
│   │   └── Backtrack to [1]
│   └── Backtrack to []
├── i=1: current=[2]
│   ├── Add [2] to result
│   └── Backtrack to []
```

**Result:** `[[], [1], [1,2], [2]]`

---

## 12. subsets3 (int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result)

**Purpose:**  
Generates all unique subsets for arrays that may contain duplicates.

**How it works:**  

- Assumes `nums` is sorted.
- At each index, skip elements that are the same as the previous one (to avoid duplicate subsets).
- Otherwise, works like `subsets2`.

**Recursion Tree Example for nums = [1, 2, 2]:**

```
subsets3(0, [1,2,2], [], result)
├── Add [] to result
├── i=0: current=[1]
│   ├── Add [1] to result
│   ├── i=1: current=[1,2]
│   │   ├── Add [1,2] to result
│   │   ├── i=2: current=[1,2,2]
│   │   │   ├── Add [1,2,2] to result
│   │   │   └── Backtrack to [1,2]
│   │   └── Backtrack to [1]
│   └── i=2: (skipped, nums[2]==nums[1])
│   └── Backtrack to []
├── i=1: current=[2]
│   ├── Add [2] to result
│   ├── i=2: current=[2,2]
│   │   ├── Add [2,2] to result
│   │   └── Backtrack to [2]
│   └── Backtrack to []
├── i=2: (skipped, nums[2]==nums[1])
```

**Result:** `[[], [1], [1,2], [1,2,2], [2], [2,2]]`

---
## Notes on `permuatations2`

### Purpose
Generates **all permutations** of a given string using recursion and returns them as a `vector<string>`.

---

### How It Works

- **Parameters:**  
  - `p`: The current permutation being built.
  - `up`: The remaining characters to permute.

- **Base Case:**  
  - If `up` is empty:
    - If `p` is not empty, return `{p}` (a vector containing the permutation).
    - Else, return an empty vector.

- **Recursive Step:**  
  - For each possible position in `p` (from 0 to `p.size()`), insert the first character of `up` at that position.
  - Recursively call `permuatations2` with the new string and the rest of `up`.
  - Collect all returned permutations in a vector and return it.

---

### Example

For `permuatations2("", "ab")`:

- Insert `'a'` at all positions in `""` → `"a"`
  - Insert `'b'` at all positions in `"a"` → `"ba"`, `"ab"`
- Result: `["ba", "ab"]`

---

### Recursion Tree (for "ab")

```
permuatations2("", "ab")
├── i=0: f="", s=""
│   └── permuatations2("a", "b")
│       ├── i=0: f="", s="a"
│       │   └── permuatations2("ba", "")
│       │       └── return ["ba"]
│       ├── i=1: f="a", s=""
│       │   └── permuatations2("ab", "")
│       │       └── return ["ab"]
│       └── returns ["ba", "ab"]
└── returns ["ba", "ab"]
```

---
```
How temp.insert(...) Works
At each level, the function collects all permutations from its recursive calls.

For example, after the three recursive calls for "ba" and "ab", you have:
For "ba":
val = {"sba"} (first call)
val = {"bsa"} (second call)
val = {"bas"} (third call)
temp becomes {"sba", "bsa", "bas"}

For "ab":
val = {"sab"} (first call)
val = {"asb"} (second call)
val = {"abs"} (third call)
temp becomes {"sab", "asb", "abs"}
At the top level, you combine both:
Final result: {"sba", "bsa", "bas", "sab", "asb", "abs"}
```

### Time and Space Complexity

- **Time Complexity:**  
  - There are `n!` permutations for a string of length `n`.
  - Each permutation takes `O(n)` time to build.
  - **Total:** `O(n! * n)`

- **Space Complexity:**  
  - Storing all permutations: `O(n! * n)`
  - Call stack: up to `O(n)` deep.



---
---

```
search()  // permutation = ""
│
├─ i=0: choose 'a' → permutation = "a"
│   └─ search()
│       ├─ i=0: already chosen
│       ├─ i=1: choose 'b' → permutation = "ab"
│       │   └─ search()
│       │       ├─ i=0: already chosen
│       │       ├─ i=1: already chosen
│       │       ├─ i=2: choose 'c' → permutation = "abc"
│       │       │   └─ search() → print "abc"
│       │       └─ backtrack to "ab"
│       ├─ i=2: choose 'c' → permutation = "ac"
│       │   └─ search()
│       │       ├─ i=0: already chosen
│       │       ├─ i=1: choose 'b' → permutation = "acb"
│       │       │   └─ search() → print "acb"
│       │       └─ i=2: already chosen
│       └─ backtrack to "a"
│
├─ i=1: choose 'b' → permutation = "b"
│   └─ search()
│       ├─ i=0: choose 'a' → permutation = "ba"
│       │   └─ search()
│       │       ├─ i=0: already chosen
│       │       ├─ i=1: already chosen
│       │       ├─ i=2: choose 'c' → permutation = "bac"
│       │       │   └─ search() → print "bac"
│       │       └─ backtrack to "ba"
│       ├─ i=1: already chosen
│       ├─ i=2: choose 'c' → permutation = "bc"
│       │   └─ search()
│       │       ├─ i=0: choose 'a' → permutation = "bca"
│       │       │   └─ search() → print "bca"
│       │       ├─ i=1: already chosen
│       │       └─ i=2: already chosen
│       └─ backtrack to "b"
│
├─ i=2: choose 'c' → permutation = "c"
│   └─ search()
│       ├─ i=0: choose 'a' → permutation = "ca"
│       │   └─ search()
│       │       ├─ i=0: already chosen
│       │       ├─ i=1: choose 'b' → permutation = "cab"
│       │       │   └─ search() → print "cab"
│       │       └─ i=2: already chosen
│       ├─ i=1: choose 'b' → permutation = "cb"
│       │   └─ search()
│       │       ├─ i=0: choose 'a' → permutation = "cba"
│       │       │   └─ search() → print "cba"
│       │       ├─ i=1: already chosen
│       │       └─ i=2: already chosen
│       └─ i=2: already chosen
```

## Summary Table

| Function      | What it does                                              | Output Type         |
|---------------|----------------------------------------------------------|---------------------|
| skip          | Skips 'a' and prints results                             | Prints              |
| skip2         | Returns string with 'a' removed                          | Returns string      |
| skip3         | Skips substring `given`                                  | Returns string      |
| skip4         | Skips `given` unless part of `not_removed`               | Returns string      |
| subser        | Prints all subsequences                                  | Prints              |
| subser1       | Stores all non-empty subsequences in vector              | Fills vector        |
| subser2       | Returns all non-empty subsequences in vector             | Returns vector      |
| print_sub_iter (string) | Prints all subsets of a string using bitmasking         | Prints              |
| print_sub_iter (vector<int>) | Prints all subsets of an int array using bitmasking      | Prints              |
| subsets       | Generates all subsets (power set) using recursion        | Fills vector<vector>|
| subsets2      | Generates all subsets, adds current at every step        | Fills vector<vector>|
| subsets3      | Generates all unique subsets for arrays with duplicates  | Fills vector<vector>|
