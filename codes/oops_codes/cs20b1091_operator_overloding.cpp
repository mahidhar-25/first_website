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
    void append(Node **head_ref , int new_data);
    void printList(Node *node);
    Node operator+(Node &head_ref);

};
 
//adds at end generally
void Node::append(Node** head_ref, int new_data)
{
    // 1. allocate node 
    Node *prev = *head_ref;
    Node* new_node = new Node();
 
    Node *last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
 
    //If the Linked List is empty, then make the new node as head 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) { //appending and checking it should be in sorted
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return;
}

//WE ARE MERGING TWO LIST AND SORTING USING + OPERATOR
Node Node::operator+(Node &head_ref)
{
    int temp;
    Node l1 = *this;
    Node *tmp = &l1;
    while(tmp->next->next!=NULL){tmp=tmp->next; }
    tmp->next = &head_ref;
     while(tmp->next->next!=NULL){ tmp=tmp->next; }
    tmp->next = NULL;

  tmp = &l1;

  Node *i,*j;
    for(i = &l1; i!=NULL;i = i->next){
        for(j = i->next ; j!=NULL; j =j->next){
            if(i->data > j->data){
                temp = i->data; i->data = j->data; j->data = temp; //swapping
            }
        }
    }
    Node s1;
    cout<<"\nafter merging : \n";
    cout<<"list 3 : " ; s1.printList(tmp);
    return *this;
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
    cout<<endl;
}

//copying the original list before merging
Node *copy_original(Node *node){
Node* new_nod = new Node();
    Node* nes = new_nod;
    while (node != NULL)
    {
        new_nod->data = node->data; node = node->next;
        Node* new_nod1 = new Node(); new_nod->next = new_nod1;
        new_nod = new_nod->next; new_nod->next==NULL;
    }
    return nes;
}

 
// main function
int main()
{
    Node s;
    //Start with the empty list 
    Node *head1 = NULL,*head2 = NULL,*head3 = NULL,*head4 = NULL;
   
     int choice,num,choice_list;
        cout<<"\n1. enter 1 to add at last \n2. enter 2 to diplay \n3. enter 3 to merge the two list \n4. enter 4 to exit ";
        cout<<"\nenter choice : ";
        cin>>choice;
    while(1){
          switch(choice){
        case 1:
            cout<<"enter which list : "; cin>>choice_list;
             cout<<"enter val : "; cin>>num;
            if(choice_list==1){ s.append(&head1, num); }
            else if(choice_list==2){  s.append(&head2, num); }
            else{ cout<<"\nenter valid choice there are only two list\n"; }
          break;
       case 2:
           cout<<"enter which list : "; cin>>choice_list;
            if(choice_list==1){ s.printList(head1);  }
            else if(choice_list==2){  s.printList(head2); }
            else{ cout<<"\nenter valid choice there are ony two list\n"; }
          break;
        case 3:
        if(head1!=NULL && head2!=NULL){
        head3 = copy_original(head1); head4 = copy_original(head2);
         *head3 + *head4;
          cout<<"list 1 : " ; s.printList(head1);
          cout<<"list 2 : " ; s.printList(head2);
        }else if(head1==NULL && head2==NULL){
            cout<<"\nboth the list are empty list are empty\n";
        }else{
            cout<<"\none of the list is empty\n";
        }
           break;
        case 4:
         exit(0);
           break;
        default :
          cout<<"\nenter valid choice ";
          break;
          }
          cout<<"\n1. enter 1 to add at last \n2. enter 2 to diplay \n3. enter 3 to merge the two list \n4. enter 4 to exit ";
        cout<<"\nenter choice : ";
        cin>>choice;
    }
    return 0;
}
   