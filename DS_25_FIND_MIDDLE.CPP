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
node* FindMiddle(node *head){
    if(head==NULL){
        cout<<"LINKED LIST IS EMPTY\n";
        return NULL;
    }
    int count=1;
    node *shadow=NULL;
    node *slow=head;
    node *fast=head;
    while(fast->next!=NULL){
        count++;
        shadow=slow;
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL)    fast=fast->next;
    }
    if(count%2==0){
        cout<<"1st MIDDLE NODE'S POSITION IS:"<<count-1<<endl;
        cout<<"1st MIDDLE NODE'S VALUE IS:"<<shadow->value<<endl;    
    }
    cout<<"MIDDLE NODE'S POSITION IS:"<<count<<endl;
    cout<<"MIDDLE NODE'S VALUE IS:"<<slow->value<<endl;
    if(count%2==0)  return shadow;
    return slow;
}
int main(){
    node* head=NULL;
    insertAtHead(head,99);
    insertAtHead(head,97);
    insertAtHead(head,94);
    insertAtHead(head,92);
    insertAtTail(head,101);
    insertAtTail(head,103);
    display(head);
    FindMiddle(head);
}