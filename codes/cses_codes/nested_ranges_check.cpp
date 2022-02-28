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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve(){
   ll n,i,j; cin>>n;
  vector<array<int , 3>> a(n);
   for(i=0;i<n;i++){
       cin>>a[i][0]>>a[i][1]; a[i][2] = i;
   }

sort(a.begin(), a.end());

vi contaions(n),contained(n);
int max_ele = 0;
for(i=0;i<n;i++){
          if(a[i][1] <= max_ele)
              contained[a[i][2]] = 1;
          max_ele = max(max_ele , a[i][1]);
}
int min_ele = INT_MAX;
for(i=n-1;i>=0;i--){
          if(a[i][1] >= min_ele)
              contaions[a[i][2]] = 1;
          min_ele = min(min_ele , a[i][1]);
}

for(auto c : contaions){
    cout<<c<<" ";
}
cout<<"\n";
for(auto c : contained){
    cout<<c<<" ";
}
cout<<"\n";
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