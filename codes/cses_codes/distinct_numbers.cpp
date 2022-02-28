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

void removeDuplicates(ll arr[], ll n)
{
  
    // Initialise a vector
    // to store the array values
    // and an iterator
    // to traverse this vector
    vector<int> v(arr, arr + n);
    vector<int>::iterator it;
  
    // using unique() method to remove duplicates
    it = unique(v.begin(), v.end());
  
    // resize the new vector
    v.resize(distance(v.begin(), it));
  
    // Print the array with duplicates removed
    cout<<v.size();
}

void solve(){
    ll n,i; cin>>n;
    ll arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    removeDuplicates(arr,n);
  
    
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