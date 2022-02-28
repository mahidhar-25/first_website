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
//2 4 1 2 7


void solve(){
    ll n,x,sum=0,ans=0,i,j,k=0,target = 0;
    cin>>n>>x;
    vi a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
   for(i=0;i<n;i++){
      
       if(target + a[i] <= x){
           target = target + a[i];
       }else{
            //cout<<"target = "<<target<<" start = "<<a[k]<<endl;
           target = target - a[k];
           i--;
           k++;
       }
       if(target == x) ans++;
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