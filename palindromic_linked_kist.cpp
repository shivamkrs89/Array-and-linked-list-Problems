Given a singly linked list node whose values are integers, determine whether the linked list forms a palindrome.

Constraints

    n ≤ 100,000 where n is the length of node

Example 1
Input
Visualize

node =

5

3

5
Output

true

Explanation

5 -> 3 -> 5 is a palindrome.
Example 2
Input
Visualize

node =

12

8

12
Output

true

Explanation

The values of the linked list are the same forwards and backwards.
//code
  
  /**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
bool solve(LLNode* node) {
    vector<int> v1;
    while(node!=NULL)
    {
        v1.push_back(node->val);
        node=node->next;
    }
    
    int low=0,hi=v1.size()-1;

    while(low<=hi)
    {
        if(v1[low]==v1[hi])
        {
            low++;hi--;
        }
        else
        return 0;
    }
    return 1;
}
  
