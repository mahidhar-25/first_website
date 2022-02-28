#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
    long long int n,result = 0,i=1;
    cin>>n;
    while(pow(5,i)<=n){
    result = result + n / pow(5,i);
    i++;
    }
    cout<<result;
}