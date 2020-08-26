/*
Max Circular Subarray Sum

Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.

Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output: 22
Explanation:  Starting from the last 
element of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.

Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output: 23
Explanation: Sum of the circular 
subarray with maximum sum is 23

Your Task:
The task is to complete the function circularSubarraySum() which returns a sum of the circular subarray with maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= Arr[i] <= 106
*/
//code goes here
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
\
 // } Driver Code Ends


// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int circularSubarraySum(int arr[], int num){
    
if (num == 1) 
        return arr[0]; 
  
     
    int sum = 0; 
    for (int i = 0; i < num; i++) { 
        sum += arr[i]; 
    } 
  
    // Initialize every variable with first value of array. 
    int curr_max = arr[0], max_so_far = arr[0], curr_min = arr[0], min_so_far = arr[0]; 
  
    for (int i = 1; i < num; i++) { 
        curr_max = max(curr_max + arr[i], arr[i]); 
        max_so_far = max(max_so_far, curr_max); 
  
    
        curr_min = min(curr_min + arr[i], arr[i]); 
        min_so_far = min(min_so_far, curr_min); 
    } 
  
    if (min_so_far == sum) 
        return max_so_far; 
  //what minsofar does is it eliminates the continuous segment whose sum in minimum
  //so if minsofar is neg sometimes then sum-minsofar can result in higher value which gives
  //competition to maxso far or sum-minsofar is circular maximum sum
    // returning the maximum value 
    return max(max_so_far, sum - min_so_far); 
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
