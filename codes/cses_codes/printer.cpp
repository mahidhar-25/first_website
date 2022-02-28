//NAME    : B.MAHIDHAR REDDY
//ROLL NO : CS20B1091
// QUEUE ADT IMPLIMENTATION
#include "queueclas"
#include<iostream>
using namespace std;


int main(){
    class QUEUE q1;   // declaring object of class
 while(1){
     int choice;
     cout<<"\n 1.Add to print Queue \n 2.Current Job \n 3.Execute a Job \n 4.Display Jobs \n 5.Exit"<<endl;
     cin>>choice;
     switch(choice){
         case 1:
         int id;
         cin>>id; // takind id to enqueue 
         q1.enqueue(id);
             break;
         case 2:
         int current_ele;   // showing the next excute id
         current_ele = q1.peek();
         if(current_ele!=0)
         cout<<current_ele<<endl;
             break;
         case 3:
         q1.dequeue(); //excuting the id
             break;
         case 4:
         q1.display();  // displaying all remaining ids
             break;
        case 5:
        exit(1); // to exit out of the loop
             break;
        default:
             cout<<"invalid choice try again"<<endl;
     }
 }

     return(0);

}