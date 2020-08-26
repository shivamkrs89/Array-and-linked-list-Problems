/*Mountain Subarray Problem

We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 <= K <= N such that,
a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN
You have to process Q queries. In each query you are given two integer L and R, denoting starting and last index of the subarrays respectively.

Example 1:

Input:
N = 8
a[] = {2,3,2,4,4,6,3,2}
Q = 2
Queries = (0,2), (1,3)
Output:
Yes
No
Explanation: For L = 0 and R = 2, a0 = 2,
a1 = 3 and a2 = 2, since they are in the
valid order,answer is Yes.
For L = 1 and R = 3, a1 = 3, a2 = 2 and
a3 = 4, since a1 > a2 and a2 < a4 the
order isn't valid, hence the answer is
No.

Your Task:

Complete the function processQueries() which takes the array, size of array queries and number of queries as parameter. It should return a vector/ArrayList/array (depending upon language cpp/Java/Python) of boolean values, true if the subarray is in mountain form, false otherwise. The driver code will print "Yes" if the returned value is true, otherwise "No".

Expected Time Complexity: O(N + Q).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N, Q <= 105
1 <= a[i] <= 106, for each valid i
0 <= L <= R <= N-1
*/
//code starts here
#include <bits/stdc++.h>

using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q);

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        auto v = processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}// } Driver Code Ends


vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q) {
    // code here
  int i;
    int inc[n],dec[n];
    for(i=0;i<n;i++)
    {
    inc[i]=0;
    dec[i]=0;
    }
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            dec[i]=1+dec[i-1];
             inc[i]=1+inc[i-1];
        }
else if(a[i]>a[i-1])
{
    inc[i]=1+inc[i-1];
    dec[i]=0;
}
else{
inc[i]=0;
dec[i]=1+dec[i-1];
}
    }
  

vector<bool> ansquery(q);
    for(i=0;i<q;i++)
    {
        int s=queries[i].first;
        int e=queries[i].second;
        
        int len,mid;
         if(s-e!=0)
         {
        
                if(inc[e]>dec[e])    //where last term is in increase motive
                {
                    len=inc[e];           
                    if(len>=(e-s))
                    {
                        ansquery[i]=1;//whole range is in increase motive of '/' type
                        continue;
                    }
                    else
                    {
                       
                        ansquery[i]=0;  //some decrease motive present in between
                        continue;
                    }
                }
                else if(dec[e]>inc[e])  //where last term is in decrease motive
                                       //it miust be '^' or '\' type
                {
                    len=dec[e];
                    if(len>=(e-s))
                    {
                        ansquery[i]=1;   //it is of '\' type
                        continue;
                    }
                    mid=e-len;
                    if(inc[mid]>=e-s-len)
                    {
                        ansquery[i]=1;    //it is of '^' type
                        continue;
                    }
                    else{
                        
                    ansquery[i]=0;     //zigzag
                    continue;
                    }
                }
            

        }
        else
        ansquery[i]=1;
        
    
        
    }
    
return ansquery;
    
}
