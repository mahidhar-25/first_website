
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define vi vector<int>

class FIND_NEG_INT{
    private :
    vi arr;
    public:
    void getdata();
    int s_way_search(vi arr, int begin , int end, int n);
    int t_way_search(vi arr, int begin , int end, int n);
};

FIND_NEG_INT s;


int FIND_NEG_INT:: s_way_search(vi arr, int begin , int end ,int n){
    int MAX =INT_MIN,middle,first,second;
    if(begin == end){
        if(arr[begin]<0){
            return(1);
        }else{
            return(0);
        }
    }
    middle = (end - begin)/2 + begin;
    first = s.s_way_search(arr, begin ,middle, n);
    second = s.s_way_search(arr, middle+1 , end, n);
    MAX = first + second;
    return(MAX);
}

int FIND_NEG_INT:: t_way_search(vi arr, int begin ,int end, int n){
    int MAX = INT_MIN, mid_1,mid_2,first,second,third;
     if(begin == end){
          if(arr[begin]<0){
            return(1);
        }else{
            return(0);
        }
    }else if(begin>end){
        return(0);
    }
    mid_1 = (end - begin)/3 + begin;
    mid_2 = (end-begin)/3 + mid_1;
    first = s.t_way_search(arr, begin ,mid_1, n);
    second = s.t_way_search(arr, mid_1+1 , mid_2, n);
    third = s.t_way_search(arr, mid_2+1 , end, n);
    MAX = first + second + third;
    return(MAX);

}


void FIND_NEG_INT:: getdata(){
    int n,x,i,k;
    cout<<"enter the size of array : "; cin>>n;
    cout<<"enter the values of an array : ";       //taking the input values from user
    for(i=0;i<n;i++){
       cin>>x; arr.push_back(x);
    }
    cout<<"no of values < 0 2 way search : "<< s.s_way_search(arr,0,n-1,n)<<endl;
    cout<<"no of values < 0 3 way search : "<< s.t_way_search(arr,0,n-1,n)<<endl;
}

int main(){
  s.getdata();
}