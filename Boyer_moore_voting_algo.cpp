You are given a list of integers nums containing n integers, where each number represents a vote to a candidate.

Return the id of the candidate that has \gt \lfloor \frac{n}{2}\rfloor>⌊ 
2
n
​
 ⌋ votes. If there's not a majority vote, return -1.

This should be done in \mathcal{O}(1)O(1) space.

//code
  int solve(vector<int>& nums) {
 int n=nums.size();
    int votes=0;
    int cand=-1;
    int i,j;

    for(i=0;i<n;i++)
    {
        if(votes==0)
        {
            cand=nums[i];
            votes=1;
        }
        else
        {
            if(cand==nums[i])
            votes++;
            else
            votes--;
        }
    }

int count=0;
    for(i=0;i<n;i++)
    {
if(cand==nums[i])
count++;
    }
   
if(count>n/2)
return cand;

return -1;

}
