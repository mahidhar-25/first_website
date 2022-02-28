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



void solve() {
ll n,m,k,i,j;
cin>>n>>m;
int a[n+1][m+1];
for(i=0;i<=n;i++){
    for(j=0;j<=m;j++){
        if(i==j){
            a[i][j] = 0; // if dimension are equal
        }else{
            a[i][j] = INT_MAX;
            for(k=1;k<i;k++){
                a[i][j] = min(a[i][j]  ,  a[k][j] + a[i-k][j] + 1);   //dividng the rectangle nto two parts and finding min for lenth
            }

             for(k=1;k<j;k++){
                a[i][j] = min(a[i][j]  ,  a[i][k] + a[i][j-k] + 1);   //dividng the rectangle nto two parts and finding min for breadth
            }
        }
    }
}

cout<<a[n][m]<<endl;
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