#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    long long int n,i,a,b;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>a>>b;
        if((a+b)%3==0 && a>0 && b>0 ){
            if((a-b)>(a+b)/3){
                cout<<"NO"<<endl;
            }else if((b-a)>(a+b)/3){
                cout<<"NO"<<endl;
            }else{
            cout<<"YES"<<endl;
            }
        }else if(a==0&&b==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}