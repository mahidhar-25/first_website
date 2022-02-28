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
   ll x,n,ele; cin>>x>>n;
   set<int> positions;
   multiset<int>lengths;
   positions.insert(0); positions.insert(x);
   lengths.insert(x-0);

   while(n--){
       cin>>ele;
       positions.insert(ele);
       auto it = positions.find(ele);
       int previous_val = *prev(it); int next_val = *next(it);
       lengths.erase(lengths.find(next_val - previous_val));
       lengths.insert(ele-previous_val); lengths.insert(next_val - ele);
       cout<<*lengths.rbegin()<<" ";
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