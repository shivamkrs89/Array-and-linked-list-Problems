/*Trapping Rain Water

Given an array arr[] of N non-negative integers representing the height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
The structure is like below:
      |
|     |
|   | |
|_ _|_|
Bars for input {3,0,0,2,0,4}
Total trapped water 3+3+1+3=10


Example 1:

Input:
N = 4
arr[] = {7,4,0,9}
Output: 10
Explanation: Water trapped by the 
block of height 4 is 3 units, block 
of height 0 is 7 units. So, the 
total unit of water trapped is 
10 units.

Example 2:

Input:
N = 3
arr[] = {6,9,9}
Output: 0
Explanation: No water will be trapped.

Your Task:
The task is to complete the function trappingWater() which returns the total amount of water that can be trapped.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
3 <= N <= 107
0 <= Ai <= 108
*/
//code starts here
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){

    // Your code here
    int i;
    int c=0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1]>=arr[i])
        {
            c++;
        }
    }
    if(c==n-1)
    return 0;
    c=0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>=arr[i+1])
        {
            c++;
        }
    }
    if(c==n-1)
    return 0;
    
    int nmax[n];
    nmax[n-1]=-1;
    for(i=n-2;i>=0;i--)
    {
           if(nmax[i+1]>arr[i] && arr[i]<arr[i+1] )
        {
            nmax[i]=max(nmax[i+1],arr[i+1]);
        }
        else if(arr[i]<arr[i+1])
        nmax[i]=arr[i+1];
        else if(arr[i]==arr[i+1])
        {
            nmax[i]=nmax[i+1];
        }
        else if(nmax[i+1]==-1)
        {
            nmax[i]=-1;
        }
      
        else if(nmax[i+1]>arr[i])
        {
            nmax[i]=nmax[i+1];
        }
        else
        nmax[i]=-1;
        
        
    }
    int pmax[n];
    pmax[0]=-1;
    for(i=1;i<n;i++)
    {
        if(pmax[i-1]>arr[i] && arr[i]<arr[i-1])
        {
            pmax[i]=max(pmax[i-1],arr[i-1]);
        }
        else if(arr[i]<arr[i-1])
        {
            pmax[i]=arr[i-1];
        }
        else if(arr[i]==arr[i-1])
        {
            pmax[i]=pmax[i-1];
        }
        else if(pmax[i-1]==-1)
        {
            pmax[i]=-1;
        }
         
        else if(pmax[i-1]>arr[i])
        {
            pmax[i]=pmax[i-1];
        }
        else
        {
            pmax[i]=-1;
        }
    }
    int s=0;
    
    // for(i=0;i<n;i++)
    // {
    //     cout<<pmax[i]<<' '<<nmax[i]<<'\n';
    // }
    for(i=1;i<n;i++)
    {
        //cout<<min(nmax[i],pmax[i])-arr[i]<<' ';
        if(nmax[i]!=-1 && pmax[i]!=-1)
        {
            s+=(min(nmax[i],pmax[i])-arr[i]);
        }
    }
    
    return s;
    
    
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
