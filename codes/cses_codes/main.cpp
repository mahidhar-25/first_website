#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
//Compiler version g++ 6.3.0
bool flag=0;

void k_way_search(int a[],int begin, int end, int find ,int k){
    cout<<"begin = "<<begin<<" "<<"end = "<<end<<endl;
    static int count =0;
    count++;
    if(count==10){
        exit(0);
    }
  if(find < a[begin] || find > a[end]){
    cout<<"no is not present";
    return;
  }else if(begin==end || end == begin+1){
      cout<<a[begin]<<","<<a[end]<<endl;
    if(find==a[begin] || find==a[end]){
      cout<<"no is present";
      flag==1; count++;
      return;
    }
    return;
  }else if(begin > end){
    return;
  }
  cout<<endl;
  int i,b[k];
  b[0] = begin;
  for(i=1;i<=k-1;i++){
    b[i] = b[i-1] + (end - begin)/k+1;
    cout<<" breaks at :  "<<b[i]<<" ";
  }
  cout<<endl;
  if(find <= a[b[1]]){
    k_way_search(a,b[0],b[1],find,k); 
  }else if(find > a[b[k-1]] && find <= a[end]){
   cout<<endl;
    k_way_search(a,b[k-1],end,find,k);
  }else{
    cout<<endl;
    for(i=1;i<k-1;i++){
      if(find > a[b[i]] && find <= a[b[i+1]]){
       cout<<endl;
        k_way_search(a,b[i],b[i+1],find,k);
      }
    }
  }
  if(count==0){
  if(flag==0){
    cout<<"\n search is unsuccessful";
 count++;
    return;
}
  }
  return;
}

int main()
{
    int n,i,k,find;
    cout<<"enter array size :"; cin>>n;
    int a[n];
    cout<<"enter values : ";
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    cout<<"enter which no u wann search : ";
    cin>>find;
    cout<<"enter k : "; cin>>k;
    k_way_search(a,0,n-1,find,k);
}