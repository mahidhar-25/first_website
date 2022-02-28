
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

ll max(ll a ,ll b){
    if(a > b) return a;
    else return b;
}
void getdata(){
    ll n,i; cin>>n;
    ll sum = INT_MIN , ans = 1;
    vector<ll> a(n);
    for(i=0;i<n;i++){
    cin>>a[i];
    int temp = sum;
    sum = max(a[i], sum + a[i]);
    if(sum%n == 0){
  ans++;
    }
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        getdata();
    }
    return(0);
}