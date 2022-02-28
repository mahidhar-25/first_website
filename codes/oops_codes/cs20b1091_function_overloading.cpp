//NAME    = B.MAHIDHAR REDDY
//ROLL NO = CS20B1091
//OPERATOR OVERLOADING
#include<iostream>
#include<iomanip>
using namespace std;
 
// A linked list node
class Node
{
    public:
    int data;
    Node *next;
    int count = 0;
    void insert(Node **head_ref , int new_data);
    void insert(Node **head_ref , int new_data , int position);
    void deleteNode(Node **head_ref);
    void deleteNode(Node **head_ref, int position);
    void printList(Node *node);

};
 
//adds at end generally
void Node::insert(Node** head_ref, int new_data)
{
    count++;
    // 1. allocate node 
   Node *temp = *head_ref;
    Node* new_node = new Node();
 
    new_node->data = new_data;
    new_node->next = NULL;
   
    //4. If the Linked List is empty, then make the new node as head 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    

    return;
}

void Node::insert(Node** head_ref, int new_data ,int position)
{
    // 1. allocate node 
    int count = 1;
    Node *temp = *head_ref;
    Node *next_node = *head_ref;
    Node* new_node = new Node();
 
    new_node->data = new_data;
    new_node->next = NULL;
    if(position > 1 && *head_ref == NULL){
        cout<<"\nlist is empty and u entered position greater than 1"<<endl;
        return;
    }
    //4. If the Linked List is empty, then make the new node as head 
    if (position == 1)
    {
        if(*head_ref == NULL){
        *head_ref = new_node;
        }else{
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
        count++;
        return;
    }else{
        while(count!= position-1 &&temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        if(count!=position-1){
            cout<<"\n there are only "<<count<<" nodes u entered more than that"<<endl;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        count++;
    }

    return;
}



//deletes the node at the given position
void Node::deleteNode(Node **head_ref)
{
    if (*head_ref == NULL){
        cout<<"\nist is empty"<<endl;
        return;
    }
    Node* temp = *head_ref;
 
   while(temp->next->next!=NULL){
       temp = temp->next;
   }
   int del_val = temp->next->data;
   temp->next = NULL;
    free(temp->next);
   cout<<del_val;
   count--;
}

//deletes the node at the given position
void Node::deleteNode(Node **head_ref, int position)
{
    int del_val;
    if (*head_ref == NULL){
        cout<<"\nlist is empty"<<endl;
        return;
    }
    Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 1)
    {
        del_val = temp->data;
        *head_ref = temp->next;
        free(temp);            
        cout<<del_val; count--;
        return;
    }
 
    // Find previous node of the node to be deleted
    for(int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
    {
        cout<<" \n position is more than nodes"<<endl;
        return;
    }
     Node *next = temp->next->next;
     del_val = temp->next->data;
    free(temp->next);
    temp->next = next;
    cout<<del_val;
    count--;
}

// This function prints contents of linked list starting from head
void Node::printList(Node *node)
{
    if(node == NULL){
        cout<<"\nlist is empty"<<endl;
        return;
    }
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

// main function
int main()
{
    Node s;
    //Start with the empty list 
    Node* head1 = NULL;
    int num,position,choice;
        cout<<"\n1. enter 1 to add at last \n2. enter 2 to add at position specify \n3. enter 3 to del last ele \n4. enter 4 to del at specifi position \n5. enter 5 to display \n6. enter 6 to exit ";
        cout<<"\nenter choice : ";
        cin>>choice;
    while(1){
          switch(choice){
        case 1:
        cout<<"enter number u wanna insert : "; cin>>num;
           s.insert(&head1 , num);
          break;
       case 2:
         cout<<"enter position between 0 and " <<s.count+1<<": "; cin>>position;
         cout<<"enter number u wanna insert : "; cin>>num;
          s.insert(&head1 , num ,position);
          break;
       case 3:
             s.deleteNode(&head1);
          break;
        case 4:
        cout<<"enter position between 0 and "<<s.count+1<<": "; cin>>position;
             s.deleteNode(&head1 , position);
           break;
        case 5:
          s.printList(head1);
          break;
        case 6:
         exit(0);
           break;
        default :
          cout<<"\nenter valid choice ";
          break;
          }
         cout<<"\n1. enter 1 to add at last \n2. enter 2 to add at position specify \n3. enter 3 to del last ele \n4. enter 4 to del at specifi position \n5. enter 5 to display \n6. enter 6 to exit ";
        cout<<"\nenter choice : ";
        cin>>choice;
    }
    return 0;
}
   