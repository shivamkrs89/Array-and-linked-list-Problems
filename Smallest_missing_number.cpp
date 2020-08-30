/*
Smallest Positive missing number

You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing
number is 6.

Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2

Your Task:
The task is to complete the function findMissing() which finds the smallest positive missing number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
*/
//code goes here
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find missing integer in array
// arr: input array
// n: size of array

int  seperate(int a[],int n)
{
    
    int i,j=0;
       for(i=0;i<n;i++)
    {
        if(a[i]<=0){
        swap(a[i],a[j]);
        j++;
        }
    }
    // for(i=0;i<n;i++)
    // cout<<a[i]<<' ';
    return j;
}

int findMissing(int a[], int n) { 
    
    // Your code here
    long long int i;
    int sift=seperate(a,n);
  n=n-sift;
   a=a+sift;
  
   for(i=0;i<n;i++)
   {
       //cout<<a[i]<<' ';
       if(abs(a[i])<=n && a[abs(a[i])-1]>0)
       {
           a[abs(a[i])-1]=-a[abs(a[i])-1];
       }
   }
    
    for(i=0;i<n;i++)
    {
       // cout<<a[i]<<' ';
        if(a[i]>0)
        {
            return i+1;
        }
    }
    
    if(i==n)
    return i+1;
    
}


// { Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        
        cout<<findMissing(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends
