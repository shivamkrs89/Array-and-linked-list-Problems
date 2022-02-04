Given two lists of integers a and b, as well as an integer k, return the number of elements in a that are strictly smaller than at least k elements in b.

Constraints

n ≤ 50,000 where n is the length of a.
m ≤ 50,000 where m is the length of b.
0 ≤ k ≤ m
Example 1
Input
a = [5, -3, 99, 10]
b = [32, 5, 29, 7, 13]
k = 3
Output
3
Explanation
-3, 5, and 10 are strictly smaller than 3 elements in b.
  
  //code
  int solve(vector<int>& a, vector<int>& b, int k) {
    if(k==0)
    return a.size();
    sort(b.begin(),b.end());

    int ele_k=b[b.size()-k];
    int c=0;
    for(auto x:a)
    if(x<ele_k)
    c++;

    return c;
}
