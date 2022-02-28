
/*
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
/*
#define size 5

class stack{
    int top;
    int arr[size];
    public:
    void set()
    {
        top = -1;
    }
    void push(int);
    void pop();
    void display(int arr[ ]);
}s1;

void stack::push(int data){
    if(top==size-1){
        cout<<"stack is full"<<endl;
    }else{
        top = top + 1;
        arr[top] = data;
    }
}

void stack::pop(){
    if(top == -1){
        cout<<"stack is empty"<<endl;
    }else{
        int temp = arr[top];
        top = top - 1;
    }
}

void stack::display(){
    int i;
    for(i=0;i<=top;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"-------"<<endl;
}

int main(){
    s1.set();
    s1.push(5);
    s1.push(7);
    s1.display();
    s1.pop();
    s1.push(7);
    s1.display();
    return(0);
}
*/

/*
#define SIZE 10

using namespace std;

class Stack
{
        int stack[SIZE],top;
 
        public:
 
        Stack()            //Constructor for initializing top
        {
                 top=-1; 
        }

        void push(int num);
        /*
        {
                if(top==SIZE-1)    //Stack is full
                {
                         cout<<"\nSTACK OVERFLOW";
                }
                else
                {
                        top++;
                        stack[top]=num;
                }
        }
        
 
        void pop();
       /*
        {
                int num;
                if(top==-1)         //Stack is empty
                {
                        cout<<"\nSTACK UNDERFLOW";
                }
                else
                {
                        num=stack[top];
                        top--;
                        cout<<"\nELEMENT DELETED: "<<num;
                }
        }
 
        void display();
        /*
        {
                if(top==-1)
                {
                        cout<<"\nSTACK IS EMPTY";
                }
                else
                {
                       cout<<"\n\nSTACK ELEMENTS\n";
  
                       for(int i=top;i>=0;i--)
                       {
                                 cout<<stack[i]<<endl;
                       }
               }
       }
       
 
};




void stack::push(int num){
                    if(top==SIZE-1)    //Stack is full
                {
                         cout<<"\nSTACK OVERFLOW";
                }
                else
                {
                        top++;
                        stack[top]=num;
                }
}

void stack::pop()
{
                int num;
                if(top==-1)         //Stack is empty
                {
                        cout<<"\nSTACK UNDERFLOW";
                }
                else
                {
                        num=stack[top];
                        top--;
                        cout<<"\nELEMENT DELETED: "<<num;
                }
        }


        void stack::display(){
                if(top==-1)
                {
                        cout<<"\nSTACK IS EMPTY";
                }
                else
                {
                       cout<<"\n\nSTACK ELEMENTS\n";
  
                       for(int i=top;i>=0;i--)
                       {
                                 cout<<stack[i]<<endl;
                       }
               }
        }

int main()
{
        Stack s;
 
        s.traverse();
 
        s.push(10);
        s.push(20);
        s.push(30);
 
        s.traverse();
 
        s.pop();
 
        s.traverse();
        return 0; 
}
*/

#include<iostream>

#define SIZE 5
 
using namespace std;
 
class STACK
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();    //defualt constructor
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
};
STACK::STACK(){
    top=-1;
}
 
int STACK::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int STACK::isFull(){
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}
 
int STACK::push(int n){
    //check stack is full or not
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int STACK::pop(){
    //to store and print which number
    //is deleted
    int temp;
    //check for empty
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void STACK::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}
 
int main(){
    //declare object
    STACK stk;
    int choice, n,temp;
     
    do
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
         
        cout<<"Enter your choice: ";
        cin>>choice;
         
        switch(choice){
            case 0: break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<temp<<" inserted."<<endl;
            break;
                 
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<temp<<" is removed (popped)."<<endl;
            break;
             
            case 3:
                stk.displayItems();
                break;
             
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(choice!=0);
 
     
    return 0;
     
}



