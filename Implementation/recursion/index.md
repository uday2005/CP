## Revision Index: Recursion and Subset Questions (with Example Test Cases)

1. **How do you skip all occurrences of a particular character in a string using recursion?**  
   *Test case:* Input: `"baacde"`, skip `'a'` → Output: `"bcde"`

2. **How do you return a new string with all occurrences of a particular character removed using recursion?**  
   *Test case:* Input: `"baacde"`, remove `'a'` → Output: `"bcde"`

3. **How do you skip all occurrences of a given substring in a string using recursion?**  
   *Test case:* Input: `"bascappleappfd"`, skip `"apple"` → Output: `"bascappfd"`

4. **How do you skip a substring only if it is not part of a larger forbidden substring?**  
   *Test case:* Input: `"bascappleappfd"`, skip `"app"` unless part of `"apple"` → Output: `"bascapplefd"`

5. **How do you print all subsequences of a string using recursion?**  
   *Test case:* Input: `"ab"` → Output: `""`, `"a"`, `"b"`, `"ab"`

6. **How do you store all non-empty subsequences of a string in a vector using recursion?**  
   *Test case:* Input: `"abc"` → Output: `"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"`

7. **How do you return all non-empty subsequences of a string as a vector using recursion?**  
   *Test case:* Input: `"abc"` → Output: `"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"`

8. **How do you print all subsets of a string using bit masking (iterative method)?**  
   *Test case:* Input: `"abc"` → Output: `""`, `"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"`

9. **How do you print all subsets of an integer array using bit masking (iterative method)?**  
   *Test case:* Input: `[1, 2, 3]` → Output: `""`, `1`, `2`, `3`, `1 2`, `1 3`, `2 3`, `1 2 3`

10. **How do you generate all subsets (the power set) of an array using recursion and backtracking?**  
    *Test case:* Input: `[1, 2]` → Output: `[]`, `[1]`, `[2]`, `[1, 2]`

11. **How do you generate all subsets of an array, adding the current subset at every recursion step?**  
    *Test case:* Input: `[1, 2]` → Output: `[]`, `[1]`, `[1, 2]`, `[2]`

12. **How do you generate all unique subsets for arrays that may contain duplicates?**  
    *Test case:* Input: `[1, 2, 2]` → Output: `[]`, `[1]`, `[1, 2]`, `[1, 2, 2]`, `[2]`, `[2, 2]`