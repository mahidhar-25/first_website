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

vi dp(MAX_N);
vi sol(MAX_N);

//  to calculate n index either white or red
// if red problem is same as n-1
// if while remaing k-1 should be white so for remaining n-k is same as above dp solution

void solve(){
int k,i,j,sum=0; cin>>k;
int a,b; cin>>a>>b;

for(i=1;i<k;i++){
    dp[i] = 1;
}
dp[k] = 2;
for(i=k+1;i<MAX_N;i++){
    dp[i] = dp[i-1] + dp[i-k];
    dp[i] %= MOD;
}

for(i=1;i<MAX_N;i++){
    sol[i] = sol[i-1] + dp[i];
    sol[i] %= MOD;
}
cout<<sol[b]-sol[a-1]<<endl;
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