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
node* mergeRecursive(node* head1,node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->value<head2->value){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{    
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }

    return result;
}
int main(){
    node* head = NULL;
    node* head1=NULL;
    insertAtTail(head1, 3);
    insertAtHead(head1, 2);
    insertAtHead(head1, 1);
    insertAtTail(head1, 99);
    insertAtTail(head1, 101);
    insertAtHead(head, 98);
    insertAtHead(head, 97);
    insertAtTail(head, 100);
    insertAtHead(head, 96);
    insertAtHead(head, 95);
    display(head);
    display(head1);
    node *head2=mergeRecursive(head,head1);
    cout<<"MERGED LINKED LIST IS:\n";
    display(head2);
}