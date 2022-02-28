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

class max_min{
    private:
    int n,max,min;
    vi a;
    public:
    void getdata();
    int find_max(int &n , vi &a );
    int find_min(int &n , vi &a );
};
  max_min s;

int max_min::find_max(int &n , vi &a ){
    int max = 0,i,index;
    for(i=0;i<n;i++){
        if(a[i]>max){
            max = a[i]; index = i;
        }
    }
    for(int j = index;j<n-1 ;j++){
        a[j] = a[j+1];
    }
    --n;
    return max;
}


int max_min::find_min(int &n , vi &a ){
    int min=MOD,i,index;
    for(i = 0;i<n;i++){
        if(a[i]<min){
            min = a[i];  index = i;
        }
    }
     for(int j = index;j<n-1 ;j++){
        a[j] = a[j+1];
    }
     --n;
   return min;
}


void max_min::getdata(){
    int x,n,i,j,k; cin>>x;
   for(i=0;i<n;i++){
       cin>>x;
      a.push_back(x);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(k=j;k<n;k++){
                    a[k] = a[k+1];
                }
                --n;
            }
        }
    }
     for(i=0;i<2;i++){
        if(i%2==0){
            cout<<"MAX = "<<s.find_max(n,a)<<endl;
            cout<<"SMAX = "<<s.find_max(n,a)<<endl;
        }else{
            cout<<"MIN = "<<s.find_min(n,a)<<endl;
            cout<<"SMIN = "<<s.find_min(n,a)<<endl;
        }
    }
}



void solve(){
    s.getdata(); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}