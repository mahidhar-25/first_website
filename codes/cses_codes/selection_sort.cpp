
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define vi vector<int>

void selection_sort(int arr[], int start , int end){
    if(start == end){
        return;
    }
 int min = start;
 for(int i = start+1 ; i< end ; i++){
     if(arr[i] < arr[min]){
         min = i;
     }
 }
 int temp = arr[min] ;
 arr[min] = arr[start];
 arr[start] = temp;
 selection_sort(arr,start+1 , end);
}

void selection_sort(int arr[], int n){
    for(int i=0 ; i< n-1 ; i++){
        int min = i;
        for(int j = i+1 ;j<n ; j++){
             if(arr[min] > arr[j]){
                 min = j;
             }
        }
        if(min!=i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min]= temp;
        }
    }
}


void solve(){
    int n , i; 
    cout<<"enter the size of an array : "; cin>>n;
    int arr[n];
    cout<<"enter values : ";
    for(i=0;i<n ;i++){
        cin>>arr[i];
    }
    cout<<endl;
    selection_sort(arr ,0 ,n); // for recursive
    selection_sort(arr ,n); // for iterative
    cout<< "sorted array is :  ";
    for(i=0; i<n ;i++){
      cout<<arr[i]<<" ";
    }
}

int main(){
    solve();
    return(0);
}