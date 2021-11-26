You are given 


a two-dimensional list of integers intervals where each list represents an inclusive [start, end] interval.

Return the total unique duration it covers.

Constraints

n ≤ 100,000 where n is length of intervals.
Example 1
Input
intervals = [
    [45, 60],
    [1, 5],
    [5, 15],
    [2, 3]
]
Output
31
Explanation
The total unique covered distance is [45, 60] (duration of 16) and [1 ,15] (duration of 15).
  
  //code
  bool comp(vector<int> &v1,vector<int> &v2)
{
    if(v1[0]==v2[0])
    return v1[1]<v2[1];

    return v1[0]<v2[0];
}

int solve(vector<vector<int>>& intervals) {

sort(intervals.begin(),intervals.end(),comp);

int n=intervals.size();
int sum=0;
int i=0,j;
for(i=0;i<n-1;i++)
{
    int st=intervals[i][0];
    int hlmax=intervals[i][1];
    if(intervals[i][1]>=intervals[i+1][0])
    {
        while(i+1<n && intervals[i+1][0]<=hlmax)
        {
           hlmax=max(hlmax,intervals[i+1][1]);
           i++;
        }
    }
    //cout<<hlmax<<'\n';
    sum+=(hlmax-st+1);
}
if(i==n-1)
{
    sum+=(intervals[n-1][1]-intervals[n-1][0]+1);
}
return sum;
}
  bool comp(vector<int> &v1,vector<int> &v2)
{
    if(v1[0]==v2[0])
    return v1[1]<v2[1];

    return v1[0]<v2[0];
}

int solve(vector<vector<int>>& intervals) {

sort(intervals.begin(),intervals.end(),comp);

int n=intervals.size();
int sum=0;
int i=0,j;
for(i=0;i<n-1;i++)
{
    int st=intervals[i][0];
    int hlmax=intervals[i][1];
    if(intervals[i][1]>=intervals[i+1][0])
    {
        while(i+1<n && intervals[i+1][0]<=hlmax)
        {
           hlmax=max(hlmax,intervals[i+1][1]);
           i++;
        }
    }
    //cout<<hlmax<<'\n';
    sum+=(hlmax-st+1);
}
if(i==n-1)
{
    sum+=(intervals[n-1][1]-intervals[n-1][0]+1);
}
return sum;
}
