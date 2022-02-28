/*
1 way is linear search
2 way is binary recursive calls
       mid = (begin + end)/2;
        binary_search(arr,begin,middle);
        bnary_search(arr,middle+1,end);
3 way search 
    first = (begin + end)/3;
    second = (begin + end)/3 + first +1;
    triple_search(arr,begin,first);
    triple_search(arr,first+1,second);
    triple_search(arr,second+1,end);

k way search
a[0] = 0;
   for(i=1;i<=k-1;i++){
       a[i] = (begin + end)/k + a[i-1] +1;
   }

   for(i=0;i<k;i++){
       k_way_search(arr,a[i],a[i+1]);
   }

   */

  #include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
bool flag = 0;


vi a(10);
void k_way_search(int arr[], int begin , int end, int find ,int k){
    cout<<"begin = "<<begin<<" "<<"end = "<<end<<endl;

     int i;
     if(begin == end){
         if(arr[begin] == find){
             cout<<"\n search is succesfull";
             flag = 1;
             return;
         }
         return;
     }else if(begin>end){
         return;
     }
     cout<<" 1 ";
      a[0] = begin;
    for(i=1;i<k;i++){
        a[i] = a[i-1] + (end-begin)/k +1;
        cout<<"break at : "<<a[i];
    
    }
     cout<<" 2 ";
    a[k] = INT_MAX;
     if(find <= arr[a[1]]){
            cout<<" 4";
        k_way_search(arr , a[0] , a[1] , find ,k);
        if(flag==1){return;}
        }
    for(i=1;i<k;i++){
         cout<<" 3----3 ";
         cout<<" ( "<<arr[a[i]]<<" , "<<find<<" , "<<arr[a[i+1]]<<" ) "<<endl;
       if(find>arr[a[i]] && find <= arr[a[i+1]]){
         k_way_search(arr , a[i]+1 , a[i+1] , find ,k);
         if(flag==1){return;}
         cout<<"begin = "<<a[i]<<" "<<"end = "<<a[i+1]<<endl;
        }
    }
     if(flag==0){
      cout<<" \nsearch is unsuccesful";
      return;
  }
}

 void triple_way_search(int arr[], int begin , int end ,int find){
     cout<<"BEGIN = "<<begin<<" "<<"end = "<<end<<endl;
     int i;
     if(begin == end){
         if(arr[begin] == find){
             cout<<"\n search is succesfull";
             flag = 1;
             return;
         }
         return;
     }else if(begin>end){
         return;
     }
     int first = begin + (end-begin)/3;
     int second = first + (end-begin)/3;
     if(find<=arr[first]){
         triple_way_search(arr , begin , first ,find);
     }else if(find > arr[first] && find <= arr[second]){
         triple_way_search(arr ,first+1 , second, find);
     }else{
         if(arr[end]<find){
             cout<<"search is unsuccesful";
             return;
         }
        triple_way_search(arr, second+1 , end , find);
     }
  if(flag==0){
      cout<<" \nsearch is unsuccesful";
      return;
  }
}

void solve(){
int n,find,i,k; 
    cout<<"enter size of array  : "; 
    cin>>n;
    int arr[n]; 
     cout<<"enter the array values : ";
    for(i=0;i<n;i++){
     cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"enter which no u wanna search : ";
     cin>>find;
    triple_way_search(arr, 0 , n-1 , find);

    cout<<"\nenter value of k : ";
    cin>>k;
     cout<<"enter which no u wanna search : ";
     cin>>find;
    k_way_search(arr, 0, n-1, find, k);
}

int main() {
        solve();
    return(0);
}


