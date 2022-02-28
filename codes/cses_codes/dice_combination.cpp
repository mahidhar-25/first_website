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
   ll n,i,j;
   cin>>n;
   vi dp(n+1 , 0);
   dp[0] = 1;
   for(i=1;i<=n;i++){
       for(j=1;j<=6 && i-j>=0 ; j++){
           dp[i] = (dp[i] + dp[i-j])%MOD;
       }
   }
   cout<<dp[n]<<endl;
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