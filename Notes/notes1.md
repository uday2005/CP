
# How to Find Number of Digits
one way to do it is that floor of log base 10 of that number plus 1 gives number of digit.
```cpp
int countDigits(int n) {
    if (n == 0) return 1;
    return floor(log10(n)) + 1;
}

int countDigits2(int n){
    int count= 0;
    whike(n >0){
        n/= 10;
        count++;
    }
    return count;
}

```
# typedef long long ll -> this will make alias of long long as ll.

```cpp


// void permute(const vector<int> &arr){
//     vector<int> perm;
//     int n = arr.size();

#include <iostream>
#include <vector>
using namespace std;

void permute(const vector<int>& arr, vector<bool>& chosen, vector<int>& perm) {
    if (perm.size() == arr.size()) {
        // Print the permutation
        for (int num : perm) cout << num << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (chosen[i]) continue;
        chosen[i] = true;
        perm.push_back(arr[i]);
        permute(arr, chosen, perm); // Pass perm and chosen as references
        chosen[i] = false;
        perm.pop_back();
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<bool> chosen(arr.size(), false);
    vector<int> perm;
    permute(arr, chosen, perm);
    return 0;
}

```
## see the problem is that we want to use chosen and perm function which doesn't get destroyed everytime we call function . So we need to make that variable global or use them as your arguments.




