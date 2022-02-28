#include<iostream>
#include<queue>
using namespace std;

class stack{
queue<int> q1,q2;
int size;
public :
stack(){
    size = 0;
}
void push(int val){
  size++; q1.push(val);
  while(!q2.empty()){
      q1.push((q2.front())); q2.pop();
  }
  q1.swap(q2);
}
void pop(){
    if(q2.empty())return;
    q2.pop(); size--;
}
int top(){
    return(q2.empty()==1)?-1 : q2.front();
}
};

int main(){
    stack s;
    s.push(4);
    s.push(5);
    s.push(9);
    s.pop();
    s.push(10);
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;


}