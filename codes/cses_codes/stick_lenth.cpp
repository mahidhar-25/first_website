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
ll n,i,cost = 0; cin>>n;
vi a(n);
for(i=0 ;i <n ;i++){
    cin>>a[i];
}
sort(all(a));
ll mid = a[n/2];
for(i=0 ;i <n ;i++){
    if(a[i]-mid >= 0){
        cost += a[i] - mid;
    }else{
        cost += (-1)*(a[i] - mid);
    }
}
cout<<cost;
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