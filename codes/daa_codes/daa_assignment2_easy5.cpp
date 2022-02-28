
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
 
 

void solve() {
    ll n,i,j = 0,k,count = 0; cin>>n;
    vi a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
   
    
    k = 1;
    while(k<=n){
     for(i=0;i<n;i++){
         if(a[i] == k){
             cout<<"at index : "<<i<<" "<<k<<"found \n";
             k++;
         }
     }
     count++;
    }
    cout<<"\ntotal iterations are : "<<count<<endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return(0);
}