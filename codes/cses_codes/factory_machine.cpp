/*
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


double n, t, a[MAX_N] ;
double  sum = 0;
 
inline bool ok(ll mid) {
    ll products = 0;
        products  = mid * sum;
        cout<<"mid = "<<  mid<<"product = "<<products<<endl;
        if (products >= t) return true;
    return false;
}

void solve() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + 1/a[i];
        }
        cout<<sum<<endl;
        sum = floor(sum);
    ll low = 0, high = INF;
    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        if (ok(mid)) high = mid;
        else low = mid;
    }
    cout << high << "\n";
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
*/
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, t, a[MAX_N];

int main() {
   cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll lo = 1, hi = 1e18;
   while(lo<hi){
       ll mid = (lo + hi)/2, sum =0;
       for(int i=0;i<n;i++){
         sum += min(mid/a[i] , (ll)1e9);
       }
       if(sum>=t){
           hi = mid;
       }else{
           lo = mid + 1;
       }
   }
    cout << lo << "\n";
}