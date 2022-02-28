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

vector<bool> filled;


int merge(vi arr , vi temp , int left , int mid , int right){
    int i,j,k,inversion_count=0;
    i=left; j = mid; k = left;

    while(i<=(mid - 1) && j<= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i]; k++;i++;
        }else{
            temp[k] = arr[j]; k++;j++;
            inversion_count += (mid - i);
        }
    }

    while(i<= mid - 1){
        temp[k] = arr[i]; k++; i++;
    }
     while(j<= right){
        temp[k] = arr[j]; k++; j++;
    }
    for(i=left; i<=right ; i++){
        arr[i] = temp[i];
    }

    return(inversion_count);
         
}


int merge_sort(vi arr , vi temp , int left , int right){
    int inversion_count=0 , mid;

    if(right > left){

    mid = left + (right - left)/2;


    inversion_count += merge_sort(arr , temp , left , mid );
    inversion_count += merge_sort(arr , temp , mid+1 , right);

    inversion_count += merge(arr , temp , left , mid+1 , right);

    }
    return(inversion_count);
}


void solve(){
int n,i,no_of_inversions; cin>>n;
vi arr(n) , temp(n);
for(i=0;i<n;i++){
    cin>>arr[i];
}
no_of_inversions = merge_sort(arr ,temp , 0,  n-1);
cout<<"no of inversions : "<<no_of_inversions<<endl;
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