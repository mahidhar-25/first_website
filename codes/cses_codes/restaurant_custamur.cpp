#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll maximum(ll a , ll b){
    if(a > b){
        return(a);
    }else{
        return(b);
    }
}

void solve() {
    ll n,i,max = 0, max1 = 0; cin>>n;
    vector<ar<int, 2>> a(2*n);
    for(i=0;i<2*n;i = i+2){
        cin>>a[i][0]>>a[i+1][0];
        a[i][1] = 1; a[i+1][1] = -1;
    }
    sort(a.begin(), a.end());
    for(i=0;i<2*n;i++){
        max = max + a[i][1];
     max1 = maximum(max1 , max); 
    }
    cout<<max1;
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