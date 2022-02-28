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

vector<string> a;
void generate_graycode(int n){
    if(n==0){
        cout<<"0"<<endl;
        exit(0);
    }
    int i,j;
    a.push_back("0");
    a.push_back("1");
    for(i=2;i<pow(2,n);i=i*2){
        for(j=i-1;j>=0;j--){
            a.push_back(a[j]);
        };
        for(j=0;j<i;j++){
            a[j] = "0" + a[j];
        }
        for(j=i;j<2*i;j++){
            a[j] = "1" + a[j];
        }
    }

    for(i=0;i<pow(2,n);i++){
        cout<<a[i]<<endl;
    }
}

void solve(){
    int n;
    cin>>n;
    generate_graycode(n);
}

int main() {
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}