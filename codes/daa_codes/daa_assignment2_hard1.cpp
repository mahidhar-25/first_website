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
int n,i,j; cin>>n;
 vector<array<int , 8>> dp(n+1);
 for(i=0;i<n+1;i++){
     for(j=0;j<8;j++){
         dp[i][j] = 0;
     }
 }
 dp[0][7] = 1;
 for(i=1;i<n+1;i++){
     dp[i][0]  +=  dp[i-1][7];
     dp[i][1]  +=  dp[i-1][6];
     dp[i][3]  +=  dp[i-1][7] + dp[i-1][4];
     dp[i][4]  +=  dp[i-1][3];
     dp[i][6]  +=  dp[i-1][7] + dp[i-1][1];
     dp[i][7]  +=  dp[i-1][3] + dp[i-1][6] + dp[i-1][0];
 }
 cout<<dp[n][7]<<endl;
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