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
  ll n,max_cost,i,j,k;
  cin>>n>>max_cost;
  vector<array<int , 2>> a(n);
  for(i=0;i<n;i++){
      cin>>a[i][1];   //price
  }
  for(i=0;i<n;i++){
      cin>>a[i][0];  //pages
  }
  int m = max_cost;
  int dp[n+1][m+1];

    for(i=0;i<=n;i++){
        for(j=0;j<=max_cost;j++){

            if(i==0||j==0){
              dp[i][j] = 0;
           }else if(a[i-1][1] <= j){

               // ifprice is less than our index(which is price) we will check by considering that price value and not considering that price value
               dp[i][j] = max(a[i-1][0] + dp[i-1][j-a[i-1][1]] , dp[i-1][j]);
           }else{

               // if price is greater we wont consider it pages
               dp[i][j] = dp[i-1][j];
           }
        }
    }
cout<<dp[n][m]<<endl;
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