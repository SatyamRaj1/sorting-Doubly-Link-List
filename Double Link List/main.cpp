//
//  main.cpp
//  Double Link List
//
//  Created by Satyam Raj Purohit on 30/04/21.
//
#include <iostream>

using namespace std;

class node{
    public:
    node* prev;
    node* next;
    int data;
};

void insertnode(node** head,int key,int new_data){
    node* a=*head;
    node* new_node=new node();
    new_node->data=new_data;
    if(head==NULL){
        new_node->next=NULL;
        new_node->prev=NULL;
        *head=new_node;
    }
    else{
    while(a->data!=key)
        a=a->next;
    new_node->prev=a->prev;
    new_node->next=a;
    (a->prev)->next=new_node;
    a->prev=new_node->next;
    }
}
void insertstart(node** head,int new_data){
    node* new_node=new node;
    new_node->data=new_data;
    (*head)->prev=new_node;
    new_node->next=*head;
    new_node->prev=NULL;
    *head=new_node;
}
void insertlast(node** head,int new_data){
    node* new_node=new node;
    new_node->data=new_data;
    new_node->next=NULL;
    node*a=*head;
    while(a->next!=NULL)
        a=a->next;
    a->next=new_node;
    new_node->prev=a;
}
void deletenode(node** head,int key){
    node* a=*head;
    while(a->data!=key)
        a=a->next;
    if(a->prev!=NULL){
        if((a->next)!=NULL){
            a->prev->next=a->next;
            a->next->prev=a->prev;
        }
        else{
            a->prev->next=NULL;
            a->prev=NULL;
        }
    }
    else{
        *head=a->next;
        a->next->prev=NULL;
        a->next=NULL;
    }
    delete a;
}
void sortlist(node** head){
    node* a=*head;
    while(a!=NULL){
        int max=a->data;
        node *b=a;
        while(b!=NULL){
         if(b->data>max)
         max=b->data;
         b=b->next;
        }
        if(a->data==max)
            a=a->next;
        deletenode(head,max);
        insertstart(head,max);
        
        
    }
}
int main()
{
    node* head=new node();
    node* sec=new node();
    node* th=new node();
    
    head->prev=NULL;
    head->next=sec;
    head->data=2;
    
    sec->prev=head;
    sec->next=th;
    sec->data=4;
    
    th->prev=sec;
    th->next=NULL;
    th->data=6;
    
    //insertnode(&head,4,3);
    //insertnode(&head,3,7);
    insertnode(&head,6,9);
    insertstart(&head,21);
    insertlast(&head,1);
    //deletenode(&head,21);
    sortlist(&head);
    
     node* p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
    

    return 0;
}



