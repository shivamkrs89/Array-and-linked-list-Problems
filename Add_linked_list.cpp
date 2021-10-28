Given a singly linked list l0 and another linked list l1, each representing a number with least significant digits first, return the summed linked list.

Note: Each value in the linked list is guaranteed to be between 0 and 9.

Constraints

    n ≤ 100,000 where n is the number of nodes in l0
    m ≤ 100,000 where m is the number of nodes in l1

Example 1
Input
Visualize

l0 = [6, 4]

l1 = [4, 7]

Output
Visualize

[0, 2, 1]

Explanation

This is 46 + 74 = 120
//code
  /**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
  //solving digit wise and taking carry
LLNode* solve(LLNode* l0, LLNode* l1) {
  
  int s1=0,s2=0;
   int exp=0;
  LLNode* lsum=new LLNode(-1);
  LLNode* ret=lsum;
int carry=0;
  while(l0!=NULL && l1!=NULL)
  {
    int s=l0->val+l1->val+carry;
    if(s>=10)
    {
       carry=s/10;
    }
    else
    carry=0;
    LLNode* lnext=new LLNode(s%10);
    lsum->next=lnext;
    lsum=lsum->next;

    l0=l0->next,l1=l1->next;
  }
 while(l0!=NULL)
 {
   LLNode* lnext;
   if(carry)
   {
     lnext=new LLNode((l0->val+carry)%10);
     carry=(l0->val+carry)/10; 
   }
  else
  lnext=new LLNode(l0->val);
    lsum->next=lnext;
    lsum=lsum->next;

    l0=l0->next;
 }
  while(l1!=NULL)
 {
  LLNode* lnext;
   if(carry)
   {
     
     lnext=new LLNode((l1->val+carry)%10);
     carry=(l1->val+carry)/10; 
   }
  else
  lnext=new LLNode(l1->val);
    lsum->next=lnext;
    lsum=lsum->next;

    l1=l1->next;
 }

 if(carry)
 {
   LLNode* Lnext=new LLNode(carry);
   lsum->next=Lnext;
 }
 ret=ret->next;

  return ret;
}
