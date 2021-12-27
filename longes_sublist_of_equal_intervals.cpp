You are given a list of integers positions representing the position of a car at equally spaced intervals of time. Return the length of the longest sublist where the car was traveling at a constant speed.

Constraints

n ≤ 100,000 where n is length of positions.
Example 1
Input
positions = [0, 3, 6, 3, 0]
Output
5
Explanation
The car is always traveling at 3 units of distance per time

Example 2
Input
positions = [0, 3, 6, 5, 4, 3, 1, 7, 10, 13]
Output
4
Explanation
The longest period the car was traveling at a constant speed was in the sublist [6, 5, 4, 3]

//code
int solve(vector<int>& positions) {
    int d,i;
    int n=positions.size();
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    d=abs(positions[0]-positions[1]);
    int len=2,mxlen=2;
    for(i=1;i<n-1;i++)
    {
        if(abs(positions[i]-positions[i+1])==d)
        {
            len++;
        }
        else
        {
            mxlen=max(len,mxlen);
            len=2;
            d=abs(positions[i]-positions[i+1]);
        }
    }
    mxlen=max(len,mxlen);

    return mxlen;
}
