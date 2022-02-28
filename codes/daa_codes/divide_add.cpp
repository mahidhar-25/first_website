
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define vi vector<int>

class FIND_MAX{
    private :
    vi arr;
    public:
    void getdata();
    int f_way_search(vi arr ,int n);
    int s_way_search(vi arr, int begin , int end, int n);
    int t_way_search(vi arr, int begin , int end, int n);
    int k_way_search(vi arr, int begin , int end, int k);
    int max(int,int);
};

FIND_MAX s;

int FIND_MAX:: max(int a, int b){
    if(a>b){
        return(a);
    }else{
        return(b);
    }
}

int FIND_MAX:: f_way_search(vi arr, int n){
    int MAX = INT_MIN;
    for(int i=0;i<n;i++){
        MAX = s.max(arr[i] , MAX);
    }
    return MAX;
}

int FIND_MAX:: s_way_search(vi arr, int begin , int end ,int n){
    int MAX =INT_MIN,middle,first,second;
    if(begin == end){
        return(arr[begin]);
    }
    middle = (end - begin)/2 + begin;
    first = s.s_way_search(arr, begin ,middle, n);
    second = s.s_way_search(arr, middle+1 , end, n);
    MAX = s.max(first, second);
    return(MAX);
}

int FIND_MAX:: t_way_search(vi arr, int begin ,int end, int n){
    int MAX = INT_MIN, mid_1,mid_2,first,second,third;
     if(begin == end){
        return(arr[begin]);
    }else if(begin>end){
        return(INT_MIN);
    }
    mid_1 = (end - begin)/3 + begin;
    mid_2 = (end-begin)/3 + mid_1;
    first = s.t_way_search(arr, begin ,mid_1, n);
    second = s.t_way_search(arr, mid_1+1 , mid_2, n);
    third = s.t_way_search(arr, mid_2+1 , end, n);
    MAX = s.max(s.max(first,second),third);
    return(MAX);

}
int FIND_MAX:: k_way_search(vi arr, int begin ,int end, int k){
    int MAX = INT_MIN, a[k+1],b[k],i;
     if(begin == end){
        return(arr[begin]);
    }else if(begin>end){
        return(INT_MIN);
    }else if(end-begin<k){
        for(i=begin;i<=end;i++){
            if(MAX<arr[i]){
                MAX = arr[i];
            }
        }
        return(MAX);
    }
    a[0] = begin;
    for(i=1;i<k;i++){
        a[i] = a[i-1]+(end-begin)/k;
    }
    a[k] = end-1;
    a[0] = a[0]-1;
    b[0] = s.k_way_search(arr,a[0]+1,a[1],k);
    for(i=1;i<k;i++){
        b[i] = s.k_way_search(arr,a[i]+1,a[i+1]+1,k);
    }
    for(i=0;i<k-1;i++){
        b[i+1] = s.max(b[i],b[i+1]);
        MAX = b[i+1];
    }
    return(MAX);

}


void FIND_MAX:: getdata(){
    int n,x,i,k;
    cout<<"enter the size of array : "; cin>>n;
    cout<<"enter the values of an array : ";       //taking the input values from user
    for(i=0;i<n;i++){
       cin>>x; arr.push_back(x);
    }
    cout<<"max is : "<< s.f_way_search(arr,n)<<endl;
    cout<<"max due to 2 way is : "<< s.s_way_search(arr,0,n-1,n)<<endl;
    cout<<"max due to 3 way : "<< s.t_way_search(arr,0,n-1,n)<<endl;
    cout<<"enter k value : "; cin>>k;
    cout<<"max due to k way : "<< s.k_way_search(arr,0,n-1,k)<<endl;
}

int main(){
  s.getdata();
}