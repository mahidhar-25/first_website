#include<bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve(){
 int n,i,j; 
  cout<<"enter size of array : ";
 cin>>n;
 vector<string> ans(n,"");
 cout<<"enter strings : ";
 for(i=0;i<n;i++){
     cin>>ans[i];
 }
 for(i=0;i<n-1;i++){
     for(j=i+1;j<n;j++){
         if(ans[i]>ans[j]){
             swap(ans[i],ans[j]);
         }
     }
 }
 cout<<"after sorting :\n";
  for(i=0;i<n;i++){
     cout<<ans[i]<<endl;
 }
}


int main() {
    
        solve();
    return(0);
}

  