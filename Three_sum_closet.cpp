/*
Three Sum Closest

Given an array Arr of N numbers and another number target, find three integers in the array such that the sum is closest to target. Return the sum of the three integers.

Example 1:

Input:
N = 6, target = 2
A[] = {-7,9,8,3,1,1}
Output: 2
Explanation: There is one triplet with sum
2 in the array. Triplet elements are -7,8,
1 whose sum is 2.

Example 2:

Input:
N = 4, target = 13
A[] = {5,2,7,5}
Output: 14
Explanation: There is one triplet with sum
12 and other with sum 14 in the array.
Triplet elements are 5, 2, 5 and 2, 7, 5
respectively. Since abs(13-12) ==
abs(13-14) maximum triplet sum will be
preferred i.e 14.

Your Task:
Complete threeSumClosest() function and return the expected answer.

NOTE: If their exists more than one answer then return the maximum sum.

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 103
-105 ≤ A[i] ≤ 105
1 ≤ target ≤ 105
*/
//code goes here
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> , int );

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        
        cout << threeSumClosest(vec, target) << "\n";
    }
}


 // } Driver Code Ends


// User function template for C++

// arr : given vector of elements
// target : given sum value

int threeSumClosest(vector<int> arr, int target) {
    // Your code goes here
    int i,j;
    int n=arr.size();
    long int mini=INT_MAX;
    int low,high,sum=0;
    
    sort(arr.begin(),arr.end());
   // cout<<a[0]<<'\n';
    for(i=0;i<n-2;i++)
    {
        low=i+1;high=n-1;
        while(low<high)
    {
        sum=arr[i]+arr[low]+arr[high];
        if(abs(sum-target) < abs(mini-target))
        {
            mini=sum;
        }
        else if(abs(sum-target)==abs(mini-target) &&(sum-target)>0)
        {
            mini=sum;
        }
        if(arr[i]+arr[low]+arr[high]<target)
        {
            low++;
        }
        else if(arr[i]+arr[low]+arr[high]>target)
        {
            high--;
            
        }
        else return arr[i]+arr[low]+arr[high];
    }
     
    }
    return mini;
}



// { Driver Code Starts.
  // } Driver Code Ends
