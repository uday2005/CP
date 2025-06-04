#include <bits/stdc++.h>
using namespace std;

// Skip a praticular character
void skip(string p , string up){

    if(up.empty()){
        cout << p << endl;
        return;
    }
    char ch = up[0];

    if(ch == 'a'){
        skip(p,up.substr(1));
    }
    else{
        skip(p+ch , up.substr(1));
    }
}

string skip2(string up){

    if(up.empty()){
        return "";
    }
    char ch = up[0];

    if(ch == 'a'){
        return skip2(up.substr(1));
    }
    else{
        return ch + skip2(up.substr(1));
    }
}


// skip a particular string

bool startsWith(const string& str, const string& prefix) {
    return str.compare(0, prefix.length(), prefix) == 0;
}

string skip3(string up, string given){

    if(up.empty()){
        return "";
    }
    int size = given.length();

    char ch = up[0];
    if(startsWith(up,given)){
        return skip3(up.substr(given.size()),given);
    }
    else{
        return ch + skip3(up.substr(1),given);
    }
}

// no what we want is only skip app only if that is not apple


string skip4(string up, string given,string not_removed){

    if(up.empty()){
        return "";
    }
    int size = given.length();

    char ch = up[0];
    if(startsWith(up,given)&& !startsWith(up ,not_removed)){
        return skip4(up.substr(given.size()),given , not_removed);
    }
    else{
        return ch + skip4(up.substr(1),given , not_removed);
    }
}

void subser(string p, string  up){
    if(up.empty()){
        cout << p << endl;
        return;
    }

    char ch = up[0];
    subser(p+ch,up.substr(1));
    subser(p,up.substr(1));
}

// we can also make a use of argument inside of the function as in reference so that we can make a anouther function 
// pr just cout the result we would get teh result
void subser1(string p, string  up, vector<string> &arr){
    if(up.empty()){
        if(!p.empty()){
            arr.push_back(p);
        }
        return;
    }

    char ch = up[0];
    subser1(p+ch,up.substr(1),arr);
    subser1(p + to_string(int(ch)), up.substr(1),arr);
    subser1(p,up.substr(1),arr);
}


vector<string> subser2(string p, string  up){
    if(up.empty()){
        if(!p.empty())
        return {p};
        else{
            return {};
        }
    }

    char ch = up[0];
    vector<string> include = subser2(p+ch,up.substr(1));
    vector<string> exclude = subser2(p,up.substr(1));

    vector<string> result;

    result.insert(result.end(), include.begin() , include.end());
    result.insert(result.end(), exclude.begin() , exclude.end());

    return result;

}


int main(){
    string p = " ";
    string up = "baacde";

    string you = "bascappleappfd";

    // skip(p,up);


    // cout << skip3(you,"apple");
    // cout << skip4(you , "app" ,"apple");

    vector<string> result;
    subser1("", "abc", result);

    for(auto x : result){
        cout << x << " ";
    }
    cout << endl;
    
    subser(" " ,"man");
}


// one more method which can be used to print the subset is th bit masking like
// we know that the number of the subsets is equal to the pow(2,n)

void print_sub_iter(string s){
    int n = s.size();

    for( int b = 0 ; b < (1 << n) ; b++){ // no of the subset
        string subs;
        for( int i = 0; i< n; i++){ // here i is  mask

            if(b & (1 << i)) {
                subs += s[i];
            }
        }
        cout << subs << endl;
    }

}
// Each bit in a number represents whether a character is included (bit is set) or excluded (bit is not set).
// For a string of length n, there are 2ⁿ possible subsequences.
// Each number from 0 to 2ⁿ-1 is a mask representing a unique subset of characters.
// If the i-th bit is set, include the i-th character in the subsequence.

void print_sub_iter(vector<int> arr){
    int n = arr.size();

    for( int b = 0 ; b < (1 << n) ; b++){
        vector<int> temp;
        for( int i = 0; i< n; i++){ // here is mask

            if(b & (1 << i)) {
             temp.push_back(arr[i]); // if bit is set then push back that element    
            }
        }
         // Print the subset
        for (int x : temp) cout << x << " ";
        cout << endl;
        
    }

}

// subsets finding if the array contains the number.
void subsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    // Exclude
    subsets(index + 1, nums, current, result);
    // Include
    current.push_back(nums[index]);
    subsets(index + 1, nums, current, result);
    current.pop_back();
}

// Anouther way

void subsets2(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for(int i = index; i< nums.size(); i++){
    current.push_back(nums[i]);
    subsets(index + 1, nums, current, result);
    current.pop_back();
    }

}

// now what will happen if we will have the duplicate in strings then how will be calculate the substring


// but it duplicates we have to carefully remember that duplicats must be conatgoius and if not
// to made it contagious we will sort the array
void subsets3(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for(int i = index; i< nums.size(); i++){
    if (i > index && nums[i] == nums[i - 1]) continue;
    current.push_back(nums[i]);
    subsets(i + 1, nums, current, result);
    current.pop_back();
    }

}
