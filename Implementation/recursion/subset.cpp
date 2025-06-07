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

void permuatations(string p , string up){
    if(up.empty()){
        cout << p << " ";
        return;
    }

    char ch = up[0];

    for(int i = 0 ; i<= p.size(); i++){
        string f = p.substr(0,i);
        string s = p.substr(i,p.length());

        permuatations(f+ch+s,up.substr(1));
    }
}

vector<string> permuatations2(string p , string up){
 
    if(up.empty()){
        // vector<string> temp2;
        // temp2.push_back(p);
        // return temp2;
        if(!p.empty()){
            return {p};
        }
        else{
            return {};
        }

    }

    char ch = up[0];
    
    
   vector<string> temp;
    for(int i = 0 ; i<= p.size(); i++){
        string f = p.substr(0,i);
        string s = p.substr(i,p.length());

        vector<string> val  = permuatations2(f+ch+s,up.substr(1));
        temp.insert(temp.end(),val.begin() , val.end());
    }
    return temp;


}

// when we want to know how many subsets that will be equivalent of how many recursion call


int permuatations3(string p , string up){
    if(up.empty()){
        return 1;
    }

    char ch = up[0];

    int count = 0;
    for(int i = 0 ; i<= p.size(); i++){
        string f = p.substr(0,i);
        string s = p.substr(i,p.length());

        count += permuatations3(f+ch+s,up.substr(1));
    }
    return count;
}
// anouther way of doing this

void permutations3(string p, string up, int& count) {
    if (up.empty()) {
        count++;
        return;
    }
    char ch = up[0];
    for (int i = 0; i <= p.size(); i++) {
        string f = p.substr(0, i);
        string s = p.substr(i, p.length());
        permutations3(f + ch + s, up.substr(1), count);
    }
}

// if the array is of num

void permute(vector<int>& nums, int idx) {
    if(idx == nums.size()) {
        // process permutation
        return;
    }
    for(int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        permute(nums, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

void generate_Permutations(string &text, int left, int right) {
    if (left == right) {
        cout << text << endl; // Process the permutation
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(text[left], text[i]);
        generate_Permutations(text, left + 1, right);
        swap(text[left], text[i]); // Backtrack
    }
}



string input = "abc";                   // The string to permute
vector<bool> chosen(input.size(), false); // Tracks which chars are used
string permutation;                       // Current permutation being built

void search() {
    if (permutation.size() == input.size()) {
        cout << permutation << endl;      // Process permutation (print)
    } else {
        for (int i = 0; i < input.size(); i++) {
            if (chosen[i]) continue;      // Skip if already used
            chosen[i] = true;
            permutation.push_back(input[i]);
            search();
            chosen[i] = false;            // Backtrack
            permutation.pop_back();
        }
    }
}


void perm_genrate_mob_no(string p , string up){

    if(up.empty()){
        cout << p << " ";
        return;
    }


    int digit = up[0]-'0';
    for(int i = (digit -1)*3;i<digit * 3;i++){
        char ch = (char)('a'+i);
        perm_genrate_mob_no(p+ch , up.substr(1));
    }
    // for 1 it will be a b c
}

vector<string> perm_genrate_mob_no2(string p , string up){

    if(up.empty()){
        return {p};
    }


    int digit = up[0]-'0';

    vector<string> temp; // creating local variable
    for(int i = (digit -1)*3;i<digit * 3;i++){
        char ch = (char)('a'+i);
        vector<string> val = perm_genrate_mob_no2(p+ch , up.substr(1));
        temp.insert(temp.end(), val.begin() , val.end());
    }
    return temp;
    // for 1 it will be a b c
}



int main(){
    string p = " ";
    string up = "baacde";

    string you = "bascappleappfd";

    // skip(p,up);


    // cout << skip3(you,"apple");
    // cout << skip4(you , "app" ,"apple");

    // vector<string> result;
    // subser1("", "abc", result);

    // for(auto x : result){
    //     cout << x << " ";
    // }
    // cout << endl;
    
    // subser(" " ,"man");

    perm_genrate_mob_no(" ","12");
}