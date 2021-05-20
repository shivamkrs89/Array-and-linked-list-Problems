Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 

Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -231 <= nums[i] <= 231 - 1

 
      
      //code
      class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj_el=nums[0];
        int n=nums.size();
        int c=1;
        int i;
        for(i=1;i<n;i++)
        {
            if(c>n/2)
                return maj_el;
            if(nums[i]==maj_el)
                c++;
            else
                c--;
            
            if(c==0)
            {
                maj_el=nums[i];
                c=1;
            }
        }
        
        return maj_el;
    }
};
