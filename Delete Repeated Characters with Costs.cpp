You are given a lowercase alphabet string s and a list of non-negative integers costs, both of which have the same length. You can remove character s[i] for cost costs[i], after which both s[i] and costs[i] is removed.

Return the minimum cost needed to delete all consecutively repeating characters.

Constraints

n ≤ 100,000 where n is the length of s and costs
Example 1
Input
s = "aabba"
nums = [1, 2, 9, 3, 5]
Output
4
Explanation
We can remove s[0] and s[3] for a total cost of 1 + 3
  //code
  int solve(string s, vector<int>& nums) {
    int i=0;
    int n=s.length();
    int mxcost=0;
    int mcost=0;
    int tcost=0;
    char cs=s[0]; //character to be matched
    for(i=0;i<n;i++)
    {
        if(s[i]==cs)
        {
          mcost+=(nums[i]);
          mxcost=max(mxcost,nums[i]);
        }
        else
        {
       tcost+=(mcost-mxcost);
      // cout<<tcost<<'\n';
       mxcost=nums[i];
       mcost=nums[i];
       cs=s[i];
        }
        
    }
    if(mcost!=mxcost) //if last occurence ed up as duplicates
    return tcost+mcost-mxcost;
    return tcost;
}
