#include<iostream>
#include<iomanip>
using namespace std;

long long int n,sum=0;

int main(){
    cin>>n;
    long long int a[n],i;
    for(i=0;i<n-1;i++){
        cin>>a[i];
        sum = sum + a[i];
    }
    long long int total;
    total = n*(n-1)/2;
   

  cout<<total-sum + n;
}