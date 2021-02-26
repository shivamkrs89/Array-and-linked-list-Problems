/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

 

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

 

Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.

 

Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N and S as input parameters and returns a list containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the list should be according to 1-based indexing. If no such subarray is found, return -1. 

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
1 <= Ai <= 1010

*/


//code goes // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s){
        // Your code here
       int sum=0;
       int i,j;
       
       vector<int> v1;
       
        i=0,j=0;
      int curr_sum=0;
        while(i < n )
        {
            int fsum=curr_sum+arr[i];
            cout<<curr_sum<<' '<<i<<'\n';
            if(fsum==s){
            v1.push_back(j+1);
            v1.push_back(i+1);
            return v1;
            }
           
            
            if(fsum<s)
          {curr_sum+=arr[i];i++;}//if future sum is smaller than s then we try that sum
 
 //in case when curr_sum becomes negative it cancels it self after adding with above condition
    
    else if(fsum>s) //if future sum is smaller than s then we delete some element from begining
     {
         curr_sum-=arr[j];
         j++;
     }

        }
        v1.push_back(-1);
        return v1;
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends here
