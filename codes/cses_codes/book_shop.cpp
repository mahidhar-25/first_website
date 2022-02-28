#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define al(x) x.rbegin(),x.rend()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<bool> filled;


void solve(){
    ll n,max_price,ans=0,i,j;cin>>n>>max_price;
    vector<array<float , 3>> a(n);
    for(i=0;i<n;i++){
        cin>>a[i][1];
    }
    for(i=0;i<n;i++){
        cin>>a[i][2];
    }
    for(i=0;i<n;i++){
        a[i][0] = a[i][2]/a[i][1];
    }
    sort(al(a));
    for(i=0;i<n;i++){
       if(a[i][1]<=max_price){
           ans = ans + a[i][2];
           max_price = max_price - a[i][1];
       }
    }
    cout<<ans<<endl;
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