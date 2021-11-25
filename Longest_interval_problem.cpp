Longest Interval
Medium

You are given a two-dimensional list of integers intervals where each list represents an inclusive [start, end] interval. Return the longest interval that you can make by merging any number of intersecting intervals.

Constraints

n ≤ 100,000 where n is the length of intervals
Example 1
Input
intervals = [
    [1, 5],
    [3, 8],
    [4, 5],
    [10, 13],
    [15, 17]
]
Output
8
Explanation
After merging, we have the interval [1, 8] which has a length of 8
  
  //corner cases
  ->[[3,5],[10,11],[1,2],[4,7]]
  ->[[0,3],[1,2],[3,4]]
  ->[[0,6]]
  
  //code
  bool comp(vector<int> &v1,vector<int> &v2)
{
    if(v1[0]==v2[0])
    return v1[1]<v2[1];

    return v1[0]<v2[0];
}

int solve(vector<vector<int>>& intervals) {
    
    int n=intervals.size(),i;
    int maxi=0;
    sort(intervals.begin(),intervals.end(),comp);
    maxi=max(maxi,intervals[0][1]-intervals[0][0]);
    for(i=0;i<n-1;i++)
    { maxi=max(maxi,intervals[i][1]-intervals[i][0]);
     if(intervals[i][1]>=intervals[i+1][0])
     {a
         int k=i;
      int hl_max=intervals[i][1];
      while(i<n-1 && intervals[i+1][0]<=hl_max)
      {
     maxi=max(maxi,intervals[i+1][1]-intervals[k][0]);
     hl_max=max(hl_max,intervals[i+1][1]);
     i++;
      }

     }
     
    }
    maxi=max(maxi,intervals[n-1][1]-intervals[n-1][0]);

    return maxi+1;
}
//[[0,3],[1,2],[3,4]]
  
