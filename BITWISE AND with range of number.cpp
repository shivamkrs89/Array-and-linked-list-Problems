/*
Given two integers start and end, return the bitwise AND of all numbers in [start, end], inclusive.

Constraints

    0 ≤ start ≤ end < 2**31

Example 1
Input

start = 5

end = 7

Output

4

Explanation

0101 = 5
0110 = 6
0111 = 7
----
0100 = 4


*/

//code goes here
string d2b(int n)
{
    string s="";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s+="1";
        else
            s+="0";
    }

    return s;
}


int solve(int start, int end) {
    string st=d2b(start);
    string en=d2b(end);
int i;
    if(st.length()!=en.length())  // if both string have unequal length then it is sure shot that 0 are going to encountered atleast once in every position of higher when moving backward to lower
    return 0;

    else//if length is same we are going to take the string only till both string maintains similarity between their bits at ith position 
    {
        string final="";
       
        for(i=0;i<st.size();i++)
        {
            if(st[i]==en[i])  //if bits are same
            {
                final+=st[i];
            }
            else {    //we break here because from here lower string moves towards higher and in this transistion 0's willbe encountered.
                break;
            };
        }
        for(int j=i;j<st.size();j++)
        final+='0';

       
      int num=stoi(final, 0, 2);
        return num;
    }
    
}
