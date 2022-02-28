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



void solve() {
   ll n,i,temp=0,ans=0;
   cin>>n;
   vector<array<int , 2>> a(n);
   for(i=0;i<n;i++){
       cin>>a[i][1]>>a[i][0];
   }

   sort(all(a));

   for(i=0;i<n;i++){
       if(temp <= a[i][1]){
           temp  = a[i][0];
           ans++;
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