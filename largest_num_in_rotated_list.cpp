Find the Largest Number in a Rotated List

Medium

You are given a list of unique integers nums that is sorted in ascending order and is rotated at some pivot point. Find the maximum number in the rotated list.

Can you solve it in O(log⁡n)\mathcal{O}(\log{}n)O(logn)?

Constraints

    n ≤ 100,000 where n is the length of nums.

Example 1
Input

arr = [6, 7, 8, 1, 4]

Output

8

Explanation

The original sorted array of [1, 4, 6, 7, 8] was rotated at index 2 and results in the input array [6, 7, 8, 1, 4,]. And the largest number is 8.
Example 2
Input

arr = [1, 2, 3]

Output

3

Example 3
Input


//code


int solve(vector<int>& arr) {
    int n=arr.size();

     if(n==1)
     return arr[0];


    int hi=n-1,low=0;
    while(low<hi)
    {
        int mid=(low+hi)/2;

        if(mid-1>=0 && mid+1<n && arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
        {
          return arr[mid];
        }
        else if(mid-1<0){
        if(arr[n-1]<arr[mid] && arr[mid+1]<arr[mid])
        {
           return arr[mid];
        }
        else if(arr[n-1]>arr[mid] && arr[n-1]>arr[n-2])
        return arr[n-1];
    }
        if(arr[mid]>arr[n-1])  //checking mid against last element to decide the transition 
        {
            low=mid+1;
        }
        else
        {
            hi=mid;
        }

    }

 return arr[0];   
}
arr = [1]

Output

1

Example 4
Input

arr = [10, 1, 2, 3, 4, 7]

Output

10

//code


int solve(vector<int>& arr) {
    int n=arr.size();

     if(n==1)
     return arr[0];


    int hi=n-1,low=0;
    while(low<hi)
    {
        int mid=(low+hi)/2;

        if(mid-1>=0 && mid+1<n && arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
        {
          return arr[mid];
        }
        else if(mid-1<0){
        if(arr[n-1]<arr[mid] && arr[mid+1]<arr[mid])
        {
           return arr[mid];
        }
        else if(arr[n-1]>arr[mid] && arr[n-1]>arr[n-2])
        return arr[n-1];
    }
        if(arr[mid]>arr[n-1])  //checking mid against last element to decide the transition 
        {
            low=mid+1;
        }
        else
        {
            hi=mid;
        }

    }

 return arr[0];   
}
