// logic : 
// step 1 : take input weights of all items , max weight , and items profit
// step 2 : sort the weight in ascending order using sort() in built function which take O(nlogn), in worst case  O(n2)
// step 3 : include the weight if it doesnt exceed and add profit to it and continue until it exceeds
// print the maximun profit

// time complexity :  O(n) + O(nlogn) is equal to O(nlogn) which is o(n2)

// space complexity : O(n);


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

void knapsack :: getdata(){
    int n,max_weigh,profit = 0, weigh = 0,i,j;
    cout<<"enter no of different items  : "; cin>>n;  //taking no of items
    int p; cout<<"enter the profit of elements : "; cin>>p; //profit of all objects
    vi w(n);
    cout<<"enter the weights all elements : ";
    for(i=0;i<n;i++){
        cin>>w[i]; //input for each item weight
    }
    cout<<"enter max weigh : "; cin>>max_weigh;
  
   sort(all(w)); //sort in ascending order
    for(i=0;i<n;i++){
         if(weigh + w[i] <= max_weigh){
             profit += p;
             weigh += w[i];
         }
    }
    cout<<"profit is : "<<profit<<endl;
}



void solve(){
s.getdata();
}

int main(){
    solve();
    return(0);
}
