#include<iostream>
#include<vector>
using namespace std;

class triplet{
    private:
    int n,x;
    vector<int> a;
    public:
    void getdata();
    void find_triplet_sum(int  n, vector<int> a, int x);
};

vector<int> ele;
void triplet::find_triplet_sum(int n, vector<int> a, int x){
    int i,j,k,sum;
    for(i=0;i<n-2;i++){
       for(j=i+1;j<n-1;j++){
       for(k=j+1;k<n;k++){
           sum = a[i]+a[j]+a[k];
           if(x==sum){
               ele.push_back(a[i]);
               ele.push_back(a[j]);
               ele.push_back(a[k]);

           }
       }
    }
    }
 int count = ele.size()/3;
 cout<<count<<endl;
  if(count==0){
      cout<<"there is no such match";
  }
 for(i=0;i<ele.size();i = i+3){
  cout<<"{ "<<ele[i]<<" , "<<ele[i+1]<<" , "<<ele[i+2]<<" } "<<endl;
 }

}


void triplet::getdata(){
    int val,i;
cout<<"enter the size of an array : ";
cin>>n;
cout<<"enter the array elements : ";
for(i=0;i<n;i++){
    cin>>val;
    a.push_back(val);
}
cout<<"enter the ele to equal sum : ";
cin>>x;
find_triplet_sum(n,a,x);
}


int main(){
    triplet s;
    s.getdata();
}

