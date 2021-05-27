Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109

//code starts
      class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int,int> m1;
      
        int i,j;
        int n=nums.size();
        for(i=0;i<n;i++)
        {
            m1[nums[i]]+=1;
        }
        int maxlen=1;
        for(i=0;i<n;i++)
        {
                   int x=nums[i];
            
            if(m1[x+1] && !m1[x-1]) //if element is smallest in its sequence
            {
                int y=x;
                int curr_len=1;
                    while(m1[++y])
                    {
                        curr_len++;
                    }
                
                maxlen=max(maxlen,curr_len);
            }
            
        
            
            
        }
        
        return maxlen;
        
    }
};
