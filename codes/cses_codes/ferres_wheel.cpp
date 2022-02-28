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


void solve(){
  ll n,max_weight,i,count=0; cin>>n>>max_weight;
  vi child_weight(n);
  for(i=0;i<n;i++){
      cin>>child_weight[i];
  }
  sort(all(child_weight));
  
  for(i=0;i<n;){
      if(i!=n-1){
      if(child_weight[i] + child_weight[n-1] <= max_weight){
          count++;i++;n--;
      }else{
          count++;n--;
      }
  }else{
      count++;i++;
  }
}
 cout<<count;
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