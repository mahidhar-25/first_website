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

//5 7
//2 -1 3 5 -2

void solve(){
   ll n,ans=0,sum=0; cin>>n;
   vi a(n),mod(n,0);
   for(int i=0;i<n;i++){
       cin>>a[i];
       sum += a[i];
      mod[((sum%n)+n)%n]++;
   }
   for(int i=0;i<n;i++){
   if(mod[i]>1){
       ans += (mod[i]*(mod[i]-1)/2);
   }
   }
   cout<<ans+mod[0]<<endl;

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