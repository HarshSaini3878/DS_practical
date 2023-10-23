#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *next;
    node(int value)
    {
        this->value = value;
        next = NULL;
    }
};
void insertAtTail(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    
}
void insertAtHead(node *&head, int value)
{
    node *n = new node(value);
    n->next=head;
    head=n;
    
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->value << "-> ";
        head = head->next;
    }
    cout<<"NULL" << endl;
}
void NODEfromBACK(node *head,int n){
    if(head==NULL)  return;
    node *temp=head;
    node *fast=head;
    for(int i=1;i<=n&&fast->next!=NULL;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        temp=temp->next;
        fast=fast->next;
    }
    cout<<n<<"th NODE FROM END HAS VALUE:"
        <<temp->value<<endl;
}
int main(){
    node* head=NULL;
    insertAtHead(head,99);
    insertAtHead(head,97);
    insertAtHead(head,94);
    insertAtHead(head,93);
    insertAtHead(head,98);
    display(head);
    NODEfromBACK(head,3);
}