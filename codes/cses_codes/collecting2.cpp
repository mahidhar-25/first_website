

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
 
 
/*
void solve() {
    ll n,i,j = 0,k,count = 0; cin>>n;
    vi a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    k = 1;
    while(k!=n){
     for(i=0;i<n;i++){
         if(a[i] == k){
             k++;
         }
     }
     count++;
    }
    cout<<count<<endl;
}
*/
void solve() {
    int n,m,i,x ,b,c,temp; cin >> n >>m;
    vector<bool> used(n + 1);
    vi a(n);
    int ans = 0;
    for(i=0; i<n ;i++){
        cin>>a[i];
    }
    m++;
    while(m--){
         cin>>b>>c;
         temp = a[c]; a[c] = a[b];  a[b] = temp;
        for(i=0;i<n;i++){
            ans = ans + !used[a[i] - 1];
            used[a[i]] = true;
        }
        cout<<ans <<" \n";
        for(i=0;i<n+1;i++){
            used[i] = false;
        }
        ans = 0;
    }
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