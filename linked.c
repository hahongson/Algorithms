/* _______Linked List___________
1. Insertion
2. Deletion


*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;


//create new node
node *createNode(int new_data){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->next=NULL;
    new_node->data=new_data;
    return new_node;
}

//print List
void printList(node *head){
    node *last=head;
    while(last!=NULL){
        printf("%d ",last->data);
        last=last->next;
    }
}

//Insertion in Linked List
//1. Add a node at the front
void addFirstNode(node **head,int new_data){
    node *temp=createNode(new_data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    temp->next=*head;
    *head=temp;
}
//2. Add a node at the end
void addLastNode(node **head,int new_data){
    node *temp=createNode(new_data);
    node *last=*head;
    if(*head==NULL){
        *head=temp;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=temp;
    return;
}
//3. Add a node after a given node
void addAfterNode(node *cur,int new_data){
    if(cur==NULL){
        printf("Can not add! the given previous is NULL!\n");
        return;
    }
    node *temp=createNode(new_data);
    temp->next=cur->next;
    cur->next=temp;
}



//Deletion in Linked List
//Delete from begin
void deleteBeginNode(node **head){
    node *temp=*head;
    *head=(*head)->next;
    free(temp);
}
//Delete from End
void deleteEndNode(node **head){
    node *temp=*head;
    node *prev=*head;
    while(temp->next=NULL){
        temp=temp->next;
        prev->next=temp->next;
    }
    free(temp);
}

int main(){
    node *head=NULL;
    addFirstNode(&head,10);
    addAfterNode(head,9);
    addLastNode(&head,11);
    printList(head);
    printf("\n");
    deleteEndNode(&head);
    printList(head);
}