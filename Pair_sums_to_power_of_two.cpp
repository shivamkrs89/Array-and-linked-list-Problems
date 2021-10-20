You are given a list of integers nums. Return the number of pairs i < j such that nums[i] + nums[j] is equal to 2 ** k for some 0 ≤ k.

Constraints

    0 ≤ n ≤ 100,000 where n is the length of nums

Example 1
Input

nums = [1, 1, 3, 5]

Output

4

Explanation

We can have the following pairs that sums to power of 2

    (1, 1)
    (1, 3)
    (1, 3)
    (3, 5)

//code
  int solve(vector<int>& nums) {
    
    long long int arr[32];
    int count=0;
    unordered_map<long long int,vector<int>> m1;
    int i,j;
    for(i=0;i<32;i++)
    {
        arr[i]=1<<i;
       
    }
    int n=nums.size();
    int maxi=0;
    for(i=0;i<n;i++)
    {
        m1[nums[i]].push_back(i);//pushing the sameelementsindex in vector
        maxi=max(nums[i],maxi);
    }
    maxi*=2;

    int m=log2(maxi);  //checking the maximum posible sum that can be and making it log to estimate highest value which 2^(value) can take
    m+=1;
    for(i=0;i<n;i++)
    {
        int x=nums[i];

        for(j=0;j<m;j++)
        {
            vector<int> v1=m1[arr[j]-x];
            if(v1.size()==0) //if such vector of indeices doesn't exist which have value equals to arr
            continue;         //[j]-x where arr[j] corresponds to 2^j
            
            vector<int>::iterator it1=upper_bound(v1.begin(),v1.end(),i);//taking upper bound to ensure only those index which have value greater than i gets counted 
            int index=it1-v1.begin();
            if(index<v1.size())
            {
                count+=(v1.size()-index);//incrementing count of such pairs
            }
        }
    }

    return count;
}
