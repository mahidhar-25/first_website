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

vector<bool> filled;



void solve(){
   ll n,i,j,target;
   cin>>n>>target;
   vi a(n);
  for(i=0;i<n;i++){
      cin>>a[i]
  }
   vi dp(target+1 , 0);
   dp[0] = 1;
   for(i=1;i<=target;i++){
       for(j=0;j<n;j++){
           if(i-a[j]>=0){
        dp[i] =(dp[i] + dp[i-a[j]])%MOD ;
   }
       }
   }
   cout<<"no of ways is : ";
   cout<<dp[target]<<endl;
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