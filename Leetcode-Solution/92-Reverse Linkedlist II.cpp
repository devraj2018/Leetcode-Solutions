class Solution {
public:

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left==right || head==NULL || left==right ) return head;      // Base Condition
    
    ListNode* dummy=new ListNode(0);                                //Dummy Node
    ListNode *curr=head,*prev=dummy,*nxt=NULL;
    dummy->next=head;
    
    for(int i=1;i<left; i++)                                       //Make left position node as curr
          {    prev=curr;                                          //Store previous element of left node in prev
		       curr=curr->next;
          }
    ListNode *first=curr,*temp=prev;                               //store current in first because its the element at left pos
    for(int i=1;i<=(right-left)+1;i++)                             //store previous element of first in temp,because here we modify prev element
        {  nxt=curr->next;                                     
          curr->next=prev;
          prev=curr;
         curr=nxt;
        }                                                         // Here prev return newhead of reversed linkedlist
    
    temp->next=prev;   
    first->next=curr;
    return dummy->next;
    
}
};
