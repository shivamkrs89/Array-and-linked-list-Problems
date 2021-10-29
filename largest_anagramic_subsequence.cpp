Given two lowercase alphabet strings a and b, return the length of the longest anagram subsequence.

Constraints

    n ≤ 100,000 where n is the length of a
    m ≤ 100,000 where m is the length of b

Example 1
Input

a = "afbc"

b = "cxba"

Output

3

Explanation

    "abc" is a subsequence in "afbc"
    "cba" is a subsequence in "cxba"

And abc and cba are anagrams of each other.
//code
  int solve(string a, string b) {
    int arr1[26];
    int arr2[26];
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    int i,j;
    int n1=a.size(),n2=b.size();
    for(i=0;i<n1;i++)
    {
        arr1[a[i]-'a']+=1;
    }
     for(i=0;i<n2;i++)
    {
        arr2[b[i]-'a']+=1;
    }

int count=0;
    for(i=0;i<26;i++)
    {
        //cout<<arr1[i]<<' '<<arr2[i]
             count+=min(arr1[i],arr2[i]);
        
    }

    return count;
}
