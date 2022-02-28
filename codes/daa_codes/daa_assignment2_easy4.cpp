
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
//  1 2 1 3 2 7 4 2



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    set<int> st;//take only unique values
    int ans = 0;
    for (int i = 0, j = 0; j < n; j++) {
        if (st.count(a[j])) {
            while (st.count(a[j])) st.erase(a[i++]);
        } 
        st.insert(a[j]);//every time we insert element
        ans = max(ans, j - i + 1); //j-i+1 is if we delete first occuring at i so we our new size is from i to j
    }
    cout << ans << "\n";
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