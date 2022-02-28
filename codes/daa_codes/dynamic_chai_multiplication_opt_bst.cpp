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


class dynamic_chain{
    vi a;
    public :
     void getdata();
     void getdata_opt_bst();
}s;

void dynamic_chain::getdata(){
    int n,i,j,k,x;
    cout<<"no of matgrices : "; cin>>n;
    vi a(n);
    cout<<"enter no of rows : ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
     
    int matrix_chain[n][n];
    for(i=1;i<n;i++){
        matrix_chain[i][i] = 0;   //no of comparisions to multiply 1 matrix is zero
    }

    for(i=2;i<n;i++){
        for(j=1;j<n-i+1;j++){
           // cout<<"evaluating for : ["<<i<<"]["<<j<<"]"<<endl;
            int k = j+i-1;
            matrix_chain[j][k] = INT_MAX;
            for(x=j;x<=k-1;x++){
                int steps = matrix_chain[j][x] + matrix_chain[x+1][k] + a[j-1]*a[x]*a[k];
                if(steps < matrix_chain[j][k]){
                    matrix_chain[j][k] = steps;
                   // cout<<"matrix chain ["<<j<<"]["<<k<<"] = "<<steps<<endl;
                }
            }
        }
    }

cout<<endl<<endl;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            cout<<matrix_chain[i][j]<<"     ";
        }
        cout<<endl<<endl;
    }
    cout<<"min steps is : "<<matrix_chain[1][n-1];
}



int sum(vi b , int i , int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum = sum + b[k];
    }
    return(sum);
}

void dynamic_chain::getdata_opt_bst(){
    int n,i,j,x;
    cout<<"enter no of key in a tree : "; cin>>n;
    vector<array<int,2>> a(n);
    cout<<"enter no and its frequency : "; 
    for(i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    sort(all(a));
    vi b(n);
    for(i=0;i<n;i++){
        b[i] = a[i][1];
    }

    
    int matrix_opt_bst[n][n];
    for(i=0;i<n;i++){
         matrix_opt_bst[i][i] = b[i];   
    }

    for(i=2;i<=n;i++){
        for(j=0;j<=n-i+1;j++){
            int k = j+i-1;
            matrix_opt_bst[j][k] = INT_MAX;
            for(x=j;x<=k;x++){
                int steps ;
                if(x>j ){
                    if(x<k){
                    steps =  matrix_opt_bst[j][x-1] +  matrix_opt_bst[x+1][k] + sum(b,j,k);
                }else{
                    steps =  matrix_opt_bst[j][x-1]+ sum(b,j,k);
                }
                }else{
                     if(x<k){
                    steps =  matrix_opt_bst[x+1][k] + sum(b,j,k);
                }else{
                    steps = sum(b,j,k);
                }
                }
                
                if(steps < matrix_opt_bst[j][k]){
                     matrix_opt_bst[j][k] = steps;
                   // cout<<"matrix chain ["<<j<<"]["<<k<<"] = "<<steps<<endl;
                }
            }
        }
    }

cout<<endl<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<=j)
            cout<< matrix_opt_bst[i][j]<<"     ";
            else
            cout<<"     ";
        }
        cout<<endl<<endl;
    }
    cout<<"min steps is : "<< matrix_opt_bst[0][n-1];
}

int main(){
    s.getdata();
    s.getdata_opt_bst();
    return(0);
}