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
      cin>>a[i];
        }
  vi dp(target+1 , INT_MAX);
dp[0] = 0;

for(i=1;i<target+1;i++){
  for(j=0;j<n;j++){
      if(a[j]<=i){
          int min_coins = dp[i-a[j]];
          if(min_coins!= INT_MAX && min_coins + 1 <dp[i]){
              dp[i] = min_coins + 1;
          }
      }
  }
}
if(dp[target]!=INT_MAX)
   cout<<dp[target]<<endl;
else
cout<<"-1"<<endl;
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