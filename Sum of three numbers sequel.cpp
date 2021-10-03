Given a list of integers nums and an integer k, find three distinct elements in nums, a, b, c, such that abs(a + b + c - k) is minimized and return the absolute difference.

Constraints

    n ≤ 1,000 where n is length of nums.

Example 1
Input

nums = [2, 4, 25, 7]

k = 15

Output

2

Explanation

Taking [2, 4, 7] will get us closest to 15 and the absolute difference is abs(13 - 15) = 2.
//code
  int solve(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(),nums.end());


int i,j;
int mindiff=INT_MAX;
for(i=0;i<n;i++)
{
    int low=i+1,hi=n-1;

    while(low<hi)
    {
            mindiff=min(mindiff,abs(nums[i]+nums[low]+nums[hi]-k));
        
         if(nums[i]+nums[low]+nums[hi]<=k)
        {
            low++;
        }
        else if(nums[i]+nums[low]+nums[hi]>k)
        hi--;
    }
    if(mindiff==0)
    return mindiff;
}
    return mindiff;
}
