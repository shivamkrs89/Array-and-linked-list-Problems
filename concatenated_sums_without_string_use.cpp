/*
You are given a list of non-negative integers nums. Return the sum of every concatenation of every pair of numbers in nums. Note that pairs (i, j) and (j, i) are considered different.

Constraints

    n ≤ 100,000 where n is the length of nums

Example 1
Input

nums = [10, 2]

Output

1344

Explanation

We have the following concatenations:

    nums[0] + nums[0] = 1010
    nums[0] + nums[1] = 102
    nums[1] + nums[0] = 210
    nums[1] + nums[1] = 22

And its sum is 1344

*/

//code goes here
int solve(vector<int>& nums) {
   int n=nums.size();
   int sumnum=0,i,j;
   vector<int> v_dig;
  
   for(i=0;i<n;i++)
   {
    
     int d;
     if(nums[i]==0)
     d=0;
     else
     d=log10(nums[i]);
     
     d+=1;

     v_dig.push_back(d);//pushing no of digits easch number has
     //cout<<d<<' ';
     sumnum+=nums[i];//adding value to sum
   }
   sumnum*=n;  //multiplying by n as those sum will be in final sum with some observation
 int sumten=0; //now sum of power of 10's that is whatever the number of gigit make it to the power of 10^(num of digits)
   for(i=0;i<n;i++)
   {
sumten+=(pow(10,v_dig[i]));//adding the power of 10'swhich are commonly multiplied ny nums[i]in next for loop
   }
   
   int f_sum=0;
   for(i=0;i<n;i++)
   {
    f_sum+=(nums[i]*sumten);//multiplying andadding up
   }

   
   return sumnum+f_sum;
}
