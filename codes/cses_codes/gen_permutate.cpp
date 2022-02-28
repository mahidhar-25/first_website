#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define vc vector<char>
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


vi permutate;
vector<bool> used;
vc val;
int n;
/*

void search(){
    int i;
    if(permutate.size()==n){
        for(i=0;i<permutate.size();i++){
            cout<<permutate[i]<<" ";
        }
        cout<<endl;
    }else{
        for(i=0;i<n;i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            permutate.push_back(val[i]);
            search();
            used[i] = false;
            permutate.pop_back();
        }
    }
}



void solve(){
    int x,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        val.push_back(x);
    }
   // used.resize(n);
    for(i=0;i<n;i++){
       used.push_back(false);
    }
    search();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
*/


int main(){
    int n,i;
    string a;
        cin>>a;
        n = a.size();
        
do{
    for(auto c :a){
        cout<<c<<" ";
    }
    cout<<"\n";
}while(next_permutation(a,a+n));
}
