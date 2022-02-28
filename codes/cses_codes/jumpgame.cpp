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
  
// 10 30 40 20
// 0  20 30 

void solve(){
  int n,sum=0,i,j;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(i=0;i<n;i++){
      cin>>a[i];
  }
  b[0] = 0;
  b[1] = a[1] - a[0];
  for(i=2;i<n;i++){
  b[i] = min(abs(b[i-1] + abs(a[i]-a[i-1])) , abs(b[i-2] + abs(a[i] - a[i-2])));
  }
  cout<<"solution is b  : "<<b[n-1]<<endl;
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