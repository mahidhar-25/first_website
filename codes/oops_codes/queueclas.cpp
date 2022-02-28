//queue implementation using class and objects
//declaring header files
#include<iostream>

using namespace std;
// declaring the size of a queue
#define size 5

//defining memebers and member function of class
class QUEUE{
    private:
    int front = -1,rear = -1,arr[size];
    public:
    //constructor when u declare object it automatically declares front = rare =0
    /*
    QUEUE(){
        front = 0;
        rare = 0;
    }
    */
    //to store in queue at rare end
    void enqueue(int num);
    //to del ele in queue at front end
    void dequeue();
    // to see ele present at front in queue
    int peek(){
        if(rear==front){
            cout<<"queue is empty"<<endl;
            return(0);
        }else{
            return(arr[front]);
        }
    }
    // it is to check queue is full/not
    int isFull(){
        if(rear==size -1){
            return(1);
        }else{
            return(0);
        }
    }
    //it is to check queue is empty/not
    int isEmpty(){
        if(rear== -1){
            return(1);
        }else{
            return(0);
        }
    }
   //to display the values of queue
    void display(){
        if(front == -1){
            cout<<"queue is empty"<<endl; 
        }else{
            for(int i=front;i<rear ; i++){
                cout<<arr[i]<<endl;
            }
        }
}
};

void QUEUE::enqueue(int num){
        if(QUEUE::isFull()){
            cout<<"queue is full "<<num<<" did not enqueued"<<endl;
        }else if(QUEUE::rear == -1 && QUEUE::front == -1){
           QUEUE::rear = QUEUE::front =0;
            arr[QUEUE::rear] = num;
        }else{
         QUEUE::rear++;
         arr[QUEUE::rear] = num;
        }
    }

    void QUEUE::dequeue(){
        int temp;
        if(QUEUE::isEmpty() ){
            cout<<"queue is empty"<<endl;
        }else if(front==0 && rear ==0){
            temp = arr[QUEUE::front];
            QUEUE::front = QUEUE::rear = -1;
            cout<<"The Job ID "<<temp<<" has been completed"<<endl;
        }else{
            temp = arr[QUEUE::front];
            QUEUE::front++;
        }
    }

    
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