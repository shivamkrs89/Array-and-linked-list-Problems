/*
Stickler Thief

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4

Your Task:
Complete the function FindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules
 

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).

Constraints:
1 <= n <= 104
1 <= a[i] <= 104
*/
//code starts here

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends


// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    if(n==1)
    return arr[0];
    if(n==2)
    return max(arr[0],arr[1]);
    if(n==3)
    {
        return max(arr[0]+arr[2],arr[1]);
    }
    ll a,b,c,d,i;
    a=arr[0];b=arr[1],c=a+arr[2];
    for(i=3;i<n;i++)
    {
        d=max(a+arr[i],b+arr[i]);
        a=b;
        b=c;
        c=d;
        if(i==n-1)
        {
            c=max(c,b);
        }
    }
    return c;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
