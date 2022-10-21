//Implementing a class Node which has a value and next to store data and pointer to next node.
class Node {
    public:
        int val;
        Node* next;
        Node(int v){
            val=v;
            next=NULL;
        }
};

class MyLinkedList {
public:
	//pointer to head
    Node* head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
		//invalid conditions when index is greater than size of linkedlist
		//or smaller than 0
        if(index<0 || index>=size){
            return -1;
        }
        Node* current=head;
		
		//iterating till the given index
        for(int i=0;i<index;++i){
            current=current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
		//calling the function addAtIndex for index=0
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
		//calling function addAtIndex for index=size
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        //invalid conditions when index is greater than size of linkedlist
        //or smaller than 0
        if(index>size || index<0 ){
            return ;
        } 
        //storing the head pointer of linkedlist in current pointer
        Node* current=head;
        
        //generating new node
        Node* n_node=new Node(val);
        
		//when we have to add node before head pointer
        if(index==0){
            n_node->next=head;
            head=n_node;
        }
        else{
			//iterating till index-1th node of linkedlist
            for(int i=0;i<index-1;++i){
                current=current->next;
            }   
            n_node->next=current->next;
            current->next=n_node;
        }        
        size++;
    }
    
    void deleteAtIndex(int index) {
		//invalid conditions when index is greater than size of linkedlist
        //or smaller than 0
        if(index<0 || index>=size){
            return ;
        }
        
		//deleting head and setting head->next as head
        if(index==0){
            Node* n_node=head->next;
            delete head;
            head=n_node;
        }
        else{
            Node* current=head;
            
			//iterating till index-1th node of linkedlist
            for(int i=0;i<index-1;++i){
                current=current->next;
            }
            Node* n_node=current->next->next;
            delete current->next;
            current->next=n_node;
        }
        size--;
    }
    
	//function to free to space
    ~MyLinkedList()
    {
        Node *n = head;
        // Delete node at head while head is not null
        while (head!=NULL)
        {
            head= head->next;
            delete n;
            n=head;
        }
    }
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */