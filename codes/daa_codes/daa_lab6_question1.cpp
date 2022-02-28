#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define al(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

class greedy{
    vi a;
    public:
   void getdata();
   void getdata_knapsack();
}s;

void greedy::getdata(){
int n,target,i,count=0;
float sum , val;
cout<<"enter the number of differnet coins : "; cin>>n;
vi a(n);
cout<<"enter the value of coins : ";
for(i=0;i<n;i++){
    cin>>a[i];
}

sort(al(a));
cout<<"enter tgha value to convert into change : "; cin>>target;
sum = target;
for(i=0;i<n;i++){
    val = sum/a[i];
    count = count + floor(val);
    sum = sum - floor(val)*a[i];
    cout<<"no of coins required used of type "<<a[i]<<" is : "<<floor(val)<<endl<<endl;
}
if(sum>0){
    cout<<"we cant convert the "<<target<<" into change \n";
}else{
    cout<<"total count of coins used : "<<count<<endl;
}

}


void greedy::getdata_knapsack(){
    int n;
    double target,sum,count=0,val,profit=0,i;
cout<<"enter the number of differnet items : "; cin>>n;
    vector<array<double , 2>> a(n),b(n);
   
    for(i=0;i<n;i++){
         cout<<"enter each weight and its profit : ";
        double x,y; cin>>x>>y;
        a[i] = {x,y}; // a[i][0] = x , a[i][1] = y
        b[i] = {y/x , i};
    }
    sort(al(b));
    cout<<"enter the max quanity can weigh : "; cin>>target;
    sum = target;
    for(i=0;i<n;i++){
        if(a[b[i][1]][0] <= sum){
            sum = sum - a[b[i][1]][0];
            cout<<"we taken weigh  "<< a[b[i][1]][0] <<"  and profit is : "<< a[b[i][1]][1]<<endl<<endl;
            profit = profit +  a[b[i][1]][1];
            count++;
        }else{
            val = (sum / a[b[i][1]][0])* a[b[i][1]][0];
            sum = sum - val;
            profit= profit + (sum / a[b[i][1]][0])* a[b[i][1]][1];
             cout<<"we taken weigh   "<< val <<" of  "<<a[b[i][1]][0] <<"  and profit is : "<< ((val/ a[b[i][1]][0])*a[b[i][1]][1])<<" of : "<<a[b[i][1]][1]<<endl<<endl;
            count = count + (val / a[b[i][1]][0]);
        }
    }
    cout<<"total count  is : "<<count<<endl<<endl;
    cout<<"total profit is : "<<profit<<endl;

}

void solve(){
    s.getdata();
    s.getdata_knapsack();
    return;
}

int main(){
    solve();
    return(0);
}