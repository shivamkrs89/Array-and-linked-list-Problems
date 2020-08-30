/*
Missing number in array

Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4

Example 2:

Input:
N = 10
A[] = {1,2,3,4,5,6,7,8,10}
Output: 9

Your Task :
Complete the function MissingNumber() that takes array and N as input and returns the value of the missing number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
1 ≤ A[i] ≤ 106
*/
//code goes from here

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

int MissingNumber(vector<int>& array, int n) {
    // Your code goes here
    int i,x;
    array.push_back(0);
       for( i=0;i<n-1;i++)
    {
         //cout<<array[i]<<' ';
        x=array[i];
        if(array[i]<0)
        {
            x=abs(array[i])/n;
        }
        array[x-1]=-array[x-1]*n -x;
       
    }
    
    for(i=0;i<array.size() ;i++)
    {
      
        if(array[i]>=0)
        return i+1;
    }
    
    return i;
    
    
}
