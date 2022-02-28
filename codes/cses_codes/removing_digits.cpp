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
    ll n,r,i,x; cin>>n;
    vi a(n+1,0);
    for(i=0;i<=9;i++){
        a[i] = 1;
    }
    for(i=10;i<=n;i++){
        ll max_digit = 0; x=i;
        while(x>0){
            r =x%10; x /=10;
            max_digit = max(max_digit , r);
        }
        a[i] = a[i] + a[i-max_digit] + 1;
    }
    cout<<a[n];
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