#include<iostream>
#include<iomanip>
using namespace std;
long long int n;
void sorting_array(long long int a[]){
    long long int i, count = 0; 
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
           if(a[i]>a[j]){
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
               count++;
           }
        }
    }
}


int main(){
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sorting_array(a);
}