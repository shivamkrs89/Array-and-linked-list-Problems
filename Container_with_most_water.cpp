/*
Container With Most Water

Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai). N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0). Find two lines, which together with x-axis forms a container, such that it contains the most water.

Example 1:

Input:
N = 4
a[] = {1,5,4,3}
Output: 6
Explanation: 5 and 3 are distance 2 apart.
So the size of the base = 2. Height of
container = min(5, 3) = 3. So total area
= 3 * 2 = 6.

Example 2:

Input:
N = 5
a[] = {3,1,2,4,5}
Output: 12
Explanation: 5 and 3 are distance 4 apart.
So the size of the base = 4. Height of
container = min(5, 3) = 3. So total area
= 4 * 3 = 12.

Your Task :
You only need to implement the given function maxArea. Do not read input, instead use the arguments given in the function and return the desired output. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
2<=N<=105
1<=A[i]<=100
*/
//code starts here
//Initial template for C++

#include<iostream>
using namespace std;
int maxArea(int A[], int len);

 // } Driver Code Ends


//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long maxi=0,index,i,j;
    
    for(i=0;i<len;i++)
    {
        if(A[i]>maxi)
        {
            maxi=A[i];
            index=i;
        }
    }
    i=0;j=len-1;
    long long int s=min(A[i],A[j])*(j-i);
    
    while(i<j)
    {
        if(A[j]<A[i])
        {
            j--;
            s=max(s,min(A[i],A[j])*(j-i));
            
        }
        else if(A[i]<A[j])
        {
            i++;
            s=max(min(A[i],A[j])*(j-i),s);
          
        }
        else
        {
            i++;j--;
        }
    }

    

    
    
    return s;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
