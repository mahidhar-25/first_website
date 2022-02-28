
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define vi vector<int>
int flag = 0;

class FIND_ELE{
    private :
    vi arr;
    public:
    void getdata();
    void s_way_search(vi arr, int begin , int end, int n);
    void t_way_search(vi arr, int begin , int end, int n);
    void R_s_way_search(vi arr, int begin , int end, int n);
    void R_t_way_search(vi arr, int begin , int end, int n);
};

FIND_ELE s;


void FIND_ELE:: s_way_search(vi arr, int begin , int end ,int find){
   int mid;
   while(begin<=end){
       mid = begin + (end - begin)/2;
       if(arr[mid]==find){
         cout<<"\nwe found "<<find<<" in the array"<<endl;
           return;
       }else if(arr[mid] > find){
           end = mid -1;
       }else{
           begin = mid + 1;
       }
   }
   cout<<"\nthere is no "<<find<<"  in array"<<endl;
   return;
}

void FIND_ELE:: R_s_way_search(vi arr, int begin , int end ,int find){
    int mid;
    static int count = 1;
     mid = begin + (end - begin)/2;
     if(begin==end){
         if(arr[begin] == find){
         cout<<"we found "<<find<<"  in array using 2_way recursion"<<endl; flag =1;
         return;
         }
         return;
     }else if(begin > end){
         return;
     }else if(begin == end -1 ){
         if(arr[begin] == find || arr[end] == find ){
             cout<<"we found "<<find<<"  in array using 3_way recursion"<<endl; flag =1;
         return;
         }
     }else if(arr[mid]>find){
         s.R_s_way_search(arr , begin , mid , find); if(flag ==1){return;}
     }else{
          s.R_s_way_search(arr , mid , end , find);  if(flag ==1){return;}
     }
    if(flag == 0 && count == 1){
     cout<<"element is not found "<<endl;
     count++;
    }
}

void FIND_ELE:: t_way_search(vi arr, int begin ,int end, int find){
 int mid_1, mid_2;
 while(begin<=end){
     mid_1 = begin + (end - begin)/3;
     mid_2 = mid_1 + (end - begin)/3;
     if(arr[mid_1] == find || arr[mid_2] == find){
         cout<<"\nwe found "<<find<<"  in the array"<<endl;
         return;
     }else if(arr[mid_1]> find){
         end = mid_1 -1;
     }else if(arr[mid_2] < find){
         begin = mid_2 + 1;
     }else{
        begin = mid_1 +1; end = mid_2 - 1;
     }
 }
 cout<<"\nthere is no "<<find<<" in array"<<endl;
 return;
}

void FIND_ELE:: R_t_way_search(vi arr, int begin ,int end, int find){
 int mid_1, mid_2;
 static int count_1 = 1;
     mid_1 = begin + (end - begin)/3;
     mid_2 = mid_1 + (end - begin)/3;
     if(begin == end){
         if(arr[begin] == find){
         cout<<"we found "<<find<<" in array using 3_way recursion"<<endl; flag =1;
         return;
     }
      return;
     }else if(begin>end){
             return;
     }else if(begin == end -1 ){
         if(arr[begin] == find || arr[end] == find ){
             cout<<"we found "<<find<<" in array using 3_way recursion"<<endl; flag =1;
         return;
         }
     }else if(arr[mid_1]>=find){
         s.R_t_way_search(arr , begin , mid_1 , find); if(flag ==1){return;}
     }else if(arr[mid_2]<=find){
          s.R_t_way_search(arr , mid_2 , end , find); if(flag ==1){return;}
     }else{
          s.R_t_way_search(arr , mid_1+1 , mid_2-1 , find); if(flag ==1){return;}
     }
     if(flag == 0 && count_1 == 1){
     cout<<"element is not found "<<endl;
     count_1++; 
    }
}

void FIND_ELE:: getdata(){
    int n,x,i,find;
    cout<<"enter the size of array : "; cin>>n;
    cout<<"enter the values of an array : ";       //taking the input values from user
    for(i=0;i<n;i++){
       cin>>x; arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    cout<<"enter the value to be searched : "; cin>>find;
    cout<<"\nusing 2 way search iterative method : "<<endl; s.s_way_search(arr,0,n-1,find); 
    cout<<"\nusing 3 way search iterative method : "<<endl; s.t_way_search(arr,0,n-1,find);
    cout<<"\nusing 2 way search recursive method : "<<endl; s.R_s_way_search(arr,0,n-1,find); flag = 0;
    cout<<"\nusing 3 way search recursive method : "<<endl; s.R_t_way_search(arr,0,n-1,find); flag = 0;
}

int main(){
  s.getdata();
}