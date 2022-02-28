
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()

class sorting{
    vi a;
    public :
    void insertion_sort(vi , int);
}s;

//same as insertion sort the only diff is we find the position of elemnt if it is less than it previous elemt by binary search
void sorting:: insertion_sort(vi b, int n){
    int i,j, temp;
    for(i=1;i<n;i++){
        temp = b[i];
        j = i-1;
     int p = 0;
      while(p<j){                           
          int mid = (p+j)/2;
          if(b[mid] == temp)  j = mid;
          else if(b[mid] > temp)  j = mid;
          else  p = mid + 1; 
      }
      for(int k = i; k>j;k--){ //adjusting array after finding the index
          b[k] = b[k-1];
        }
        b[j]= temp;
       for(auto c : b ){
        cout<<c<<" ";
    }
    cout<<endl;
    }
     cout<<"sorted array through insertion sort is : ";
    for(auto c : b ){
        cout<<c<<" ";
    }
}

void solve(){
    int n,i; 
    cout<<"enter the size of an array : "; cin>>n;
    vi a(n), b(n) ;cout<<"entere the elements of an array :";
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    s.insertion_sort(b , n); cout<<endl;
    
}
int main(){
    solve();
}



