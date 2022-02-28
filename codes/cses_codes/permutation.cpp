#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    long long int n,i;
    cin>>n;
    if(n==1 || n>3){
        for(i=1;2*i<n+1;i++){
        cout<<2*i<<" ";
    }
    for(i=0;2*i+1<n+1;i++){
        cout<<2*i+1<<" ";
    }
    
    }else{
        cout<<"NO SOLUTION";
    }
}