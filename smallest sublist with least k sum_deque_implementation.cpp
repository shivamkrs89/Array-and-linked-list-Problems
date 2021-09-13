Given a list of integers nums, and an integer target, return the length of the shortest sublist such that its sum is target or larger. If there's no such sublist, return -1.

Constraints

    k ≤ n ≤ 100,000 where n is the length of nums

Example 1
Input

nums = [1, 10, -5, 15, 3]

target = 17

Output

2

Explanation

We can use [15, 3] to reach sum of at least 17.

  //cases 1.10,15,-5,15,3 17
  //-1,-2,-3      2
  //-5, -2,-3    -4
  //0             0
  
  int solve(vector<int>& nums, int target) {
    
    int n=nums.size();
     if(n==0)
     return -1;
    int i,j;
    
    deque<pair<int,int>> dq;
    int sum=0,mini=1e9+7;
    i=0;
  //cases non negative targets only as negative increase length uselessly
    if(target>=0){
    while(i<n)
    {
        if(nums[i]>=0){
        sum+=nums[i];
        dq.push_back(make_pair(nums[i],i));}
        pair<int,int> p1;
        while(!dq.empty() && sum>=target)
        {p1=dq.front();dq.pop_front();mini=min(mini,i-p1.second+1);
        sum-=(p1.first);}
i++;
    }
if(mini==1e9+7)
return -1;
return mini;
    }
    else//case for negative which is quite easy we need to just find maxi and check wheter target is less than that or not if not then we return -1 else we return 1 as 1 length is enough
    {
        //sort(nums.begin(),nums.end());
        int maxi=nums[0];
        for(i=n-1;i>=1;i--)
        {
        maxi=max(maxi,nums[i]);
        }
        if(maxi>=target)
        return 1;
        else
        return -1;

    }

}
  
  //code
