#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

//Create a new node
struct node* create_node(int x){
    struct node* temp= new node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

//Enter the node into the linked list
void push(node** head,int x){
    struct node* store=create_node(x);
    if(*head==NULL){
        *head =store;
        return;
    }
    struct node* temp=*head;
    //add the number in the front of the linked list
	store->next=temp;
    *head=store;
}

//pop from the stack
void pop(node** head){
	if(*head==NULL)
		return;
	struct node* temp=(*head)->next;
	*head=temp;				//delete from the front
}
void print(node* head){
	struct node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
    struct node* l=NULL;
    push(&l,1);
    push(&l,2);
    push(&l,3);
    push(&l,4);
    push(&l,5);
    push(&l,6);
    cout<<"Before the pop operation"<<endl;
    print(l);
    pop(&l);
    pop(&l);
    cout<<"\nAfter the pop operation"<<endl;
    print(l);
    return 0;
}
