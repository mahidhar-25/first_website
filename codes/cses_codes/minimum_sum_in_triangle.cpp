#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<bool> filled;
// 1
// 2 3 1
// 1 2 3 4
// 2 1 1 1 1


void minimum_sum(vvi a , int n ){
    int sum = a[1][0], k=1,i,j;
    for(i=1;i<n;i++){
        for(j=0;j<k;j++){
            cout<<"sum = "<<sum<<endl;
            sum += min(a[i][j],a[i][j+1]);
            if(a[i][j]>a[i][j+1]){
                k = j+1+1;
            }else{
                k = j+1;
            }
        }
    }
    cout<<sum<<endl;
}

void print(vvi ans , int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

void solve(){
    int t,x,y,j,k=1,i,count=0; cin>>t;
    for(i=0;i<t;i++){
       cout<<"case count : "<<i<<endl;
       cout<<"enter s case : "; cin>>x; j=0; k=1;
        vvi ans(x); vi a;
        while(j<k && k<x+1){
            //cout<<"count = "<<k-1<<endl; 
           cin>>y; a.push_back(y); j++;
           if(j==k){
               ans.push_back(a);
               a.resize(0); j = 0; k++;
               print(ans , k-1);
           }
        }
        cout<<"loop complete ";
        minimum_sum(ans , ans.size());
        ans.resize(0);
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