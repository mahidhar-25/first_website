//logic : 
// step 1 : take inputs from user of all weights and profits and max weigh
// step 2 :  generate all possible subsets with condition 
//           we generally we include and we add it weight to our sum and keep track of sum and profit
//           we retutn() if sum > max_weigh or if k == n max size 
//           if sum < max_weight we print the possible subset and its profit
// step 3 : we print all sunsets

// time complexity : 
//                  here we generating all possibilites subsets of weights using back tracking method its time complexity O(2^n); 
//                  any way we decrease some computations using sum > max_weigh condition it doesnt effect time complexity much
//                  O(2^n);
//space complexity : 
//                   O(n)

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

class knapsack{
    int w;
    public : 
    void getdata();
}s;
int sum=0,profit=0,count=0;
vi subset;

//generating all possible subsets using backtracking 

void generate_subsets(vi &a,int n ,int k , int max_weigh , vector<array<int , 2>> b){
   // cout<<"n  = "<<n<<"  k = "<<k<<endl;
   if(sum > max_weigh) return; //checking condition that it doesnt exceed max_weigh
    if(k==n){
        if(sum <= max_weigh){
            cout<<"subset : ";
        for(auto c: subset){
            cout<<c<<" ";
        }
        cout<<"\nprofit :- "<<profit;
        cout<<"\n\n";
        ::count++;
        }
    }else{
        subset.push_back(a[k]);
        sum += a[k]; profit += b[k][0];
        generate_subsets(a,n,k+1 , max_weigh , b);  // taking the weight and continuiong
        subset.pop_back();
        sum -= a[k]; profit -= b[k][0];
        generate_subsets(a,n,k+1 , max_weigh , b);   // not taking the weight and continuing
    }
}
//we take the input from user 
void knapsack :: getdata(){
    int n,i,max_weigh; 
    cout<<"entyer no of different items : "; cin>>n;
    vector<array<int , 2>> b(n);
    vi a(n);
    cout<<"enter weight and profits : ";
    for(i=0;i<n;i++){
        cin>>b[i][1]>>b[i][0];
        a[i] = b[i][1];
    }
    cout<<"enter max weight : "; cin>>max_weigh;
    generate_subsets(a , n , 0 , max_weigh ,b);

}

void solve(){
s.getdata();
cout<<"max passoibilites are : "<<::count<<endl;
}

int main(){
    solve();
    return(0);
}
