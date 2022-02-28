#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define al(x) x.rbegin(),x.rend()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<bool> filled;



void solve(){
int n,i,count=0; cin>>n;
double sum=0;
vi b(n);
for(i=0;i<n;i++){
    cin>>b[i];
}
for(i=0; i+2<n;i++){
    sum = b[i]+ b[i+1] + b[i+2];
    sum /= 3;
    if(floor(sum) == sum){
        count++;
    }
}
cout<<count<<endl;
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