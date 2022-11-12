
/*
    Ha Hong Son 20215130
    Date: 12/11/2022
    Aim: Quan ly sinh vien voi Linked list
    Using: Insert, Delete, Find, Change, Sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char id[10];
    char name[30];
    int grade;
}data_t;

struct node{
    data_t data;
    struct node *next;
};
typedef struct node node;

node *createNode(data_t new_data){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=new_data;
    new_node->next=NULL;
    return new_node;
}
//tao mang luu du lieu cho truoc
data_t Students[]={
    {"001","sv1",10},
    {"002","sv2",4},
    {"003","sv3",5},
    {"004","sv4",8}, 
    {"005","sv5",9}
};
//addData : tao du lieu kieu data_t nhap tu ban phim
data_t addData(){
    data_t new_data;
    printf("Nhap du lieu cho sinh vien \n");
    printf("-->ID: "); scanf("%s",new_data.id);
    printf("-->Name: ");fflush(stdin); fgets(new_data.name,30,stdin); new_data.name[strlen(new_data.name)-1]='\0';
    printf("-->Grade: "); scanf("%d",&new_data.grade);
    return new_data;
}
//hien thi noi dung cua Student (id,name,grade)
void showNode(node *cur){
    printf("%-10s%-20s%-4d\n",cur->data.id,cur->data.name,cur->data.grade);
}
//liet ke toan bo cac danh sach sinh vien
void printLinkedList(node *head){
    printf("%-10s%-20s%-4s\n","ID","Name","Grade");
    for(node *temp=head;temp!=NULL;temp=temp->next){
        showNode(temp);
    }
}
/*=============== Insertion =================*/
//them Student vao vi tri dau danh sach
void addFirstNode(node **head,data_t new_data)
{
    node *temp=createNode(new_data);
    if(*head==NULL){
        *head=temp;
        return ;
    }
    temp->next=*head;
    *head=temp;
    return ;
}

//them Student vao ci tri cuoi danh sach
void addLastNode(node **head,data_t new_data){
    node *temp=createNode(new_data);
    if(*head==NULL){
        *head=temp;
        return ;
    }
    node *last=*head;
    while(last->next!=NULL)
        last=last->next;
    last->next=temp;
    return;
}
//Them Student vao sau mot Student cho truoc
void addAfterNode(node **cur,data_t new_data){
    if(*cur==NULL){
        printf("Can not add! the given previous is NULL!\n");
        return ;
    }
    node *temp=createNode(new_data);
    temp->next=(*cur)->next;
    (*cur)->next=temp;
}
/*================ Search =================*/
//Tim kiem Student theo ID
node *llFindStudent(node *head,char id[]){
    node *temp=head;
    while(temp!=NULL){
        if(strcmp(temp->data.id,id)==0){
            return temp;
        }
        temp=temp->next;
    }
    printf("No result for %s.\n",id);
    return NULL;
}
/*==========DELETE++++++++++++++++++*/
//Xoa Student dau tien cua danh sach
node *deleteBeginNode(node *head){
    node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
//Xoa Student theo ID
node *llDeleteStudent(node *head,char id[]){
    node *cur=llFindStudent(head,id);
    if(cur==NULL){
        return head;
    }
    if(cur==head){
        head=deleteBeginNode(head);
        return head;
    }
    node *prev=head;
    while(prev->next!=cur){
        prev=prev->next;
    }
    prev->next=cur->next;
    free(cur);
    return head;
}
void llDeleteAll(node **head) {
  node* temp = NULL;
  for (; *head != NULL; *head = temp) {
    temp = (*head)->next;
    free(*head);
  }
  return ;
}
/*=================Change Grade====================*/
//Thay doi diem cho Student
node *llChangeGrade(node *head,char id[],int newGrade){
    node *find_node=llFindStudent(head,id);
    if(find_node==NULL)
        return NULL;
    find_node->data.grade=newGrade;
    printf("...After changed: ");
    showNode(find_node);
    return head;
}
/*================= Sort ====================*/
node *sorted=NULL;
//thuc hien them va sap xep theo thu tu tang dan
void insertSort(node *newNode){
    if(sorted==NULL||newNode->data.grade <= sorted->data.grade){
        newNode->next=sorted;
        sorted=newNode;
    }
    else{
        node *cur=sorted;
        while( cur->next!=NULL && cur->next->data.grade < newNode->data.grade ){
            cur=cur->next;
        }
            
        newNode->next=cur->next;
        cur->next=newNode;
    }
}
//duyet cac phan tu cho vao mang sorted
void sortGrade(node **head){
    node *cur=*head;
    while(cur!=NULL){
        node *next=cur->next;
        insertSort(cur);
        cur=next;
    }
    *head=sorted;
    printLinkedList(*head);
}

/*================TOOLS=====================*/
//In noi dung cac chuong trinh 
void menu(){
    printf("#############################\n");
    printf("____________MENU_____________\n");
    printf("0. Show Students\n");
    printf("1. Insert Student\n");
    printf("2. Find Student\n");
    printf("3. Delete Student\n");
    printf("4. Change grade for Student\n");
    printf("5. Sort by grade.\n");
    printf("6. Exit\n");
}
//Cac lua chon them Student
void printChoiceInsert(){
    printf("1: Insert head of list\n");
    printf("2: Insert last of list\n");
    printf("Enter: ");
}
//Khoi tao Danh sach lien ket tu mang cho truoc
node *init(){
    node *head,*temp;
    temp=createNode(Students[0]);
    head=temp;
    int i=1;
    while(i<5){
        temp->next=createNode(Students[i]);
        temp=temp->next;
        i++;
    } 
    return head;
}

int main(){
    node *head=NULL;
    char id[10];
    head=init(head);
    while(1){
        menu();
        fflush(stdin);
        int lc; printf("Enter number: "); scanf("%d",&lc);
        switch (lc){
        case 0:
            printLinkedList(head);
            break;
        case 1:
            printChoiceInsert();
            scanf("%d",&lc);
            if(lc==1)
                addFirstNode(&head,addData());
            else if(lc==2)
                addLastNode(&head,addData());
            else{
                printf("Unsuitable input!\n");
            }
            break;
        case 2:
            printf("Enter ID want to search: "); fflush(stdin);
            scanf("%s",id);
            node *find_node=llFindStudent(head,id);
            if(find_node!=NULL)
                showNode(find_node);
            break;
        case 3:
            printf("Enter ID want to delete: "); fflush(stdin);
            scanf("%s",id);
            head=llDeleteStudent(head,id);
            break;
        case 4:
            printf("Enter ID for changing grade: "); scanf("%s",id);
            int newGrade;
            printf("Enter change grade: \n"); scanf("%d",&newGrade);
            llChangeGrade(head,id,newGrade);
            break;
        case 5:
            sortGrade(&head);
            sorted=NULL;
            break;
        default:
            llDeleteAll(&head);
            printf("DONE.\n");
            return 0;
        }
    }

}

