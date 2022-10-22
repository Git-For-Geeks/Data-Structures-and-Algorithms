class Solution {
public:
    void deleteNode(ListNode* node) {
        
    ListNode *temp = node->next;      //store address of curr node's next
    node->val = temp->val;            //update curr->val with temp->val
    node->next = temp->next;          //update connections 
    delete temp;      
        
    }
};