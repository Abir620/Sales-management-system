#include<bits/stdc++.h>
using namespace std;
struct Node{
   int data;
   Node *next;

};


void print(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data;
        n=n->next;
    }
    cout<<endl;
}

void pushfirst(Node** head,int newdata)
{
    Node* newnode=new Node();
    newnode->data=newdata;
    newnode->next=*head;
    *head=newnode;
}
Node* isPresent(Node* n, int value)
{
    Node* prevnode = new Node();
    prevnode = NULL;
    while (n != NULL)
    {
        int dataVal = n->data;

        if(dataVal == value)
        {
            prevnode = n;
            break;
        }

        n = n->next;

    }
return prevnode;

}
void pushafter(Node** head,int value,int newdata)
{
    Node* prevnode=isPresent(*head,value);

    if (prevnode == NULL)
    {
       cout<<"the given previous node cannot be NULL";
       return;
    }

    Node* newnode=new Node();
    newnode->data  = newdata;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}
void insertlast(Node** head,int newdata)
{
    Node* newnode=new Node();
    newnode->data=newdata;
    newnode->next=NULL;
    Node* lastnode=*head;
    if(*head==NULL)
    {
        *head=newnode;
    }
    while(lastnode->next!=NULL)
    {
        lastnode=lastnode->next;
    }

    lastnode->next=newnode;
}
int main()
{
    Node *head=NULL;
    pushfirst(&head,1);
    print(head);
    pushafter(&head,1,2);
    print(head);
    pushafter(&head,2,3);
    print(head);
    pushafter(&head,3,4);
    print(head);
    insertlast(&head,5);
    print(head);

}
