#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}; // node declared


struct node* create(struct node *first) //creation logic
  {  
      struct node *t,*p; // t = temp pointer p = present pointer
      int n;
      printf("\nEnter how many nodes you want to insert: ");
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
   { 
        t=(struct node *)malloc(sizeof(struct node)); //dynamically alloting memory to the node
        printf("\nEnter the data: ");
        scanf("%d",&t->data);
        t->next=NULL; // setting next to null making the node last node
        if(first==NULL)
        {
            first=p=t; //insitialising the first pointer
        }

        else
        { 
            p = first;
            while(p->next != NULL){
                p = p->next; //traversing the present pointer p as the nodes are created
            }
            p->next = t; //setting temporary pointer one pointer ahead
        }
   }
  return first; 
  }


  struct node* display(struct node *first)
  { struct node *p; //pointer for traversal
      p=first; //setting to first
      if(p==NULL) // if p = null that means the linked list is empty
      {
        printf("The linked list is empty"); 
      }
      else{
      printf("\nThe elements in the linked list are\n");
      printf("\n");
      while(p!=NULL) //traversing till end
      {             
        printf("%d ",p->data);
        p=p->next; //making p to p next after printing current node
      }
      printf("\n");
    }
    return first;
  }

struct node * search(struct node *first)
{
    struct node* ptr;
     int elem,i=0;
     int flag=0;
     ptr=first;

     printf("Enter the element which you want to search\n");
     scanf("%d",&elem);

     while(ptr!=NULL) //traversing till end
     {
         if(ptr->data==elem) //if match found print it and increment flag to keep a count of total elements found
         {
             printf("\nThe element is found at %d place.\n",i+1);
             flag++;
         }
         else
         {
             flag=-1; //not found set flag to -1
         }
         i++;
         ptr=ptr->next; //traversal
     }

     if(flag==0)
     {
          printf("\nThe element is not present in the linked list\n");
     }
}


struct node * insert_begin(struct node *first)
{
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data value for the node: " );
        scanf("%d",&t->data);
        t->next =NULL;
        if(first==NULL)
        {
            first=t;
        }
        else
        {
            t->next=first;
            first=t;
        }
        return first;
}

struct node * insert_end(struct node *first)
{
    struct node *t,*p;
    t=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data which you insert at the end: ");
    scanf("%d",&t->data);
    t->next=NULL;
    if(first==NULL)
    { 
        first=t;   
    }
    else
    {
        p=first;
        while(p->next!=NULL)
        {
            p=p->next;

        }
        p->next=t;
    }
    return first;
}

struct node * insert_position(struct node *first)
{
    struct node*t,*p;
    int pos;
    int i=1;
    t=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the place at which you want to insert the data");
    scanf("%d",&pos);
    printf("\nEnter the data which you want to insert at the given position above: ");
    scanf("%d",&t->data);
    t->next=NULL;
    
    if(pos==1)
    {
       t->next=first;
       first=t;
    }
    else
    { 
      p=first;
      
      while(i<pos-1)
      {
        p=p->next;
        i++;
      }

      if(p==NULL)
      {
        printf("The enter position is not valid");
      }
      else
      {
        t->next=p->next;
        p->next=t;  
      }

 }
 return first;
}

struct node * delete_begin(struct node *first){
        struct node *t;
        t = first;
        if(first == NULL){
            printf("\nThe linked list is empty.\n");
        }
        else{
        first = first->next;
        free(t);
        }
        return first;
}

struct node * delete_end(struct node *first){
      struct node *t,*p;
      
      if(first==NULL){
          printf("\nLinked list is empty.");
      }

      else if(first->next==NULL){   
          t = first;
          free(t);
          first = NULL;
      }

      else{
          t = first;
          while(t->next !=NULL){
              p = t;
              t = t->next;
          }
          p->next =NULL;
          free(t);
      }
      return first;
}

struct node * delete_position(struct node *first){
        struct node *t,*p;
        int pos;
        int i =1;
        
        if(first==NULL){
            printf("List is empty.");
        }
        else{
            printf("\nEnter the place at which you want to delete the data (0 for 1st position and so on..)");
            scanf("%d",&pos);
            p = first;
            for(int i =0;i<pos;i++){
                t = p;
                p=p->next;
            }
            t->next=p->next;
            free(p);
        }
        return first;
}

struct node * reverse(struct node *first){
        struct node *t,*p,*prev;
        prev = NULL;
        t = first;
        p=first;
        while(p!=NULL){
            p = p->next;
            t->next = prev;
            prev = t;
            t=p;
        }
        first = prev;
        return first;
}

struct node * length(struct node *first){
    struct node *t;
    int i=0;
    t = first;
    while(t->next!=NULL){
        i++;
        t=t->next;
    }
    printf("\nLength of the linked list is %d\n", i+1);
}



  int main()
  { struct node * first=NULL;
      int ch;
      while(1)
      {
          printf("\n1.Create the linked list\n");
          printf("\n2.Display the linked list\n");
          printf("\n3.Search for an element\n");
          printf("\n4.Insert at begining\n");
          printf("\n5.Insert at the end \n");
          printf("\n6.Insert at the specified position\n");
          printf("\n7.Delete from begining\n");
          printf("\n8.Delete from end\n");
          printf("\n9.Delete at a position\n");
          printf("\n10.Reverse a linkedlist\n");
          printf("\n11.Length of linkedList\n");
          printf("\n12.Exit\n");
          printf("\n");
          scanf("%d",&ch);

        switch(ch)
        {
            case 1: first= create(first);
                    break;
            case 2: first = display(first);
                    break;
            case 3 : first = search(first);    
                    break;  
            case 4 : first=insert_begin(first);    
                    break; 
            case 5 : first = insert_end(first);    
                    break;
            case 6 : first = insert_position(first);    
                    break;   
            case 7 : first = delete_begin(first);
                    break;
            case 8 : first = delete_end(first);
                    break;
            case 9 : first = delete_position(first);
                    break;
            case 10 : first = reverse(first);
                    break;
            case 11 : first = length(first);
                    break;
            case 12 : exit(0);
        }
          
    }
      return 0;
  }