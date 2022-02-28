#include <iostream>

using namespace std;

void show(int a[],int z,int n){
    int i;
    cout<<"\n";
    for(i=0;i<z;i++){
        cout<<a[i]<<" ";
    }
    cout<<"| ";
    for(i=z;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n,i,j,temp;
    cout<<"enter number of elements:";
    cin>>n;
    int a[n];
    cout<<"enter all elements in order:\n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"starting swaps:\n";
    show(a,n,n);
    for(j=n-1;j>0;j--){
        for(i=j;i>0;i--){
            if(a[i]>a[(i-1)/2]){
                temp=a[i];
                a[i]=a[(i-1)/2];
                a[(i-1)/2]=temp;
            }
            show(a,j+1,n);
        }
        temp=a[j];
        a[j]=a[0];
        a[0]=temp;
    }
    show(a,0,n);
    return 0;
}


