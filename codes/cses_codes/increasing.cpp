#include<iostream>
#include<iomanip>
using namespace std;
long long int n;
void sorting_array(long long int a[]){
    long long int i, count = 0,j,temp; 
    for(i=0;i<n-1;i++){
           if(a[i]>a[i+1]){
               count = count + a[i] - a[i+1];
               a[i+1] = a[i];
           }
        }
    
    cout<<count;
}


int main(){
    cin>>n;
    long long int a[n];
    long long int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sorting_array(a);
}