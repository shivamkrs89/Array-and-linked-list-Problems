Given a list of intervals that are:

    Non-overlapping
    Sorted in increasing order by end times

Merge a new interval target into the list so that the above two properties are met.

Constraints

    n ≤ 100,000 where n is the length of intervals

Example 1
Input

intervals = [
    [1, 10],
    [20, 30],
    [70, 100]
]

target = [5, 25]

Output

[
    [1, 30],
    [70, 100]
]

Explanation

[5, 25] is merged with the first two intervals [1, 10], [20, 30].
Example 2
Input

intervals = [
    [1, 2],
    [3, 5],
    [7, 10]
]

target = [5, 7]

Output

[
    [1, 2],
    [3, 10]
]

Explanation

The [5, 7] is merged with [3, 5] and [7, 10].
//code
      vector<vector<int>> solve(vector<vector<int>>& in, vector<int>& target) {
    vector<vector<int>> res;
    

    for(int i =0 ;i<in.size(); i++ ){
     
        if(in[i][1] < target[0]){ //non overlapping with target
            res.push_back(in[i]);
        }
        else if (target[1] < in[i][0]){ // target interval is entirely smaller than given ith interval
            res.push_back(target); //pushing target as it fits completely
            target=in[i];     //new target is current interval
        }
        else{  //overlapping interval case
            target[0] = min(target[0],in[i][0]); //setting target with least 1st and most 2nd
            target[1] = max(target[1],in[i][1]);
        }
        
    }
    
    res.push_back(target);
    
    return res;
}
