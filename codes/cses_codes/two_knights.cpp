// f(n) = f(n-1) + (n^2-n)*(2n-1)   base case : f(1)=0;
// f(n) = f(n-1) + (8(n-2))     base case : f(2)=0;

#include<iostream>
#include<iomanip>
using namespace std;

long long int total(long long int n){
return(n*n*(n*n-1)/2);
}

long long int removal(long long int n){
 if(n<2){
     return(0);
 }else{
     return(removal(n-1)+8*(n-2));
 }
}

//(n*n*(n*n-1)/2)-(4*(n-1)*(n-2));

int main(){
    long long int n;
    cin>>n;
   long long int i=n;
   n=1;
    for(n=1;n<=i;n++){
      //  cout<<total(i)-removal(i)<<endl;
      long long int result = total(i)-removal(i);
      cout<<result<<endl;
    }
}