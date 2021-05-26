Given a sorted array of size N. Count the number of distinct absolute values present in the array.
 

Example 1:

Input:
N = 6
Arr[] = {-3, -2, 0, 3, 4, 5}
Output: 5
Explanation: There are 5 distinct absolute 
values i.e. 0, 2, 3, 4 and 5.


Example 2:

Input:
N = 9
Arr[] = {-1, -1, -1, -1, 0, 1, 1, 1, 1}
Output: 2
Explanation: There are 2 distinct absolute values 
among the elements of this array, i.e. 0 and 1.


Your Task:
You don't need to read input or print anything. Your task is to complete the function distinctCount() which takes the array of integers arr[] and its size n as input parameters and returns an integer denoting the answer.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
  
  //code starts here
  
  // { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int distinctCount(int arr[], int n) {
        // code here
        int count=n;
        int p1=0,p2=1;
        int ip=n-1,in=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1]){
                count--;
            }
        }
        
        
        while(in<ip)
        {
            if(arr[in]>=0)
            break;
            
            if(arr[ip]+arr[in]==0){
                if(arr[in]!=p1 && arr[ip]!=p2){  //for checking whether we already checked the numbers. observe -8 -8 -3 0 0 0 1 1 2 2 4 7 8 8 9  
            count--;//decrementing count as number is repeated 
            p1=arr[in],p2=arr[ip];
                }
            in++;ip--;
            }
            else if(arr[in]+arr[ip]>0)  //if positive number is greater then we decrement its index 
            {
               ip--; 
            }
            else
            in++;  //else we increment the negative numbers index
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.distinctCount(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

  // } Driver Code Ends
  
