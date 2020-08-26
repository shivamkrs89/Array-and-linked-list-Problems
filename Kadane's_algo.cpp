/*
Kadane's Algorithm

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output: 9
Explanation: Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.

Example 2:

Input:
N = 4
arr[] = {-1,-2,-3,-4}
Output: -1
Explanation: Max subarray sum is -1 
of element (-1)

Your Task:
The task is to complete the function maxSubarraySum() which returns the sum of subarray with maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107
*/
//code stars here
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int a[], int n){
    
    // Your code here
    long int maxi=-10000001;
    long long int s=0,i;
    int currmax=0,gmax=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>maxi)
        maxi=a[i];
    }
    
    for(i=0;i<n;i++)
    {
        currmax+=a[i];
        if(currmax<0)
        currmax=0;
        if(currmax>gmax)
        gmax=currmax;
    }
    if(gmax==0 && maxi<0)
    gmax=maxi;
    return gmax;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
