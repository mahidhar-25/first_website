#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define size 5
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

class stack{
public:
int top;
int arr[size];
public:
void push(int x){

    if(top==size-1){
        cout<<"stack is full"<<endl;
    }else{
        arr[top++]=x;
    }
}
int pop()
    {
    if(top==-1){
        cout<<"stack is empty"<<endl;
    }else{
        top = top -1;
    }
}

void print_stack(){
    int i;
    for(i=0;i<=top;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;

}
stack(){
    top = -1;
}

}stk1;
/*
void stack::push(int x){

    if(top==size-1){
        cout<<"stack is full"<<endl;
    }else{
        arr[top++]=x;
    }
}
*/
/*
int stack::pop(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
    }else{
        top = top -1;
    }
}
*/

/*
void stack::print_stack(){
    int i;
    for(i=0;i<=top;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
*/

void solve(){
  stk1.push(8);
  stk1.push(7);
  stk1.print_stack();
  stk1.pop();
  stk1.push(9);
  stk1.print_stack();  
}

int main() {
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    time(&end);
     double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return(0);
}