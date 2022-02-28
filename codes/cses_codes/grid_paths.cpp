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
/*

//backtrack 

ll fn(int x , int y, vector<vector<char>> a){
    if(x<0 || y<0 || a[x][y]=='*'){
        return(0);
    }else if(x==0 && y==0){
        return(1);
    }else{
        return(fn(x-1 , y,a) + fn(x , y-1,a));
    }
}
*/

void solve(){
    ll n,r,i,x,j; cin>>n;
    vector<vector<char>> a(n , vector<char> (n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<ll>> dp(n , vector<ll> (n,0));
    dp[0][0] = 1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
               if(a[i][j] == '.'){
                   if (i > 0) {
	                  (dp[i][j] += dp[i-1][j]) %= MOD;
	               }
	               if (j > 0) {
	                  (dp[i][j] += dp[i][j-1]) %= MOD;
	               }
                   } else {
	                  dp[i][j] = 0;
                      }
               }
        }
    cout<<dp[n-1][n-1];
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