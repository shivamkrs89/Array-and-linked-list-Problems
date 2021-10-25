Given a linked list node and a non-negative integer k, rotate the list to the right by k places.

Note: The linked list is guaranteed to have at least one element, and k is guaranteed to be less than or equal to the length of the list.

Constraints

    k ≤ n ≤ 100,000 where n is the number of nodes in node

Example 1
Input
Visualize

node =

1

2

3

4

k = 2

Output
Visualize

3

4

1

2
Example 2
Input
Visualize

node =

1

2

3

4

k = 4

Output
Visualize

1

2

3

4
Example 3
Input
Visualize

node =

1

2

3

4

k = 0

Output
Visualize

1

2

3

4
//https://binarysearch.com/problems/Rotate-Linked-List-by-K
/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node, int k) {
    LLNode* n1;
    n1=node;
    LLNode* n2;
    n2=node;
    int k1=k;
    while(k1--)
    {
        n1=n1->next;
    }

    while(n1!=NULL)
    {
        
        if(n1->next==NULL)
        {
        n1->next=node;
        node=n2->next;
        n2->next=NULL;
        break;
        }
        n1=n1->next;
        n2=n2->next;
    }
    
    return node;
   
}
