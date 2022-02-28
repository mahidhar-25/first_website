#include<iostream>
#include<iomanip>
using namespace std;

void print_value(long long int x , long long int y){
 if(x>=y){
       if(x%2==0){
           cout<<x*x-y+1<<endl;
       }else{
           cout<<(x-1)*(x-1)+y<<endl;
       }
   }else{
      if(y%2==0){
          cout<<(y-1)*(y-1)+x<<endl;
      }else{
          cout<<y*y-x+1<<endl;
      }
   }
}

int main(){
long long int t,i;
cin>>t;
long long int x,y;
for(i=0;i<t;i++){
    cin>>x>>y;
    print_value(x,y);
}
}