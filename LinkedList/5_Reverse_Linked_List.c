/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    //If their is only 1 or 2 node, then return head.
    if(head==NULL || head->next==NULL)
        return head;

    //current points to node after head
    struct ListNode* current=head->next;
    //prev points to node before head
    struct ListNode* prev=NULL;

    //running loop till head becomes NULL
    while(head!=NULL){
        //shifting current to node just after head
        current=head->next;
        //connecting head with prev node
        head->next=prev;
        //shifting prev to head i.e. moving prev forward
        prev=head;
        //shifting head to current i.e. moving head forward
        head=current;
    }
    //returning prev as it will be the new head
    return prev;

}
