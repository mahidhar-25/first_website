#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int i,j,n,u=1;
    cout<<"enter no of elements: ";
    cin>>n;
    int a[n];
    cout<<"enter all elements:\n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> key,fq;
    key.push_back(a[0]);
    fq.push_back(0);
    int ch=0;
    for(i=0;i<n;i++){
        for(j=0;j<u;j++){
            if(key[j]==a[i]){
                ch=1;
                break;
            }
        }
        if(ch==1){
            fq[j]++;
            ch=0;
        }else{
            u++;
            key.push_back(a[i]);
            fq.push_back(1);
        }
    }
    for(i=0;i<u;i++){
        cout<<key[i]<<"  "<<fq[i]<<"\n";
    }
    int d,max=999999999;
    for(i=0;i<u;i++){
        d=0;
        for(j=0;j<u;j++){
            if(fq[i]<=fq[j]){
                d=d+(fq[j]-fq[i]);
            }else{
                d=d+fq[j];
            }
        }
        if(max>d){
            max=d;
        }
    }
    
    cout<<"final ans = "<<max;
    
}